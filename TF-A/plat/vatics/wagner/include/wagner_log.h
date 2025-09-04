/*
 *   Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 *   SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __WAGNER_LOG_H
#define __WAGNER_LOG_H

/**
 *   Wagner Error Codes. Error values printed to console and memory.
 **/
enum {
	WAGNER_SUCCESS,			/** Reserve 0. */

	WAGNER_ERR_LOAD_BL2,		/** Error: BL2 image load fail. */
	WAGNER_ERR_ROLLBACK,		/** Error: Rollback id verify fail. */
	WAGNER_ERR_EIP130INIT,		/** Error: eip130_initfw() fail. */
	WAGNER_ERR_EIP130VERIFY,	/** Error: eip130_verifyImage() fail. */
	WAGNER_ERR_USB_COREINIT,	/** Error: dwc3_core_init() fail */
	WAGNER_ERR_USB_FBCMD,		/** Error: fastboot_handle_command() */
	WAGNER_ERR_AUTHMOD_VERIFY,	/** Error: FWU: auth_mod_verify_img() */

	WAGNER_ERR_MAX = 0xFFFF		/** MAX error codes. */
};


/**
 *   Wagner Boot Steps. Step values printed to console and memory.
 **/
enum {
	WAGNER_STEP_BL1_EARLY_SETUP,	/** bl1_early_platform_setup() */
	WAGNER_STEP_BL1_WDT_START,	/** Start boot watchdog */
	WAGNER_STEP_BL1_MMU_START,	/** If init MMU */
	WAGNER_STEP_BL1_PLAT_SETUP,	/** bl1_platform_setup() */
	WAGNER_STEP_BL1_TZC,		/** wagner_tzc_bl1_init() */
	WAGNER_STEP_BL1_CLEAN_BL2,	/** clean bl2 & ns_bl1u memory */
	WAGNER_STEP_BL1_BOOTMODE_1,	/** 1st boot mode */
	WAGNER_STEP_BL1_BOOTMODE_2,	/** 2nd boot mode */
	WAGNER_STEP_BL1_HEADER_INFO,	/** eip130_headerInfo() */
	WAGNER_STEP_BL1_NS_BOOT,	/** Non-Secure Boot */
	WAGNER_STEP_BL1_EIP130INIT,	/** eip130_initfw() */
	WAGNER_STEP_BL1_EIP130NOPUBKEY,	/** No PUBKEY in OTP */
	WAGNER_STEP_BL1_EIP130NOPUBHASH,/** No PUBHASH in OTP */
	WAGNER_STEP_BL1_EIP130VERIFY,	/** eip130_verifyImage() */
	WAGNER_STEP_BL1_VERIFY_OK,	/** BL2 image verify pass */
	WAGNER_STEP_BL1_POST_LOAD,	/** bl1_plat_handle_post_image_load() */
	WAGNER_STEP_BL1_GET_DESC,	/** bl1_plat_get_image_desc() */
	WAGNER_STEP_BL1_NEXT_EP,	/** bl1_plat_set_ep_info() */
	WAGNER_STEP_USB_SUSPEND,	/** composite_suspend() */

	WAGNER_STEP_MAX = 255		/** Max Number of steps. */
};

void wagner_log_init(void);
void wagner_err(uint16_t err_no);
void wagner_bootstep(uint8_t step_no);
void wagner_log_ep_addr(uint8_t step_no, uintptr_t addr);
void wagner_log_bootselect(uint8_t sel1, uint8_t sel2);

#endif /* __WAGNER_LOG_H */
