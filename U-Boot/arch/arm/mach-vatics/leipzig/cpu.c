// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021 VATICS Inc.
 */

#include <common.h>
#include <command.h>
#include <config.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/arch/soc.h>
#include <asm/global_data.h>
#include <asm/armv8/mmu.h>
#include <mapmem.h>

DECLARE_GLOBAL_DATA_PTR;

static struct mm_region wagner_mem_map[] = {
	{
		/* DDR */
		.virt = 0x00000000UL,
		.phys = 0x00000000UL,
		.size = 0x80000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_OUTER_SHARE,
	},
	{
		.virt = 0x80000000UL,
		.phys = 0x80000000UL,
		.size = 0x80000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{
		0,
	}
};

struct mm_region *mem_map = wagner_mem_map;

void __weak reset_cpu(void)
{
	/* do nothing */
}

void enable_caches(void)
{
	icache_enable();
	dcache_enable();
}

int misc_init_r(void)
{
	printf("Relocation Offset is: %08lx\n", gd->reloc_off);
	printf("Relocating to %08lx, new gd at %08lx, sp at %08lx\n", gd->relocaddr,
	       (ulong)map_to_sysmem(gd->new_gd), gd->start_addr_sp);
	printf("Relocation FDT at %08lx\n", (ulong)map_to_sysmem(gd->new_fdt));

	return 0;
}
