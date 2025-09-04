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
#include "clk-mux.h"

static inline struct vtx_clk_regmap_mux *
to_vtx_clk_regmap_mux(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_regmap_mux,
			    clkr);
}

static u8 vtx_clk_regmap_mux_get_parent(struct clk_hw *hw)
{
	struct vtx_clk_regmap_mux *mux = to_vtx_clk_regmap_mux(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int mask = GENMASK(mux->width - 1, 0);
	unsigned int val;
	int ret;

	ret = regmap_read(clkr->regmap, mux->reg, &val);
	if (ret)
		return ret;

	val >>= mux->shift;
	val &= mask;
	return clk_mux_val_to_index(hw, NULL, mux->flags, val);
}

static int vtx_clk_regmap_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct vtx_clk_regmap_mux *mux = to_vtx_clk_regmap_mux(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int val = clk_mux_index_to_val(NULL, mux->flags, index);
	unsigned int mask = GENMASK(mux->width - 1, 0);

	return regmap_update_bits(clkr->regmap, mux->reg,
				  mask << mux->shift,
				  val << mux->shift);
}

static int vtx_clk_regmap_mux_determine_rate(struct clk_hw *hw,
					 struct clk_rate_request *req)
{
	struct vtx_clk_regmap_mux *mux = to_vtx_clk_regmap_mux(hw);

	return clk_mux_determine_rate_flags(hw, req, mux->flags);
}

const struct clk_ops vtx_clk_regmap_mux_ops = {
	.get_parent = vtx_clk_regmap_mux_get_parent,
	.set_parent = vtx_clk_regmap_mux_set_parent,
	.determine_rate = vtx_clk_regmap_mux_determine_rate,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_mux_ops);

const struct clk_ops vtx_clk_regmap_mux_ro_ops = {
	.get_parent = vtx_clk_regmap_mux_get_parent,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_mux_ro_ops);

