/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <errno.h>
#include <string.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <bl1/tbbr/tbbr_img_desc.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <common/interrupt_props.h>
#include <drivers/ti/uart/uart_16550.h>
#include <drivers/delay_timer.h>
#include <drivers/generic_delay_timer.h>
#include <lib/mmio.h>
#include <lib/utils.h>
#include <safezone.h>
#include <plat/common/platform.h>
#include <drivers/vatics/mmc/sdhci.h>
#include <drivers/vatics/wdt.h>

#include <wagner_buf.h>
#include <wagner_log.h>
#include "maps.h"
#include "wagner_def.h"
#include "wagner_private.h"

/*
 * Declarations of linker defined symbols which will help us find the layout
 * of trusted RAM
 */

/* Data structure which holds the extents of the trusted RAM for BL1 */
static meminfo_t bl1_tzram_layout;
static console_t console;
static bootselect_t bootselect;

extern bl_header_info_t bl_header_info;

/* Declare overlay buffer for each boot mode */
union OverlaidBuffer overlaid_buffer;

/* OTP Info */
bool	wagner_USB3_clk_external;
bool	wagner_TZC_enable;
bool	wagner_PMU_disable;

meminfo_t *bl1_plat_sec_mem_layout(void)
{
	return &bl1_tzram_layout;
}

/*
 * Perform any BL1 specific platform actions.
 */
void bl1_early_platform_setup(void)
{
	uint32_t chip_id_info, production_mode;

	wagner_pinmux_init();
	write_cntfrq_el0(plat_get_syscnt_freq2());
	generic_delay_timer_init();
	/* Initialize the console to provide early debug support */
	console_16550_register(UART_0, UART_CLOCK,
			       115200, &console);

	wagner_log_init();
	wagner_bootstep(WAGNER_STEP_BL1_EARLY_SETUP);
	/* Set Watchdog */
	chip_id_info = mmio_read_32(SYSC_S_BASE + SYSC_CHIP_ID_INFO);
	wagner_PMU_disable = !!(chip_id_info & PMU_BOOT_DISABLE);
	production_mode = (mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0))
				& PRODUCTION_MODE;
	if (production_mode)
		wagner_PMU_disable = 1;
#if (ENABLE_WATCHDOG == 1)
	if (((mmio_read_32(WAGNER_BOOTMODE_ADDR) >> 16) & SYSC_BOOT_MODE_MASK)
			!= BOOT_INVALID) {
		vpl_wdt_start(BOOT_WATCHDOG_TIME);
		wagner_bootstep(WAGNER_STEP_BL1_WDT_START);
	}
#endif

	/* Allow BL1 to see the whole Trusted RAM */
	bl1_tzram_layout.total_base = BL_SRAM_BASE;
	bl1_tzram_layout.total_size = BL_SRAM_SIZE;

	INFO("BL1: 0x%lx - 0x%lx [size = %lu]\n", BL1_RAM_BASE, BL1_RAM_LIMIT,
	     BL1_RAM_LIMIT - BL1_RAM_BASE); /* bl1_size */
}

/*
 * Perform the very early platform specific architecture setup here. At the
 * moment this only does basic initialization. Later architectural setup
 * (bl1_arch_setup()) does not do anything platform specific.
 */
void bl1_plat_arch_setup(void)
{
#if BL1_ENABLE_MMU
	wagner_bootstep(WAGNER_STEP_BL1_MMU_START);
	wagner_init_mmu_el3(bl1_tzram_layout.total_base,
			      bl1_tzram_layout.total_size,
			      BL1_RO_BASE,
			      BL1_RO_LIMIT);
#endif
}



/*
 * Function which will perform any remaining platform-specific setup that can
 * occur after the MMU and data cache have been enabled.
 */
void bl1_platform_setup(void)
{
	uint32_t otp_hw_cfg1;

	wagner_bootstep(WAGNER_STEP_BL1_PLAT_SETUP);
	otp_hw_cfg1 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_1);
	wagner_USB3_clk_external = !!(otp_hw_cfg1 & USB3_CLK_EXTERNAL);
	wagner_TZC_enable = !!(otp_hw_cfg1 & SECUREBOOT_ENABLE);

	if (wagner_TZC_enable) {
		wagner_bootstep(WAGNER_STEP_BL1_TZC);
		wagner_tzc_bl1_init();
	}

	wagner_get_boot_select(&bootselect);
	wagner_log_bootselect(bootselect.boot_1st, bootselect.boot_2nd);
	VERBOSE("Boot Select (%d,%d)\n",
			bootselect.boot_1st, bootselect.boot_2nd);
}

/*
 * The following function checks if Firmware update is needed,
 * by checking if TOC in FIP image is valid or not.
 */
unsigned int bl1_plat_get_next_image_id(void)
{

	if ((bootselect.boot_1st == BOOT_BYPASS) &&
	    (bootselect.boot_2nd == RECOVERY_TBBR))
		return NS_BL1U_IMAGE_ID;
	else
		return BL2_IMAGE_ID;
}

