/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2012  VATICS Inc.
 *
 */

#ifndef __BOOT_PARAM_H__
#define __BOOT_PARAM_H__

/*----------------------------------------------------------
 * Boot Arguments from TF-A
 *----------------------------------------------------------
 */
extern u64 tfa_boot_args[];
#define VATICS_BL2_MAGIC	(0xFACADE01)
#define ARG_MAGIC		0
#define ARG_BOOTMODE		1
#define ARG_SPI_PARAM		2
//	<RESERVE>		3

/*----------------------------------------------------------
 * Boot Mode
 *----------------------------------------------------------
 */
#define SYSC_ENGINEER_MODE_SHIFT        3

// Normnal Boot
#define BOOT_NOR_P0_1BIT        0       //000000
#define BOOT_NOR_P0_QUAD        1       //000001
#define BOOT_NAND_P0_1BIT       2       //000010
#define BOOT_NAND_P0_QUAD       3       //000011
#define BOOT_NOR_P1_1BIT        4       //000100
#define BOOT_NAND_P1_1BIT       5       //000101
#define BOOT_MSHC1_MMC4         6       //000110
#define BOOT_MSHC0_MMC8         7       //000111
// Engineer Boot
/* case BOOT_USB20: BOOT_USB20 overridden by RECOVERY_USB20 in BL1 */
#define BOOT_USB30              (1 << SYSC_ENGINEER_MODE_SHIFT) //001000
#define BOOT_MSHC0_SD           (2 << SYSC_ENGINEER_MODE_SHIFT) //010000
#define BOOT_BYPASS             (3 << SYSC_ENGINEER_MODE_SHIFT) //011000
// USB 2nd recovery (to distinguish BOOT_USB20 & BOOT_NOR_P0_1BIT)
#define RECOVERY_USB20          (4 << SYSC_ENGINEER_MODE_SHIFT) //100000
#define RECOVERY_USB30          (5 << SYSC_ENGINEER_MODE_SHIFT) //101000
#define RECOVERY_TBBR           (7 << SYSC_ENGINEER_MODE_SHIFT) //111000
// Invalid mode fOR debug (SD + MMC8 is invalid combination)
#define BOOT_INVALID            (BOOT_MSHC0_SD | BOOT_MSHC0_MMC8)

unsigned int get_bootmode(void);

#endif
