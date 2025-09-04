// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_MUX_H_
#define CLK_VTX_CLK_MUX_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* multiplexer clock */
/**
 * struct vtx_clk_regmap_mux - regmap backed multiplexer clock specific data
 *
 * @reg:	offset of controlling multiplexer
 * @shift:	shift to multiplexer bit field
 * @flags:	hardware-specific flags
 *
 * Clock with multiple selectable parents.  Implements .get_parent, .set_parent
 * and .determine_rate
 *
 * Flags:
 * Same as clk_divider except CLK_MUX_HIWORD_MASK which is ignored
 */
struct vtx_clk_regmap_mux {
	u32 reg;
	u32 shift;
	u32 width;
	u8 flags;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_MUX(_name, _pdata, _flags, _mr, _ms, _mw, _mf)  \
	static struct vtx_clk_regmap_mux _name = {                 \
		.reg = _mr,                                        \
		.shift = _ms,                                      \
		.width = _mw,                                      \
		.flags = _mf,                                      \
		.clkr.hw.init =                                    \
			&(struct clk_init_data){                   \
				.name = #_name,                    \
				.flags = _flags,                   \
				.ops = &vtx_clk_regmap_mux_ops,    \
				.parent_data = _pdata,             \
				.num_parents = ARRAY_SIZE(_pdata), \
			},                                         \
		.clkr.type = vtx_clk_type_mux,                     \
	}

#define DEFINE_VTX_MUX_RO(_name, _pdata, _flags, _mr, _ms, _mw, _mf) \
	static struct vtx_clk_regmap_mux _name = {                   \
		.reg = _mr,                                          \
		.shift = _ms,                                        \
		.width = _mw,                                        \
		.flags = _mf,                                        \
		.clkr.hw.init =                                      \
			&(struct clk_init_data){                     \
				.name = #_name,                      \
				.flags = _flags,                     \
				.ops = &vtx_clk_regmap_mux_ro_ops,   \
				.parent_data = _pdata,               \
				.num_parents = ARRAY_SIZE(_pdata),   \
			},                                           \
		.clkr.type = vtx_clk_type_mux,                       \
	}

extern const struct clk_ops vtx_clk_regmap_mux_ops;
extern const struct clk_ops vtx_clk_regmap_mux_ro_ops;


#endif // CLK_VTX_CLK_MUX_H_
