/*
 * Copyright (c) 2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <errno.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <bl31/interrupt_mgmt.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <common/interrupt_props.h>
#include <drivers/arm/cci.h>
#include <drivers/arm/gicv3.h>
#include <drivers/ti/uart/uart_16550.h>
#include <drivers/delay_timer.h>
#include <drivers/generic_delay_timer.h>
#include <drivers/console.h>
#include <lib/mmio.h>
#include <plat/common/platform.h>
#include <plat/arm/common/plat_arm.h>
#include <safezone.h>

#include "wagner_private.h"

static entry_point_info_t bl32_ep_info;
static entry_point_info_t bl33_ep_info;
static console_t console;

/* OTP Info */
bool	wagner_PMU_disable;

/*******************************************************************************
 * Return a pointer to the 'entry_point_info' structure of the next image for
 * the security state specified. BL33 corresponds to the non-secure image type
 * while BL32 corresponds to the secure image type. A NULL pointer is returned
 * if the image does not exist.
 ******************************************************************************/
entry_point_info_t *bl31_plat_get_next_image_ep_info(uint32_t type)
{
	entry_point_info_t *next_image_info;

	assert(sec_state_is_valid(type));
	next_image_info = (type == NON_SECURE) ? &bl33_ep_info : &bl32_ep_info;

	/* None of the images on this platform can have 0x0 as the entrypoint */
	if (next_image_info->pc)
		return next_image_info;
	return NULL;
}

void bl31_early_platform_setup2(u_register_t arg0, u_register_t arg1,
				u_register_t arg2, u_register_t arg3)
{
	void *from_bl2;

	from_bl2 = (void *) arg0;

	generic_delay_timer_init();
	/* Initialize the console to provide early debug support */
	console_16550_register(UART_0, UART_CLOCK,
				115200, &console);
	console_set_scope(&console, CONSOLE_FLAG_BOOT | CONSOLE_FLAG_RUNTIME);

	/*
	 * In debug builds, a special value is passed in 'arg3' to verify
	 * platform parameters from BL2 to BL31. Not used in release builds.
	 */
	assert(arg3 == WAGNER_BL31_PLAT_PARAM_VAL);

	/*
	 * Check params passed from BL2 should not be NULL,
	 */
	bl_params_t *params_from_bl2 = (bl_params_t *)from_bl2;

	assert(params_from_bl2 != NULL);
	assert(params_from_bl2->h.type == PARAM_BL_PARAMS);
	assert(params_from_bl2->h.version >= VERSION_2);

	bl_params_node_t *bl_params = params_from_bl2->head;

	/*
	 * Copy BL33 and BL32 (if present), entry point information.
	 * They are stored in Secure RAM, in BL2's address space.
	 */
	while (bl_params) {
		if (bl_params->image_id == BL32_IMAGE_ID)
			bl32_ep_info = *bl_params->ep_info;

		if (bl_params->image_id == BL33_IMAGE_ID)
			bl33_ep_info = *bl_params->ep_info;

		bl_params = bl_params->next_params_info;
	}

	if (bl33_ep_info.pc == 0)
		panic();
}

void bl31_plat_arch_setup(void)
{
	wagner_init_mmu_el3(BL31_BASE,
			    BL31_LIMIT - BL31_BASE,
			    BL_CODE_BASE,
			    BL_CODE_END);
}

void bl31_platform_setup(void)
{
	uint32_t otp_hw_cfg0, chip_id_info, production_mode;
#if !WAGNER_FPGA
	uintptr_t gpfw_base;
	uint32_t otp_hw_cfg1, fips_disable;
#endif
	/* Initialize the GIC driver, cpu and distributor interfaces */
	plat_arm_gic_driver_init();
	plat_arm_gic_init();

	otp_hw_cfg0 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0);

	/* Get PMU status */
	chip_id_info = mmio_read_32(SYSC_S_BASE + SYSC_CHIP_ID_INFO);
	wagner_PMU_disable = !!(chip_id_info & PMU_BOOT_DISABLE);
	production_mode = otp_hw_cfg0 & PRODUCTION_MODE;
	if (production_mode)
		wagner_PMU_disable = 1;

#if !WAGNER_FPGA
	/*init eip130 gpfw*/
	otp_hw_cfg1 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_1);
	fips_disable = !(otp_hw_cfg1 & FIPS_ENABLE);
	gpfw_base = VPL_SCRTU_EIP130_GPFW_BASE;

	/* we have eip130, but it's not initialized */
	if ((otp_hw_cfg0 & SCRTU_EIP130_ENABLE) &&
				!(otp_hw_cfg1 & SECUREBOOT_ENABLE))
		eip130_initfw(gpfw_base, fips_disable);
#endif
}

void bl31_plat_runtime_setup(void)
{
}

