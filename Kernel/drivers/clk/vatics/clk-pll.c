// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <asm/div64.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/clk-provider.h>
#include <linux/iopoll.h>
#include <linux/regmap.h>
#include <linux/clk.h>

#include "clk.h"
#include "clk-pll.h"


#define mask(w) ((1 << (w)) - 1)
#define ref_div_mask(p) mask(p->div_nmp->ref_div_width)
#define post_div1_mask(p) mask(p->div_nmp->post_div1_width)
#define post_div2_mask(p) mask(p->div_nmp->post_div2_width)
#define fb_int_div_mask(p) mask(p->div_nmp->fb_int_div_width)
#define fb_frac_div_mask(p) mask(p->div_nmp->fb_frac_div_width)

#define ref_div_shift(p) ((p)->div_nmp->ref_div_shift)
#define post_div1_shift(p) ((p)->div_nmp->post_div1_shift)
#define post_div2_shift(p) ((p)->div_nmp->post_div2_shift)
#define fb_int_div_shift(p) ((p)->div_nmp->fb_int_div_shift)
#define fb_frac_div_shift(p) ((p)->div_nmp->fb_frac_div_shift)

static inline struct vtx_clk_regmap_pll *
to_vtx_clk_regmap_pll(struct clk_hw *hw)
{
	return container_of(to_vtx_clk_regmap(hw), struct vtx_clk_regmap_pll,
			    clkr);
}

static int vtx_clk_pll_wait_for_lock(struct vtx_clk_regmap *clkr,
					 struct vtx_clk_regmap_pll *pll)
{
	u32 val;

	regmap_read(clkr->regmap, pll->pll_reg + pll->ctrl_reg, &val);

	if ((pll->pll_flags & VTX_PLL_FRAC))
		val |= (VTX_PLL_UPDATE | VTX_PLL_FRAC);
	else
		val |= (VTX_PLL_UPDATE);

	regmap_write(clkr->regmap, pll->pll_reg + pll->ctrl_reg, val);

	/* wait update complete */
	while (regmap_read(clkr->regmap, pll->pll_reg + pll->ctrl_reg, &val) &
	       VTX_PLL_UPDATE) {
		// do nothing
	}

	// TODO wait pll lock ?

	return 0;
}

static void _update_pll_mnp(struct vtx_clk_regmap *clkr,
			struct vtx_clk_regmap_pll *pll,
			 struct vtx_clk_pll_freq_table *cfg)
{
	u32 val;

	/* update divider control 0 */
	val = ((cfg->ref_div << ref_div_shift(pll)) |
		(cfg->post_div1 << post_div1_shift(pll)) |
		(cfg->post_div2 << post_div2_shift(pll)) |
		(cfg->fb_int_div << fb_int_div_shift(pll)));

	regmap_write(clkr->regmap, pll->pll_reg + pll->div_0_reg, val);

	/* update divider control 0 */
	if ((pll->pll_flags & VTX_PLL_FRAC)) {
		val = (cfg->fb_frac_div << fb_frac_div_shift(pll));
		regmap_write(clkr->regmap, pll->pll_reg + pll->div_1_reg, val);
	}
}

static void _get_pll_mnp(struct clk_hw *hw,
			 struct vtx_clk_pll_freq_table *cfg)
{
	u32 val;
	struct vtx_clk_regmap_pll *pll = to_vtx_clk_regmap_pll(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	const struct div_nmp *div_nmp = pll->div_nmp;

	regmap_read(clkr->regmap, pll->pll_reg + pll->div_0_reg, &val);

	cfg->ref_div = (val >> div_nmp->ref_div_shift) & ref_div_mask(pll);
	cfg->post_div1 = (val >> div_nmp->post_div1_shift)
		& post_div1_mask(pll);
	cfg->post_div2 = (val >> div_nmp->post_div2_shift)
		& post_div2_mask(pll);
	cfg->fb_int_div = (val >> div_nmp->fb_int_div_shift)
		& fb_int_div_mask(pll);

	if ((pll->pll_flags & VTX_PLL_FRAC)) {
		regmap_read(clkr->regmap, pll->pll_reg + pll->div_1_reg, &val);
		cfg->fb_frac_div = (val >> div_nmp->fb_frac_div_shift)
			& fb_frac_div_mask(pll);
	} else {
		cfg->fb_frac_div = 0;
	}

	pr_debug("%s: pll(offset 0x%x) for ref_div: %d, postdiv1: %d, "
		 "postdiv2: %d, "
		 "fb_int_div: %d, fb_frac_div: 0x%x\n",
		 __func__, (uint)((long)pll->pll_reg), cfg->ref_div,
		 cfg->post_div1, cfg->post_div2, cfg->fb_int_div,
		 cfg->fb_frac_div);
}

static int _program_pll(struct vtx_clk_regmap *clkr,
			struct vtx_clk_regmap_pll *pll,
			struct vtx_clk_pll_freq_table *cfg, unsigned long rate)
{
	int ret = 0;

	_update_pll_mnp(clkr, pll, cfg);

	ret = vtx_clk_pll_wait_for_lock(clkr, pll);

