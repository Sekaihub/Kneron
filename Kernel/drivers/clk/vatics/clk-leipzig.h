// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_LEIPZIG_H_
#define CLK_VTX_LEIPZIG_H_


/* PLL */
#define PLL_0_BASE 0x00
#define PLL_1_BASE 0x20
#define PLL_2_BASE 0x40
#define PLL_3_BASE 0x60
#define PLL_4_BASE 0x80
#define PLL_5_BASE 0xA0
#define PLL_6_BASE 0xC0
#define PLL_7_BASE 0xE0
#define PLL_8_BASE 0x100
#define PLL_9_BASE 0x120

#define PLL_VERSION 0x0
#define PLL_CTRL 0x4
#define PLL_STAT 0x8
#define PLL_DIV_0 0xc
#define PLL_DIV_1 0x10
#define PLL_SSM 0x14
#define PLL_DCC 0x18

#define PLL_FB_INT_DIV_SHIFT 16
#define PLL_FB_INT_DIV_WIDTH 12
#define PLL_POST_DIV2_SHIFT 12
#define PLL_POST_DIV2_WIDTH 3
#define PLL_POST_DIV1_SHIFT 8
#define PLL_POST_DIV1_WIDTH 3
#define PLL_FB_FRAC_DIV_SHIFT 0
#define PLL_FB_FRAC_DIV_WIDTH 24
#define PLL_REF_DIV_SHIFT 0
#define PLL_REF_DIV_WIDTH 6

#define PLL_SSM_DEPTH_SHIFT 12
#define PLL_SSM_DEPTH_WIDTH 5
#define PLL_SSM_FMODE_SHIFT 8
#define PLL_SSM_FMODE_WIDTH 4
#define PLL_SSM_TYPE_SHIFT 4
#define PLL_SSM_TYPE_WIDTH 1
#define PLL_SSM_EN_SHIFT 0
#define PLL_SSM_EN_WIDTH 1



#endif // CLK_VTX_LEIPZIG_H_
