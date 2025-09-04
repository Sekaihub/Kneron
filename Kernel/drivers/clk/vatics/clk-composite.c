// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <linux/slab.h>
#include <linux/bitops.h>
#include <linux/regmap.h>
#include <linux/clk.h>
#include <linux/clk-provider.h>

#include "clk.h"
#include "clk-composite.h"
#include "clk-gate.h"
#include "clk-mux.h"
#include "clk-div.h"

static inline struct vtx_clk_regmap_composite *
to_vtx_clk_regmap_composite(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw),
			    struct vtx_clk_regmap_composite, clkr);
}

static u8 vtx_clk_composite_get_parent(struct clk_hw *hw)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *mux_ops = composite->mux_ops;
	struct clk_hw *mux_hw = composite->mux_hw;

	__clk_hw_set_clk(mux_hw, hw);

	return mux_ops->get_parent(mux_hw);
}

static int vtx_clk_composite_set_parent(struct clk_hw *hw, u8 index)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *mux_ops = composite->mux_ops;
	struct clk_hw *mux_hw = composite->mux_hw;

	__clk_hw_set_clk(mux_hw, hw);

	return mux_ops->set_parent(mux_hw, index);
}

static unsigned long vtx_clk_composite_recalc_rate(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *rate_ops = composite->rate_ops;
	struct clk_hw *rate_hw = composite->rate_hw;

	__clk_hw_set_clk(rate_hw, hw);

	return rate_ops->recalc_rate(rate_hw, parent_rate);
}

static int vtx_clk_composite_determine_rate(struct clk_hw *hw,
					struct clk_rate_request *req)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *rate_ops = composite->rate_ops;
	const struct clk_ops *mux_ops = composite->mux_ops;
	struct clk_hw *rate_hw = composite->rate_hw;
	struct clk_hw *mux_hw = composite->mux_hw;

	if (rate_hw && rate_ops &&
	    (rate_ops->determine_rate || rate_ops->round_rate) &&
	    mux_hw && mux_ops && mux_ops->set_parent) {
		return 0;
	} else if (rate_hw && rate_ops && rate_ops->determine_rate) {
		__clk_hw_set_clk(rate_hw, hw);
		return rate_ops->determine_rate(rate_hw, req);
	} else if (mux_hw && mux_ops && mux_ops->determine_rate) {
		__clk_hw_set_clk(mux_hw, hw);
		return mux_ops->determine_rate(mux_hw, req);
	}

	pr_err("clk: clk_composite_determine_rate function called, but no mux or rate callback set!\n");
	return -EINVAL;
}

static int vtx_clk_composite_set_rate(struct clk_hw *hw, unsigned long rate,
			       unsigned long parent_rate)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *rate_ops = composite->rate_ops;
	struct clk_hw *rate_hw = composite->rate_hw;

	__clk_hw_set_clk(rate_hw, hw);

	return rate_ops->set_rate(rate_hw, rate, parent_rate);
}

static int vtx_clk_composite_is_enabled(struct clk_hw *hw)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *gate_ops = composite->gate_ops;
	struct clk_hw *gate_hw = composite->gate_hw;

	__clk_hw_set_clk(gate_hw, hw);

	return gate_ops->is_enabled(gate_hw);
}

static int vtx_clk_composite_enable(struct clk_hw *hw)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *gate_ops = composite->gate_ops;
	struct clk_hw *gate_hw = composite->gate_hw;

	__clk_hw_set_clk(gate_hw, hw);

	return gate_ops->enable(gate_hw);
}

static void vtx_clk_composite_disable(struct clk_hw *hw)
{
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(hw);
	const struct clk_ops *gate_ops = composite->gate_ops;
	struct clk_hw *gate_hw = composite->gate_hw;

	__clk_hw_set_clk(gate_hw, hw);

	gate_ops->disable(gate_hw);
}

const struct clk_ops vtx_clk_composite_nodiv_ops = {
	.get_parent = vtx_clk_composite_get_parent,
	.set_parent = vtx_clk_composite_set_parent,
	.determine_rate = vtx_clk_composite_determine_rate,
	.is_enabled = vtx_clk_composite_is_enabled,
	.enable = vtx_clk_composite_enable,
	.disable = vtx_clk_composite_disable,
};
EXPORT_SYMBOL_GPL(vtx_clk_composite_nodiv_ops);

const struct clk_ops vtx_clk_composite_nomux_ops = {
	.recalc_rate = vtx_clk_composite_recalc_rate,
	.determine_rate = vtx_clk_composite_determine_rate,
	.set_rate = vtx_clk_composite_set_rate,
	.is_enabled = vtx_clk_composite_is_enabled,
	.enable = vtx_clk_composite_enable,
	.disable = vtx_clk_composite_disable,
};
EXPORT_SYMBOL_GPL(vtx_clk_composite_nomux_ops);

void vtx_clk_composite_setup_regmap(struct vtx_clk_regmap *rclk)
{
	struct vtx_clk_regmap *clkr;
	struct vtx_clk_regmap_composite *composite =
		to_vtx_clk_regmap_composite(&rclk->hw);
	struct regmap *regmap = rclk->regmap;

	if (composite->mux_hw) {
		clkr = to_vtx_clk_regmap(composite->mux_hw);
		clkr->regmap = regmap;
	}

	if (composite->rate_hw) {
		clkr = to_vtx_clk_regmap(composite->rate_hw);
		clkr->regmap = regmap;
	}

	if (composite->gate_hw) {
		clkr = to_vtx_clk_regmap(composite->gate_hw);
		clkr->regmap = regmap;
	}
}
EXPORT_SYMBOL_GPL(vtx_clk_composite_setup_regmap);
