// SPDX-License-Identifier: GPL-2.0
/*
 * Watchdog driver for Vatics SoCs
 *
 * Copyright (C) 2023 Vatics Inc.
 * Author: Michael Wu <michael.wu@vatics.com>
 */

#include <dm.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <clk.h>
#include <wdt.h>

struct vpl_wdt {
	void __iomem *regs;
	ulong clk_rate;
};

#define WDTC_CTRL_OP_EN			BIT(2)

#define WDTC_REG_CTRL(base)		((base) + 0x4)
#define WDTC_REG_RELOAD_VALUE(base)	((base) + 0x10)
#define WDTC_REG_RELOAD_CTRL(base)	((base) + 0x18)

#define WDTC_RELOAD_PASSWD		(0x28791166)

/* decrease WDTC_COUNT by one per 64 input clock cycles */
#define WDTC_TICKS(freq)		((freq) >> 6)

static int wdtc_start(struct vpl_wdt *priv, u32 ticks)
{
	/* stop timer */
	writel(0, WDTC_REG_CTRL(priv->regs));

	/* configure ticks */
	writel(ticks, WDTC_REG_RELOAD_VALUE(priv->regs));

	/* apply configured ticks */
	writel(WDTC_RELOAD_PASSWD, WDTC_REG_RELOAD_CTRL(priv->regs));

	/* start timer */
	writel(WDTC_CTRL_OP_EN, WDTC_REG_CTRL(priv->regs));

	return 0;
}

static int vpl_wdt_start(struct udevice *dev, u64 timeout_ms, ulong flags)
{
	struct vpl_wdt *priv = dev_get_priv(dev);
	u32 ticks = WDTC_TICKS(priv->clk_rate) / 1000 * timeout_ms;

	return wdtc_start(priv, ticks);
}

static int vpl_wdt_stop(struct udevice *dev)
{
	struct vpl_wdt *priv = dev_get_priv(dev);

	writel(0, WDTC_REG_CTRL(priv->regs));

	return 0;
}

static int vpl_wdt_reset(struct udevice *dev)
{
	struct vpl_wdt *priv = dev_get_priv(dev);

	writel(WDTC_RELOAD_PASSWD, WDTC_REG_RELOAD_CTRL(priv->regs));

	return 0;
}

static int vpl_wdt_expire_now(struct udevice *dev, ulong flags)
{
	struct vpl_wdt *priv = dev_get_priv(dev);

	return wdtc_start(priv, 1);
}

static const struct wdt_ops vpl_wdt_ops = {
	.start = vpl_wdt_start,
	.stop = vpl_wdt_stop,
	.reset = vpl_wdt_reset,
	.expire_now = vpl_wdt_expire_now,
};

static const struct udevice_id vpl_wdt_ids[] = {
	{ .compatible = "vatics,vpl-wdt" },
	{ /* sentinel */ }
};

static int vpl_wdt_probe(struct udevice *dev)
{
	struct vpl_wdt *priv = dev_get_priv(dev);
	struct clk clk;
	int ret;

	priv->regs = dev_remap_addr(dev);
	if (!priv->regs)
		return -EINVAL;

	ret = clk_get_by_index(dev, 0, &clk);
	if (ret)
		return -EINVAL;

	priv->clk_rate = clk_get_rate(&clk);

	vpl_wdt_stop(dev);

	return 0;
}

U_BOOT_DRIVER(vpl_wdt) = {
	.name = "vpl_wdt",
	.id = UCLASS_WDT,
	.of_match = vpl_wdt_ids,
	.probe = vpl_wdt_probe,
	.priv_auto = sizeof(struct vpl_wdt),
	.ops = &vpl_wdt_ops,
};

