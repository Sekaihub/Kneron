// SPDX-License-Identifier: GPL-2.0-only
/*
 * phy-leipzig-usb2.c - USB20C PHY driver for Vatics Leipzig
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

#define LEIPZIG_USB20C_VERSION                     (0x0)
#define LEIPZIG_USB20C_PHY_CTRL_0                  (0x04)
#define LEIPZIG_USB20C_PHY_CTRL_1                  (0x08)
#define LEIPZIG_USB20C_PHY_CTRL_2                  (0x0C)
#define LEIPZIG_USB20C_PHY_CTRL_3                  (0x10)
#define LEIPZIG_USB20C_DWC_USB3_CTRL_1             (0x14)
#define LEIPZIG_USB20C_DWC_USB3_CTRL_2             (0x18)
#define LEIPZIG_USB20C_DWC_USB3_CTRL_3             (0x1C)
#define LEIPZIG_USB20C_DWC_USB3_CTRL_4             (0x20)
#define LEIPZIG_USB20C_DWC_USB3_CTRL_5             (0x24)

struct leipzig_usb2_phy_priv {
	struct regmap		*regmap;
};

static int leipzig_usb2_phy_init(struct phy *phy)
{
	struct udevice *dev = phy->dev;
	struct leipzig_usb2_phy_priv *priv = dev_get_priv(dev);
	u32 val;

	regmap_read(priv->regmap, LEIPZIG_USB20C_VERSION, &val);
	dev_info(dev, "usb2 phy version %08x\n", val);

	return 0;
}

static struct phy_ops leipzig_usb2_phy_ops = {
	.init = leipzig_usb2_phy_init,
};

static int leipzig_usb2_phy_probe(struct udevice *dev)
{
	struct leipzig_usb2_phy_priv *priv = dev_get_priv(dev);
	int ret;

	ret = regmap_init_mem(dev_ofnode(dev), &priv->regmap);
	if (ret)
		return ret;

	return 0;
}

static const struct udevice_id leipzig_usb2_phy_ids[] = {
	{ .compatible = "vatics,leipzig-usb2-phy" },
	{ /* sentinel */ }
};

U_BOOT_DRIVER(leipzig_usb2_phy) = {
	.name = "leipzig-usb2-phy",
	.id = UCLASS_PHY,
	.of_match = leipzig_usb2_phy_ids,
	.probe = leipzig_usb2_phy_probe,
	.ops = &leipzig_usb2_phy_ops,
	.priv_auto = sizeof(struct leipzig_usb2_phy_priv),
};
