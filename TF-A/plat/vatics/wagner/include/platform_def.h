/*
 * Copyright (c) 2017-2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLATFORM_DEF_H
#define PLATFORM_DEF_H

#include <arch.h>
#include <lib/utils_def.h>

#include "../wagner_def.h"
#include "../maps.h"


/*  BRC_SRAM: VPL_BRC_RAM_BASE = 0xC0038000
 *  0xC0037FD8 - 0xC0037FE0 WAGNER_BACKUPSTEP_ADDR	// 8 bytes
 *  0xC0037FE0 - 0xC0037FE8 WAGNER_BOOTSTEP_ADDR	// 8 bytes
 *  0xC0037FE8 - 0xC0037FEC WAGNER_BOOTERR_ADDR		// 4 bytes (2+2)
 *  0xC0037FEC - 0xC0037FF0 WAGNER_BOOTMODE_ADDR	// 4 bytes
 *  0xC0037FF0 - 0xC0038000 WAGNER_WDT_BOOT_ADDR	// 16 bytes
 */

/* UUID address for non-PMU boot flag watchdog reset */
#define WAGNER_WDT_BOOT_UUID \
	{{0x1b, 0x6d, 0xfa, 0x6d}, {0x51, 0x36}, {0x40, 0x8c}, 0x9b, 0x1f, {0x7e, 0xfe, 0xb5, 0x75, 0xf4, 0x07} }
#define WAGNER_WDT_BOOT_ADDR	(VPL_BRC_RAM_BASE + 0x8000 - 0x10)

/* BOOT Mode stored in SRAM address */
#define WAGNER_BOOTMODE_ADDR	(WAGNER_WDT_BOOT_ADDR - 0x04)

/* BOOT steps and error code address */
#define WAGNER_BOOTERR_ADDR	(WAGNER_WDT_BOOT_ADDR - 0x08)
#define WAGNER_BOOTSTEP_ADDR	(WAGNER_WDT_BOOT_ADDR - 0x10)
#define WAGNER_BACKUPSTEP_ADDR	(WAGNER_WDT_BOOT_ADDR - 0x18)

/* Special value used to verify platform parameters from BL2 to BL3-1 */
#define WAGNER_BL31_PLAT_PARAM_VAL	0x0f1e2d3c4b5a6978ULL

/*
 * Generic platform constants
 */
#define PLAT_WAGNER_PRIMARY_CPU		(0x0)
#define SECONDARY_CPU_SPIN_BASE_ADDR    (SYSC_S_BASE + SYSC_CORE0_SPIN)

/* Size of cacheable stacks */
#define PLATFORM_STACK_SIZE		SZ_4K

#define FIRMWARE_WELCOME_STR		"Booting Trusted Firmware\n"

#define CONFIG_SYS_CACHELINE_SIZE       SZ_64
#define PLATFORM_CLUSTER_COUNT		U(1)
#define PLATFORM_CORE_COUNT_PER_CLUSTER	U(4)
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER_COUNT * \
					 PLATFORM_CORE_COUNT_PER_CLUSTER)
#define PLAT_MAX_PWR_LVL		MPIDR_AFFLVL1
#define PLAT_NUM_PWR_DOMAINS		(PLATFORM_CORE_COUNT + \
					 PLATFORM_CLUSTER_COUNT)

#define PLAT_MAX_RET_STATE		U(1)
#define PLAT_MAX_OFF_STATE		U(2)

/* Local power state for power domains in Run state. */
#define PLAT_LOCAL_STATE_RUN            U(0)
/* Local power state for retention. Valid only for CPU power domains */
#define PLAT_LOCAL_STATE_RET            U(1)
/*
 * Local power state for OFF/power-down. Valid for CPU and cluster power
 * domains.
 */
#define PLAT_LOCAL_STATE_OFF            2


#define MAX_IO_DEVICES			3
#define MAX_IO_HANDLES			4

/*
 * Platform memory map related constants
 */
//#define BL_SRAM_BASE			(VPL_BRC_RAM_BASE)
//#define BL_SRAM_SIZE			(0x9000)

