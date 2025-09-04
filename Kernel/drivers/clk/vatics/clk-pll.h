// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_PLL_H_
#define CLK_VTX_CLK_PLL_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* PLL */
struct vtx_clk_pll_freq_table {
	unsigned long	input_rate;
	unsigned long	output_rate;
	union {
		struct {
			/* for leipzig */
			unsigned int ref_div;
			unsigned int post_div1;
			unsigned int post_div2;
			unsigned int fb_int_div;
			unsigned int fb_frac_div;
		};
	};
};

/**
 * struct div_nmp - offset and width of m,n and p fields
 *
 * @fb_int_div_shift:	shift to the feedback divider bit field
 * @fb_int_div_width:	width of the feedback divider bit field
 */
struct div_nmp {
	u8		fb_int_div_shift;
	u8		fb_int_div_width;
	u8		post_div2_shift;
	u8		post_div2_width;
	u8		post_div1_shift;
	u8		post_div1_width;
	u8		ref_div_shift;
	u8		ref_div_width;
	u8		fb_frac_div_shift;
	u8		fb_frac_div_width;
};


/**
 * struct vtx_clk_regmap_pll_data - PLL clock
 *
 * @pll_reg:			offset of the register for configuring the PLL.
 * @ctrl_reg:			offset of the General Control MMR
 * @stat_reg:			offset of the Status MMR
 * @div_0_reg:			offset of the Divider Control 0 MMR
 * @div_1_reg:			offset of the Status Control 1 MMR
 * @ssm_reg:			offset of the Spread Spectrum Modulation MMR
 * @dcc_reg:			offset of the Deskew Calibration Control MMR
 * @pll_flags:			PLL flags
 * @div_nmp:			offsets and widths on n, m and p fields
 * @freq_table:			array of frequencies supported by PLL
 * @fixed_rate:			PLL rate if it is fixed
 *
 * Flags:
 * VTX_PLL_FRAC - PLL has fraction function.
 */
struct vtx_clk_regmap_pll {
	u32		pll_reg;
	u32		ctrl_reg;
	u32		stat_reg;
	u32		div_0_reg;
	u32		div_1_reg;
	u32		ssm_reg;
	u32		dcc_reg;
	u32		pll_flags;
	const struct div_nmp	*div_nmp;
	const struct vtx_clk_pll_freq_table	*freq_table;
	unsigned long	fixed_rate;

	struct vtx_clk_regmap clkr;
};

#define VTX_PLL_UPDATE BIT(0)
#define VTX_PLL_NOISE_CANCEL_DAC BIT(2)
#define VTX_PLL_FRAC BIT(3)
#define VTX_PLL_SLOW_CLK_OUT BIT(4)
#define VTX_PLL_PWR_DOWN BIT(8)
#define VTX_PLL_BYPASS BIT(9)
#define VTX_PLL_POSTDIV_0_CLK BIT(10)
#define VTX_PLL_POSTDIV_1_CLK BIT(11)
#define VTX_PLL_GATING_OUT_CLK BIT(16)
#define VTX_PLL_GATING_OUT_DIV_CLK BIT(17)


#define DEFINE_VTX_PLL(_name, _pname, _reg, _flags)         \
	static struct vtx_clk_regmap_pll _name = {          \
		.pll_reg = _reg,                            \
		.ctrl_reg = PLL_CTRL,                       \
		.stat_reg = PLL_STAT,                       \
		.div_0_reg = PLL_DIV_0,                     \
		.div_1_reg = PLL_DIV_1,                     \
		.ssm_reg = PLL_SSM,                         \
		.dcc_reg = PLL_DCC,                         \
		.div_nmp = &pll_nmp,                        \
		.freq_table = _name##_freq_table,           \
		.pll_flags = _flags,                        \
		.clkr.hw.init =                             \
			&(struct clk_init_data){            \
				.name = #_name,             \
				.flags = CLK_IGNORE_UNUSED, \
				.ops = &vtx_clk_pll_ops,    \
				.parent_data = _pname,      \
				.num_parents = 1,           \
			},                                  \
		.clkr.type = vtx_clk_type_pll,              \
	}

extern const struct clk_ops vtx_clk_pll_ops;


#endif // CLK_VTX_CLK_PLL_H_
