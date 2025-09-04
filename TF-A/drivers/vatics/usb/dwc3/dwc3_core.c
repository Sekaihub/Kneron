// SPDX-License-Identifier: GPL-2.0
/**
 * core.c - DesignWare USB3 DRD Controller Core file
 *
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com
 *
 * Authors: Felipe Balbi <balbi@ti.com>,
 *	    Sebastian Andrzej Siewior <bigeasy@linutronix.de>
 *
 * Taken from Linux Kernel v3.19-rc1 (drivers/usb/dwc3/core.c) and ported
 * to uboot.
 *
 * commit cd72f890d2 : usb: dwc3: core: enable phy suspend quirk on non-FPGA
 */

#include <assert.h>
#include <errno.h>
#include <string.h>

#include <drivers/delay_timer.h>
#include <common/debug.h>

#include <drivers/vatics/usb/dwc3-uboot.h>
#include <linux/err.h>
#include <linux/types.h>

#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>

#include <drivers/vatics/usb/dwc3/core.h>
#include <drivers/vatics/usb/dwc3/gadget.h>
#include <drivers/vatics/usb/dwc3/io.h>

#include <wagner_buf.h>
#include <wagner_log.h>

#define DWC3_ALIGN_MASK		(16 - 1)

/* -------------------------------------------------------------------------- */

static void dwc3_set_mode(struct dwc3 *dwc, u32 mode)
{
	u32 reg;

	reg = dwc3_readl(dwc->regs, DWC3_GCTL);
	reg &= ~(DWC3_GCTL_PRTCAPDIR(DWC3_GCTL_PRTCAP_OTG));
	reg |= DWC3_GCTL_PRTCAPDIR(mode);
	dwc3_writel(dwc->regs, DWC3_GCTL, reg);
}

/**
 * dwc3_core_soft_reset - Issues core soft reset and PHY reset
 * @dwc: pointer to our context structure
 */
static __maybe_unused int dwc3_core_soft_reset(struct dwc3 *dwc)
{
	u32		reg;

	/* Before Resetting PHY, put Core in Reset */
	reg = dwc3_readl(dwc->regs, DWC3_GCTL);
	reg |= DWC3_GCTL_CORESOFTRESET;
	dwc3_writel(dwc->regs, DWC3_GCTL, reg);

	/* Assert USB3 PHY reset */
	reg = dwc3_readl(dwc->regs, DWC3_GUSB3PIPECTL(0));
	reg |= DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel(dwc->regs, DWC3_GUSB3PIPECTL(0), reg);

	/* Assert USB2 PHY reset */
	reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
	reg |= DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);

	mdelay(100);

	/* Clear USB3 PHY reset */
	reg = dwc3_readl(dwc->regs, DWC3_GUSB3PIPECTL(0));
	reg &= ~DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel(dwc->regs, DWC3_GUSB3PIPECTL(0), reg);

	/* Clear USB2 PHY reset */
	reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
	reg &= ~DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);

	mdelay(100);

	/* After PHYs are stable we can take Core out of reset state */
	reg = dwc3_readl(dwc->regs, DWC3_GCTL);
	reg &= ~DWC3_GCTL_CORESOFTRESET;
	dwc3_writel(dwc->regs, DWC3_GCTL, reg);

	return 0;
}

/**
 * dwc3_free_one_event_buffer - Frees one event buffer
 * @dwc: Pointer to our controller context structure
 * @evt: Pointer to event buffer to be freed
 */
static void dwc3_free_one_event_buffer(struct dwc3 *dwc,
		struct dwc3_event_buffer *evt)
{
	/* dma_free_coherent(evt->buf); */
	evt->buf = NULL;
}

/**
 * dwc3_alloc_one_event_buffer - Allocates one event buffer structure
 * @dwc: Pointer to our controller context structure
 * @length: size of the event buffer
 *
 * Returns a pointer to the allocated event buffer structure on success
 * otherwise ERR_PTR(errno).
 */
static __maybe_unused struct dwc3_event_buffer *dwc3_alloc_one_event_buffer(
					struct dwc3 *dwc, unsigned int length)
{
	struct dwc3_event_buffer	*evt;

#ifdef IMAGE_BL2
	evt = &overlaid_bufferp->usb_buf.evt;

	inv_dcache_range((uintptr_t)evt, sizeof(*evt));
	inv_dcache_range((uintptr_t)evt->buf, evt->length);
	evt->dwc	= dwc;
	evt->length	= length;
#else
	evt = &overlaid_buffer.usb_buf.evt;
	memset(evt, 0, sizeof(*evt));