#if ROM_IN_DRAM	//ROM in SRAM
#define BL1_RESERVE			SZ_128K //BL1(RO) in SRAM for test
#else
#define BL1_RESERVE			0
#endif
#define HEADER_RESERVE		SZ_4K	//To avoid copy after SPI loading
#define BL_SRAM_BASE			(KDPU_SRAM_BASE + HEADER_RESERVE)
#define BL_SRAM_SIZE			(SZ_1M - BL1_RESERVE - HEADER_RESERVE)

/*
 * BL1 specific defines.
 */
#if ROM_IN_DRAM	//ROM in SRAM
#define BL1_RO_BASE			(BL_SRAM_BASE + BL_SRAM_SIZE)
#define BL1_RO_SIZE			BL1_RESERVE // Larger size for debug msg
#else
#define BL1_RO_BASE			(VPL_BRC_ROM_BASE)
#define BL1_RO_SIZE			SZ_64K // Real ROM size = 64KB
#endif

#define BL1_RO_LIMIT			(BL1_RO_BASE + BL1_RO_SIZE)

#define BL1_RW_BASE			(BL_SRAM_BASE + BL_SRAM_SIZE - \
					BL1_RW_SIZE)

#define BL1_RW_SIZE			SZ_64K
#define BL1_RW_LIMIT			(BL1_RW_BASE + BL1_RW_SIZE)

#if BL_SRAM_SIZE < BL1_RW_SIZE
#error "BL1_RW_SIZE is too big to fit BL_SRAM_SIZE!"
#endif

/*
 * BL2 specific defines.
 */
#define USB_FB_HEADER_SIZE		SZ_512
#define UNKNOWN_ADDR			0xFFFFFFFF
#define UNKNOWN_SIZE			0xFFFFFFFF
//#if ROM_IN_DRAM
//#define BL2_BASE			(BL1_RO_LIMIT)
//#define BL2_LIMIT			(BL2_BASE + 0xa000)
//#else
#define BL2_IMG_BASE			(BL_SRAM_BASE)	//BL2 loading address
#define BL2_BASE			(BL_SRAM_BASE)	//BL2 running address
#define BL2_LIMIT			(BL1_RW_BASE)

//BL2 package size = round_down to boundary 512 and max 256K
#define BL2_PACKSIZE_DEFAULT     \
	((((BL2_LIMIT - BL2_BASE) >> 9) << 9) < SZ_256K ? \
	 (((BL2_LIMIT - BL2_BASE) >> 9) << 9) : SZ_256K)

#if (BL2_PACKSIZE_DEFAULT < SZ_256K)
	#warn("BL2_PACKSIZE_DEFAULT < 256K bytes")
#endif

//#endif

/*
 * BL31 specific defines.
 */
#define BL31_BASE			(0x4000000)
#define BL31_LIMIT			(BL31_BASE + 0x40000)

/*
 * BL2 XLAT.
 */
#define BL2_XLAT_BASE			(BL31_BASE - 0x10000)
#define BL2_XLAT_LIMIT			(BL31_BASE)

/*
 * BL33 specific defines.
 */
#define BL33_BASE			(0x2000)
#define BL33_LIMIT			(BL2_XLAT_BASE - BL33_BASE)

/*
 * BL3-2 specific defines.
 */

/*
 * The TSP currently executes from TZC secured area of DRAM.
 */
#define BL32_DRAM_BASE                  (DDR_SEC_BASE)
#define BL32_DRAM_LIMIT                 (DDR_SEC_BASE+DDR_SEC_SIZE)

#ifdef SPD_opteed
/* Load pageable part of OP-TEE at end of allocated DRAM space for BL32 */
#define WAGNER_OPTEE_PAGEABLE_LOAD_BASE	(BL32_DRAM_LIMIT - \
			WAGNER_OPTEE_PAGEABLE_LOAD_SIZE) /* 0x3FC0_0000 */
#define WAGNER_OPTEE_PAGEABLE_LOAD_SIZE	0x400000 /* 4MB */
#endif

