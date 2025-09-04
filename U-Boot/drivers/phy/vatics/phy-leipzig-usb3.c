// SPDX-License-Identifier: GPL-2.0-only
/*
 * phy-leipzig-usb3.c - USB30C PHY driver for Vatics Leipzig
 *
 * Copyright (C) 2022 VATICS Inc.
 */

#include <common.h>
#include <clk.h>
#include <dm.h>
#include <generic-phy.h>
#include <regmap.h>
#include <reset-uclass.h>
#include <syscon.h>
#include <asm/io.h>
#include <dm/device_compat.h>
#include <dm/lists.h>

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
	struct regmap *regmap;
	struct regmap *sysc_regmap;
};

static int leipzig_usb3_phy_init(struct phy *phy)
{
	struct udevice *dev = phy->dev;
	struct leipzig_usb3_phy_priv *priv = dev_get_priv(dev);
	u32 val;

	regmap_read(priv->regmap, LEIPZIG_USB30C_VERSION, &val);
	dev_info(dev, "usb3 phy version %08x\n", val);

	return 0;
}

static struct phy_ops leipzig_usb3_phy_ops = {
	.init = leipzig_usb3_phy_init,
};

static int leipzig_usb3_phy_probe(struct udevice *dev)
{
	struct leipzig_usb3_phy_priv *priv = dev_get_priv(dev);
	struct udevice *syscon;
	int ret;
	uint otp_hw_cfg1;
	uint reg_val;
	bool wagner_USB3_clk_external;

	ret = regmap_init_mem(dev_ofnode(dev), &priv->regmap);
	if (ret)
		return ret;

	/* get corresponding syscon phandle */
	ret = uclass_get_device_by_phandle(UCLASS_SYSCON, dev, "regmap",
					   &syscon);
	if (ret) {
		dev_err(dev, "unable to find syscon device\n");
		return ret;
	}

	priv->sysc_regmap = syscon_get_regmap(syscon);
	if (!priv->sysc_regmap) {
		dev_err(dev, "unable to find regmap\n");
		return -ENODEV;
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

static const struct udevice_id leipzig_usb3_phy_ids[] = {
	{ .compatible = "vatics,leipzig-usb3-phy" },
	{ /* sentinel */ }
};

U_BOOT_DRIVER(leipzig_usb3_phy) = {
	.name = "leipzig-usb3-phy",
	.id = UCLASS_PHY,
	.of_match = leipzig_usb3_phy_ids,
	.probe = leipzig_usb3_phy_probe,
	.ops = &leipzig_usb3_phy_ops,
	.priv_auto = sizeof(struct leipzig_usb3_phy_priv),
};
