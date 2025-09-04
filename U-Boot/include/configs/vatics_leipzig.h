/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration for Leipzig board
 *
 * Copyright (C) 2021 VATICS Inc.
 */

#ifndef __VATICS_LEIPZIG_H__
#define __VATICS_LEIPZIG_H__

#include <linux/sizes.h>
#include <asm/arch/maps.h>


#define CONFIG_SYS_LOAD_ADDR			0x22000000			/* load address */
#define CONFIG_SYS_MALLOC_LEN			SZ_4M

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG

/********* DRAM *********/
#define CONFIG_SYS_DDR_SDRAM_BASE		0x00000000
#define CONFIG_SYS_SDRAM_BASE			CONFIG_SYS_DDR_SDRAM_BASE
#define CONFIG_SYS_INIT_SP_ADDR			(CONFIG_SYS_SDRAM_BASE + 0x1000000)

#define MACH_TYPE_EVM				0x778
#define CONFIG_MACH_TYPE			MACH_TYPE_EVM
#define BOOT_PARAMS_ADDR			CONFIG_SYS_SDRAM_BASE + 0x100

/******** UART ********/
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_MEM32
#define CONFIG_SYS_NS16550_COM1			(VPL_UARTC0_MMR_BASE + 0x4)

#if defined(CONFIG_TARGET_LEIPZIG_EVM)
#define CONFIG_SYS_NS16550_CLK			200000000
#else
#define CONFIG_SYS_NS16550_CLK			8000000
#endif

/******** SPI NAND ********/
#define CONFIG_SYS_MAX_NAND_DEVICE		2
#define CONFIG_SYS_NAND_SELF_INIT

#endif /*__VATICS_WAGNER_H__*/
