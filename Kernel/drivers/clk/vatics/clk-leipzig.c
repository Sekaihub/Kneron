// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <linux/clk-provider.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>
#include <dt-bindings/clock/leipzig-clk.h>
#include <linux/clk.h>

#include "clk-leipzig.h"

#include "clk.h"
#include "clk-pll.h"
#include "clk-gate.h"
#include "clk-mux.h"
#include "clk-div.h"
#include "clk-composite.h"
#include "clk-fixed-factor.h"
#include "clk-phase.h"


#define MFLAGS 0
#define DFLAGS 0
#define GFLAGS 0
#define PFLAGS 0
#define MEM_PWR_FLAGS (CLK_GATE_SET_TO_DISABLE)

/* PLL */
static struct div_nmp pll_nmp = {
	.ref_div_shift = PLL_REF_DIV_SHIFT,
	.ref_div_width = PLL_REF_DIV_WIDTH,
	.post_div1_shift = PLL_POST_DIV1_SHIFT,
	.post_div1_width = PLL_POST_DIV1_WIDTH,
	.post_div2_shift = PLL_POST_DIV2_SHIFT,
	.post_div2_width = PLL_POST_DIV2_WIDTH,
	.fb_int_div_shift = PLL_FB_INT_DIV_SHIFT,
	.fb_int_div_width = PLL_FB_INT_DIV_WIDTH,
	.fb_frac_div_shift = PLL_FB_FRAC_DIV_SHIFT,
	.fb_frac_div_width = PLL_FB_FRAC_DIV_WIDTH,
};

static struct vtx_clk_pll_freq_table pll_0_freq_table[] = {
	{ /* 400 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 80,
	  .fb_frac_div = 0,
	  .output_rate = 400000000 },
	{ /* 533.3333 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 3,
	  .post_div2 = 1,
	  .fb_int_div = 80,
	  .fb_frac_div = 0,
	  .output_rate = 5333333000 },
	{ /* 600 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 60,
	  .fb_frac_div = 0,
	  .output_rate = 600000000 },
	{ /* 666.6666 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 3,
	  .post_div2 = 1,
	  .fb_int_div = 100,
	  .fb_frac_div = 0,
	  .output_rate = 666666600 },
	{ /* 700 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 70,
	  .fb_frac_div = 0,
	  .output_rate = 700000000 },
	{ /* 760 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 76,
	  .fb_frac_div = 0,
	  .output_rate = 760000000 },
	{ /* 800 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 80,
	  .fb_frac_div = 0,
	  .output_rate = 800000000 },
	{ /* 933.3333 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 3,
	  .post_div2 = 1,
	  .fb_int_div = 140,
	  .fb_frac_div = 0,
	  .output_rate = 933333300 },
	{ /* 1066.6666 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 3,
	  .post_div2 = 1,
	  .fb_int_div = 160,
	  .fb_frac_div = 0,
	  .output_rate = 1066666600 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_1_freq_table[] = {
	{ /* 900 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 45,
	  .fb_frac_div = 0,
	  .output_rate = 900000000 },
	{ /* 1100 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 55,
	  .fb_frac_div = 0,
	  .output_rate = 1100000000 },
	{ /* 1440 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 72,
	  .fb_frac_div = 0,
	  .output_rate = 1440000000 },
	{ /* 1600 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 80,
	  .fb_frac_div = 0,
	  .output_rate = 1600000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_2_freq_table[] = {
	{ /* 250 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 50,
	  .fb_frac_div = 0,
	  .output_rate = 250000000 },
	{ /* 500 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 50,
	  .fb_frac_div = 0,
	  .output_rate = 500000000 },
	{ /* 750 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 75,
	  .fb_frac_div = 0,
	  .output_rate = 750000000 },
	{ /* 900 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 90,
	  .fb_frac_div = 0,
	  .output_rate = 900000000 },
	{ /* 1200 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 120,
	  .fb_frac_div = 0,
	  .output_rate = 1200000000 },
	{ /* 1350 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 135,
	  .fb_frac_div = 0,
	  .output_rate = 1350000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_3_freq_table[] = {
	{ /* 540 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 54,
	  .fb_frac_div = 0,
	  .output_rate = 540000000 },
	{ /* 890 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 89,
	  .fb_frac_div = 0,
	  .output_rate = 890000000 },
	{ /* 940 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 94,
	  .fb_frac_div = 0,
	  .output_rate = 940000000 },
	{ /* 1020 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 102,
	  .fb_frac_div = 0,
	  .output_rate = 1020000000 },
	{ /* 1070 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 107,
	  .fb_frac_div = 0,
	  .output_rate = 1070000000 },
	{ /* 1250 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 125,
	  .fb_frac_div = 0,
	  .output_rate = 1250000000 },
	{ /* 1340 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 134,
	  .fb_frac_div = 0,
	  .output_rate = 1340000000 },
	{ /* 1430 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 143,
	  .fb_frac_div = 0,
	  .output_rate = 1430000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_4_freq_table[] = {
	{ /* 600 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 60,
	  .fb_frac_div = 0,
	  .output_rate = 600000000 },
	{ /* 1000 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 50,
	  .fb_frac_div = 0,
	  .output_rate = 1000000000 },
	{ /* 1200 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 60,
	  .fb_frac_div = 0,
	  .output_rate = 1200000000 },
	{ /* 1600 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 80,
	  .fb_frac_div = 0,
	  .output_rate = 1600000000 },
	{ /* 1880 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 94,
	  .fb_frac_div = 0,
	  .output_rate = 1880000000 },
	{ /* 2260 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 113,
	  .fb_frac_div = 0,
	  .output_rate = 2260000000 },
	{ /* 2700 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 135,
	  .fb_frac_div = 0,
	  .output_rate = 2700000000 },
	{ /* 2000 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 100,
	  .fb_frac_div = 0,
	  .output_rate = 2000000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_5_freq_table[] = {
	{ /* 2000 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 1,
	  .post_div2 = 1,
	  .fb_int_div = 100,
	  .fb_frac_div = 0,
	  .output_rate = 2000000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_6_freq_table[] = {
	{ /* 40 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 7,
	  .post_div2 = 3,
	  .fb_int_div = 42,
	  .fb_frac_div = 1,
	  .output_rate = 40000000 },
	{ /* 80 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 7,
	  .post_div2 = 3,
	  .fb_int_div = 84,
	  .fb_frac_div = 1,
	  .output_rate = 80000000 },
	{ /* 48 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 43,
	  .fb_frac_div = 3355443,
	  .output_rate = 48000000 },
	{ /* 54 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 48,
	  .fb_frac_div = 10066330,
	  .output_rate = 54000000 },
	{ /* 74.25 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 66,
	  .fb_frac_div = 13841203,
	  .output_rate = 74250000 },
	{ /* 148.5 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 2,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 148500000 },
	{ /* 150 MHz */
		.input_rate = 20000000,
		.ref_div = 1,
		.post_div1 = 2,
		.post_div2 = 3,
		.fb_int_div = 45,
		.fb_frac_div = 1,
		.output_rate = 150000000 },
	{ /* 160 MHz */
		.input_rate = 20000000,
		.ref_div = 1,
		.post_div1 = 7,
		.post_div2 = 3,
		.fb_int_div = 168,
		.fb_frac_div = 1,
		.output_rate = 160000000 },
	{ /* 297 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 297000000 },
	{ /* 312 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 62,
	  .fb_frac_div = 8388608,
	  .output_rate = 312000000 },
	{ /* 50 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 5,
	  .fb_int_div = 62,
	  .fb_frac_div = 8388608,
	  .output_rate = 50000000 },
	{ /* 144 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 1,
	  .fb_int_div = 43,
	  .fb_frac_div = 3355443,
	  .output_rate = 144000000 },
	{ /* 76.4 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 7,
	  .post_div2 = 6,
	  .fb_int_div = 160,
	  .fb_frac_div = 6710886,
	  .output_rate = 76400000 },
	{ /* 38.2 MHz */
	  .input_rate = 20000000,
	  .ref_div = 2,
	  .post_div1 = 7,
	  .post_div2 = 6,
	  .fb_int_div = 160,
	  .fb_frac_div = 6710886,
	  .output_rate = 38200000 },
	{ /* 194 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 2,
	  .fb_int_div = 97,
	  .fb_frac_div = 0,
	  .output_rate = 194000000 },
	{ /* 20 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 7,
	  .post_div2 = 6,
	  .fb_int_div = 42,
	  .fb_frac_div = 1,
	  .output_rate = 20000000 },
	{ /* 24 MHz */
	  .input_rate = 20000000,
	  .ref_div = 2,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 43,
	  .fb_frac_div = 3355443,
	  .output_rate = 24000000 },
	{ /* 126 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 2,
	  .fb_int_div = 63,
	  .fb_frac_div = 0,
	  .output_rate = 126000000 },
	{ /* 76.8 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 5,
	  .fb_int_div = 96,
	  .fb_frac_div = 0,
	  .output_rate = 76800000 },
	{ /* 64 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 1,
	  .fb_int_div = 16,
	  .fb_frac_div = 0,
	  .output_rate = 64000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_7_freq_table[] = {
	{ /* 148.5 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 2,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 148500000 },
	{ /* 297 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 297000000 },
	{ /* 54 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 48,
	  .fb_frac_div = 10066330,
	  .output_rate = 54000000 },
	{ /* 30 MHz */
		.input_rate = 20000000,
		.ref_div = 1,
		.post_div1 = 5,
		.post_div2 = 2,
		.fb_int_div = 30,
		.fb_frac_div = 0,
		.output_rate = 60000000 },
	{ /* 29.70 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 4,
	  .fb_int_div = 29,
	  .fb_frac_div = 11744051,
	  .output_rate = 29700000 },
	{ /* 50.35 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 4,
	  .fb_int_div = 50,
	  .fb_frac_div = 5872026,
	  .output_rate = 50350000 },
	{ /* 108 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 2,
	  .fb_int_div = 43,
	  .fb_frac_div = 3355443,
	  .output_rate = 108000000 },
	{ /* 120 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 2,
	  .fb_int_div = 48,
	  .fb_frac_div = 0,
	  .output_rate = 120000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_8_freq_table[] = {
	{ /* 27 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 6,
	  .fb_int_div = 48,
	  .fb_frac_div = 10066330,
	  .output_rate = 27000000 },
	{ /* 30 MHz */
	 .input_rate = 20000000,
	 .ref_div = 1,
	 .post_div1 = 5,
	 .post_div2 = 2,
	 .fb_int_div = 30,
	 .fb_frac_div = 0,
	 .output_rate = 60000000 },
	{ /* 72 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 3,
	  .fb_int_div = 64,
	  .fb_frac_div = 13421773,
	  .output_rate = 72000000 },
	{ /* 148.5 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 148500000 },
	{ /* 216 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 1,
	  .fb_int_div = 64,
	  .fb_frac_div = 13421773,
	  .output_rate = 216000000 },
	{ /* 297 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 1,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 297000000 },
	{ /* 480 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 2,
	  .fb_int_div = 96,
	  .fb_frac_div = 0,
	  .output_rate = 480000000 },
	{ /* 594 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 59,
	  .fb_frac_div = 6710886,
	  .output_rate = 594000000 },
	{ /* 1188 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 2,
	  .post_div2 = 1,
	  .fb_int_div = 118,
	  .fb_frac_div = 13421773,
	  .output_rate = 1188000000 },
	{ /* sentinel */ }
};

