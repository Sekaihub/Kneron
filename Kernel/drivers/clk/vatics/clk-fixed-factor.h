// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_FIXED_FACTOR_H_
#define CLK_VTX_CLK_FIXED_FACTOR_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* fixed factor clock */

/**
 * struct clk_fixed_factor - fixed multiplier and divider clock
 *
 * @mult:	multiplier
 * @div:	divider
 *
 * Clock with a fixed multiplier and divider. The output frequency is the
 * parent clock rate divided by div and multiplied by mult.
 * Implements .recalc_rate, .set_rate and .round_rate
 */

struct vtx_clk_fixed_factor {
	unsigned int	mult;
	unsigned int	div;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_FACTOR(_name, _pname, _flags, _fm, _fd)         \
	static struct vtx_clk_fixed_factor _name = {               \
		.mult = _fm,                                       \
		.div = _fd,                                        \
		.clkr.hw.init =                                    \
			&(struct clk_init_data){                   \
				.name = #_name,                    \
				.flags = _flags,                   \
				.ops = &vtx_clk_fixed_factor_ops,  \
				.parent_hws =                      \
					(const struct clk_hw *[]){ \
						&_pname.clkr.hw,   \
					},                         \
				.num_parents = 1,                  \
			},                                         \
		.clkr.type = vtx_clk_type_factor,                  \
	}

#define DEFINE_VTX_FACTOR_PDATA(_name, _pdata, _flags, _fm, _fd)   \
	static struct vtx_clk_fixed_factor _name = {               \
		.mult = _fm,                                       \
		.div = _fd,                                        \
		.clkr.hw.init =                                    \
			&(struct clk_init_data){                   \
				.name = #_name,                    \
				.flags = _flags,                   \
				.ops = &vtx_clk_fixed_factor_ops,  \
				.parent_data = _pdata,             \
				.num_parents = 1,                  \
			},                                         \
		.clkr.type = vtx_clk_type_factor,                  \
	}

extern const struct clk_ops vtx_clk_fixed_factor_ops;

#endif // CLK_VTX_CLK_FIXED_FACTOR_H_