#if TRUSTED_BOARD_BOOT
image_desc_t *bl1_plat_get_image_desc(unsigned int image_id)
{
	unsigned int index = 0;

	wagner_bootstep(WAGNER_STEP_BL1_GET_DESC);
	while (bl1_tbbr_image_descs[index].image_id != INVALID_IMAGE_ID) {
		if (bl1_tbbr_image_descs[index].image_id == image_id)
			return &bl1_tbbr_image_descs[index];
		index++;
	}

	return NULL;
}
#endif


/* Called from bl1_prepare_next_image(), the last platform step to BL2 */
void bl1_plat_set_ep_info(unsigned int image_id,
		entry_point_info_t *ep_info)
{
	wagner_log_ep_addr(WAGNER_STEP_BL1_NEXT_EP, ep_info->pc);
}

int bl1_plat_load_auth_image(unsigned int image_id, image_desc_t *image_desc)
{
	/*****************************************************************
	 * Parameter description
	 * image_id = BL2_IMAGE_ID or NS_BL1U_IMAGE_ID, tell you to load next image
	 * image_data->image_base = Image loading from flash to this address
	 * image_data->image_max_size : You should not load more than this size
	 * image_desc->ep_info.pc : Next BL runtime base address
	 *****************************************************************/

	image_info_t *image_data;
	int ret = -1;
	uint32_t otp_hw_cfg0, otp_hw_cfg1, fips_disable, current_bootmode;
	uintptr_t gpfw_base;

	image_data = &image_desc->image_info;

	// Clear BL2 or NS_BL1U memory before BL1 loading
	wagner_bootstep(WAGNER_STEP_BL1_CLEAN_BL2);
	zeromem((void *)image_data->image_base, BL2BL1U_CLEAN_SIZE);

	// 1st boot mode
	wagner_bootstep(WAGNER_STEP_BL1_BOOTMODE_1);
	if (wagner_TZC_enable)
		wagner_tzc_bl1_dev1_init(bootselect.boot_1st);

	switch (bootselect.boot_1st) {
	case BOOT_BYPASS:
	default:
		break;
	case BOOT_MSHC0_SD:
		VERBOSE("SD boot first\n");
		mshc0_cd_pad_pull();
		ret = wagner_sdhci_bl1(VPL_MSHC_0_MMR_BASE, image_id,
				image_data, MODE_NORMAL_MSHC, 4);
		break;
	case BOOT_USB30:
	case BOOT_USB20:
		ret = wagner_usb_boot(image_id, image_data,
					bootselect.boot_1st);
		break;
	}

	if (ret >= 0) {
		current_bootmode = bootselect.boot_1st;
		if (current_bootmode == BOOT_USB20) {
			//to distinguish BOOT_USB20 & BOOT_NOR_P0_1BIT for bl2
			current_bootmode = RECOVERY_USB20;
		}
	} else {
		// 2nd boot mode
		current_bootmode = bootselect.boot_2nd;
		wagner_bootstep(WAGNER_STEP_BL1_BOOTMODE_2);
		if (wagner_TZC_enable)
			wagner_tzc_bl1_dev2_init(bootselect.boot_2nd);

		switch (bootselect.boot_2nd) {
		case BOOT_NOR_P0_1BIT:
			VERBOSE("Boot NOR p0 d0 (1-bit)\n");
			ret = bl1_plat_spi_nor_read(image_id,
					image_data, 0, 1);
			break;
		case BOOT_NOR_P0_QUAD:
			VERBOSE("Boot NOR p0 d0 (quad)\n");
			ret = bl1_plat_spi_nor_read(image_id,
					image_data, 0, 4);
			break;
		case BOOT_NAND_P0_1BIT:
			VERBOSE("Boot NAND p0 d0 (1-bit)\n");
			ret = bl1_plat_spi_nand_read(image_id,
					image_data, 0, 1);
			break;
		case BOOT_NAND_P0_QUAD:
			VERBOSE("Boot NAND p0 d0 (quad)\n");
			ret = bl1_plat_spi_nand_read(image_id,
					image_data, 0, 4);
			break;
		case BOOT_NOR_P1_1BIT:
			VERBOSE("Boot NOR p1 d0 (1-bit)\n");
			ret = bl1_plat_spi_nor_read(image_id,
					image_data, 1, 1);
			break;
		case BOOT_NAND_P1_1BIT:
			VERBOSE("Boot NAND p1 d0 (1-bit)\n");
			ret = bl1_plat_spi_nand_read(image_id,
					image_data, 1, 1);
			break;
		case BOOT_MSHC1_MMC4:
			VERBOSE("MSHC 1 (4-bit eMMC mode)\n");
			ret = wagner_sdhci_bl1(VPL_MSHC_1_MMR_BASE, image_id,
					image_data, MODE_EMMC_BOOT, 4);
			break;
		case BOOT_MSHC0_MMC8:
			VERBOSE("MSHC 0 (8-bit eMMC mode)\n");
			ret = wagner_sdhci_bl1(VPL_MSHC_0_MMR_BASE, image_id,
					image_data, MODE_EMMC_BOOT, 8);
			break;
		case RECOVERY_TBBR:
			VERBOSE("TBBR Recovery (NOR p1 d0)\n");
			wagner_enable_q7_sram();
			ret = bl1_plat_spi_nor_read(image_id,
					image_data, 1, 1);
			break;
		case RECOVERY_USB30:
		case RECOVERY_USB20:
			ret = wagner_usb_boot(image_id, image_data,
						bootselect.boot_2nd);
			break;
		default:
			break;
		}
	}

	/*
	 * Mark these 2 lines to retain TZC settings for BL2 (USB must retain)
	 *
	 *if (wagner_TZC_enable)
	 *        wagner_tzc_bl1_dev_finish(bootselect.boot_2nd);
	 */

	if (ret < 0) {	// image load fail
		wagner_err(WAGNER_ERR_LOAD_BL2);
		//vpl_wdt_set_timeout(BOOT_ERR_RESET_TIME);
		return ret;
	}

	// Parsing EIP130 header
	//	  1. Image Type
	//	  2. SPI Info
	//	  3. SCRTU_FW_EXTERNAL Offset if exist
	//	  4. DDR_FW_EXTERNAL Offset if exist
	//	  5. BL2 Image Size
	//	  6. BL2 Offset
	wagner_bootstep(WAGNER_STEP_BL1_HEADER_INFO);
	eip130_headerInfo((SBIF_Header_t *)image_data->image_base);

	//Update next ep_info.args
	// arg0 = SPI Info
	// arg1 = DDR_FW_EXTERNAL Address if exist
	// arg2 = current bootmode
	// arg3 = overlaid_buffer address
	// arg4 = USB evt->lpos (only USB boot)
	image_desc->ep_info.args.arg2 = current_bootmode;
	image_desc->ep_info.args.arg0 = bl_header_info.spi_attr;
	if (bl_header_info.ddr_fw_offset)
		image_desc->ep_info.args.arg1 = image_data->image_base +
						bl_header_info.ddr_fw_offset;
	else
		image_desc->ep_info.args.arg1 = 0;

	image_desc->ep_info.args.arg3 = (uintptr_t)&overlaid_buffer;
	if (current_bootmode == BOOT_USB30 ||
		current_bootmode == RECOVERY_USB20 ||
		current_bootmode == RECOVERY_USB30)
		image_desc->ep_info.args.arg4 = overlaid_buffer.usb_buf.evt.lpos;

	//Read OTP again for safety
	otp_hw_cfg0 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0);
	otp_hw_cfg1 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_1);

	//Check Non-secure Boot
	if (!(otp_hw_cfg0 & SCRTU_EIP130_ENABLE) ||
		!(otp_hw_cfg1 & SECUREBOOT_ENABLE)) {
		if (image_desc->ep_info.pc !=
			image_data->image_base + bl_header_info.bl_offset)
			wagner_memcpy((void *)image_desc->ep_info.pc,
				(const void *)(image_data->image_base +
				bl_header_info.bl_offset),
				bl_header_info.bl_image_size);
		wagner_bootstep(WAGNER_STEP_BL1_NS_BOOT);
		vpl_wdt_ping();
		return 0;
	}

	//Load image success, start verify
	fips_disable = !(otp_hw_cfg1 & FIPS_ENABLE);

	if ((otp_hw_cfg0 & SCRTU_FW_EXTERNAL) == SCRTU_FW_EXTERNAL) {
		gpfw_base = image_data->image_base +
					bl_header_info.scrtu_fw_offset;
	} else
		gpfw_base = VPL_SCRTU_EIP130_GPFW_BASE;

	wagner_bootstep(WAGNER_STEP_BL1_EIP130INIT);
	ret = eip130_initfw(gpfw_base, fips_disable);
	if (ret == 0) {
		wagner_bootstep(WAGNER_STEP_BL1_EIP130VERIFY);
		ret = eip130_verifyImage(image_id,
				image_data->image_base,
				image_desc->ep_info.pc);
	} else {
		wagner_err(WAGNER_ERR_EIP130INIT);
		//vpl_wdt_set_timeout(BOOT_ERR_RESET_TIME);
		return ret;
	}

	if (ret == 0) {
		wagner_bootstep(WAGNER_STEP_BL1_VERIFY_OK);
		vpl_wdt_ping();
	} else {
		wagner_err(WAGNER_ERR_EIP130VERIFY);
		//vpl_wdt_set_timeout(BOOT_ERR_RESET_TIME);
	}

	return ret;
}

/*
 * Wagner implementation for bl1_plat_handle_post_image_load(). This function
 * populates the default arguments to BL2.
 */
int bl1_plat_handle_post_image_load(unsigned int image_id)
{
	wagner_bootstep(WAGNER_STEP_BL1_POST_LOAD);

	if (image_id != BL2_IMAGE_ID)
		return 0;

	return 0;
}