static struct vtx_clk_pll_freq_table pll_9_freq_table[] = {
	{ /* 49.152 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 4,
	  .fb_int_div = 58,
	  .fb_frac_div = 16481937,
	  .output_rate = 49152000 },
	{ /* 98.304 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 6,
	  .post_div2 = 2,
	  .fb_int_div = 58,
	  .fb_frac_div = 16481937,
	  .output_rate = 98304000 },
	{ /* 196.608 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 3,
	  .post_div2 = 2,
	  .fb_int_div = 58,
	  .fb_frac_div = 16481937,
	  .output_rate = 196608000 },
	{ /* 67.7376 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 4,
	  .fb_int_div = 67,
	  .fb_frac_div = 12374875,
	  .output_rate = 67737600 },
	{ /* 135.4752 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 5,
	  .post_div2 = 2,
	  .fb_int_div = 67,
	  .fb_frac_div = 12374875,
	  .output_rate = 67737600 },
	{ /* 147.4560 MHz */
	  .input_rate = 20000000,
	  .ref_div = 1,
	  .post_div1 = 4,
	  .post_div2 = 2,
	  .fb_int_div = 58,
	  .fb_frac_div = 16481937,
	  .output_rate = 147456000 },
	{ /* sentinel */ }
};

/* clk gate registers */
static const struct vtx_gate_regs gate_0_regs = {
	.sta_reg = 0x48,
	.set_reg = 0x180,
	.clr_reg = 0x184,
};

static const struct vtx_gate_regs gate_1_regs = {
	.sta_reg = 0x4C,
	.set_reg = 0x188,
	.clr_reg = 0x18C,
};

static const struct vtx_gate_regs gate_2_regs = {
	.sta_reg = 0x50,
	.set_reg = 0x190,
	.clr_reg = 0x194,
};

static const struct vtx_gate_regs gate_3_regs = {
	.sta_reg = 0x54,
	.set_reg = 0x198,
	.clr_reg = 0x19C,
};

static const struct vtx_gate_regs gate_4_regs = {
	.sta_reg = 0x58,
	.set_reg = 0x1A0,
	.clr_reg = 0x1A4,
};

static const struct vtx_gate_regs gate_5_regs = {
	.sta_reg = 0x5C,
	.set_reg = 0x1A8,
	.clr_reg = 0x1AC,
};

static const struct vtx_gate_regs mem_pwr_0_regs = {
	.sta_reg = 0x60,
	.set_reg = 0x1B0,
	.clr_reg = 0x1B4,
};

static const struct vtx_gate_regs mem_pwr_1_regs = {
	.sta_reg = 0x64,
	.set_reg = 0x1B8,
	.clr_reg = 0x1BC,
};

/* clk divider table */
static struct clk_div_table pll_6_div_vic_ref_div_table[33];
static struct clk_div_table pll_9_div_i2ssc_int_rx_serial_div_table[8193];
static struct clk_div_table pll_9_div_i2ssc_int_tx_serial_div_table[8193];
static struct clk_div_table adcdcc_rx_div_table[513];
static struct clk_div_table adcdcc_tx_div_table[513];
static struct clk_div_table ca55u_core_0_div_table[17];
static struct clk_div_table ca55u_core_1_div_table[17];
static struct clk_div_table ca55u_core_2_div_table[17];
static struct clk_div_table ca55u_core_3_div_table[17];
static struct clk_div_table i2ssc_o_mclk_div_table[513];
static struct clk_div_table i2ssc_tx_ws_div_table[257];
static struct clk_div_table i2ssc_rx_ws_div_table[257];
static struct clk_div_table mshc_0_tx_div_table[1025];
static struct clk_div_table mshc_1_tx_div_table[1025];
static struct clk_div_table kdpu_core_div_table[17];
static struct clk_div_table vq7u_core_div_table[17];

/*
 * clk architecture
 **/
static const struct clk_parent_data osc_20m_pdata[] = {
	{ .fw_name = "osc_20m", .name = "osc_20m" },
};
DEFINE_VTX_FACTOR_PDATA(osc_20m_d20, osc_20m_pdata, 0, 1, 20);

/* clk plls */
DEFINE_VTX_PLL(pll_0, osc_20m_pdata, PLL_0_BASE, VTX_PLL_FRAC);
DEFINE_VTX_PLL(pll_1, osc_20m_pdata, PLL_1_BASE, 0);
DEFINE_VTX_PLL(pll_2, osc_20m_pdata, PLL_2_BASE, 0);
DEFINE_VTX_PLL(pll_3, osc_20m_pdata, PLL_3_BASE, 0);
DEFINE_VTX_PLL(pll_4, osc_20m_pdata, PLL_4_BASE, 0);
DEFINE_VTX_PLL(pll_5, osc_20m_pdata, PLL_5_BASE, VTX_PLL_FRAC);
DEFINE_VTX_PLL(pll_6, osc_20m_pdata, PLL_6_BASE, VTX_PLL_FRAC);
DEFINE_VTX_PLL(pll_7, osc_20m_pdata, PLL_7_BASE, VTX_PLL_FRAC);
DEFINE_VTX_PLL(pll_8, osc_20m_pdata, PLL_8_BASE, VTX_PLL_FRAC);
DEFINE_VTX_PLL(pll_9, osc_20m_pdata, PLL_9_BASE, VTX_PLL_FRAC);

DEFINE_VTX_FACTOR(pll_4_d2, pll_4, 0, 1, 2);
DEFINE_VTX_FACTOR(pll_4_d3, pll_4, 0, 1, 3);
DEFINE_VTX_FACTOR(pll_4_d4, pll_4, 0, 1, 4);
DEFINE_VTX_FACTOR(pll_4_d6, pll_4, 0, 1, 6);
DEFINE_VTX_FACTOR(pll_4_d8, pll_4, 0, 1, 8);
DEFINE_VTX_FACTOR(pll_5_d3, pll_5, 0, 1, 3);
DEFINE_VTX_FACTOR(pll_5_d4, pll_5, 0, 1, 4);
DEFINE_VTX_FACTOR(pll_5_d5, pll_5, 0, 1, 5);
DEFINE_VTX_FACTOR(pll_5_d6, pll_5, 0, 1, 6);
DEFINE_VTX_FACTOR(pll_5_d8, pll_5, 0, 1, 8);
DEFINE_VTX_FACTOR(pll_5_d10, pll_5, 0, 1, 10);
DEFINE_VTX_FACTOR(pll_5_d16, pll_5, 0, 1, 16);
DEFINE_VTX_FACTOR(pll_5_d20, pll_5, 0, 1, 20);
DEFINE_VTX_FACTOR(pll_5_out2, pll_5, 0, 1, 4);
DEFINE_VTX_FACTOR(pll_5_out2_d4, pll_5_out2, 0, 1, 4);
DEFINE_VTX_FACTOR(pll_5_out2_d10, pll_5_out2, 0, 1, 10);
DEFINE_VTX_FACTOR(pll_5_out2_d20, pll_5_out2, 0, 1, 20);
DEFINE_VTX_FACTOR(pll_5_out2_d200, pll_5_out2, 0, 1, 200);

static const struct clk_parent_data pll_5_d3_ahb_1_grp_pdata[] = {
	{ .hw = &pll_5_d3.clkr.hw },
	{ .hw = &pll_5_d6.clkr.hw },
};
DEFINE_VTX_MUX(pll_5_d3_ahb_1_grp, pll_5_d3_ahb_1_grp_pdata, 0, 0x248, 17, 1,
	       MFLAGS);

DEFINE_VTX_DIV(pll_6_div_vic_ref, pll_6, CLK_SET_RATE_PARENT, 0xDC, 4, 5,
	       DFLAGS, pll_6_div_vic_ref_div_table, 0);
DEFINE_VTX_FACTOR(pll_7_out1, pll_7, 0, 1, 2);
DEFINE_VTX_FACTOR(pll_8_out1, pll_8, 0, 1, 2);
DEFINE_VTX_DIV(pll_9_div_i2ssc_int_rx_serial, pll_9, 0, 0xAC, 16, 13, DFLAGS,
	       pll_9_div_i2ssc_int_rx_serial_div_table, 12);
DEFINE_VTX_DIV(pll_9_div_i2ssc_int_tx_serial, pll_9, 0, 0xB4, 16, 13, DFLAGS,
	       pll_9_div_i2ssc_int_tx_serial_div_table, 12);

