/* SPDX-License-Identifier: GPL-2.0 */
/* include/dwc3-uboot.h
 *
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
 *
 * Designware SuperSpeed USB uboot init
 */

#ifndef __DWC3_UBOOT_H_
#define __DWC3_UBOOT_H_

#include <errno.h>
#include <linux/types.h>
#include <linux/usb/otg.h>
#include <linux/usb/phy.h>
#include <linux/usb/ch9.h>

struct dwc3_device {
	unsigned long base;
	u32 maximum_speed;
	u8 lpm_nyet_threshold;
	u8 hird_threshold;
	unsigned tx_fifo_resize:1;
	unsigned has_lpm_erratum:1;
	unsigned is_utmi_l1_suspend:1;
	unsigned disable_scramble_quirk:1;
	unsigned u2exit_lfps_quirk:1;
	unsigned u2ss_inp3_quirk:1;
	unsigned req_p1p2p3_quirk:1;
	unsigned del_p1p2p3_quirk:1;
	unsigned del_phy_power_chg_quirk:1;
	unsigned lfps_filter_quirk:1;
	unsigned rx_detect_poll_quirk:1;
	unsigned dis_u3_susphy_quirk:1;
	unsigned dis_u2_susphy_quirk:1;
	unsigned dis_del_phy_power_chg_quirk:1;
	unsigned dis_tx_ipgap_linecheck_quirk:1;
	unsigned dis_enblslpm_quirk:1;
	unsigned dis_u2_freeclk_exists_quirk:1;
	unsigned tx_de_emphasis_quirk:1;
	unsigned tx_de_emphasis:2;
};

int dwc3_uboot_init(struct dwc3_device *dev);
void dwc3_uboot_exit(void);
void dwc3_uboot_handle_interrupt(void);

struct phy;
#endif /* __DWC3_UBOOT_H_ */