	evt->dwc	= dwc;
	evt->length	= length;
	evt->buf = overlaid_buffer.usb_buf.evt_buf;
	memset(evt->buf, 0, length);
	evt->dma = (unsigned long) overlaid_buffer.usb_buf.evt_buf;
#endif
	dwc3_flush_cache((uintptr_t)evt->buf, evt->length);

	return evt;
}

/**
 * dwc3_free_event_buffers - frees all allocated event buffers
 * @dwc: Pointer to our controller context structure
 */
static void dwc3_free_event_buffers(struct dwc3 *dwc)
{
	struct dwc3_event_buffer	*evt;

	evt = dwc->ev_buffs[0];
	if (evt)
		dwc3_free_one_event_buffer(dwc, evt);
}

/**
 * dwc3_alloc_event_buffers - Allocates @num event buffers of size @length
 * @dwc: pointer to our controller context structure
 * @length: size of event buffer
 *
 * Returns 0 on success otherwise negative errno. In the error case, dwc
 * may contain some buffers allocated but not all which were requested.
 */
static int dwc3_alloc_event_buffers(struct dwc3 *dwc, unsigned length)
{
#ifdef IMAGE_BL2
	struct usb_related *usb_buf = &overlaid_bufferp->usb_buf;

	dwc->ev_buffs = (struct dwc3_event_buffer **) usb_buf->dwc_ev_buffs;
#else
	struct usb_related *usb_buf = &overlaid_buffer.usb_buf;

	dwc->ev_buffs = (struct dwc3_event_buffer **) usb_buf->dwc_ev_buffs;
	memset(dwc->ev_buffs, 0, sizeof(*dwc->ev_buffs));
#endif
	struct dwc3_event_buffer	*evt;

	evt = dwc3_alloc_one_event_buffer(dwc, length);

	dwc->ev_buffs[0] = evt;
	return 0;
}

/**
 * dwc3_event_buffers_setup - setup our allocated event buffers
 * @dwc: pointer to our controller context structure
 *
 * Returns 0 on success otherwise negative errno.
 */
static __maybe_unused int dwc3_event_buffers_setup(struct dwc3 *dwc)
{
	struct dwc3_event_buffer	*evt;
	int				n = 0;

	evt = dwc->ev_buffs[n];
	DBGUSB("Event buf %p dma %08llx length %d\n",
			evt->buf, (unsigned long long) evt->dma,
			evt->length);

	evt->lpos = 0;

	dwc3_writel(dwc->regs, DWC3_GEVNTADRLO(n), lower_32_bits(evt->dma));
	dwc3_writel(dwc->regs, DWC3_GEVNTADRHI(n), upper_32_bits(evt->dma));
	dwc3_writel(dwc->regs, DWC3_GEVNTSIZ(n),
				DWC3_GEVNTSIZ_SIZE(evt->length));

	dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(n), 0);

	return 0;
}

static void dwc3_event_buffers_cleanup(struct dwc3 *dwc)
{
	struct dwc3_event_buffer	*evt;
	int				n = 0;

	evt = dwc->ev_buffs[n];

	evt->lpos = 0;

	dwc3_writel(dwc->regs, DWC3_GEVNTADRLO(n), 0);
	dwc3_writel(dwc->regs, DWC3_GEVNTADRHI(n), 0);
	dwc3_writel(dwc->regs, DWC3_GEVNTSIZ(n), DWC3_GEVNTSIZ_INTMASK
			| DWC3_GEVNTSIZ_SIZE(0));
	dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(n), 0);
}

static void dwc3_core_num_eps(struct dwc3 *dwc)
{
	/*
	struct dwc3_hwparams	*parms = &dwc->hwparams;

	dwc->num_in_eps = DWC3_NUM_IN_EPS(parms);
	dwc->num_out_eps = DWC3_NUM_EPS(parms) - dwc->num_in_eps;
	*/

	dwc->num_in_eps = FB_NUM_IN_EPS;
	dwc->num_out_eps = FB_NUM_OUT_EPS;

	DBGUSB("found %d IN and %d OUT endpoints\n",
			dwc->num_in_eps, dwc->num_out_eps);
}

