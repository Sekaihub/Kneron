/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <drivers/vatics/usb/dwc3-uboot.h>
#include <drivers/vatics/usb/fastboot.h>
#include <drivers/vatics/usb/g_dnl.h>
#include <assert.h>
#include <sysctrl.h>
#include "maps.h"
#include <lib/mmio.h>
#include <drivers/vatics/wdt.h>
#include <wagner_buf.h>

/* USE quirks as #define */
//#define HAS_HIBERNATION
//#define HAS_LPM_ERRATUM
//#define IS_UTMI_L1_SUSPEND
//#define IS_SELFPOWERED	// unused in dwc3 controller
//#define NEEDS_FIFO_RESIZE	//tx_fifo_resize
//#define SETUP_PACKET_PENDING  //if (dwc->revision < DWC3_REVISION_188A)
//#define U2EXIT_LFPS
//#define U2SS_INP3
//#define DEL_P1P2P3
//#define DEL_PHY_POWER_CHG
//#define LFPS_FILTER
//#define RX_DETECT_POLL
//#define DIS_ENBLSLPM
//#define DIS_U2_FREECLK_EXISTS
//#define TX_DE_EMPHASIS_QUIRK
//#define TX_DE_EMPHASIS
//#define DISABLE_SCRAMBLE_QUIRK

// use usb 3.0 as default structure
static struct dwc3_device dwc3_device_data = {
	.maximum_speed = USB_SPEED_SUPER,
	.base = VPL_USBC30_MMR_BASE,
	.dis_enblslpm_quirk = 1,
	.dis_u3_susphy_quirk = 1,
	.dis_u2_susphy_quirk = 1,
	.req_p1p2p3_quirk = 1,
	.dis_del_phy_power_chg_quirk = 1,
};

int wagner_usb_boot(unsigned int image_id, image_info_t *image_data,
			unsigned int bootmode)
{
	int ret = -1;
	u32 reg = 0;

#if WAGNER_FPGA
	/* Enable USB20C/USB30C VBUS OC pad */
	// Bit 25-25: USB30C VBUS OC pad enable control (default: 1'b0).
	// Bit 22-22: USB20C VBUS OC pad enable control (default: 1'b0).
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_SET_REG_7, 0x2400000);
	// clear scrtu dbg share pin
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_6, 0x1000000);
#endif

	switch (bootmode) {
	case BOOT_USB20:
	case RECOVERY_USB20:
		VERBOSE("USB 2.0 boot\n");
		dwc3_device_data.maximum_speed = USB_SPEED_HIGH;
		dwc3_device_data.base = VPL_USBC20_MMR_BASE;

		/* Enable VBUS Valid comparator */
		reg = mmio_read_32(VPL_USBC20_WRAPPER_MMR_BASE + 0x10);
		reg |= (1U << 8);
		mmio_write_32(VPL_USBC20_WRAPPER_MMR_BASE + 0x10, reg);

		break;
	case BOOT_USB30:
	case RECOVERY_USB30:
		VERBOSE("USB 3.0 boot\n");
		/* Enable VBUS Valid comparator */
		reg = mmio_read_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x1c);
		reg |= (1U << 25);
		mmio_write_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x1c, reg);

#if !WAGNER_FPGA
		/* dwc3 phy setup
		 *
		 * There is a specific order for the signal setting:
		 * a)  ref_use_pad
		 * b)  ref_ssp_en
		 * c)  ssc_range
		 * d)  ssc_en
		 */

		extern	bool	wagner_USB3_clk_external;
		reg = mmio_read_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x14);

		/* a)  ref_use_pad */
		/* disable USB30C PHY clock */
		mmio_write_32(SYSC_S_BASE + SYSC_CLK_EN_CLR_REG_5, (1U<<2));

		/* select USB30C reference source clk */
		reg = (reg & ~(0x1)) | wagner_USB3_clk_external;
		mmio_write_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x14, reg);

		/* enable USB30C PHY clock */
		mmio_write_32(SYSC_S_BASE + SYSC_CLK_EN_SET_REG_5, (1U<<2));

		/* b)  ref_ssp_en: Reference Clock Enable for SS function. */
		reg |= (1U << 4);
		mmio_write_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x14, reg);

		/* c)  ssc_range: Spread Spectrum Clock Range */
		reg = mmio_read_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x18);
		reg |= (1U << 4); /* 3'b001: -4492ppm */
		mmio_write_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x18, reg);

		/* d)  ssc_en: Spread Spectrum Enable */
		reg |= (1U << 1);
		mmio_write_32(VPL_USBC30_WRAPPER_MMR_BASE + 0x18, reg);
#endif /* !WAGNER_FPGA */

		break;
	default:
		VERBOSE("USB mode error 0x%x\n", bootmode);
		break;
	}

	fastboot_init((void *)(image_data->image_base - USB_FB_HEADER_SIZE),
			image_data->image_max_size);

	dwc3_uboot_init(&dwc3_device_data);
	ret = g_dnl_register("usb_dnl_fastboot");
	if (ret) {
		ERROR("g_dnl_register fail\n");
		ret = -1;
	} else{
		while (1) {
			if (g_dnl_detach())
				break;
			//WATCHDOG_RESET();
			//usb_gadget_handle_interrupts(0);
			dwc3_uboot_handle_interrupt();
		}
		ret = 0;
	}

	return ret;
}

int wagner_usb_boot_bl2(unsigned int image_id, image_info_t *image_data,
			unsigned int bootmode)
{
	static bool     bl2_usb_finish_init;
	int ret = -1;
//	struct f_fastboot *fastboot_func;
	struct usb_function *function;

#ifdef IMAGE_BL2
	function = &overlaid_bufferp->usb_buf.f_fb.usb_function;
#else
	function = &overlaid_buffer.usb_buf.f_fb.usb_function;
#endif

	if (bl2_usb_finish_init) {
		VERBOSE("USB download re-entry !\n");
		fastboot_init((void *)image_data->image_base,
				image_data->image_max_size);
		g_dnl_clear_detach();
		while (1) {
			if (g_dnl_detach())
				break;
			dwc3_uboot_handle_interrupt();
		}
		VERBOSE("USB download re-exit !\n");
		return g_dnl_get_imagesize();
	}

	bl2_usb_finish_init = 1;

	switch (bootmode) {
	/* case BOOT_USB20: BOOT_USB20 overridden by RECOVERY_USB20 in BL1 */
	case RECOVERY_USB20:
		VERBOSE("USB 2.0 boot\n");
		dwc3_device_data.maximum_speed = USB_SPEED_HIGH;
		dwc3_device_data.base = VPL_USBC20_MMR_BASE;

		break;
	case BOOT_USB30:
	case RECOVERY_USB30:
		VERBOSE("USB 3.0 boot\n");
		break;
	default:
		VERBOSE("USB mode error 0x%x\n", bootmode);
		break;
	}

	fastboot_init((void *)image_data->image_base,
			image_data->image_max_size);

	dwc3_uboot_init(&dwc3_device_data);
	ret = g_dnl_register("usb_dnl_fastboot");
	if (ret) {
		ERROR("g_dnl_register fail\n");
		ret = -1;
	} else{
		function->set_alt(function, 0, 0);
		while (1) {
			if (g_dnl_detach())
				break;
			//WATCHDOG_RESET();
			//usb_gadget_handle_interrupts(0);
			dwc3_uboot_handle_interrupt();
		}
		ret = g_dnl_get_imagesize();
	}

	return ret;
}
