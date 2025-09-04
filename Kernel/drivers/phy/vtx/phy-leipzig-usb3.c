// SPDX-License-Identifier: GPL-2.0-only
/*
 * phy-leipzig-usb3.c - USB30C PHY driver for Vatics Leipzig
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

/* otp */
//Bit 31-00
#define SYSC_HW_CFG_1		0x248
// 0:internal, 1:external
#define USB3_CLK_EXTERNAL	BIT(27)

/* USB30C register */
#define LEIPZIG_USB30C_VERSION                     (0x0)
#define LEIPZIG_USB30C_PHY_PARAM_0                 (0x4)
#define LEIPZIG_USB30C_PHY_PARAM_1                 (0x8)
#define LEIPZIG_USB30C_PHY_PARAM_2                 (0xC)
#define LEIPZIG_USB30C_PHY_PARAM_3                 (0x10)
#define LEIPZIG_USB30C_PHY_CTRL_0                  (0x14)
#define LEIPZIG_USB30C_PHY_CTRL_1                  (0x18)
#define LEIPZIG_USB30C_PHY_CTRL_2                  (0x1C)
#define LEIPZIG_USB30C_PHY_CTRL_3                  (0x20)
#define LEIPZIG_USB30C_PHY_CTRL_4                  (0x24)
#define LEIPZIG_USB30C_DWC_USB3_CTRL_0             (0x28)
#define LEIPZIG_USB30C_DWC_USB3_CTRL_1             (0x2C)

/* LEIPZIG_USB30C_PHY_CTRL_0 */
#define LEIPZIG_USB30C_PHY_CTRL_0_REF_USE_PAD      BIT(0)
#define LEIPZIG_USB30C_PHY_CTRL_0_REF_SS_EN        BIT(4)

/* LEIPZIG_USB30C_PHY_CTRL_1 */
#define LEIPZIG_USB30C_PHY_CTRL_1_SSC_EN           BIT(0)
#define LEIPZIG_USB30C_PHY_CTRL_1_SSC_RANGE(n)     (((n) & 0x7) << 4)

struct leipzig_usb3_phy_priv {
	struct device *dev;
	struct regmap *regmap;
	struct regmap *sysc_regmap;
};

static int leipzig_usb3_phy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	struct leipzig_usb3_phy_priv *priv;
	uint otp_hw_cfg1;
	uint reg_val;
	bool wagner_USB3_clk_external;

	priv = devm_kzalloc(dev, sizeof(struct leipzig_usb3_phy_priv),
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

	/* dwc3 phy setup
	 *
	 * There is a specific order for the signal setting:
	 * a)  ref_use_pad
	 * b)  ref_ssp_en
	 * c)  ssc_range
	 * d)  ssc_en
	 */

	/* read otp */
	regmap_read(priv->sysc_regmap, SYSC_HW_CFG_1, &otp_hw_cfg1);
	wagner_USB3_clk_external = !!(otp_hw_cfg1 & USB3_CLK_EXTERNAL);

	/* a)  ref_use_pad */
	/* select USB30C reference source clk */
	regmap_read(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_0, &reg_val);
	reg_val = (reg_val & ~(LEIPZIG_USB30C_PHY_CTRL_0_REF_USE_PAD)) |
		wagner_USB3_clk_external;
	regmap_write(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_0, reg_val);

	/* b)  ref_ssp_en: Reference Clock Enable for SS function. */
	reg_val |= LEIPZIG_USB30C_PHY_CTRL_0_REF_SS_EN;
	regmap_write(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_0, reg_val);

	/* c)  ssc_range: Spread Spectrum Clock Range */
	regmap_read(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_1, &reg_val);
	reg_val |= LEIPZIG_USB30C_PHY_CTRL_1_SSC_RANGE(1); /* -4492ppm */
	/* regmap_write(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_1, reg_val); */

	/* d)  ssc_en: Spread Spectrum Enable */
	reg_val |= LEIPZIG_USB30C_PHY_CTRL_1_SSC_EN;
	regmap_write(priv->regmap, LEIPZIG_USB30C_PHY_CTRL_1, reg_val);

	return 0;
}

static int leipzig_usb3_phy_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id leipzig_usb3_phy_dt_ids[] = {
	{ .compatible = "vatics,leipzig-usb3-phy" },
	{ /* sentinel */ }
};

MODULE_DEVICE_TABLE(of, leipzig_usb3_phy_dt_ids);

static struct platform_driver leipzig_usb3_phy_driver = {
	.probe		= leipzig_usb3_phy_probe,
	.remove		= leipzig_usb3_phy_remove,
	.driver		= {
		.name	= "leipzig-usb3-phy",
		.of_match_table = leipzig_usb3_phy_dt_ids,
	},
};

module_platform_driver(leipzig_usb3_phy_driver);

MODULE_DESCRIPTION("Vatics Leipzig USB 3.0 phy controller");
MODULE_LICENSE("GPL");
