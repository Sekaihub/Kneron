// SPDX-License-Identifier: GPL-2.0-only
/*
 * phy-leipzig-usb2.c - USB20C PHY driver for Vatics Leipzig
 *
 * Copyright (C) 2022 VATICS Inc.
 */


#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include <linux/regmap.h>
#include <linux/reset.h>

#include <linux/mfd/syscon.h>
#include <linux/phy/phy.h>

#define LEIPZIG_USB20C_VERSION                     (0x0)
#define LEIPZIG_USB20C_PHY_CTRL_0                  (0x04)
#define LEIPZIG_USB20C_PHY_CTRL_1                  (0x08)
#define LEIPZIG_USB20C_PHY_CTRL_2                  (0x0C)
#define LEIPZIG_USB20C_PHY_CTRL_3                  (0x10)

struct leipzig_usb2_phy_priv {
	struct device *dev;
	struct regmap *regmap;
	struct regmap *sysc_regmap;
};


static int leipzig_usb2_phy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	struct leipzig_usb2_phy_priv *priv;

	priv = devm_kzalloc(dev, sizeof(struct leipzig_usb2_phy_priv),
			    GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->dev = dev;
	priv->regmap = syscon_node_to_regmap(np);
	if (IS_ERR(priv->regmap))
		return PTR_ERR(priv->regmap);

	priv->sysc_regmap = syscon_regmap_lookup_by_phandle(np, "sysc-regmap");
	if (IS_ERR(priv->sysc_regmap)) {
		dev_err(dev, "missing sysc-regmap phandle\n");
		return PTR_ERR(priv->sysc_regmap);
	}

	return 0;
}

static int leipzig_usb2_phy_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id leipzig_usb2_phy_dt_ids[] = {
	{ .compatible = "vatics,leipzig-usb2-phy" },
	{ /* sentinel */ }
};

MODULE_DEVICE_TABLE(of, leipzig_usb2_phy_dt_ids);

static struct platform_driver leipzig_usb2_phy_driver = {
	.probe		= leipzig_usb2_phy_probe,
	.remove		= leipzig_usb2_phy_remove,
	.driver		= {
		.name	= "leipzig-usb2-phy",
		.of_match_table = leipzig_usb2_phy_dt_ids,
	},
};

module_platform_driver(leipzig_usb2_phy_driver);

MODULE_DESCRIPTION("Vatics Leipzig USB 2.0 phy controller");
MODULE_LICENSE("GPL");
