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
#include "clk-gate.h"

static inline struct vtx_clk_regmap_gate *
to_vtx_clk_regmap_gate(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_regmap_gate,
			    clkr);
}

static int vtx_clk_regmap_gate_is_enabled(struct clk_hw *hw)
{
	struct vtx_clk_regmap_gate *gate = to_vtx_clk_regmap_gate(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	u32 val;

	regmap_read(clkr->regmap, gate->regs->sta_reg, &val);

	/* if a set bit disables this clk, flip it before masking */
	if (gate->flags & CLK_GATE_SET_TO_DISABLE)
		val ^= BIT(gate->bit_idx);

	val &= BIT(gate->bit_idx);

	pr_debug("%s: %s is_enabled %d\n", __func__,
		 __clk_get_name(hw->clk), val);
	return val ? 1 : 0;
}

static void vtx_clk_regmap_gate_endisable(struct clk_hw *hw, int enable)
{
	struct vtx_clk_regmap_gate *gate = to_vtx_clk_regmap_gate(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	int set = gate->flags & CLK_GATE_SET_TO_DISABLE ? 1 : 0;

	set ^= enable;

	if (set)
		regmap_write(clkr->regmap, gate->regs->set_reg,
			     BIT(gate->bit_idx));
	else
		regmap_write(clkr->regmap, gate->regs->clr_reg,
			     BIT(gate->bit_idx));
}

static int vtx_clk_regmap_gate_enable(struct clk_hw *hw)
{
	int ret;

	vtx_clk_regmap_gate_endisable(hw, 1);

	ret = vtx_clk_regmap_gate_is_enabled(hw);
	if (ret)
		return 0;
	else
		return -EINVAL;
}

static void vtx_clk_regmap_gate_disable(struct clk_hw *hw)
{
	vtx_clk_regmap_gate_endisable(hw, 0);
}

const struct clk_ops vtx_clk_regmap_gate_ops = {
	.is_enabled = vtx_clk_regmap_gate_is_enabled,
	.enable = vtx_clk_regmap_gate_enable,
	.disable = vtx_clk_regmap_gate_disable,
};
EXPORT_SYMBOL_GPL(vtx_clk_regmap_gate_ops);

