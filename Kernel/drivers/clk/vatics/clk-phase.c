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
#include "clk-phase.h"

static inline struct vtx_clk_regmap_phase *
to_vtx_clk_regmap_phase(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_regmap_phase,
			    clkr);
}

static int vtx_clk_regmap_phase_get_phase(struct clk_hw *hw)
{
	struct vtx_clk_regmap_phase *phase = to_vtx_clk_regmap_phase(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int mask = GENMASK(phase->width - 1, 0);
	unsigned int val;
	int ret;

	ret = regmap_read(clkr->regmap, phase->reg, &val);
	if (ret)
		return ret;

	val >>= phase->shift;
	val &= mask;
	return val * phase->step_degrees;
}

static int vtx_clk_regmap_phase_set_phase(struct clk_hw *hw, int degrees)
{
	struct vtx_clk_regmap_phase *phase = to_vtx_clk_regmap_phase(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	unsigned int mask = GENMASK(phase->width - 1, 0);
	unsigned int val;

	val = (degrees / phase->step_degrees);

	return regmap_update_bits(clkr->regmap, phase->reg,
				  mask << phase->shift,
				  val << phase->shift);
}

const struct clk_ops vtx_clk_regmap_phase_ops = {
	.get_phase = vtx_clk_regmap_phase_get_phase,
	.set_phase = vtx_clk_regmap_phase_set_phase,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_phase_ops);
