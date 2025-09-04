// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VTX_CLK_COMPOSITE_H_
#define CLK_VTX_CLK_COMPOSITE_H_

#include <linux/io.h>
#include <linux/clk-provider.h>

#include "clk.h"
#include "clk-gate.h"
#include "clk-mux.h"
#include "clk-div.h"


struct vtx_clk_regmap_composite {
	const struct clk_ops	ops;

	struct clk_hw	*mux_hw;
	struct clk_hw	*rate_hw;
	struct clk_hw	*gate_hw;

	const struct clk_ops	*mux_ops;
	const struct clk_ops	*rate_ops;
	const struct clk_ops	*gate_ops;

	struct vtx_clk_regmap clkr;
};

#define DEFINE_VTX_COM_GATE(_name, _gregs, _gbit, _gflags)     \
	static struct vtx_clk_regmap_gate _name##_com_gate = { \
		.regs = _gregs,                                \
		.bit_idx = _gbit,                              \
		.flags = _gflags,                              \
	}

#define DEFINE_VTX_COM_DIV(_name, _dr, _ds, _dw, _df, _dt, _du)   \
	static struct vtx_clk_regmap_div _name##_com_div = { \
		.reg = _dr,                                  \
		.shift = _ds,                                \
		.width = _dw,                                \
		.flags = _df,                                \
		.table = _dt,                                \
		.update = _du,                               \
	}

#define DEFINE_VTX_COM_MUX(_name, _mr, _ms, _mw, _mf)        \
	static struct vtx_clk_regmap_mux _name##_com_mux = { \
		.reg = _mr,                                  \
		.shift = _ms,                                \
		.width = _mw,                                \
		.flags = _mf,                                \
	}

#define DEFINE_VTX_COMPOSITE_NODIV(_name, _pdata, _flags, _mr, _ms, _mw, _mf, \
				   _gregs, _gbit, _gflags)                    \
	DEFINE_VTX_COM_MUX(_name, _mr, _ms, _mw, _mf);                        \
	DEFINE_VTX_COM_GATE(_name, _gregs, _gbit, _gflags);                   \
	static struct vtx_clk_regmap_composite _name = {                      \
		.mux_hw = &_name##_com_mux.clkr.hw,                           \
		.gate_hw = &_name##_com_gate.clkr.hw,                         \
		.mux_ops = &vtx_clk_regmap_mux_ops,                           \
		.gate_ops = &vtx_clk_regmap_gate_ops,                         \
		.clkr.hw.init =                                               \
			&(struct clk_init_data){                              \
				.name = #_name,                               \
				.flags = _flags,                              \
				.ops = &vtx_clk_composite_nodiv_ops,          \
				.parent_data = _pdata,                        \
				.num_parents = ARRAY_SIZE(_pdata),            \
			},                                                    \
		.clkr.type = vtx_clk_type_composite,                          \
	}

#define DEFINE_VTX_COMPOSITE_NOMUX(_name, _pname, _flags, _dr, _ds, _dw, _df, \
				   _dt, _du, _gregs, _gbit, _gflags)          \
	DEFINE_VTX_COM_DIV(_name, _dr, _ds, _dw, _df, _dt, _du);              \
	DEFINE_VTX_COM_GATE(_name, _gregs, _gbit, _gflags);                   \
	static struct vtx_clk_regmap_composite _name = {                      \
		.rate_hw = &_name##_com_div.clkr.hw,                          \
		.gate_hw = &_name##_com_gate.clkr.hw,                         \
		.rate_ops = &vtx_clk_regmap_div_ops,                          \
		.gate_ops = &vtx_clk_regmap_gate_ops,                         \
		.clkr.hw.init =                                               \
			&(struct clk_init_data){                              \
				.name = #_name,                               \
				.flags = _flags,                              \
				.ops = &vtx_clk_composite_nomux_ops,          \
				.parent_hws =                                 \
					(const struct clk_hw *[]){            \
						&_pname.clkr.hw,              \
					},                                    \
				.num_parents = 1,                             \
			},                                                    \
		.clkr.type = vtx_clk_type_composite,                          \
	}

extern const struct clk_ops vtx_clk_composite_nodiv_ops;
extern const struct clk_ops vtx_clk_composite_nomux_ops;

extern void vtx_clk_composite_setup_regmap(struct vtx_clk_regmap *rclk);

#endif // CLK_VTX_CLK_COMPOSITE_H_