static void dwc3_cache_hwparams(struct dwc3 *dwc)
{
	struct dwc3_hwparams	*parms = &dwc->hwparams;

	parms->hwparams0 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS0);
	//parms->hwparams1 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS1);
	//parms->hwparams2 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS2);
	parms->hwparams3 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS3);
	//parms->hwparams4 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS4);
	//parms->hwparams5 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS5);
	parms->hwparams6 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS6);
	//parms->hwparams7 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS7);
	//parms->hwparams8 = dwc3_readl(dwc->regs, DWC3_GHWPARAMS8);
}

static void dwc3_hsphy_mode_setup(struct dwc3 *dwc)
{
	u32 reg;

	/* Set dwc3 usb2 phy config */
	reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));

	//Wagner use USBPHY_INTERFACE_MODE_UTMI (8 bit)
	reg &= ~(DWC3_GUSB2PHYCFG_PHYIF_MASK |
		DWC3_GUSB2PHYCFG_USBTRDTIM_MASK);
	reg |= DWC3_GUSB2PHYCFG_PHYIF(UTMI_PHYIF_8_BIT) |
		DWC3_GUSB2PHYCFG_USBTRDTIM(USBTRDTIM_UTMI_8_BIT);

	dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);
}

/**
 * dwc3_phy_setup - Configure USB PHY Interface of DWC3 Core
 * @dwc: Pointer to our controller context structure
 */
static __maybe_unused void dwc3_phy_setup(struct dwc3 *dwc)
{
	u32 reg;

	reg = dwc3_readl(dwc->regs, DWC3_GUSB3PIPECTL(0));

	/*
	 * Above 1.94a, it is recommended to set DWC3_GUSB3PIPECTL_SUSPHY
	 * to '0' during coreConsultant configuration. So default value
	 * will be '0' when the core is reset. Application needs to set it
	 * to '1' after the core initialization is completed.
	 */
//	if (dwc->revision > DWC3_REVISION_194A)	//WAGNER DWC3 5533330b
		reg |= DWC3_GUSB3PIPECTL_SUSPHY;

#ifdef U2SS_INP3
	if (dwc->u2ss_inp3_quirk)
		reg |= DWC3_GUSB3PIPECTL_U2SSINP3OK;
#endif

	if (dwc->req_p1p2p3_quirk)
		reg |= DWC3_GUSB3PIPECTL_REQP1P2P3;

#ifdef DEL_P1P2P3
	if (dwc->del_p1p2p3_quirk)
		reg |= DWC3_GUSB3PIPECTL_DEP1P2P3_EN;
#endif

#ifdef DEL_PHY_POWER_CHG
	if (dwc->del_phy_power_chg_quirk)
		reg |= DWC3_GUSB3PIPECTL_DEPOCHANGE;
#endif

#ifdef LFPS_FILTER
	if (dwc->lfps_filter_quirk)
		reg |= DWC3_GUSB3PIPECTL_LFPSFILT;
#endif

#ifdef RX_DETECT_POLL
	if (dwc->rx_detect_poll_quirk)
		reg |= DWC3_GUSB3PIPECTL_RX_DETOPOLL;
#endif

#ifdef TX_DE_EMPHASIS_QUIRK
	if (dwc->tx_de_emphasis_quirk)
		reg |= DWC3_GUSB3PIPECTL_TX_DEEPH(dwc->tx_de_emphasis);
#endif

	if (dwc->dis_u3_susphy_quirk)
		reg &= ~DWC3_GUSB3PIPECTL_SUSPHY;

	if (dwc->dis_del_phy_power_chg_quirk)
		reg &= ~DWC3_GUSB3PIPECTL_DEPOCHANGE;

	dwc3_writel(dwc->regs, DWC3_GUSB3PIPECTL(0), reg);

	dwc3_hsphy_mode_setup(dwc);

	mdelay(100);

	reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));

	/*
	 * Above 1.94a, it is recommended to set DWC3_GUSB2PHYCFG_SUSPHY to
	 * '0' during coreConsultant configuration. So default value will
	 * be '0' when the core is reset. Application needs to set it to
	 * '1' after the core initialization is completed.
	 */
	//if (dwc->revision > DWC3_REVISION_194A) //WAGNER DWC3 5533330b
		reg |= DWC3_GUSB2PHYCFG_SUSPHY;

	if (dwc->dis_u2_susphy_quirk)
		reg &= ~DWC3_GUSB2PHYCFG_SUSPHY;

#ifdef DIS_ENBLSLPM
	if (dwc->dis_enblslpm_quirk)
		reg &= ~DWC3_GUSB2PHYCFG_ENBLSLPM;
#endif

