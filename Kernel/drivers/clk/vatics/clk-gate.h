// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_GATE_H_
#define CLK_VTX_CLK_GATE_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* gating clock */

/*
 * @set_reg:	offset of set gatting
 * @clr_reg:	offset of clear gatting
 * @sta_reg:	offset of status gatting
 */
struct vtx_gate_regs {
	u32 sta_reg;
	u32 clr_reg;
	u32 set_reg;
};

/**
 * struct vtx_clk_regmap_gate - gating clock
 *
 * @bit_idx:	single bit controlling gate
 * @flags:	hardware-specific flags
 * @regs:	register controlling gate (set, clear, status)
 * @bit_idx:	single bit controlling gate
 * @flags:	hardware-specific flags
 * @lock:	register lock
 *
 * Clock which can gate its output.  Implements .enable & .disable
 *
 * Flags:
 * CLK_GATE_SET_TO_DISABLE - by default this clock sets the bit at bit_idx to
 *	enable the clock.  Setting this flag does the opposite: setting the bit
 *	disable the clock and clearing it enables the clock
 */
struct vtx_clk_regmap_gate {
	const struct vtx_gate_regs *regs;
	u8 bit_idx;
	u8 flags;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_GATE(_name, _pname, _flags, _gregs, _gbit, _gflags) \
	static struct vtx_clk_regmap_gate _name = {                    \
		.regs = _gregs,                                        \
		.bit_idx = _gbit,                                      \
		.flags = _gflags,                                      \
		.clkr.hw.init =                                        \
			&(struct clk_init_data){                       \
				.name = #_name,                        \
				.flags = _flags,                       \
				.ops = &vtx_clk_regmap_gate_ops,       \
				.parent_hws =                          \
					(const struct clk_hw *[]){     \
						&_pname.clkr.hw,       \
					},                             \
				.num_parents = 1,                      \
			},                                             \
		.clkr.type = vtx_clk_type_gate,                        \
	}

#define DEFINE_VTX_GATE_PDATA(_name, _pdata, _flags, _gregs, _gbit, _gflags) \
	static struct vtx_clk_regmap_gate _name = {                          \
		.regs = _gregs,                                              \
		.bit_idx = _gbit,                                            \
		.flags = _gflags,                                            \
		.clkr.hw.init =                                              \
			&(struct clk_init_data){                             \
				.name = #_name,                              \
				.flags = _flags,                             \
				.ops = &vtx_clk_regmap_gate_ops,             \
				.parent_data = _pdata,                       \
				.num_parents = 1,                            \
			},                                                   \
		.clkr.type = vtx_clk_type_gate,                              \
	}

#define DEFINE_VTX_GATE_NOPARENT(_name, _flags, _gregs, _gbit, _gflags) \
	static struct vtx_clk_regmap_gate _name = {                     \
		.regs = _gregs,                                         \
		.bit_idx = _gbit,                                       \
		.flags = _gflags,                                       \
		.clkr.hw.init =                                         \
			&(struct clk_init_data){                        \
				.name = #_name,                         \
				.flags = _flags,                        \
				.ops = &vtx_clk_regmap_gate_ops,        \
				.parent_names = NULL,                   \
				.num_parents = 0,                       \
			},                                              \
		.clkr.type = vtx_clk_type_gate,                         \
	}

extern const struct clk_ops vtx_clk_regmap_gate_ops;

#endif // CLK_VTX_CLK_GATE_H_