#define TSP_SEC_MEM_BASE		(BL32_DRAM_BASE)
#define TSP_SEC_MEM_SIZE		(BL32_DRAM_LIMIT - BL32_DRAM_BASE)
#define BL32_BASE			(BL32_DRAM_BASE)
#define BL32_LIMIT			(BL32_DRAM_LIMIT)

/* BL32 is mandatory in AArch32 */
#ifdef __aarch64__
#ifdef SPD_none
#undef BL32_BASE
#endif /* SPD_none */
#endif

/*
 * TBBR Firmware update memory map
 */
#define NS_BL1U_BASE			(VQ7U_SRAM_BASE + HEADER_RESERVE)
#define NS_BL1U_SIZE			(SZ_256K - HEADER_RESERVE)
#define NS_BL1U_LIMIT			(NS_BL1U_BASE + NS_BL1U_SIZE)

#define BL2U_BASE			(BL2_BASE)
#define BL2U_LIMIT			(BL2_LIMIT)

#define NS_FWU_DRAM_BASE		DDR_BASE
#define NS_FWU_DRAM_SIZE		SZ_1G
#define NS_BL2U_BASE			NS_FWU_DRAM_BASE


// Clear BL2 or NS_BL1U memory before BL1 loading
#define BL2BL1U_CLEAN_SIZE		(SZ_4K)

#if ((BL2BL1U_CLEAN_SIZE + BL2_BASE) > BL2_LIMIT)
	#warn("BL2 Clean over BL2_LIMIT")
#endif

#if ((BL2BL1U_CLEAN_SIZE + NS_BL1U_BASE) > NS_BL1U_LIMIT)
	#warn("NS_BL1U Clean over NS_BL1U_LIMIT")
#endif

/*
 * Platform specific page table and MMU setup constants
 */
#define PLAT_VIRT_ADDR_SPACE_SIZE   (1ULL << 32)
#define PLAT_PHY_ADDR_SPACE_SIZE    (1ULL << 32)

#if defined(IMAGE_BL1) || defined(IMAGE_BL32)
#define MAX_XLAT_TABLES			3
#endif

#if defined(IMAGE_BL2) || defined(IMAGE_BL31)
#define MAX_XLAT_TABLES			5
#endif

#define MAX_MMAP_REGIONS		16

/*
 * Declarations and constants to access the mailboxes safely. Each mailbox is
 * aligned on the biggest cache line size in the platform. This is known only
 * to the platform as it might have a combination of integrated and external
 * caches. Such alignment ensures that two maiboxes do not sit on the same cache
 * line at any cache level. They could belong to different cpus/clusters &
 * get written while being protected by different locks causing corruption of
 * a valid mailbox address.
 */
#define CACHE_WRITEBACK_SHIFT		6
#define CACHE_WRITEBACK_GRANULE		(1 << CACHE_WRITEBACK_SHIFT)

#define PLAT_WAGNER_GICD_BASE		GICD_REG_BASE
#define PLAT_WAGNER_GICR_BASE		GICR_REG_BASE

/* Interrupt numbers */
#define ARM_IRQ_SEC_PHY_TIMER           29

#define ARM_IRQ_SEC_SGI_0               8
#define ARM_IRQ_SEC_SGI_1               9
#define ARM_IRQ_SEC_SGI_2               10
#define ARM_IRQ_SEC_SGI_3               11
#define ARM_IRQ_SEC_SGI_4               12
#define ARM_IRQ_SEC_SGI_5               13
#define ARM_IRQ_SEC_SGI_6               14
#define ARM_IRQ_SEC_SGI_7               15

/*
 * Define properties of Group 1 Secure and Group 0 interrupts as per GICv3
 * terminology. On a GICv2 system or mode, the lists will be merged and treated
 * as Group 0 interrupts.
 */
#define PLAT_WAGNER_G1S_IRQ_PROPS(grp) \
	INTR_PROP_DESC(ARM_IRQ_SEC_PHY_TIMER, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_LEVEL), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_1, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_2, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_3, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_4, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_5, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_7, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE)

#define PLAT_WAGNER_G0_IRQ_PROPS(grp) \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_0, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE), \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_6, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_EDGE)


#endif /* PLATFORM_DEF_H */