#ifdef DIS_U2_FREECLK_EXISTS
	if (dwc->dis_u2_freeclk_exists_quirk)
		reg &= ~DWC3_GUSB2PHYCFG_U2_FREECLK_EXISTS;
#endif

	dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);

	mdelay(100);
}

/**
 * dwc3_core_init - Low-level initialization of DWC3 Core
 * @dwc: Pointer to our controller context structure
 *
 * Returns 0 on success otherwise negative errno.
 */
static int __maybe_unused dwc3_core_init(struct dwc3 *dwc)
{
	__maybe_unused unsigned long		timeout;
	/* u32			hwparams4 = dwc->hwparams.hwparams4; */
	u32			reg;
	__maybe_unused int	ret;

	reg = dwc3_readl(dwc->regs, DWC3_GSNPSID);
	/* This should read as U3 followed by revision number */
	/*
	if ((reg & DWC3_GSNPSID_MASK) != 0x55330000) {
		ERROR("this is not a DesignWare USB3 DRD Core\n");
		ret = -ENODEV;
		goto err0;
	}
	*/
	dwc->revision = reg;

	/* Handle USB2.0-only core configuration */
	if (DWC3_GHWPARAMS3_SSPHY_IFC(dwc->hwparams.hwparams3) ==
			DWC3_GHWPARAMS3_SSPHY_IFC_DIS) {
		if (dwc->maximum_speed == USB_SPEED_SUPER)
			dwc->maximum_speed = USB_SPEED_HIGH;
	}

	/* issue device SoftReset too */
	timeout = 5000;

#ifndef IMAGE_BL2
	dwc3_writel(dwc->regs, DWC3_DCTL, DWC3_DCTL_CSFTRST);
	while (timeout--) {
		reg = dwc3_readl(dwc->regs, DWC3_DCTL);
		if (!(reg & DWC3_DCTL_CSFTRST))
			break;
	};

	if (!timeout) {
		ERROR("Reset Timed Out\n");
		ret = -ETIMEDOUT;
		goto err0;
	}

	dwc3_phy_setup(dwc);

	ret = dwc3_core_soft_reset(dwc);
	if (ret)
		goto err0;
#endif

	reg = dwc3_readl(dwc->regs, DWC3_GCTL);
	reg &= ~DWC3_GCTL_SCALEDOWN_MASK;

	/* check if current dwc3 is on simulation board */
	if (dwc->hwparams.hwparams6 & DWC3_GHWPARAMS6_EN_FPGA) {
		DBGUSB("it is on FPGA board\n");
		dwc->is_fpga = true;
	}

#ifdef DISABLE_SCRAMBLE_QUIRK
	if(dwc->disable_scramble_quirk && !dwc->is_fpga)
		WARN("disable_scramble cannot be used on non-FPGA builds\n");

	if (dwc->disable_scramble_quirk && dwc->is_fpga)
		reg |= DWC3_GCTL_DISSCRAMBLE;
	else
		reg &= ~DWC3_GCTL_DISSCRAMBLE;
#else
	reg &= ~DWC3_GCTL_DISSCRAMBLE;
#endif

#ifdef U2EXIT_LFPS
	if (dwc->u2exit_lfps_quirk)
		reg |= DWC3_GCTL_U2EXIT_LFPS;
#endif

	/*
	 * WORKAROUND: DWC3 revisions <1.90a have a bug
	 * where the device can fail to connect at SuperSpeed
	 * and falls back to high-speed mode which causes
	 * the device to enter a Connect/Disconnect loop
	 */
#if 0	//WAGNER DWC3 5533330b
	if (dwc->revision < DWC3_REVISION_190A)
		reg |= DWC3_GCTL_U2RSTECN;
#endif

	dwc3_core_num_eps(dwc);

#ifndef IMAGE_BL2
	dwc3_writel(dwc->regs, DWC3_GCTL, reg);
#endif

	return 0;

#ifndef IMAGE_BL2
err0:
	wagner_err(WAGNER_ERR_USB_COREINIT);
	return ret;
#endif
}

static void dwc3_core_exit(struct dwc3 *dwc)
{
}

static int __maybe_unused dwc3_core_init_mode(struct dwc3 *dwc)
{
	int ret;

	// Wagner always use mode :USB_DR_MODE_PERIPHERAL
	dwc3_set_mode(dwc, DWC3_GCTL_PRTCAP_DEVICE);
	ret = dwc3_gadget_init(dwc);
	if (ret) {
		ERROR("failed to initialize gadget\n");
		return ret;
	}

	return 0;
}

