// SPDX-License-Identifier: GPL-2.0-only
/*
 * Vatics SoC reset code
 *
 * Copyright (C) 2023 VATICS Inc
 * Copyright (c) 2014 Hisilicon Ltd.
 * Copyright (c) 2014 Linaro Ltd.
 *
 */

#include <linux/platform_device.h>
#include <linux/of_address.h>
#include <linux/clk.h>
#include <linux/reboot.h>

#define WDTC_REG_CTRL(base)			((base) + 0x04)
#define WDTC_REG_RELOAD_VALUE(base)		((base) + 0x10)
#define WDTC_REG_RELOAD_CTRL(base)		((base) + 0x18)

static void __iomem *base;
static struct clk *clk;
static struct device *dev;

static void do_reset(unsigned int ticks)
{
	int err;

	/* enable the source clock */
	err = clk_enable(clk);
	if (err) {
		dev_err(dev,
			"unable to enable the clock (err=%d)\n",
			err);

		return;
	}

	/* disable timer */
	writel_relaxed(0x0, WDTC_REG_CTRL(base));

	/* configure timeout */
	writel_relaxed(ticks, WDTC_REG_RELOAD_VALUE(base));

	/* apply timeout */
	writel_relaxed(0x28791166, WDTC_REG_RELOAD_CTRL(base));

	/* enable timer */
	writel_relaxed(0x4, WDTC_REG_CTRL(base));
}

static int vtx_restart_handler(struct notifier_block *this,
				unsigned long mode, void *cmd)
{
	do_reset(1);

	while (1)
		cpu_do_idle();

	return NOTIFY_DONE;
}

static struct notifier_block vtx_restart_nb = {
	.notifier_call = vtx_restart_handler,
	.priority = 128,
};

static int vtx_reboot_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	int err;

	dev = &pdev->dev;

	base = of_iomap(np, 0);
	if (!base) {
		WARN(1, "failed to map base address");
		return -ENODEV;
	}

	clk = devm_clk_get(dev, NULL);
	if (IS_ERR(clk)) {
		dev_err(dev, "unable to get the clock\n");
		return PTR_ERR(clk);
	}

	err = clk_prepare_enable(clk);
	if (err) {
		dev_err(dev,
			"unable to prepare and enable the clock (err=%d)\n",
			err);
		return err;
	}

	clk_disable(clk);

	err = register_restart_handler(&vtx_restart_nb);
	if (err) {
		dev_err(dev,
			"cannot register restart handler (err=%d)\n",
			err);
		iounmap(base);
	}

	return err;
}

static const struct of_device_id vtx_reboot_of_match[] = {
	{ .compatible = "vatics,reboot" },
	{}
};

static struct platform_driver vtx_reboot_driver = {
	.probe = vtx_reboot_probe,
	.driver = {
		.name = "vtx-reboot",
		.of_match_table = vtx_reboot_of_match,
	},
};

module_platform_driver(vtx_reboot_driver);
