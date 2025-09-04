// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <linux/slab.h>
#include <linux/bitops.h>
#include <linux/clk.h>
#include <linux/clk-provider.h>

#include "clk.h"
#include "clk-fixed-factor.h"

static inline struct vtx_clk_fixed_factor *
to_vtx_clk_fixed_factor(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_fixed_factor,
			    clkr);
}

/*
 * DOC: basic fixed multiplier and divider clock that cannot gate
 *
 * Traits of this clock:
 * prepare - clk_prepare only ensures that parents are prepared
 * enable - clk_enable only ensures that parents are enabled
 * rate - rate is fixed.  clk->rate = parent->rate / div * mult
 * parent - fixed parent.  No clk_set_parent support
 */

static unsigned long vtx_clk_factor_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	struct vtx_clk_fixed_factor *fix = to_vtx_clk_fixed_factor(hw);
	unsigned long long rate;

	rate = (unsigned long long)parent_rate * fix->mult;
	do_div(rate, fix->div);
	return (unsigned long)rate;
}

static long vtx_clk_factor_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *prate)
{
	struct vtx_clk_fixed_factor *fix = to_vtx_clk_fixed_factor(hw);

	if (clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT) {
		unsigned long best_parent;

		best_parent = (rate / fix->mult) * fix->div;
		*prate = clk_hw_round_rate(clk_hw_get_parent(hw), best_parent);
	}

	return (*prate / fix->div) * fix->mult;
}

static int vtx_clk_factor_set_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long parent_rate)
{
	/*
	 * We must report success but we can do so unconditionally because
	 * clk_factor_round_rate returns values that ensure this call is a
	 * nop.
	 */

	return 0;
}

const struct clk_ops vtx_clk_fixed_factor_ops = {
	.round_rate = vtx_clk_factor_round_rate,
	.set_rate = vtx_clk_factor_set_rate,
	.recalc_rate = vtx_clk_factor_recalc_rate,
};
EXPORT_SYMBOL_GPL(vtx_clk_fixed_factor_ops);