	return ret;
}

static int _get_table_rate(struct clk_hw *hw,
			struct vtx_clk_pll_freq_table *cfg,
			unsigned long rate, unsigned long parent_rate)
{
	struct vtx_clk_regmap_pll *pll = to_vtx_clk_regmap_pll(hw);
	const struct vtx_clk_pll_freq_table *sel;

	for (sel = pll->freq_table; sel->input_rate != 0; sel++)
		if (sel->input_rate == parent_rate &&
			sel->output_rate == rate)
			break;

	if (sel->input_rate == 0)
		return -EINVAL;

	cfg->input_rate = sel->input_rate;
	cfg->output_rate = sel->output_rate;
	cfg->ref_div = sel->ref_div;
	cfg->post_div1 = sel->post_div1;
	cfg->post_div2 = sel->post_div2;
	cfg->fb_int_div = sel->fb_int_div;
	cfg->fb_frac_div = sel->fb_frac_div;

	return 0;
}

static int vtx_clk_pll_enable(struct clk_hw *hw)
{
	/*  for current hw design, we enable all pll at loader, and
	 *  we dont turn it off
	 */
	return 0;
}

static void vtx_clk_pll_disable(struct clk_hw *hw)
{
	/*  for current hw design, we enable all pll at loader, and
	 *  we dont turn it off
	 */
}

static long vtx_clk_pll_round_rate(struct clk_hw *hw, unsigned long rate,
			unsigned long *prate)
{
	struct vtx_clk_pll_freq_table cfg;
	int ret;

	ret = _get_table_rate(hw, &cfg, rate, *prate);
	pr_debug("%s: %s rate = %ld\n", __func__, __clk_get_name(hw->clk), rate);

	if (ret)
		return 0;

	pr_debug("%s: in: %lu out: %lu for ref_div: %d, postdiv1: %d, "
		"postdiv2: %d, fb_int_div: %d, fb_frac_div: 0x%x\n",
		__func__, cfg.input_rate, cfg.output_rate,
		cfg.ref_div,
		cfg.post_div1,
		cfg.post_div2,
		cfg.fb_int_div,
		cfg.fb_frac_div);

	return cfg.output_rate;
}

static unsigned long vtx_clk_pll_recalc_rate(struct clk_hw *hw,
					 unsigned long parent_rate)
{
	struct vtx_clk_pll_freq_table cfg;
	u64 rate;
	u64 rate_int;
	u64 rate_frac;
	u64 divider;
	u64 output_rate;
	u64 parent_rate_ext = parent_rate;

	/* init stage, we dont care, we'll later reparent clk's parent */
	if (parent_rate == 0)
		return 0;

	_get_pll_mnp(hw, &cfg);

	// rate = (parent_rate * cfg.fb_int_div) / ((cfg.post_div2 + 1) *
	//         (cfg.post_div1 + 1) * (cfg.ref_div + 1));
	if (cfg.fb_frac_div == 0) {
		rate = parent_rate_ext * cfg.fb_int_div;
		divider = cfg.post_div2 * cfg.post_div1 * cfg.ref_div;
		output_rate = div64_u64(rate, divider);
	} else {
		rate_int = parent_rate_ext * cfg.fb_int_div;
		rate_frac = cfg.fb_frac_div;
		/*rate fractinal
		 * - fractional = fb_frac_div / 0x1000000;
		 * - fractional multiple 10000 to avoid truncate
		 * - don't multiple larger 10000 to avoid overflow
		 */
		rate_frac = parent_rate_ext * (rate_frac * 10000);
		rate_frac = div64_u64(rate_frac, 0x1000000);
		rate_frac = div64_u64(rate_frac, 10000);

		divider = (cfg.post_div2 * cfg.post_div1 * cfg.ref_div);
		output_rate = div64_u64(rate_int, divider) +
			      div64_u64(rate_frac, divider);
	}

	pr_debug("%s, %s parent_rate: %lu, rate: %lld\n",
		__func__, __clk_get_name(hw->clk), parent_rate, output_rate);

	return (u32)output_rate;
}

static int vtx_clk_pll_set_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long parent_rate)
{
	struct vtx_clk_regmap_pll *pll = to_vtx_clk_regmap_pll(hw);
	struct vtx_clk_regmap *clkr = to_vtx_clk_regmap(hw);
	struct vtx_clk_pll_freq_table cfg, old_cfg;
	/* unsigned long flags = 0; */
	int ret = 0;

	pr_debug("%s: changing %s to %lu with a parent rate of %lu\n",
		 __func__, __clk_get_name(hw->clk), rate, parent_rate);

	cfg.fb_int_div = 0;
	cfg.post_div2 = 0;
	cfg.post_div1 = 0;
	cfg.ref_div = 0;
	cfg.fb_frac_div = 0;

	if (_get_table_rate(hw, &cfg, rate, parent_rate)) {
		pr_err("%s: Failed to set %s rate %lu\n", __func__,
		       clk_hw_get_name(hw), rate);
		WARN_ON(1);
		return -EINVAL;
	}

	_get_pll_mnp(hw, &old_cfg);

	if (old_cfg.fb_int_div != cfg.fb_int_div
		|| old_cfg.post_div2 != cfg.post_div2
		|| old_cfg.post_div1 != cfg.post_div1
		|| old_cfg.ref_div != cfg.ref_div
		|| old_cfg.fb_frac_div != cfg.fb_frac_div)
		ret = _program_pll(clkr, pll, &cfg, rate);

	return ret;
}

const struct clk_ops vtx_clk_pll_ops = {
	.enable = vtx_clk_pll_enable,
	.disable = vtx_clk_pll_disable,
	.round_rate = vtx_clk_pll_round_rate,
	.recalc_rate = vtx_clk_pll_recalc_rate,
	.set_rate = vtx_clk_pll_set_rate,
};
EXPORT_SYMBOL_GPL(vtx_clk_pll_ops);
