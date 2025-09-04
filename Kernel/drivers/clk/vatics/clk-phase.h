// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_PHASE_H_
#define CLK_VTX_CLK_PHASE_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"

/* phase clock */

struct vtx_clk_regmap_phase {
	u32 reg;
	u32 shift;
	u32 width;
	u32 step_degrees;
	u8 flags;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_PHASE(_name, _pname, _flags, _pr, _ps, _pw, _pd, _pf) \
	static struct vtx_clk_regmap_phase _name = {                     \
		.reg = _pr,                                              \
		.shift = _ps,                                            \
		.width = _pw,                                            \
		.step_degrees = _pd,                                     \
		.flags = _pf,                                            \
		.clkr.hw.init =                                          \
			&(struct clk_init_data){                         \
				.name = #_name,                          \
				.flags = _flags,                         \
				.ops = &vtx_clk_regmap_phase_ops,        \
				.parent_hws =                            \
					(const struct clk_hw *[]){       \
						&_pname.clkr.hw,         \
					},                               \
				.num_parents = 1,                        \
			},                                               \
		.clkr.type = vtx_clk_type_div,                           \
	}

#define DEFINE_VTX_PHASE_PDATA(_name, _pdata, _flags, _pr, _ps, _pw, _pd, _pf) \
	static struct vtx_clk_regmap_phase _name = {                           \
		.reg = _pr,                                                    \
		.shift = _ps,                                                  \
		.width = _pw,                                                  \
		.step_degrees = _pd,                                           \
		.flags = _pf,                                                  \
		.clkr.hw.init =                                                \
			&(struct clk_init_data){                               \
				.name = #_name,                                \
				.flags = _flags,                               \
				.ops = &vtx_clk_regmap_phase_ops,              \
				.parent_data = _pdata,                         \
				.num_parents = 1,                              \
			},                                                     \
		.clkr.type = vtx_clk_type_div,                                 \
	}

extern const struct clk_ops vtx_clk_regmap_phase_ops;

#endif // CLK_VTX_CLK_PHASE_H_