static void dwc3_gadget_run(struct dwc3 *dwc)
{
	dwc3_writel(dwc->regs, DWC3_DCTL, DWC3_DCTL_RUN_STOP);
	mdelay(100);
}

static void dwc3_core_exit_mode(struct dwc3 *dwc)
{

	// Wagner always use mode :USB_DR_MODE_PERIPHERAL
	dwc3_gadget_exit(dwc);

	/*
	 * switch back to peripheral mode
	 * This enables the phy to enter idle and then, if enabled, suspend.
	 */
	dwc3_set_mode(dwc, DWC3_GCTL_PRTCAP_DEVICE);
	dwc3_gadget_run(dwc);
}

/**
 * dwc3_uboot_init - dwc3 core uboot initialization code
 * @dwc3_dev: struct dwc3_device containing initialization data
 *
 * Entry point for dwc3 driver (equivalent to dwc3_probe in linux
 * kernel driver). Pointer to dwc3_device should be passed containing
 * base address and other initialization data. Returns '0' on success and
 * a negative value on failure.
 *
 * Generally called from board_usb_init() implemented in board file.
 */
int dwc3_uboot_init(struct dwc3_device *dwc3_dev)
{
	struct dwc3		*dwc;
	u8			lpm_nyet_threshold;
	u8			tx_de_emphasis;
	u8			hird_threshold;

	int			ret;

	void			*mem;

#ifdef IMAGE_BL2
	mem = &overlaid_bufferp->usb_buf.dwc_mem;
#else
	mem = &overlaid_buffer.usb_buf.dwc_mem;
	memset(mem, 0, sizeof(struct dwc3));
#endif

	dwc = PTR_ALIGN(mem, DWC3_ALIGN_MASK + 1);
	dwc->mem = mem;

	dwc->regs = (void *)(uintptr_t)(dwc3_dev->base +
					DWC3_GLOBALS_REGS_START);

	/* default to highest possible threshold */
	lpm_nyet_threshold = 0xff;

	/* default to -3.5dB de-emphasis */
	tx_de_emphasis = 1;

	/*
	 * default to assert utmi_sleep_n and use maximum allowed HIRD
	 * threshold value of 0b1100
	 */
	hird_threshold = 12;

	dwc->maximum_speed = dwc3_dev->maximum_speed;
#ifdef HAS_LPM_ERRATUM
	dwc->has_lpm_erratum = dwc3_dev->has_lpm_erratum;
#endif
	if (dwc3_dev->lpm_nyet_threshold)
		lpm_nyet_threshold = dwc3_dev->lpm_nyet_threshold;
#ifdef IS_UTMI_L1_SUSPEND
	dwc->is_utmi_l1_suspend = dwc3_dev->is_utmi_l1_suspend;
#endif

#if 0
	if (dwc3_dev->hird_threshold)
		hird_threshold = dwc3_dev->hird_threshold;
#endif

#ifdef NEEDS_FIFO_RESIZE
	dwc->needs_fifo_resize = dwc3_dev->tx_fifo_resize;
#endif
	//dwc->dr_mode = dwc3_dev->dr_mode;

	dwc->disable_scramble_quirk = dwc3_dev->disable_scramble_quirk;
#ifdef U2EXIT_LFPS
	dwc->u2exit_lfps_quirk = dwc3_dev->u2exit_lfps_quirk;
#endif
#ifdef U2SS_INP3
	dwc->u2ss_inp3_quirk = dwc3_dev->u2ss_inp3_quirk;
#endif
	dwc->req_p1p2p3_quirk = dwc3_dev->req_p1p2p3_quirk;
#ifdef DEL_P1P2P3
	dwc->del_p1p2p3_quirk = dwc3_dev->del_p1p2p3_quirk;
#endif
#ifdef DEL_PHY_POWER_CHG
	dwc->del_phy_power_chg_quirk = dwc3_dev->del_phy_power_chg_quirk;
#endif
#ifdef LFPS_FILTER
	dwc->lfps_filter_quirk = dwc3_dev->lfps_filter_quirk;
#endif
#ifdef RX_DETECT_POLL
	dwc->rx_detect_poll_quirk = dwc3_dev->rx_detect_poll_quirk;
#endif
	dwc->dis_u3_susphy_quirk = dwc3_dev->dis_u3_susphy_quirk;
	dwc->dis_u2_susphy_quirk = dwc3_dev->dis_u2_susphy_quirk;
	dwc->dis_del_phy_power_chg_quirk = dwc3_dev->dis_del_phy_power_chg_quirk;
#if 0
	//Is dis_tx_ipgap_linecheck_quirk useless ?
	dwc->dis_tx_ipgap_linecheck_quirk = dwc3_dev->dis_tx_ipgap_linecheck_quirk;
#endif
#ifdef DIS_ENBLSLPM
	dwc->dis_enblslpm_quirk = dwc3_dev->dis_enblslpm_quirk;
#endif
#ifdef DIS_U2_FREECLK_EXISTS
	dwc->dis_u2_freeclk_exists_quirk = dwc3_dev->dis_u2_freeclk_exists_quirk;
#endif

#ifdef TX_DE_EMPHASIS_QUIRK
	dwc->tx_de_emphasis_quirk = dwc3_dev->tx_de_emphasis_quirk;
#endif
#ifdef TX_DE_EMPHASIS
	if (dwc3_dev->tx_de_emphasis)
		tx_de_emphasis = dwc3_dev->tx_de_emphasis;
#endif

	dwc->lpm_nyet_threshold = lpm_nyet_threshold;
	dwc->tx_de_emphasis = tx_de_emphasis;

#ifdef IS_UTMI_L1_SUSPEND
	dwc->hird_threshold = hird_threshold
		| (dwc->is_utmi_l1_suspend << 4);
#else
	dwc->hird_threshold = hird_threshold;
#endif

	/*dwc->index = dwc3_dev->index;*/

	dwc3_cache_hwparams(dwc);

	ret = dwc3_alloc_event_buffers(dwc, DWC3_EVENT_BUFFERS_SIZE);

	/* TFA: always use peripheral mode */
	//dwc->dr_mode = USB_DR_MODE_PERIPHERAL;

	ret = dwc3_core_init(dwc);
	if (ret) {
		WARN("failed to initialize core\n");
		goto err0;
	}

#ifndef IMAGE_BL2
	ret = dwc3_event_buffers_setup(dwc);

	ret = dwc3_core_init_mode(dwc);
	if (ret)
		goto err2;

	return 0;
#else
	ret = dwc3_gadget_init(dwc);
	if (ret) {
		ERROR("failed to initialize gadget\n");
		goto err2;
	}
	usb_gadget_set_state(&dwc->gadget, USB_STATE_CONFIGURED);
	//dwc3_ep0_stall_and_restart
	//dwc3_gadget_ep0_set_halt(&dwc->eps[0]->endpoint, 0);
	//dwc->eps[1]->flags = DWC3_EP_ENABLED;
	//dwc->eps[0]->flags = DWC3_EP_ENABLED;
	//dwc3_ep0_out_start(&dwc);
	return 0;
#endif

err2:
	dwc3_event_buffers_cleanup(dwc);

	dwc3_core_exit(dwc);

err0:
	dwc3_free_event_buffers(dwc);

	return ret;
}

