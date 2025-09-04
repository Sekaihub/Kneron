/*
 * Copyright (c) 2017-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <lib/mmio.h>
#include <lib/xlat_tables/xlat_tables_v2.h>
#include <plat/common/platform.h>

#include "../wagner_def.h"
#include "../wagner_private.h"
#include "sysctrl.h"

#define MAP_DDR		MAP_REGION_FLAT(DDR_BASE,			\
					DDR_SIZE,			\
					MT_MEMORY | MT_RW | MT_NS)

#define MAP_DDR_SEC	MAP_REGION_FLAT(DDR_SEC_BASE,			\
					DDR_SEC_SIZE,			\
					MT_MEMORY | MT_RW | MT_SECURE)

#define MAP_DEVICE	MAP_REGION_FLAT(DEVICE_BASE,			\
					DEVICE_SIZE,			\
					MT_DEVICE | MT_RW | MT_SECURE)

#define MAP_CA55_BUS	MAP_REGION_FLAT(CA55_BUS_BASE,			\
					CA55_BUS_SIZE,			\
					MT_DEVICE | MT_RW | MT_SECURE)

#define MAP_BL1_RW	MAP_REGION_FLAT(BL1_RW_BASE,			\
					BL1_RW_LIMIT - BL1_RW_BASE,	\
					MT_MEMORY | MT_RW | MT_SECURE)

#define MAP_BL2_XLAT	MAP_REGION_FLAT(BL2_XLAT_BASE,			\
					BL2_XLAT_LIMIT - BL2_XLAT_BASE,	\
					MT_MEMORY | MT_RW | MT_SECURE)

/*
 * Table of regions for different BL stages to map using the MMU.
 * This doesn't include Trusted RAM as the 'mem_layout' argument passed to
 * wagner_init_mmu_elx() will give the available subset of that,
 */
#ifdef IMAGE_BL1
static const mmap_region_t wagner_mmap[] = {
	MAP_DEVICE,
	{0}
};
#endif

#ifdef IMAGE_BL2
static const mmap_region_t wagner_mmap[] = {
	MAP_DDR,
	MAP_DDR_SEC,
	MAP_DEVICE,
	MAP_BL2_XLAT,
	{0}
};
#endif

#ifdef IMAGE_BL31
static const mmap_region_t wagner_mmap[] = {
	MAP_DEVICE,
	MAP_CA55_BUS,
	{0}
};
#endif

#ifdef IMAGE_BL32
static const mmap_region_t wagner_mmap[] = {
	MAP_DEVICE,
	MAP_DDR,
	{0}
};
#endif

/*
 * Macro generating the code for the function setting up the pagetables as per
 * the platform memory map & initialize the mmu, for the given exception level
 */
#define WAGNER_CONFIGURE_MMU_EL(_el)					\
	void wagner_init_mmu_el##_el(unsigned long total_base,	\
				unsigned long total_size,		\
				unsigned long ro_start,			\
				unsigned long ro_limit)			\
	{								\
	       mmap_add_region(total_base, total_base,			\
			       total_size,				\
			       MT_MEMORY | MT_RW | MT_SECURE);		\
	       mmap_add_region(ro_start, ro_start,			\
			       ro_limit - ro_start,			\
			       MT_MEMORY | MT_RO | MT_SECURE);		\
	       mmap_add(wagner_mmap);					\
	       init_xlat_tables();					\
									\
	       enable_mmu_el##_el(0);					\
	}

/* Define EL1 and EL3 variants of the function initialising the MMU */
WAGNER_CONFIGURE_MMU_EL(1)
WAGNER_CONFIGURE_MMU_EL(3)

unsigned long plat_get_ns_image_entrypoint(void)
{
	return NS_BL1U_BASE;
}

unsigned int plat_get_syscnt_freq2(void)
{
	unsigned int sysc_counter_div =
	(mmio_read_32(VPL_SYSC_SECURE_MMR_BASE+SYSC_CNT_CTRL) & 0xFFFF) + 1;

	return (SYS_COUNT_CLOCK / sysc_counter_div);
}
