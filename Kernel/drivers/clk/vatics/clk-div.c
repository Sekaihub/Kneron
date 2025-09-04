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
#include "clk-div.h"

static inline struct vtx_clk_regmap_div *
to_vtx_clk_regmap_div(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_regmap_div,
			    clkr);
}

static unsigned long vtx_clk_regmap_div_recalc_rate(struct clk_hw *hw,
						unsigned long prate)
{
	struct vtx_clk_regmap_div *div = to_vtx_clk_regmap_div(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int val;
	int ret;

	ret = regmap_read(clkr->regmap, div->reg, &val);
	if (ret)
		/* Gives a hint that something is wrong */
		return 0;

	val >>= div->shift;
	val &= clk_div_mask(div->width);
	return divider_recalc_rate(hw, prate, val, div->table, div->flags,
				   div->width);
}

static int vtx_clk_regmap_div_determine_rate(struct clk_hw *hw,
					 struct clk_rate_request *req)
{
	struct vtx_clk_regmap_div *div = to_vtx_clk_regmap_div(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int val;
	int ret;

	/* if read only, just return current value */
	if (div->flags & CLK_DIVIDER_READ_ONLY) {
		ret = regmap_read(clkr->regmap, div->reg, &val);
		if (ret)
			return ret;

		val >>= div->shift;
		val &= clk_div_mask(div->width);

		return divider_ro_determine_rate(hw, req, div->table,
						 div->width, div->flags, val);
	}

	return divider_determine_rate(hw, req, div->table, div->width,
				      div->flags);
}

static int vtx_clk_regmap_div_set_rate(struct clk_hw *hw, unsigned long rate,
				   unsigned long parent_rate)
{
	struct vtx_clk_regmap_div *div = to_vtx_clk_regmap_div(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int mask = clk_div_mask(div->width) << div->shift;
	unsigned int val;
	int ret;

	ret = divider_get_val(rate, parent_rate, div->table, div->width,
			      div->flags);
	if (ret < 0)
		return ret;

	regmap_read(clkr->regmap, div->reg, &val);

	ret <<= div->shift;
	val = val & ~mask;
	val |= ret & mask;
	val |= (0x1u << div->update);
	pr_debug("%s: %s val 0x%x\n", __func__, __clk_get_name(hw->clk), val);

	return regmap_write(clkr->regmap, div->reg, val);
};

const struct clk_ops vtx_clk_regmap_div_ops = {
	.recalc_rate = vtx_clk_regmap_div_recalc_rate,
	.determine_rate = vtx_clk_regmap_div_determine_rate,
	.set_rate = vtx_clk_regmap_div_set_rate,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_div_ops);

const struct clk_ops vtx_clk_regmap_div_ro_ops = {
	.recalc_rate = vtx_clk_regmap_div_recalc_rate,
	.determine_rate = vtx_clk_regmap_div_determine_rate,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_div_ro_ops);
