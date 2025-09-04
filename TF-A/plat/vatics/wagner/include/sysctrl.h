/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __VPL_SYSCTRL_H__
#define __VPL_SYSCTRL_H__

#include "../maps.h"

//-----------------------------------------------------------------------------
// SYSC definitions
//-----------------------------------------------------------------------------
#define SYSC_S_BASE		VPL_SYSC_SECURE_MMR_BASE
#define SYSC_NS_BASE		VPL_SYSC_NONSECURE_MMR_BASE
#define SYSC_CNT_CTRL        0x18

#define SYSC_CLK_0_EN_STAT	0x48
#define SYSC_CLK_1_EN_STAT	0x4c
#define SYSC_CLK_2_EN_STAT	0x50
#define SYSC_CLK_3_EN_STAT	0x54
#define SYSC_CLK_4_EN_STAT	0x58
#define SYSC_CLK_5_EN_STAT	0x5c
#define SYSC_MSHC_CTRL       0xc8

#define SHIFT(shift, value)     ((value)<<(shift))
#define GPIO(bit)		((1)<<(bit))
#define AGPIO(position, bit)    (((1)<<(bit+(16*(position%2)))))

#define SYSC_RST_RELEASE_SET_REG_0	0x158
#define SYSC_RST_RELEASE_CLR_REG_0	0x15C
#define SYSC_RST_RELEASE_SET_REG_1	0x160
#define SYSC_RST_RELEASE_CLR_REG_1	0x164
#define SYSC_RST_RELEASE_SET_REG_2	0x168
#define SYSC_RST_RELEASE_CLR_REG_2	0x16C
#define SYSC_RST_RELEASE_SET_REG_3	0x170
#define SYSC_RST_RELEASE_CLR_REG_3	0x174
#define SYSC_RST_RELEASE_SET_REG_4	0x178
#define SYSC_RST_RELEASE_CLR_REG_4	0x17C

#define SYSC_GEN_INOUT_PAD_PULL_CTRL_5	0x120

#define SYSC_CLK_EN_SET_REG_0		0x180
#define SYSC_CLK_EN_CLR_REG_0		0x184
#define SYSC_CLK_EN_SET_REG_1		0x188
#define SYSC_CLK_EN_CLR_REG_1		0x18c
#define SYSC_CLK_EN_SET_REG_2		0x190
#define SYSC_CLK_EN_CLR_REG_2		0x194
#define SYSC_CLK_EN_SET_REG_3		0x198
#define SYSC_CLK_EN_CLR_REG_3		0x19c
#define SYSC_CLK_EN_SET_REG_4		0x1a0
#define SYSC_CLK_EN_CLR_REG_4		0x1a4
#define SYSC_CLK_EN_SET_REG_5		0x1a8
#define SYSC_CLK_EN_CLR_REG_5		0x1ac
#define SYSC_MEM_PWR_DOWN_SET_0		0x1B0
#define SYSC_MEM_PWR_DOWN_CLR_0		0x1B4
#define SYSC_MEM_PWR_DOWN_SET_1		0x1B8
#define SYSC_MEM_PWR_DOWN_CLR_1		0x1BC

#define     MSHC_CTRL_4BIT_8BIT           (1U<<31)
#define     MSHC_CTRL_DIV0_OFFSET         4
#define     MSHC_CTRL_DIV0_MASK           (0x3ffU << MSHC_CTRL_DIV0_OFFSET)
#define     MSHC_CTRL_DIV0_REQ            (0x1U   << 0)
#define     MSHC_CTRL_DIV1_OFFSET         20
#define     MSHC_CTRL_DIV1_MASK           (0x3ffU << MSHC_CTRL_DIV1_OFFSET)
#define     MSHC_CTRL_DIV1_REQ            (0x1U   << 16)

#define		MSHC_DEV_0_CLK_TX	(1U<<22)
#define		MSHC_DEV_0_CLK_TM	(1U<<21)
#define		MSHC_DEV_0_CLK_CQETM	(1U<<19)
#define		MSHC_DEV_0_CLK_BASE	(1U<<18)
#define		MSHC_DEV_0_CLK_AXI	(1U<<17)
#define		MSHC_DEV_0_CLK_AHB	(1U<<16)

