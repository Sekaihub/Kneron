// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <linux/slab.h>
#include <linux/clkdev.h>
#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/io.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>

#include "clk.h"
#include "clk-composite.h"

static struct clk_hw *vtx_clk_hw_get(struct of_phandle_args *clkspec,
					 void *data)
{
	struct vtx_clk_cc *cc = data;
	unsigned int idx = clkspec->args[0];

	if (idx >= cc->num_rclks) {
		pr_err("%s: invalid index %u\n", __func__, idx);
		return ERR_PTR(-EINVAL);
	}

	return cc->rclks[idx] ? &cc->rclks[idx]->hw : NULL;
}

/**
 * devm_clk_register_regmap - register a clk_regmap clock
 *
 * @dev: reference to the caller's device
 * @rclk: clk to operate on
 *
 * Clocks that use regmap for their register I/O should register their
 * clk_regmap struct via this function so that the regmap is initialized
 * and so that the clock is registered with the common clock framework.
 */
int devm_vtx_clk_register_regmap(struct device *dev, struct vtx_clk_regmap *rclk)
{
	return devm_clk_hw_register(dev, &rclk->hw);
}
EXPORT_SYMBOL_GPL(devm_vtx_clk_register_regmap);


int vtx_clk_probe(struct platform_device *pdev, const struct vtx_clk_desc *desc)
{
	int i, ret;
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	size_t num_rclks = desc->num_rclks;
	struct vtx_clk_regmap **rclks = desc->rclks;
	struct regmap *pll_regmap;
	struct regmap *sysc_regmap;
	struct vtx_clk_cc *cc;

	cc = devm_kzalloc(dev, sizeof(*cc), GFP_KERNEL);
	if (!cc)
		return -ENOMEM;

	sysc_regmap = syscon_regmap_lookup_by_phandle(np, "sysc-regmap");
	if (IS_ERR(sysc_regmap)) {
		dev_err(dev, "missing sysc-regmap phandle\n");
		return PTR_ERR(sysc_regmap);
	}

	pll_regmap = syscon_regmap_lookup_by_phandle(np, "pll-regmap");
	if (IS_ERR(pll_regmap)) {
		dev_err(dev, "missing pll-regmap phandle\n");
		return PTR_ERR(pll_regmap);
	}

	cc->rclks = rclks;
	cc->num_rclks = num_rclks;

	for (i = 0; i < num_rclks; i++) {
		if (!rclks[i])
			continue;

		if (rclks[i]->type == vtx_clk_type_pll)
			rclks[i]->regmap = pll_regmap;
		else
			rclks[i]->regmap = sysc_regmap;

		if (rclks[i]->type == vtx_clk_type_composite)
			vtx_clk_composite_setup_regmap(rclks[i]);

		ret = devm_vtx_clk_register_regmap(dev, rclks[i]);
		if (ret) {
			dev_err(&pdev->dev, "%s: leipzig: faled clk register\n",
				__func__);
			return ret;
		}
	}

	ret = devm_of_clk_add_hw_provider(dev, vtx_clk_hw_get, cc);
	if (ret)
		return ret;

	return 0;
}
EXPORT_SYMBOL_GPL(vtx_clk_probe);
