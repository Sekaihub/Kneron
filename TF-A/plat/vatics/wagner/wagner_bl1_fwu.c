/*
 * Copyright (c) 2015-2021, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <errno.h>

#include <platform_def.h>

#include <bl1/tbbr/tbbr_img_desc.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <lib/utils.h>

/* Struct to keep track of usable memory */
typedef struct bl1_mem_info {
	uintptr_t mem_base;
	unsigned int mem_size;
} bl1_mem_info_t;

static bl1_mem_info_t fwu_addr_map_secure[] = {
	{
		.mem_base = BL2U_BASE,
		.mem_size = (BL2U_LIMIT - BL2U_BASE)
	},
	{
		.mem_size = 0
	}
};

static bl1_mem_info_t fwu_addr_map_non_secure[] = {
	{
		.mem_base = NS_FWU_DRAM_BASE,
		.mem_size = NS_FWU_DRAM_SIZE
	},
	{
		.mem_base = NS_BL1U_BASE,
		.mem_size = NS_BL1U_SIZE
	},
	{
		.mem_size = 0
	}
};

int bl1_plat_mem_check(uintptr_t mem_base,
		unsigned int mem_size,
		unsigned int flags)
{
	unsigned int index = 0;
	bl1_mem_info_t *mmap;

	assert(mem_base);
	assert(mem_size);
	/*
	 * The caller of this function is responsible for checking upfront that
	 * the end address doesn't overflow. We double-check this in debug
	 * builds.
	 */
	assert(!check_uptr_overflow(mem_base, mem_size - 1));

	/*
	 * Check the given image source and size.
	 */
	if (GET_SECURITY_STATE(flags) == SECURE)
		mmap = fwu_addr_map_secure;
	else
		mmap = fwu_addr_map_non_secure;

	while (mmap[index].mem_size) {
		if ((mem_base >= mmap[index].mem_base) &&
			((mem_base + mem_size)
			<= (mmap[index].mem_base +
			mmap[index].mem_size)))
			return 0;

		index++;
	}

	return -ENOMEM;
}