#define		MSHC_DEV_1_CLK_TX	(1U<<28)
#define		MSHC_DEV_1_CLK_TM	(1U<<27)
#define		MSHC_DEV_1_CLK_CQETM	(1U<<26)
#define		MSHC_DEV_1_CLK_BASE	(1U<<25)
#define		MSHC_DEV_1_CLK_AXI	(1U<<24)
#define		MSHC_DEV_1_CLK_AHB	(1U<<23)

#define		MSHC_DEV_0_CLK_MASK	(MSHC_DEV_0_CLK_TX |\
					 MSHC_DEV_0_CLK_TM |\
					 MSHC_DEV_0_CLK_CQETM |\
					 MSHC_DEV_0_CLK_BASE |\
					 MSHC_DEV_0_CLK_AXI |\
					 MSHC_DEV_0_CLK_AHB)

#define		MSHC_DEV_1_CLK_MASK	(MSHC_DEV_1_CLK_TX |\
					 MSHC_DEV_1_CLK_TM |\
					 MSHC_DEV_1_CLK_CQETM |\
					 MSHC_DEV_1_CLK_BASE |\
					 MSHC_DEV_1_CLK_AXI |\
					 MSHC_DEV_1_CLK_AHB)

/*----------------------------------------------------------
 * Boot Mode
 *----------------------------------------------------------
 */
#define SYSC_GENERAL_INFO		0x148	// SYS_I_BOOT_MODE_SEL[5:0]
#define SYSC_ENGINEER_FIRST_DISABLE	(1<<5)
#define SYSC_TBBR_ENABLE		(1<<4)
#define SYSC_TBBR_RECOVERY		(1<<3)
#define SYSC_BOOT_MODE_MASK		0x3F
#define	SYSC_NORMAL_MODE_MASK		0x7
#define SYSC_ENGINEER_MODE_MASK		0x38
#define	SYSC_ENGINEER_MODE_SHIFT	3

// Normnal Boot
#define	BOOT_NOR_P0_1BIT	0	//000000
#define	BOOT_NOR_P0_QUAD	1	//000001
#define	BOOT_NAND_P0_1BIT	2	//000010
#define	BOOT_NAND_P0_QUAD	3	//000011
#define	BOOT_NOR_P1_1BIT	4	//000100
#define	BOOT_NAND_P1_1BIT	5	//000101
#define	BOOT_MSHC1_MMC4		6	//000110
#define	BOOT_MSHC0_MMC8		7	//000111
// Engineer Boot
#define	BOOT_USB20		(0 << SYSC_ENGINEER_MODE_SHIFT) //000000
#define	BOOT_USB30		(1 << SYSC_ENGINEER_MODE_SHIFT) //001000
#define	BOOT_MSHC0_SD		(2 << SYSC_ENGINEER_MODE_SHIFT) //010000
#define	BOOT_BYPASS		(3 << SYSC_ENGINEER_MODE_SHIFT) //011000
// USB 2nd recovery (to distinguish BOOT_USB20 & BOOT_NOR_P0_1BIT)
#define RECOVERY_USB20		(4 << SYSC_ENGINEER_MODE_SHIFT) //100000
#define RECOVERY_USB30		(5 << SYSC_ENGINEER_MODE_SHIFT) //101000
#define RECOVERY_TBBR		(7 << SYSC_ENGINEER_MODE_SHIFT) //111000
// Invalid mode fOR debug (SD + MMC8 is invalid combination)
#define BOOT_INVALID		(BOOT_MSHC0_SD | BOOT_MSHC0_MMC8)


#define	SYSC_CHIP_ID_INFO	0x228
#define PMU_BOOT_DISABLE	(1U << 13) //0: support warmboot by pmu