/**
 * dwc3_uboot_exit - dwc3 core uboot cleanup code
 * @index: index of this controller
 *
 * Performs cleanup of memory allocated in dwc3_uboot_init and other misc
 * cleanups (equivalent to dwc3_remove in linux). index of _this_ controller
 * should be passed and should match with the index passed in
 * dwc3_device during init.
 *
 * Generally called from board file.
 */
void dwc3_uboot_exit(void)
{
	struct dwc3 *dwc;

#ifdef IMAGE_BL2
	dwc = &overlaid_bufferp->usb_buf.dwc_mem;
#else
	dwc = &overlaid_buffer.usb_buf.dwc_mem;
#endif
	dwc3_core_exit_mode(dwc);
	dwc3_event_buffers_cleanup(dwc);
	dwc3_free_event_buffers(dwc);
	dwc3_core_exit(dwc);
	/* kfree(dwc->mem); */
}

/**
 * dwc3_uboot_handle_interrupt - handle dwc3 core interrupt
 * @index: index of this controller
 *
 * Invokes dwc3 gadget interrupts.
 *
 * Generally called from board file.
 */
void dwc3_uboot_handle_interrupt(void)
{
	struct dwc3 *dwc;
#ifdef IMAGE_BL2
	dwc = &overlaid_bufferp->usb_buf.dwc_mem;
#else
	dwc = &overlaid_buffer.usb_buf.dwc_mem;
#endif
	dwc3_gadget_uboot_handle_interrupt(dwc);
}