/* adcdcc */
DEFINE_VTX_GATE(adcdcc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 0,
		GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(adcdcc_rx, pll_9, CLK_IGNORE_UNUSED, 0x9C, 4, 9,
			   DFLAGS, adcdcc_rx_div_table, 0, &gate_0_regs, 1,
			   GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(adcdcc_tx, pll_9, CLK_IGNORE_UNUSED, 0x9C, 20, 9,
			   DFLAGS, adcdcc_tx_div_table, 16, &gate_0_regs, 2,
			   GFLAGS);

/* agpoc */
DEFINE_VTX_GATE(agpoc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 3,
		GFLAGS);

/* brc */
DEFINE_VTX_GATE(brc_axi, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 4, GFLAGS);

/* ca55u */
DEFINE_VTX_GATE(ca55u_axi_ctl, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 5,
		GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(ca55u_core_0, pll_1, CLK_IGNORE_UNUSED, 0xA0, 4, 4,
			   DFLAGS, ca55u_core_0_div_table, 0,
			   &gate_0_regs, 6, GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(ca55u_core_1, pll_1, CLK_IGNORE_UNUSED, 0xA0, 12, 4,
			   DFLAGS, ca55u_core_1_div_table, 8, &gate_0_regs, 7,
			   GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(ca55u_core_2, pll_1, CLK_IGNORE_UNUSED, 0xA0, 20, 4,
			   DFLAGS, ca55u_core_2_div_table, 16, &gate_0_regs, 8,
			   GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(ca55u_core_3, pll_1, CLK_IGNORE_UNUSED, 0xA0, 28, 4,
			   DFLAGS, ca55u_core_3_div_table, 24, &gate_0_regs, 9,
			   GFLAGS);
DEFINE_VTX_GATE(ca55u_dbg, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 10,
		GFLAGS);
DEFINE_VTX_GATE(ca55u_gic, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 11,
		GFLAGS);
DEFINE_VTX_GATE(ca55u_pclk, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 12,
		GFLAGS);
DEFINE_VTX_GATE(ca55u_scu, pll_0, CLK_IGNORE_UNUSED, &gate_0_regs, 13, GFLAGS);

/* cdce */
DEFINE_VTX_GATE(cdce_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 14,
		GFLAGS);
DEFINE_VTX_GATE(cdce_axi, pll_0, CLK_IGNORE_UNUSED, &gate_0_regs, 15, GFLAGS);

static const struct clk_parent_data cdce_bpu_pdata[] = {
	{ .hw = &pll_4_d4.clkr.hw },
	{ .hw = &pll_4_d8.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(cdce_bpu, cdce_bpu_pdata, CLK_IGNORE_UNUSED, 0x248,
			   14, 1, MFLAGS, &gate_0_regs, 16, GFLAGS);

static const struct clk_parent_data cdce_vce_pdata[] = {
	{ .hw = &pll_4_d3.clkr.hw },
	{ .hw = &pll_4_d6.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(cdce_vce, cdce_vce_pdata, CLK_IGNORE_UNUSED, 0x248,
			   14, 1, MFLAGS, &gate_0_regs, 17, GFLAGS);

/* dmac */
DEFINE_VTX_GATE(dmac_0_ahb, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED, &gate_0_regs,
		18, GFLAGS);
DEFINE_VTX_GATE(dmac_1_ahb, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED, &gate_0_regs,
		19, GFLAGS);

/* eqosc */
static const struct clk_parent_data eqosc_i_rx_pdata[] = {
	{ .fw_name = "eqosc_i_rx", .name = "eqosc_i_rx" },
};

DEFINE_VTX_FACTOR_PDATA(eqosc_i_rx_d2, eqosc_i_rx_pdata, 0, 1, 2);
DEFINE_VTX_FACTOR_PDATA(eqosc_i_rx_d20, eqosc_i_rx_pdata, 0, 1, 20);

static const struct clk_parent_data eqosc_rmode_0_mux_pdata[] = {
	{ .hw = &pll_5_out2_d4.clkr.hw },
	{ .hw = &pll_5_out2_d4.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_rmode_0_mux, eqosc_rmode_0_mux_pdata, 0, 0xA4, 4, 1,
	       MFLAGS);

static const struct clk_parent_data eqosc_rmode_1_mux_pdata[] = {
	{ .hw = &pll_5_out2_d20.clkr.hw },
	{ .hw = &pll_5_out2_d20.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_rmode_1_mux, eqosc_rmode_1_mux_pdata, 0, 0xA4, 4, 1,
	       MFLAGS);

static const struct clk_parent_data eqosc_rmode_2_mux_pdata[] = {
	{ .hw = &pll_5_out2_d200.clkr.hw },
	{ .hw = &pll_5_out2_d200.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_rmode_2_mux, eqosc_rmode_2_mux_pdata, 0, 0xA4, 4, 1,
	       MFLAGS);

DEFINE_VTX_PHASE(eqosc_rmii_phase_mux, pll_5_out2_d10, 0, 0xA4, 20, 2, 90,
		 PFLAGS);

static const struct clk_parent_data eqosc_freq_mux_pdata[] = {
	{ .hw = &pll_5_out2_d4.clkr.hw },   { .hw = &pll_5_out2_d20.clkr.hw },
	{ .hw = &pll_5_out2_d200.clkr.hw }, { .hw = &eqosc_i_rx_d2.clkr.hw },
	{ .hw = &eqosc_i_rx_d20.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_freq_mux, eqosc_freq_mux_pdata, 0, 0xA4, 0, 3, MFLAGS);

DEFINE_VTX_GATE(eqos_axi_dma, pll_5_d4, CLK_IGNORE_UNUSED, &gate_0_regs, 20,
			 GFLAGS);
DEFINE_VTX_GATE(eqos_axi_mmr, pll_5_d5, CLK_IGNORE_UNUSED, &gate_0_regs, 21,
			 GFLAGS);
DEFINE_VTX_GATE(eqosc_ptp_ref, pll_5_d20, CLK_IGNORE_UNUSED, &gate_0_regs, 22,
		GFLAGS);

static const struct clk_parent_data eqosc_rmii_pdata[] = {
	{ .hw = &pll_5_out2_d10.clkr.hw },
	{ .fw_name = "eqosc_i_rx", .name = "eqosc_i_rx" },
};
DEFINE_VTX_COMPOSITE_NODIV(eqosc_rmii, eqosc_rmii_pdata, CLK_IGNORE_UNUSED,
			   0xA4, 28, 1, MFLAGS, &gate_0_regs, 23, GFLAGS);

static const struct clk_parent_data eqosc_rx_pdata[] = {
	{ .fw_name = "eqosc_i_rx", .name = "eqosc_i_rx" },
	{ .hw = &eqosc_freq_mux.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(eqosc_rx, eqosc_rx_pdata, CLK_IGNORE_UNUSED, 0xA4, 8,
			   1, MFLAGS, &gate_0_regs, 24, GFLAGS);

static const struct clk_parent_data eqosc_tx_pdata[] = {
	{ .fw_name = "eqosc_i_tx", .name = "eqosc_i_tx" },
	{ .hw = &eqosc_freq_mux.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(eqosc_tx, eqosc_tx_pdata, CLK_IGNORE_UNUSED, 0xA4,
			   12, 1, MFLAGS, &gate_0_regs, 25, GFLAGS);

static const struct clk_parent_data eqosc_o_ref_pdata[] = {
	{ .hw = &pll_5_out2_d20.clkr.hw },
	{ .hw = &pll_5_out2_d20.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_o_ref, eqosc_o_ref_pdata, 0, 0xA4, 29, 1, MFLAGS);

static const struct clk_parent_data eqosc_o_tx_pdata[] = {
	{ .hw = &eqosc_rmode_0_mux.clkr.hw },
	{ .hw = &eqosc_rmode_1_mux.clkr.hw },
	{ .hw = &eqosc_rmode_2_mux.clkr.hw },
	{ .hw = &eqosc_rmii_phase_mux.clkr.hw },
};
DEFINE_VTX_MUX(eqosc_o_tx, eqosc_o_tx_pdata, 0, 0xA4, 24, 2, MFLAGS);

/* gpioc */
DEFINE_VTX_GATE(gpioc_0_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 26,
		GFLAGS);
DEFINE_VTX_GATE(gpioc_1_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 27,
		GFLAGS);
DEFINE_VTX_GATE(gpioc_2_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 28,
		GFLAGS);

/* i2c */
DEFINE_VTX_GATE(i2c_0_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 29,
		GFLAGS);
DEFINE_VTX_GATE(i2c_1_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 30,
		GFLAGS);
DEFINE_VTX_GATE(i2c_2_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_0_regs, 31,
		GFLAGS);

/* ddr */
DEFINE_VTX_GATE(ddr_mmr_apb, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 0, GFLAGS);
DEFINE_VTX_GATE(ddr_apm_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 1,
		GFLAGS);
DEFINE_VTX_GATE(ddr_axi, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 2, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_0, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 3, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_1, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 4, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_2, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 5, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_3, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 6,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_4, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 7,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_5, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 8,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_6, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 9, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_7, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 10,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_8, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 11,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_9, pll_4_d3, CLK_IGNORE_UNUSED, &gate_1_regs, 12,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_10, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 13, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_11, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 14, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_12, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 15, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_13, pll_4_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 16,
		GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_14, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 17, GFLAGS);
DEFINE_VTX_GATE(ddr_dpm_15, pll_0, CLK_IGNORE_UNUSED, &gate_1_regs, 18, GFLAGS);
DEFINE_VTX_GATE(ddr_mctl_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 19,
		GFLAGS);
DEFINE_VTX_GATE(ddr_pub_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 20,
		GFLAGS);

/* i2ssc */
DEFINE_VTX_DIV(i2ssc_o_mclk, pll_9, 0, 0xA8, 4, 9, DFLAGS,
	       i2ssc_o_mclk_div_table, 0);
DEFINE_VTX_GATE(i2ssc_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 21,
		GFLAGS);

static const struct clk_parent_data i2ssc_rx_sclk_pdata[] = {
	/* internal audio codec */
	{ .fw_name = "adcdcc_i_rx", .name = "adcdcc_i_rx" },
	/* external audio codec */
	{ .fw_name = "i2ssc_io_rx_sclk", .name = "i2ssc_io_rx_sclk" },
	{ .hw = &pll_9_div_i2ssc_int_rx_serial.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(i2ssc_rx_sclk, i2ssc_rx_sclk_pdata,
			   CLK_IGNORE_UNUSED, 0xAC, 8, 2, MFLAGS, &gate_1_regs,
			   22, GFLAGS);

static const struct clk_parent_data i2ssc_tx_sclk_pdata[] = {
	/* internal audio codec */
	{ .fw_name = "adcdcc_i_tx", .name = "adcdcc_i_tx" },
	/* external audio codec */
	{ .fw_name = "i2ssc_io_tx_sclk", .name = "i2ssc_io_tx_sclk" },
	{ .hw = &pll_9_div_i2ssc_int_tx_serial.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(i2ssc_tx_sclk, i2ssc_tx_sclk_pdata,
			   CLK_IGNORE_UNUSED, 0xB4, 8, 2, MFLAGS, &gate_1_regs,
			   23, GFLAGS);
DEFINE_VTX_DIV(i2ssc_tx_ws, pll_9_div_i2ssc_int_tx_serial, 0, 0xB8, 4, 8,
	       DFLAGS, i2ssc_tx_ws_div_table, 0);
DEFINE_VTX_DIV(i2ssc_rx_ws, pll_9_div_i2ssc_int_rx_serial, 0, 0xB0, 4, 8,
	       DFLAGS, i2ssc_rx_ws_div_table, 0);

/* ieu */
DEFINE_VTX_GATE(ieu_0_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 24,
		GFLAGS);
DEFINE_VTX_GATE(ieu_0_axi, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 25,
		GFLAGS);
DEFINE_VTX_GATE(ieu_1_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 26,
		GFLAGS);
DEFINE_VTX_GATE(ieu_1_axi, pll_5_d4, CLK_IGNORE_UNUSED, &gate_1_regs, 27,
		GFLAGS);

/* ifpe */
DEFINE_VTX_GATE(ifpe_apb, pll_4_d3, CLK_IGNORE_UNUSED, &gate_1_regs, 28,
		GFLAGS);

/* intc */
DEFINE_VTX_GATE(intc_ahb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_1_regs, 30,
		GFLAGS);

/* irdac */
DEFINE_VTX_GATE(irdac_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_1_regs, 31,
		GFLAGS);

/* ispe */
DEFINE_VTX_GATE(ispe_apb, pll_4_d3, CLK_IGNORE_UNUSED, &gate_2_regs, 0, GFLAGS);
DEFINE_VTX_GATE(ispe_cache, pll_3, CLK_SET_RATE_PARENT, &gate_2_regs, 1, GFLAGS);
DEFINE_VTX_GATE(ispe_daxi, pll_0, CLK_IGNORE_UNUSED, &gate_2_regs, 2, GFLAGS);

static const struct clk_parent_data ispe_gtr_pdata[] = {
	{ .hw = &pll_4_d2.clkr.hw },
	{ .hw = &pll_4_d3.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(ispe_gtr, ispe_gtr_pdata, CLK_IGNORE_UNUSED, 0x248,
			   14, 1, MFLAGS, &gate_2_regs, 3, GFLAGS);

/* jdbe */
DEFINE_VTX_GATE(jdbe_ahb, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED, &gate_2_regs,
		4, GFLAGS);
DEFINE_VTX_GATE(jebe_ahb, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED, &gate_2_regs,
		5, GFLAGS);

/* kdpu */
DEFINE_VTX_GATE(kdpu_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_2_regs, 6, GFLAGS);
DEFINE_VTX_GATE(kdpu_axi, pll_0, CLK_IGNORE_UNUSED, &gate_2_regs, 7, GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(kdpu_core, pll_2, CLK_IGNORE_UNUSED, 0xBC, 4, 4,
			   DFLAGS, kdpu_core_div_table, 0, &gate_2_regs, 8,
			   GFLAGS);

/* mbc */
DEFINE_VTX_GATE(mbc_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_2_regs, 9, GFLAGS);
DEFINE_VTX_GATE(mbc_axi_ctl, pll_5_d5, CLK_IGNORE_UNUSED, &gate_2_regs, 10,
		GFLAGS);
DEFINE_VTX_GATE(mbc_axi_ddr, pll_0, CLK_IGNORE_UNUSED, &gate_2_regs, 11,
		GFLAGS);
DEFINE_VTX_GATE(mbc_hbus_1_slave, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED,
		&gate_2_regs, 12, GFLAGS);
DEFINE_VTX_GATE(mbc_pbus_1_slave, pll_4_d3, CLK_IGNORE_UNUSED, &gate_2_regs, 13,
		GFLAGS);
DEFINE_VTX_GATE(mbc_pbus_2_slave, pll_4_d4, CLK_IGNORE_UNUSED, &gate_2_regs, 14,
		GFLAGS);
DEFINE_VTX_GATE(mbc_pbus_5_slave, pll_5_d10, CLK_IGNORE_UNUSED, &gate_2_regs,
		15, GFLAGS);
DEFINE_VTX_GATE(mbc_pbus_6_slave, pll_5_d10, CLK_IGNORE_UNUSED, &gate_2_regs,
		16, GFLAGS);
DEFINE_VTX_GATE(mbc_xbus_2_master, pll_5_d4, CLK_IGNORE_UNUSED, &gate_2_regs,
		17, GFLAGS);
DEFINE_VTX_GATE(mbc_xbus_3_kernel, pll_5_d3_ahb_1_grp, CLK_IGNORE_UNUSED,
		&gate_2_regs, 18, GFLAGS);

/* mem */
DEFINE_VTX_GATE_PDATA(mem_module_base, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_2_regs, 19, GFLAGS);

/* mipirc */
DEFINE_VTX_GATE(mipirc_0_apb_mmr, pll_5_d10, CLK_IGNORE_UNUSED, &gate_2_regs,
		20, GFLAGS);
DEFINE_VTX_GATE(mipirc_0_common_pel, pll_4_d4, CLK_IGNORE_UNUSED, &gate_2_regs,
		21, GFLAGS);
DEFINE_VTX_GATE(mipirc_0_dev_0_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_2_regs,
		22, GFLAGS);

static const struct clk_parent_data mipirc_0_dev_0_pel_pdata[] = {
	{ .hw = &pll_4_d3.clkr.hw },
	{ .hw = &pll_4_d6.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(mipirc_0_dev_0_pel, mipirc_0_dev_0_pel_pdata,
			   CLK_IGNORE_UNUSED, 0xC0, 0, 1, MFLAGS, &gate_2_regs,
			   23, GFLAGS);

static const struct clk_parent_data mipirc_0_dphy_pdata[] = {
	{ .fw_name = "mipirc_0_dphy", .name = "mipirc_0_dphy" },
};
DEFINE_VTX_GATE_PDATA(mipirc_0_dev_0_phy_0_byte, mipirc_0_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_2_regs, 24, GFLAGS);
DEFINE_VTX_GATE_PDATA(mipirc_0_dev_0_phy_1_byte, mipirc_0_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_2_regs, 25, GFLAGS);
DEFINE_VTX_GATE(mipirc_0_dev_1_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_2_regs,
		26, GFLAGS);

static const struct clk_parent_data mipirc_0_dev_1_pel_pdata[] = {
	{ .hw = &pll_4_d3.clkr.hw },
	{ .hw = &pll_4_d6.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(mipirc_0_dev_1_pel, mipirc_0_dev_1_pel_pdata,
			   CLK_IGNORE_UNUSED, 0xC0, 4, 1, MFLAGS, &gate_2_regs,
			   27, GFLAGS);

DEFINE_VTX_GATE_PDATA(mipirc_0_dev_1_phy_1_byte, mipirc_0_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_2_regs, 28, GFLAGS);
DEFINE_VTX_GATE_PDATA(mipirc_0_phy, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_2_regs, 29, GFLAGS);
DEFINE_VTX_GATE(mipirc_1_apb_mmr, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 0,
		GFLAGS);
DEFINE_VTX_GATE(mipirc_1_common_pel, pll_4_d4, CLK_IGNORE_UNUSED, &gate_3_regs,
		1, GFLAGS);
DEFINE_VTX_GATE(mipirc_1_dev_0_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs,
		2, GFLAGS);

static const struct clk_parent_data mipirc_1_dev_0_pel_pdata[] = {
	{ .hw = &pll_4_d3.clkr.hw },
	{ .hw = &pll_4_d6.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(mipirc_1_dev_0_pel, mipirc_1_dev_0_pel_pdata,
			   CLK_IGNORE_UNUSED, 0xC0, 8, 1, MFLAGS, &gate_3_regs,
			   3, GFLAGS);

static const struct clk_parent_data mipirc_1_dphy_pdata[] = {
	{ .fw_name = "mipirc_1_dphy", .name = "mipirc_1_dphy" },
};
DEFINE_VTX_GATE_PDATA(mipirc_1_dev_0_phy_0_byte, mipirc_1_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_3_regs, 4, GFLAGS);
DEFINE_VTX_GATE_PDATA(mipirc_1_dev_0_phy_1_byte, mipirc_1_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_3_regs, 5, GFLAGS);
DEFINE_VTX_GATE(mipirc_1_dev_1_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs,
		6, GFLAGS);

static const struct clk_parent_data mipirc_1_dev_1_pel_pdata[] = {
	{ .hw = &pll_4_d3.clkr.hw },
	{ .hw = &pll_4_d6.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(mipirc_1_dev_1_pel, mipirc_1_dev_1_pel_pdata,
			   CLK_IGNORE_UNUSED, 0xC0, 12, 1, MFLAGS, &gate_3_regs,
			   7, GFLAGS);
DEFINE_VTX_GATE_PDATA(mipirc_1_dev_1_phy_1_byte, mipirc_1_dphy_pdata,
		      CLK_IGNORE_UNUSED, &gate_3_regs, 8, GFLAGS);
DEFINE_VTX_GATE_PDATA(mipirc_1_phy, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_3_regs, 9, GFLAGS);

/* mipitc */
DEFINE_VTX_GATE(mipitc_apb_mmr, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 10,
		GFLAGS);
DEFINE_VTX_GATE(mipitc_csi2_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 11,
		GFLAGS);
DEFINE_VTX_GATE(mipitc_dsi_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 12,
		GFLAGS);
DEFINE_VTX_GATE(mipitc_pel, pll_8_out1, CLK_IGNORE_UNUSED, &gate_3_regs, 13,
		GFLAGS);
DEFINE_VTX_GATE_PDATA(mipitc_phy, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_3_regs, 14, GFLAGS);

static const struct clk_parent_data mipitc_dphy_pdata[] = {
	{ .fw_name = "mipitc_dphy", .name = "mipitc_dphy" },
};
DEFINE_VTX_GATE_PDATA(mipitc_phy_byte, mipitc_dphy_pdata, CLK_IGNORE_UNUSED,
		      &gate_3_regs, 15, GFLAGS);

/* mshc */
DEFINE_VTX_GATE(mshc_0_ahb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_3_regs, 16,
		GFLAGS);
DEFINE_VTX_GATE(mshc_0_axi, pll_5_d4, CLK_IGNORE_UNUSED, &gate_3_regs, 17,
		GFLAGS);
DEFINE_VTX_GATE(mshc_0_base, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 18,
		GFLAGS);
DEFINE_VTX_GATE(mshc_0_cqetm, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 19,
		GFLAGS);
DEFINE_VTX_GATE(mshc_0_lbt, osc_20m_d20, CLK_IGNORE_UNUSED, &gate_3_regs, 20,
		GFLAGS);
DEFINE_VTX_GATE(mshc_0_tm, osc_20m_d20, CLK_IGNORE_UNUSED, &gate_3_regs, 21,
		GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(mshc_0_tx, pll_5_d5, CLK_IGNORE_UNUSED, 0xC8, 4, 10,
			   DFLAGS, mshc_0_tx_div_table, 0, &gate_3_regs, 22,
			   GFLAGS);
DEFINE_VTX_GATE(mshc_1_ahb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_3_regs, 23,
		GFLAGS);
DEFINE_VTX_GATE(mshc_1_axi, pll_5_d4, CLK_IGNORE_UNUSED, &gate_3_regs, 24,
		GFLAGS);
DEFINE_VTX_GATE(mshc_1_base, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 25,
		GFLAGS);
DEFINE_VTX_GATE(mshc_1_cqetm, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 26,
		GFLAGS);
DEFINE_VTX_GATE(mshc_1_tm, osc_20m_d20, CLK_IGNORE_UNUSED, &gate_3_regs, 27,
		GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(mshc_1_tx, pll_5_d5, CLK_IGNORE_UNUSED, 0xC8, 20, 10,
			   DFLAGS, mshc_1_tx_div_table, 16, &gate_3_regs, 28,
			   GFLAGS);

/* pdma */
DEFINE_VTX_GATE(pdma_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_3_regs, 29,
		GFLAGS);
DEFINE_VTX_GATE(pdma_axi_ddr, pll_0, CLK_IGNORE_UNUSED, &gate_3_regs, 30,
		GFLAGS);

/* pllc */
DEFINE_VTX_GATE(pllc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_3_regs, 31,
		GFLAGS);

/* pmu */
static const struct clk_parent_data rtc_32k_pdata[] = {
	{ .fw_name = "rtc_32k", .name = "rtc_32k" },
};

DEFINE_VTX_GATE(pmu_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 0, GFLAGS);
DEFINE_VTX_GATE_PDATA(pmu_base, rtc_32k_pdata, CLK_IGNORE_UNUSED, &gate_4_regs,
		      1, GFLAGS);

/* scrtu */
DEFINE_VTX_GATE(scrtu_axi_ctl, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 2,
		GFLAGS);
DEFINE_VTX_GATE(scrtu_axi_dma, pll_5_d3, CLK_IGNORE_UNUSED, &gate_4_regs, 3,
		GFLAGS);
DEFINE_VTX_GATE(scrtu_ctr, osc_20m_d20, CLK_IGNORE_UNUSED, &gate_4_regs, 4,
		GFLAGS);
DEFINE_VTX_GATE_PDATA(scrtu_xt1, osc_20m_pdata, CLK_IGNORE_UNUSED, &gate_4_regs,
		      5, GFLAGS);

/* ssic */
DEFINE_VTX_GATE(ssic_0_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 6,
		GFLAGS);
DEFINE_VTX_GATE(ssic_1_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 7,
		GFLAGS);
DEFINE_VTX_GATE(ssic_2_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 8,
		GFLAGS);
DEFINE_VTX_GATE(ssic_3_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 9,
		GFLAGS);

/* sysc */
DEFINE_VTX_GATE(sysc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 10,
		GFLAGS);

/* tmrc */
DEFINE_VTX_GATE(tmrc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 11,
		GFLAGS);

/* uartc */
DEFINE_VTX_GATE(uartc_0_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 12,
		GFLAGS);
DEFINE_VTX_GATE(uartc_0_core, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 13,
		GFLAGS);
DEFINE_VTX_GATE(uartc_1_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 14,
		GFLAGS);
DEFINE_VTX_GATE(uartc_1_core, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 15,
		GFLAGS);
DEFINE_VTX_GATE(uartc_2_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 16,
		GFLAGS);
DEFINE_VTX_GATE(uartc_2_core, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 17,
		GFLAGS);
DEFINE_VTX_GATE(uartc_3_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 18,
		GFLAGS);
DEFINE_VTX_GATE(uartc_3_core, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 19,
		GFLAGS);
DEFINE_VTX_GATE(uartc_4_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 20,
		GFLAGS);
DEFINE_VTX_GATE(uartc_4_core, pll_5_d10, CLK_IGNORE_UNUSED, &gate_4_regs, 21,
		GFLAGS);

/* usb20c */
static const struct clk_parent_data usb_phy_60m_pdata[] = {
	{ .fw_name = "usb_phy_60m", .name = "usb_phy_60m" },
};
static const struct clk_parent_data usb_phy_125m_pdata[] = {
	{ .fw_name = "usb_phy_125m", .name = "usb_phy_125m" },
};

DEFINE_VTX_GATE(usb20c_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 22,
		GFLAGS);
DEFINE_VTX_GATE(usb20c_axi, pll_5_d5, CLK_IGNORE_UNUSED, &gate_4_regs, 23,
		GFLAGS);
DEFINE_VTX_GATE_PDATA(usb20c_phy, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_4_regs, 24, GFLAGS);
DEFINE_VTX_GATE(usb20c_ram, usb20c_axi, CLK_IGNORE_UNUSED, &gate_4_regs, 25,
			 GFLAGS);
DEFINE_VTX_GATE_PDATA(usb20c_utmi, usb_phy_60m_pdata, CLK_IGNORE_UNUSED,
		      &gate_4_regs, 26, GFLAGS);
DEFINE_VTX_FACTOR(usb20c_susp, pmu_base, 0, 1, 1);

/* usb30c */
DEFINE_VTX_GATE(usb30c_apb, pll_5_d5, CLK_IGNORE_UNUSED, &gate_5_regs, 0,
		GFLAGS);
DEFINE_VTX_GATE(usb30c_axi, pll_5_d5, CLK_IGNORE_UNUSED, &gate_5_regs, 1,
		GFLAGS);
DEFINE_VTX_GATE_PDATA(usb30c_phy, osc_20m_pdata, CLK_IGNORE_UNUSED,
		      &gate_5_regs, 2, GFLAGS);
DEFINE_VTX_GATE_PDATA(usb30c_pipe, usb_phy_125m_pdata, CLK_IGNORE_UNUSED,
		      &gate_5_regs, 3, GFLAGS);
DEFINE_VTX_GATE(usb30c_ram, usb30c_axi, CLK_IGNORE_UNUSED, &gate_5_regs, 4,
			 GFLAGS);
DEFINE_VTX_GATE_PDATA(usb30c_utmi, usb_phy_60m_pdata, CLK_IGNORE_UNUSED,
		      &gate_5_regs, 5, GFLAGS);
DEFINE_VTX_FACTOR(usb30c_susp, pmu_base, 0, 1, 1);

/* vic */
DEFINE_VTX_PHASE(vic_o_ref, pll_6_div_vic_ref, CLK_SET_RATE_PARENT, 0xDC, 20, 1,
		 180, PFLAGS);

DEFINE_VTX_GATE(vic_apb, pll_4_d4, CLK_IGNORE_UNUSED, &gate_5_regs, 6, GFLAGS);

static const struct clk_parent_data vic_i_dev_0_phase_pdata[] = {
	{ .fw_name = "vic_i_dev_0", .name = "vic_i_dev_0" },
};
DEFINE_VTX_PHASE_PDATA(vic_i_dev_0_phase, vic_i_dev_0_phase_pdata, 0, 0xDC, 12,
		       1, 180, PFLAGS);
DEFINE_VTX_GATE(vic_0_pel, vic_i_dev_0_phase, CLK_IGNORE_UNUSED, &gate_5_regs,
		8, GFLAGS);

static const struct clk_parent_data vic_i_dev_1_phase_pdata[] = {
	{ .fw_name = "vic_i_dev_1", .name = "vic_i_dev_1" },
};
DEFINE_VTX_PHASE_PDATA(vic_i_dev_1_phase, vic_i_dev_1_phase_pdata, 0, 0xDC, 16,
		       1, 180, PFLAGS);
DEFINE_VTX_GATE(vic_1_pel, vic_i_dev_1_phase, CLK_IGNORE_UNUSED, &gate_5_regs,
		9, GFLAGS);

static const struct clk_parent_data vic_tgen_pdata[] = {
	{ .hw = &pll_7_out1.clkr.hw },
	{ .hw = &pll_8_out1.clkr.hw },
};
DEFINE_VTX_COMPOSITE_NODIV(vic_tgen, vic_tgen_pdata, CLK_IGNORE_UNUSED, 0xDC,
			   24, 1, MFLAGS, &gate_5_regs, 10, GFLAGS);

/* voc */
DEFINE_VTX_PHASE(voc_1_o, pll_7_out1, 0, 0xE0, 0, 2, 90, PFLAGS);
DEFINE_VTX_GATE(voc_0_apb, pll_4_d4, CLK_IGNORE_UNUSED, &gate_5_regs, 11,
		GFLAGS);
DEFINE_VTX_GATE(voc_0_daxi, pll_0, CLK_IGNORE_UNUSED, &gate_5_regs, 12, GFLAGS);
DEFINE_VTX_GATE(voc_0_pel, pll_8_out1, CLK_IGNORE_UNUSED, &gate_5_regs, 13,
		GFLAGS);
DEFINE_VTX_GATE(voc_1_apb, pll_4_d4, CLK_IGNORE_UNUSED, &gate_5_regs, 14,
		GFLAGS);
DEFINE_VTX_GATE(voc_1_daxi, pll_0, CLK_IGNORE_UNUSED, &gate_5_regs, 15, GFLAGS);
DEFINE_VTX_GATE(voc_1_pel, pll_7_out1, CLK_IGNORE_UNUSED, &gate_5_regs, 16,
		GFLAGS);

/* vq7u */
DEFINE_VTX_GATE(vq7u_axi_ctl, pll_5_d5, CLK_IGNORE_UNUSED, &gate_5_regs, 17,
		GFLAGS);
DEFINE_VTX_GATE(vq7u_axi_dma, pll_0, CLK_IGNORE_UNUSED, &gate_5_regs, 18,
		GFLAGS);
DEFINE_VTX_COMPOSITE_NOMUX(vq7u_core, pll_2, CLK_IGNORE_UNUSED, 0xE4, 4, 4,
			   DFLAGS, vq7u_core_div_table, 0, &gate_5_regs, 19,
			   GFLAGS);

/* wdtc */
DEFINE_VTX_GATE(wdtc_apb, pll_5_d10, CLK_IGNORE_UNUSED, &gate_5_regs, 20,
		GFLAGS);

/* internal memory power down */
DEFINE_VTX_GATE_NOPARENT(mem_pwr_brc, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 0,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_brc_rom, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 1,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_core_0, CLK_IGNORE_UNUSED,
			 &mem_pwr_0_regs, 2, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_core_1, CLK_IGNORE_UNUSED,
			 &mem_pwr_0_regs, 3, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_core_2, CLK_IGNORE_UNUSED,
			 &mem_pwr_0_regs, 4, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_core_3, CLK_IGNORE_UNUSED,
			 &mem_pwr_0_regs, 5, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_dsu, CLK_IGNORE_UNUSED, &mem_pwr_0_regs,
			 6, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ca55u_gic_600, CLK_IGNORE_UNUSED,
			 &mem_pwr_0_regs, 7, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_cdce, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 8,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ddrnsdmc, CLK_IGNORE_UNUSED, &mem_pwr_0_regs,
			 9, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_dmac_0, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 10,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_dmac_1, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 11,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_eqosc, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 12,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ieu_0, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 13,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ieu_1, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 14,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ifpe, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 15,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_ispe, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 16,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_jdbe, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 17,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_jebe, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 18,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_kdpu, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 19,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mbc, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 20,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mipirc_0, CLK_IGNORE_UNUSED, &mem_pwr_0_regs,
			 21, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mipirc_1, CLK_IGNORE_UNUSED, &mem_pwr_0_regs,
			 22, MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mipitc, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 23,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mshc_0, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 24,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_mshc_1, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 25,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_pdmac, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 26,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_scrtu, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 27,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_usb20c, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 28,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_usb30c, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 29,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_vic, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 30,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_voc_0, CLK_IGNORE_UNUSED, &mem_pwr_0_regs, 31,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_voc_1, CLK_IGNORE_UNUSED, &mem_pwr_1_regs, 0,
			 MEM_PWR_FLAGS);
DEFINE_VTX_GATE_NOPARENT(mem_pwr_vq7u, CLK_IGNORE_UNUSED, &mem_pwr_1_regs, 1,
			 MEM_PWR_FLAGS);

static struct vtx_clk_regmap *leipzig_rclks[] = {
	[CLK_OSC_20M_D20] = &osc_20m_d20.clkr,
	[CLK_PLL_0] = &pll_0.clkr,
	[CLK_PLL_1] = &pll_1.clkr,
	[CLK_PLL_2] = &pll_2.clkr,
	[CLK_PLL_3] = &pll_3.clkr,
	[CLK_PLL_4] = &pll_4.clkr,
	[CLK_PLL_5] = &pll_5.clkr,
	[CLK_PLL_6] = &pll_6.clkr,
	[CLK_PLL_7] = &pll_7.clkr,
	[CLK_PLL_8] = &pll_8.clkr,
	[CLK_PLL_9] = &pll_9.clkr,
	[CLK_PLL_4_D2] = &pll_4_d2.clkr,
	[CLK_PLL_4_D3] = &pll_4_d3.clkr,
	[CLK_PLL_4_D4] = &pll_4_d4.clkr,
	[CLK_PLL_4_D6] = &pll_4_d6.clkr,
	[CLK_PLL_4_D8] = &pll_4_d8.clkr,
	[CLK_PLL_5_D3] = &pll_5_d3.clkr,
	[CLK_PLL_5_D4] = &pll_5_d4.clkr,
	[CLK_PLL_5_D5] = &pll_5_d5.clkr,
	[CLK_PLL_5_D6] = &pll_5_d6.clkr,
	[CLK_PLL_5_D8] = &pll_5_d8.clkr,
	[CLK_PLL_5_D10] = &pll_5_d10.clkr,
	[CLK_PLL_5_D16] = &pll_5_d16.clkr,
	[CLK_PLL_5_D20] = &pll_5_d20.clkr,
	[CLK_PLL_5_OUT2] = &pll_5_out2.clkr,
	[CLK_PLL_5_OUT2_D4] = &pll_5_out2_d4.clkr,
	[CLK_PLL_5_OUT2_D10] = &pll_5_out2_d10.clkr,
	[CLK_PLL_5_OUT2_D20] = &pll_5_out2_d20.clkr,
	[CLK_PLL_5_OUT2_D200] = &pll_5_out2_d200.clkr,
	[CLK_PLL_5_D3_AHB_1_GRP] = &pll_5_d3_ahb_1_grp.clkr,
	[CLK_PLL_6_DIV_VIC_REF] = &pll_6_div_vic_ref.clkr,
	[CLK_PLL_7_OUT1] = &pll_7_out1.clkr,
	[CLK_PLL_8_OUT1] = &pll_8_out1.clkr,
	[CLK_PLL_9_DIV_I2SSC_INT_RX_SERIAL] =
		&pll_9_div_i2ssc_int_rx_serial.clkr,
	[CLK_PLL_9_DIV_I2SSC_INT_TX_SERIAL] =
		&pll_9_div_i2ssc_int_tx_serial.clkr,
	[CLK_ADCDCC_APB] = &adcdcc_apb.clkr,
	[CLK_ADCDCC_RX] = &adcdcc_rx.clkr,
	[CLK_ADCDCC_TX] = &adcdcc_tx.clkr,
	[CLK_AGPOC_APB] = &agpoc_apb.clkr,
	[CLK_BRC_AXI] = &brc_axi.clkr,
	[CLK_CA55U_AXI_CTL] = &ca55u_axi_ctl.clkr,
	[CLK_CA55U_CORE_0] = &ca55u_core_0.clkr,
	[CLK_CA55U_CORE_1] = &ca55u_core_1.clkr,
	[CLK_CA55U_CORE_2] = &ca55u_core_2.clkr,
	[CLK_CA55U_CORE_3] = &ca55u_core_3.clkr,
	[CLK_CA55U_DBG] = &ca55u_dbg.clkr,
	[CLK_CA55U_GIC] = &ca55u_gic.clkr,
	[CLK_CA55U_PCLK] = &ca55u_pclk.clkr,
	[CLK_CA55U_SCU] = &ca55u_scu.clkr,
	[CLK_CDCE_APB] = &cdce_apb.clkr,
	[CLK_CDCE_AXI] = &cdce_axi.clkr,
	[CLK_CDCE_BPU] = &cdce_bpu.clkr,
	[CLK_CDCE_VCE] = &cdce_vce.clkr,
	[CLK_DMAC_0_AHB] = &dmac_0_ahb.clkr,
	[CLK_DMAC_1_AHB] = &dmac_1_ahb.clkr,
	[CLK_EQOSC_I_RX_D2] = &eqosc_i_rx_d2.clkr,
	[CLK_EQOSC_I_RX_D20] = &eqosc_i_rx_d20.clkr,
	[CLK_EQOSC_RMODE_0_MUX] = &eqosc_rmode_0_mux.clkr,
	[CLK_EQOSC_RMODE_1_MUX] = &eqosc_rmode_1_mux.clkr,
	[CLK_EQOSC_RMODE_2_MUX] = &eqosc_rmode_2_mux.clkr,
	[CLK_EQOSC_RMII_PHASE_MUX] = &eqosc_rmii_phase_mux.clkr,
	[CLK_EQOSC_FREQ_MUX] = &eqosc_freq_mux.clkr,
	[CLK_EQOS_AXI_DMA] = &eqos_axi_dma.clkr,
	[CLK_EQOS_AXI_MMR] = &eqos_axi_mmr.clkr,
	[CLK_EQOSC_PTP_REF] = &eqosc_ptp_ref.clkr,
	[CLK_EQOSC_RMII] = &eqosc_rmii.clkr,
	[CLK_EQOSC_RX] = &eqosc_rx.clkr,
	[CLK_EQOSC_TX] = &eqosc_tx.clkr,
	[CLK_EQOSC_O_REF] = &eqosc_o_ref.clkr,
	[CLK_EQOSC_O_TX] = &eqosc_o_tx.clkr,
	[CLK_GPIOC_0_APB] = &gpioc_0_apb.clkr,
	[CLK_GPIOC_1_APB] = &gpioc_1_apb.clkr,
	[CLK_GPIOC_2_APB] = &gpioc_2_apb.clkr,
	[CLK_I2C_0_APB] = &i2c_0_apb.clkr,
	[CLK_I2C_1_APB] = &i2c_1_apb.clkr,
	[CLK_I2C_2_APB] = &i2c_2_apb.clkr,
	[CLK_DDR_MMR_APB] = &ddr_mmr_apb.clkr,
	[CLK_DDR_APM_APB] = &ddr_apm_apb.clkr,
	[CLK_DDR_AXI] = &ddr_axi.clkr,
	[CLK_DDR_DPM_0] = &ddr_dpm_0.clkr,
	[CLK_DDR_DPM_1] = &ddr_dpm_1.clkr,
	[CLK_DDR_DPM_2] = &ddr_dpm_2.clkr,
	[CLK_DDR_DPM_3] = &ddr_dpm_3.clkr,
	[CLK_DDR_DPM_4] = &ddr_dpm_4.clkr,
	[CLK_DDR_DPM_5] = &ddr_dpm_5.clkr,
	[CLK_DDR_DPM_6] = &ddr_dpm_6.clkr,
	[CLK_DDR_DPM_7] = &ddr_dpm_7.clkr,
	[CLK_DDR_DPM_8] = &ddr_dpm_8.clkr,
	[CLK_DDR_DPM_9] = &ddr_dpm_9.clkr,
	[CLK_DDR_DPM_10] = &ddr_dpm_10.clkr,
	[CLK_DDR_DPM_11] = &ddr_dpm_11.clkr,
	[CLK_DDR_DPM_12] = &ddr_dpm_12.clkr,
	[CLK_DDR_DPM_13] = &ddr_dpm_13.clkr,
	[CLK_DDR_DPM_14] = &ddr_dpm_14.clkr,
	[CLK_DDR_DPM_15] = &ddr_dpm_15.clkr,
	[CLK_DDR_MCTL_APB] = &ddr_mctl_apb.clkr,
	[CLK_DDR_PUB_APB] = &ddr_pub_apb.clkr,
	[CLK_I2SSC_O_MCLK] = &i2ssc_o_mclk.clkr,
	[CLK_I2SSC_APB] = &i2ssc_apb.clkr,
	[CLK_I2SSC_RX_SCLK] = &i2ssc_rx_sclk.clkr,
	[CLK_I2SSC_TX_SCLK] = &i2ssc_tx_sclk.clkr,
	[CLK_I2SSC_TX_WS] = &i2ssc_tx_ws.clkr,
	[CLK_I2SSC_RX_WS] = &i2ssc_rx_ws.clkr,
	[CLK_IEU_0_APB] = &ieu_0_apb.clkr,
	[CLK_IEU_0_AXI] = &ieu_0_axi.clkr,
	[CLK_IEU_1_APB] = &ieu_1_apb.clkr,
	[CLK_IEU_1_AXI] = &ieu_1_axi.clkr,
	[CLK_IFPE_APB] = &ifpe_apb.clkr,
	[CLK_INTC_AHB] = &intc_ahb.clkr,
	[CLK_IRDAC_APB] = &irdac_apb.clkr,
	[CLK_ISPE_APB] = &ispe_apb.clkr,
	[CLK_ISPE_CACHE] = &ispe_cache.clkr,
	[CLK_ISPE_DAXI] = &ispe_daxi.clkr,
	[CLK_ISPE_GTR] = &ispe_gtr.clkr,
	[CLK_JDBE_AHB] = &jdbe_ahb.clkr,
	[CLK_JEBE_AHB] = &jebe_ahb.clkr,
	[CLK_KDPU_APB] = &kdpu_apb.clkr,
	[CLK_KDPU_AXI] = &kdpu_axi.clkr,
	[CLK_KDPU_CORE] = &kdpu_core.clkr,
	[CLK_MBC_APB] = &mbc_apb.clkr,
	[CLK_MBC_AXI_CTL] = &mbc_axi_ctl.clkr,
	[CLK_MBC_AXI_DDR] = &mbc_axi_ddr.clkr,
	[CLK_MBC_HBUS_1_SLAVE] = &mbc_hbus_1_slave.clkr,
	[CLK_MBC_PBUS_1_SLAVE] = &mbc_pbus_1_slave.clkr,
	[CLK_MBC_PBUS_2_SLAVE] = &mbc_pbus_2_slave.clkr,
	[CLK_MBC_PBUS_5_SLAVE] = &mbc_pbus_5_slave.clkr,
	[CLK_MBC_PBUS_6_SLAVE] = &mbc_pbus_6_slave.clkr,
	[CLK_MBC_XBUS_2_MASTER] = &mbc_xbus_2_master.clkr,
	[CLK_MBC_XBUS_3_KERNEL] = &mbc_xbus_3_kernel.clkr,
	[CLK_MEM_MODULE_BASE] = &mem_module_base.clkr,
	[CLK_MIPIRC_0_APB_MMR] = &mipirc_0_apb_mmr.clkr,
	[CLK_MIPIRC_0_COMMON_PEL] = &mipirc_0_common_pel.clkr,
	[CLK_MIPIRC_0_DEV_0_APB] = &mipirc_0_dev_0_apb.clkr,
	[CLK_MIPIRC_0_DEV_0_PEL] = &mipirc_0_dev_0_pel.clkr,
	[CLK_MIPIRC_0_DEV_0_PHY_0_BYTE] = &mipirc_0_dev_0_phy_0_byte.clkr,
	[CLK_MIPIRC_0_DEV_0_PHY_1_BYTE] = &mipirc_0_dev_0_phy_1_byte.clkr,
	[CLK_MIPIRC_0_DEV_1_APB] = &mipirc_0_dev_1_apb.clkr,
	[CLK_MIPIRC_0_DEV_1_PEL] = &mipirc_0_dev_1_pel.clkr,
	[CLK_MIPIRC_0_DEV_1_PHY_1_BYTE] = &mipirc_0_dev_1_phy_1_byte.clkr,
	[CLK_MIPIRC_0_PHY] = &mipirc_0_phy.clkr,
	[CLK_MIPIRC_1_APB_MMR] = &mipirc_1_apb_mmr.clkr,
	[CLK_MIPIRC_1_COMMON_PEL] = &mipirc_1_common_pel.clkr,
	[CLK_MIPIRC_1_DEV_0_APB] = &mipirc_1_dev_0_apb.clkr,
	[CLK_MIPIRC_1_DEV_0_PEL] = &mipirc_1_dev_0_pel.clkr,
	[CLK_MIPIRC_1_DEV_0_PHY_0_BYTE] = &mipirc_1_dev_0_phy_0_byte.clkr,
	[CLK_MIPIRC_1_DEV_0_PHY_1_BYTE] = &mipirc_1_dev_0_phy_1_byte.clkr,
	[CLK_MIPIRC_1_DEV_1_APB] = &mipirc_1_dev_1_apb.clkr,
	[CLK_MIPIRC_1_DEV_1_PEL] = &mipirc_1_dev_1_pel.clkr,
	[CLK_MIPIRC_1_DEV_1_PHY_1_BYTE] = &mipirc_1_dev_1_phy_1_byte.clkr,
	[CLK_MIPIRC_1_PHY] = &mipirc_1_phy.clkr,
	[CLK_MIPITC_APB_MMR] = &mipitc_apb_mmr.clkr,
	[CLK_MIPITC_CSI2_APB] = &mipitc_csi2_apb.clkr,
	[CLK_MIPITC_DSI_APB] = &mipitc_dsi_apb.clkr,
	[CLK_MIPITC_PEL] = &mipitc_pel.clkr,
	[CLK_MIPITC_PHY] = &mipitc_phy.clkr,
	[CLK_MIPITC_PHY_BYTE] = &mipitc_phy_byte.clkr,
	[CLK_MSHC_0_AHB] = &mshc_0_ahb.clkr,
	[CLK_MSHC_0_AXI] = &mshc_0_axi.clkr,
	[CLK_MSHC_0_BASE] = &mshc_0_base.clkr,
	[CLK_MSHC_0_CQETM] = &mshc_0_cqetm.clkr,
	[CLK_MSHC_0_LBT] = &mshc_0_lbt.clkr,
	[CLK_MSHC_0_TM] = &mshc_0_tm.clkr,
	[CLK_MSHC_0_TX] = &mshc_0_tx.clkr,
	[CLK_MSHC_1_AHB] = &mshc_1_ahb.clkr,
	[CLK_MSHC_1_AXI] = &mshc_1_axi.clkr,
	[CLK_MSHC_1_BASE] = &mshc_1_base.clkr,
	[CLK_MSHC_1_CQETM] = &mshc_1_cqetm.clkr,
	[CLK_MSHC_1_TM] = &mshc_1_tm.clkr,
	[CLK_MSHC_1_TX] = &mshc_1_tx.clkr,
	[CLK_PDMA_APB] = &pdma_apb.clkr,
	[CLK_PDMA_AXI_DDR] = &pdma_axi_ddr.clkr,
	[CLK_PLLC_APB] = &pllc_apb.clkr,
	[CLK_PMU_APB] = &pmu_apb.clkr,
	[CLK_PMU_BASE] = &pmu_base.clkr,
	[CLK_SCRTU_AXI_CTL] = &scrtu_axi_ctl.clkr,
	[CLK_SCRTU_AXI_DMA] = &scrtu_axi_dma.clkr,
	[CLK_SCRTU_CTR] = &scrtu_ctr.clkr,
	[CLK_SCRTU_XT1] = &scrtu_xt1.clkr,
	[CLK_SSIC_0_APB] = &ssic_0_apb.clkr,
	[CLK_SSIC_1_APB] = &ssic_1_apb.clkr,
	[CLK_SSIC_2_APB] = &ssic_2_apb.clkr,
	[CLK_SSIC_3_APB] = &ssic_3_apb.clkr,
	[CLK_SYSC_APB] = &sysc_apb.clkr,
	[CLK_TMRC_APB] = &tmrc_apb.clkr,
	[CLK_UARTC_0_APB] = &uartc_0_apb.clkr,
	[CLK_UARTC_0_CORE] = &uartc_0_core.clkr,
	[CLK_UARTC_1_APB] = &uartc_1_apb.clkr,
	[CLK_UARTC_1_CORE] = &uartc_1_core.clkr,
	[CLK_UARTC_2_APB] = &uartc_2_apb.clkr,
	[CLK_UARTC_2_CORE] = &uartc_2_core.clkr,
	[CLK_UARTC_3_APB] = &uartc_3_apb.clkr,
	[CLK_UARTC_3_CORE] = &uartc_3_core.clkr,
	[CLK_UARTC_4_APB] = &uartc_4_apb.clkr,
	[CLK_UARTC_4_CORE] = &uartc_4_core.clkr,
	[CLK_USB20C_APB] = &usb20c_apb.clkr,
	[CLK_USB20C_AXI] = &usb20c_axi.clkr,
	[CLK_USB20C_PHY] = &usb20c_phy.clkr,
	[CLK_USB20C_RAM] = &usb20c_ram.clkr,
	[CLK_USB20C_UTMI] = &usb20c_utmi.clkr,
	[CLK_USB30C_APB] = &usb30c_apb.clkr,
	[CLK_USB30C_AXI] = &usb30c_axi.clkr,
	[CLK_USB30C_PHY] = &usb30c_phy.clkr,
	[CLK_USB30C_PIPE] = &usb30c_pipe.clkr,
	[CLK_USB30C_RAM] = &usb30c_ram.clkr,
	[CLK_USB30C_UTMI] = &usb30c_utmi.clkr,
	[CLK_VIC_O_REF] = &vic_o_ref.clkr,
	[CLK_VIC_APB] = &vic_apb.clkr,
	[CLK_VIC_I_DEV_0_PHASE] = &vic_i_dev_0_phase.clkr,
	[CLK_VIC_0_PEL] = &vic_0_pel.clkr,
	[CLK_VIC_I_DEV_1_PHASE] = &vic_i_dev_1_phase.clkr,
	[CLK_VIC_1_PEL] = &vic_1_pel.clkr,
	[CLK_VIC_TGEN] = &vic_tgen.clkr,
	[CLK_VOC_1_O] = &voc_1_o.clkr,
	[CLK_VOC_0_APB] = &voc_0_apb.clkr,
	[CLK_VOC_0_DAXI] = &voc_0_daxi.clkr,
	[CLK_VOC_0_PEL] = &voc_0_pel.clkr,
	[CLK_VOC_1_APB] = &voc_1_apb.clkr,
	[CLK_VOC_1_DAXI] = &voc_1_daxi.clkr,
	[CLK_VOC_1_PEL] = &voc_1_pel.clkr,
	[CLK_VQ7U_AXI_CTL] = &vq7u_axi_ctl.clkr,
	[CLK_VQ7U_AXI_DMA] = &vq7u_axi_dma.clkr,
	[CLK_VQ7U_CORE] = &vq7u_core.clkr,
	[CLK_WDTC_APB] = &wdtc_apb.clkr,
	[CLK_USB20C_SUSP] = &usb20c_susp.clkr,
	[CLK_USB30C_SUSP] = &usb30c_susp.clkr,

	/* internal memory power down */
	[MEM_PWR_BRC] = &mem_pwr_brc.clkr,
	[MEM_PWR_BRC_ROM] = &mem_pwr_brc_rom.clkr,
	[MEM_PWR_CA55U_CORE_0] = &mem_pwr_ca55u_core_0.clkr,
	[MEM_PWR_CA55U_CORE_1] = &mem_pwr_ca55u_core_1.clkr,
	[MEM_PWR_CA55U_CORE_2] = &mem_pwr_ca55u_core_2.clkr,
	[MEM_PWR_CA55U_CORE_3] = &mem_pwr_ca55u_core_3.clkr,
	[MEM_PWR_CA55U_DSU] = &mem_pwr_ca55u_dsu.clkr,
	[MEM_PWR_CA55U_GIC_600] = &mem_pwr_ca55u_gic_600.clkr,
	[MEM_PWR_CDCE] = &mem_pwr_cdce.clkr,
	[MEM_PWR_DDRNSDMC] = &mem_pwr_ddrnsdmc.clkr,
	[MEM_PWR_DMAC_0] = &mem_pwr_dmac_0.clkr,
	[MEM_PWR_DMAC_1] = &mem_pwr_dmac_1.clkr,
	[MEM_PWR_EQOSC] = &mem_pwr_eqosc.clkr,
	[MEM_PWR_IEU_0] = &mem_pwr_ieu_0.clkr,
	[MEM_PWR_IEU_1] = &mem_pwr_ieu_1.clkr,
	[MEM_PWR_IFPE] = &mem_pwr_ifpe.clkr,
	[MEM_PWR_ISPE] = &mem_pwr_ispe.clkr,
	[MEM_PWR_JDBE] = &mem_pwr_jdbe.clkr,
	[MEM_PWR_JEBE] = &mem_pwr_jebe.clkr,
	[MEM_PWR_KDPU] = &mem_pwr_kdpu.clkr,
	[MEM_PWR_MBC] = &mem_pwr_mbc.clkr,
	[MEM_PWR_MIPIRC_0] = &mem_pwr_mipirc_0.clkr,
	[MEM_PWR_MIPIRC_1] = &mem_pwr_mipirc_1.clkr,
	[MEM_PWR_MIPITC] = &mem_pwr_mipitc.clkr,
	[MEM_PWR_MSHC_0] = &mem_pwr_mshc_0.clkr,
	[MEM_PWR_MSHC_1] = &mem_pwr_mshc_1.clkr,
	[MEM_PWR_PDMAC] = &mem_pwr_pdmac.clkr,
	[MEM_PWR_SCRTU] = &mem_pwr_scrtu.clkr,
	[MEM_PWR_USB20C] = &mem_pwr_usb20c.clkr,
	[MEM_PWR_USB30C] = &mem_pwr_usb30c.clkr,
	[MEM_PWR_VIC] = &mem_pwr_vic.clkr,
	[MEM_PWR_VOC_0] = &mem_pwr_voc_0.clkr,
	[MEM_PWR_VOC_1] = &mem_pwr_voc_1.clkr,
	[MEM_PWR_VQ7U] = &mem_pwr_vq7u.clkr,

};

static void __init leipzig_clk_ini_div_table(void)
{
	int i;

	/* setup pll_6_div_vic_ref_div_table */
	for (i = 0; i < (ARRAY_SIZE(pll_6_div_vic_ref_div_table) - 1); ++i) {
		pll_6_div_vic_ref_div_table[i].val = i;
		pll_6_div_vic_ref_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	pll_6_div_vic_ref_div_table[ARRAY_SIZE(pll_6_div_vic_ref_div_table) - 1]
		.val = 0;
	pll_6_div_vic_ref_div_table[ARRAY_SIZE(pll_6_div_vic_ref_div_table) - 1]
		.div = 0;

	/* setup pll_9_div_i2ssc_int_rx_serial_div_table */
	for (i = 0;
	     i < (ARRAY_SIZE(pll_9_div_i2ssc_int_rx_serial_div_table) - 1);
	     ++i) {
		pll_9_div_i2ssc_int_rx_serial_div_table[i].val = i;
		pll_9_div_i2ssc_int_rx_serial_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	pll_9_div_i2ssc_int_rx_serial_div_table
		[ARRAY_SIZE(pll_9_div_i2ssc_int_rx_serial_div_table) - 1]
			.val = 0;
	pll_9_div_i2ssc_int_rx_serial_div_table
		[ARRAY_SIZE(pll_9_div_i2ssc_int_rx_serial_div_table) - 1]
			.div = 0;

	/* setup pll_9_div_i2ssc_int_tx_serial_div_table */
	for (i = 0;
	     i < (ARRAY_SIZE(pll_9_div_i2ssc_int_tx_serial_div_table) - 1);
	     ++i) {
		pll_9_div_i2ssc_int_tx_serial_div_table[i].val = i;
		pll_9_div_i2ssc_int_tx_serial_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	pll_9_div_i2ssc_int_tx_serial_div_table
		[ARRAY_SIZE(pll_9_div_i2ssc_int_tx_serial_div_table) - 1]
			.val = 0;
	pll_9_div_i2ssc_int_tx_serial_div_table
		[ARRAY_SIZE(pll_9_div_i2ssc_int_tx_serial_div_table) - 1]
			.div = 0;

	/* setup adcdcc_rx_div_table */
	for (i = 0; i < (ARRAY_SIZE(adcdcc_rx_div_table) - 1); ++i) {
		adcdcc_rx_div_table[i].val = i;
		adcdcc_rx_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	adcdcc_rx_div_table[ARRAY_SIZE(adcdcc_rx_div_table) - 1].val = 0;
	adcdcc_rx_div_table[ARRAY_SIZE(adcdcc_rx_div_table) - 1].div = 0;

	/* setup adcdcc_tx_div_table */
	for (i = 0; i < (ARRAY_SIZE(adcdcc_tx_div_table) - 1); ++i) {
		adcdcc_tx_div_table[i].val = i;
		adcdcc_tx_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	adcdcc_tx_div_table[ARRAY_SIZE(adcdcc_tx_div_table) - 1].val = 0;
	adcdcc_tx_div_table[ARRAY_SIZE(adcdcc_tx_div_table) - 1].div = 0;

	/* setup ca55u_core_0_div_table */
	for (i = 0; i < (ARRAY_SIZE(ca55u_core_0_div_table) - 1); ++i) {
		ca55u_core_0_div_table[i].val = i;
		ca55u_core_0_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	ca55u_core_0_div_table[ARRAY_SIZE(ca55u_core_0_div_table) - 1].val = 0;
	ca55u_core_0_div_table[ARRAY_SIZE(ca55u_core_0_div_table) - 1].div = 0;

	/* setup ca55u_core_1_div_table */
	for (i = 0; i < (ARRAY_SIZE(ca55u_core_1_div_table) - 1); ++i) {
		ca55u_core_1_div_table[i].val = i;
		ca55u_core_1_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	ca55u_core_1_div_table[ARRAY_SIZE(ca55u_core_1_div_table) - 1].val = 0;
	ca55u_core_1_div_table[ARRAY_SIZE(ca55u_core_1_div_table) - 1].div = 0;

	/* setup ca55u_core_2_div_table */
	for (i = 0; i < (ARRAY_SIZE(ca55u_core_2_div_table) - 1); ++i) {
		ca55u_core_2_div_table[i].val = i;
		ca55u_core_2_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	ca55u_core_2_div_table[ARRAY_SIZE(ca55u_core_2_div_table) - 1].val = 0;
	ca55u_core_2_div_table[ARRAY_SIZE(ca55u_core_2_div_table) - 1].div = 0;

	/* setup ca55u_core_3_div_table */
	for (i = 0; i < (ARRAY_SIZE(ca55u_core_3_div_table) - 1); ++i) {
		ca55u_core_3_div_table[i].val = i;
		ca55u_core_3_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	ca55u_core_3_div_table[ARRAY_SIZE(ca55u_core_3_div_table) - 1].val = 0;
	ca55u_core_3_div_table[ARRAY_SIZE(ca55u_core_3_div_table) - 1].div = 0;

	/* setup i2ssc_o_mclk_div_table */
	for (i = 0; i < (ARRAY_SIZE(i2ssc_o_mclk_div_table) - 1); ++i) {
		i2ssc_o_mclk_div_table[i].val = i;
		i2ssc_o_mclk_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	i2ssc_o_mclk_div_table[ARRAY_SIZE(i2ssc_o_mclk_div_table) - 1].val = 0;
	i2ssc_o_mclk_div_table[ARRAY_SIZE(i2ssc_o_mclk_div_table) - 1].div = 0;

	/* setup i2ssc_tx_ws_div_table */
	for (i = 0; i < (ARRAY_SIZE(i2ssc_tx_ws_div_table) - 1); ++i) {
		i2ssc_tx_ws_div_table[i].val = i;
		i2ssc_tx_ws_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	i2ssc_tx_ws_div_table[ARRAY_SIZE(i2ssc_tx_ws_div_table) - 1].val = 0;
	i2ssc_tx_ws_div_table[ARRAY_SIZE(i2ssc_tx_ws_div_table) - 1].div = 0;

	/* setup i2ssc_rx_ws_div_table */
	for (i = 0; i < (ARRAY_SIZE(i2ssc_rx_ws_div_table) - 1); ++i) {
		i2ssc_rx_ws_div_table[i].val = i;
		i2ssc_rx_ws_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	i2ssc_rx_ws_div_table[ARRAY_SIZE(i2ssc_rx_ws_div_table) - 1].val = 0;
	i2ssc_rx_ws_div_table[ARRAY_SIZE(i2ssc_rx_ws_div_table) - 1].div = 0;

	/* setup mshc_0_tx_div_table */
	for (i = 0; i < (ARRAY_SIZE(mshc_0_tx_div_table) - 1); ++i) {
		mshc_0_tx_div_table[i].val = i;
		mshc_0_tx_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	mshc_0_tx_div_table[ARRAY_SIZE(mshc_0_tx_div_table) - 1].val = 0;
	mshc_0_tx_div_table[ARRAY_SIZE(mshc_0_tx_div_table) - 1].div = 0;

	/* setup mshc_1_tx_div_table */
	for (i = 0; i < (ARRAY_SIZE(mshc_1_tx_div_table) - 1); ++i) {
		mshc_1_tx_div_table[i].val = i;
		mshc_1_tx_div_table[i].div = (i + 1) * 2;
	}
	/* add sentinel at the end */
	mshc_1_tx_div_table[ARRAY_SIZE(mshc_1_tx_div_table) - 1].val = 0;
	mshc_1_tx_div_table[ARRAY_SIZE(mshc_1_tx_div_table) - 1].div = 0;

	/* setup kdpu_core_div_table */
	for (i = 0; i < (ARRAY_SIZE(kdpu_core_div_table) - 1); ++i) {
		kdpu_core_div_table[i].val = i;
		kdpu_core_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	kdpu_core_div_table[ARRAY_SIZE(kdpu_core_div_table) - 1].val = 0;
	kdpu_core_div_table[ARRAY_SIZE(kdpu_core_div_table) - 1].div = 0;

	/* setup vq7u_core_div_table */
	for (i = 0; i < (ARRAY_SIZE(vq7u_core_div_table) - 1); ++i) {
		vq7u_core_div_table[i].val = i;
		vq7u_core_div_table[i].div = (i + 1);
	}
	/* add sentinel at the end */
	vq7u_core_div_table[ARRAY_SIZE(vq7u_core_div_table) - 1].val = 0;
	vq7u_core_div_table[ARRAY_SIZE(vq7u_core_div_table) - 1].div = 0;

}

static const struct vtx_clk_desc clk_leipzig_desc = {
	.rclks = leipzig_rclks,
	.num_rclks = ARRAY_SIZE(leipzig_rclks),
};

static int clk_leipzig_probe(struct platform_device *pdev)
{
	/* initial divider table */
	leipzig_clk_ini_div_table();

	vtx_clk_probe(pdev, &clk_leipzig_desc);
	return 0;
}

static const struct of_device_id clk_leipzig_match_table[] = {
	{.compatible = "vatics,leipzig-clk"},
	{ }
};
MODULE_DEVICE_TABLE(of, clk_leipzig_match_table);

static struct platform_driver clk_leipzig_driver = {
	.probe		= clk_leipzig_probe,
	.driver		= {
		.name	= "clk-leipzig",
		.of_match_table = clk_leipzig_match_table,
	},
};

static int __init clk_leipzig_init(void)
{
	return platform_driver_register(&clk_leipzig_driver);
}
core_initcall(clk_leipzig_init);

static void __exit clk_leipzig_exit(void)
{
	platform_driver_unregister(&clk_leipzig_driver);
}
module_exit(clk_leipzig_exit);