#define SYSC_PAD_EN_SET_REG_0		0x1e0
#define SYSC_PAD_EN_CLR_REG_0		0x1e4
#define SYSC_PAD_EN_SET_REG_1		0x1e8
#define SYSC_PAD_EN_CLR_REG_1		0x1ec
#define SYSC_PAD_EN_SET_REG_2		0x1f0
#define SYSC_PAD_EN_CLR_REG_2		0x1f4
#define SYSC_PAD_EN_SET_REG_3		0x1f8
#define SYSC_PAD_EN_CLR_REG_3		0x1fc
#define SYSC_PAD_EN_SET_REG_4		0x200
#define SYSC_PAD_EN_CLR_REG_4		0x204
#define SYSC_PAD_EN_SET_REG_5		0x208
#define SYSC_PAD_EN_CLR_REG_5		0x20c
#define SYSC_PAD_EN_SET_REG_6		0x210
#define SYSC_PAD_EN_CLR_REG_6		0x214
#define SYSC_PAD_EN_SET_REG_7		0x218
#define SYSC_PAD_EN_CLR_REG_7		0x21c
#define SYSC_PAD_EN_SET_REG_8		0x220
#define SYSC_PAD_EN_CLR_REG_8		0x224


/*----------------------------------------------------------
 * Non-Secure SYSC access control (default: 32'h0000_0000)
 * 1'b0: Non-accessible for APB slave 1.
 * 1'b1: Accessible for APB slave 1.
 *----------------------------------------------------------
 */
#define SYSC_ACCESS_CTRL_REG_0		0x230	// Bit 31-06: MMR 31-06 access control.
#define SYSC_ACCESS_CTRL_REG_1		0x234	// Bit 31-00: MMR 63-32 access control.
#define SYSC_ACCESS_CTRL_REG_2		0x238	// Bit 31-00: MMR 95-64 access control.
#define SYSC_ACCESS_CTRL_REG_3		0x23C	// Bit 31-00: MMR 127-96 access control.
#define SYSC_ACCESS_CTRL_REG_4		0x240	// Bit 23-00: MMR 151-128 access control.

#define SYSC_ACCESS_MSHC_CTRL	BIT_32(SYSC_MSHC_CTRL/4 - 32)		//050
#define SYSC_ACCESS_CLR_CLK3	BIT_32(SYSC_CLK_EN_CLR_REG_3/4 - 96)	//103
#define SYSC_ACCESS_SET_CLK3	BIT_32(SYSC_CLK_EN_SET_REG_3/4 - 96)	//102
#define SYSC_ACCESS_CLR_CLK5	BIT_32(SYSC_CLK_EN_CLR_REG_5/4 - 96)	//107
#define SYSC_ACCESS_SET_CLK5	BIT_32(SYSC_CLK_EN_SET_REG_5/4 - 96)	//106

/*----------------------------------------------------------
 * OTP
 *----------------------------------------------------------
 */
#define SYSC_HW_CFG_0		0x244		// Bit 30-03: OTP bit 62-35.
#define PRODUCTION_MODE		(1U << 31)	// Bit 31-31:
						// 1'b0: Normal function mode.
						// 1'b1: Production function mode.
#define SCRTU_FW_EXTERNAL	(1U << (50-32))	// bit50, 0:ROM, 1:external
#define SCRTU_EIP130_ENABLE	(1U << (52-32))	// bit52, EIP130 enable

#define SYSC_HW_CFG_1		0x248		// Bit 31-00:
						// OTP parameter set bit 31-00.
#define SECUREBOOT_ENABLE	(1U << 24)	// TZC blocks enable
#define FIPS_ENABLE		(1U << 25)	// 0:cfgB, 1:cfgA
#define USB3_CLK_EXTERNAL	(1U << 27)	// 0:internal, 1:external

#define SYSC_HW_CFG_2		0x24C		// Bit 31-00:
						// OTP parameter set bit 63-32.
/*----------------------------------------------------------
 * Start CPU Core polloing address
 *----------------------------------------------------------
 */
#define SYSC_CORE0_SPIN		0x250
#define SYSC_CORE1_SPIN		0x254
#define SYSC_CORE2_SPIN		0x258
#define SYSC_CORE3_SPIN		0x25C

#endif
