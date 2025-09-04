// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef CLK_VATICS_CLK_H_
#define CLK_VATICS_CLK_H_

#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/clk-provider.h>

struct clk;

/* vtx clk common */
struct vtx_clk_cc {
	struct vtx_clk_regmap **rclks;
	size_t num_rclks;
};


struct vtx_clk_desc {
	struct vtx_clk_regmap **rclks;
	size_t num_rclks;
};

enum vtx_clk_type {
	vtx_clk_type_pll,
	vtx_clk_type_composite,
	vtx_clk_type_mux,
	vtx_clk_type_div,
	vtx_clk_type_gate,
	vtx_clk_type_factor,
};

/**
 * struct vtx_clk_regmap - regmap backed clock
 *
 * @hw:	       handle between common and hardware-specific interfaces
 * @regmap:	regmap to use for regmap helpers and/or by providers
 * @lock:      maintains exclusion between callbacks for a given clock-provider.
 * @data:      data specific to the clock type
 *
 * Clock which is controlled by regmap backed registers. The actual type of
 * the clock is controlled by the clock_ops and data.
 */
struct vtx_clk_regmap {
	struct clk_hw hw;
	struct regmap *regmap;
	enum vtx_clk_type type;
};

static inline struct vtx_clk_regmap *to_vtx_clk_regmap(struct clk_hw *hw)
{
	return container_of(hw, struct vtx_clk_regmap, hw);
}

extern int devm_vtx_clk_register_regmap(struct device *dev,
				 struct vtx_clk_regmap *rclk);

extern int vtx_clk_probe(struct platform_device *pdev,
			 const struct vtx_clk_desc *desc);

#endif // CLK_VATICS_CLK_H_
