// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_DIV_H_
#define CLK_VTX_CLK_DIV_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* divider clock */
/**
 * struct vtx_clk_regmap_div - divider clock
 *
 * @reg:	register containing the divider
 * @shift:	shift to the divider bit field
 * @width:	width of the divider bit field
 * @table:	array of value/divider pairs, last entry should have div = 0
 * @flags:	hardware-specific flags
 * @update:	update request bit
 *
 * Flags:
 * Same as clk_divider except CLK_DIVIDER_HIWORD_MASK which is ignored
 */
struct vtx_clk_regmap_div {
	int reg;
	u8 shift;
	u8 width;
	const struct clk_div_table *table;
	u8 flags;
	u8 update;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_DIV(_name, _pname, _flags, _dr, _ds, _dw, _df, _dt, _du) \
	static struct vtx_clk_regmap_div _name = {                     \
		.reg = _dr,                                            \
		.shift = _ds,                                          \
		.width = _dw,                                          \
		.flags = _df,                                          \
		.table = _dt,                                          \
		.update = _du,                                         \
		.clkr.hw.init =                                        \
			&(struct clk_init_data){                       \
				.name = #_name,                        \
				.flags = _flags,                       \
				.ops = &vtx_clk_regmap_div_ops,        \
				.parent_hws =                          \
					(const struct clk_hw *[]){     \
						&_pname.clkr.hw,       \
					},                             \
				.num_parents = 1,                      \
			},                                             \
		.clkr.type = vtx_clk_type_div,                         \
	}

extern const struct clk_ops vtx_clk_regmap_div_ops;
extern const struct clk_ops vtx_clk_regmap_div_ro_ops;

#endif // CLK_VTX_CLK_DIV_H_
