// SPDX-License-Identifier: GPL-2.0
/*
 * Watchdog Driver for VPL watchdog timer
 *
 * Copyright (C) 2013-2018  VATICS Inc.
 */

#include <linux/clk.h>
#include <linux/interrupt.h>
#include <linux/of.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/watchdog.h>

#define WDTC_VERSION			0x00
#define WDTC_CTRL			0x04
#define WDTC_STAT			0x08
#define WDTC_COUNT			0x0c
#define WDTC_RELOAD_VALUE		0x10
#define WDTC_MATCH_VALUE		0x14
#define WDTC_RELOAD_CTRL		0x18
#define WDTC_RST_LEN			0x1c

#define WDTC_CTRL_ACK_EN		0x2
#define WDTC_CTRL_OP_EN			0x4
#define WDTC_RELOAD_PASSWD		0x28791166
#define WDTC_RESET_LEN			0xffff

#define WDTC_DEFAULT_TIMEOUT		60

/* decrease WDTC_COUNT by one per 64 input clock cycles */
#define WDTC_TICKS(freq)		((freq) >> 6)

static bool nowayout = WATCHDOG_NOWAYOUT;
module_param(nowayout, bool, 0000);
MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started (default="
		 __MODULE_STRING(WATCHDOG_NOWAYOUT) ")");

static unsigned int timeout = WDTC_DEFAULT_TIMEOUT;
module_param(timeout, uint, 0000);
MODULE_PARM_DESC(timeout, "Watchdog timeout in seconds (default = 60s)");

static bool testmode;
module_param(testmode, bool, 0000);
MODULE_PARM_DESC(testmode, "Watchdog test mode (1 = no reboot) (default = 0)");

struct vpl_wdtc {
	void __iomem *base;
	struct device *dev;
	struct watchdog_device wdd;
	struct clk *clk;
	u32 clk_freq;
};

static void wdtc_set_timer(struct vpl_wdtc *wdev, unsigned int timeout)
{
	void __iomem *base = wdev->base;
	u32 val = timeout * WDTC_TICKS(wdev->clk_freq);

	writel(val, base + WDTC_RELOAD_VALUE);
}

static void wdtc_reload(struct vpl_wdtc *wdev)
{
	void __iomem *base = wdev->base;

	writel(WDTC_RELOAD_PASSWD, base + WDTC_RELOAD_CTRL);
}

static void wdtc_enable(struct vpl_wdtc *wdev)
{
	void __iomem *base = wdev->base;
	u32 ctrl = readl(base + WDTC_CTRL);

	if (testmode) {
		writel(0, base + WDTC_RST_LEN);
		ctrl |= WDTC_CTRL_ACK_EN;
	} else {
		writel(WDTC_RESET_LEN, base + WDTC_RST_LEN);
		ctrl &= ~WDTC_CTRL_ACK_EN;
	}

	writel(ctrl | WDTC_CTRL_OP_EN, base + WDTC_CTRL);
}

static void wdtc_disable(struct vpl_wdtc *wdev)
{
	void __iomem *base = wdev->base;
	u32 ctrl = readl(base + WDTC_CTRL) & ~WDTC_CTRL_OP_EN;

	writel(ctrl, base + WDTC_CTRL);
}

static int vpl_wdt_start(struct watchdog_device *wdd)
{
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	wdtc_set_timer(wdev, wdd->timeout);
	wdtc_reload(wdev);
	wdtc_enable(wdev);

	return 0;
}

static int vpl_wdt_stop(struct watchdog_device *wdd)
{
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	wdtc_disable(wdev);

	return 0;
}

static int vpl_wdt_ping(struct watchdog_device *wdd)
{
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	wdtc_reload(wdev);

	return 0;
}

static int vpl_wdt_set_timeout(struct watchdog_device *wdd,
			       unsigned int timeout)
{
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	wdtc_set_timer(wdev, timeout);
	wdtc_reload(wdev);

	wdd->timeout = timeout;

	return 0;
}

static irqreturn_t vpl_wdt_isr(int irq, void *dev_id)
{
	struct platform_device *pdev = dev_id;
	struct watchdog_device *wdd = platform_get_drvdata(pdev);

	vpl_wdt_ping(wdd);

	dev_info(&pdev->dev, "watchdog timer expired\n");

	return IRQ_HANDLED;
}

static const struct watchdog_info vpl_wdt_info = {
	.options = WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING,
	.identity = "VPL Watchdog Timer",
};

static const struct watchdog_ops vpl_wdt_ops = {
	.owner = THIS_MODULE,
	.start = vpl_wdt_start,
	.stop = vpl_wdt_stop,
	.ping = vpl_wdt_ping,
	.set_timeout = vpl_wdt_set_timeout,
};

static int vpl_wdt_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct watchdog_device *wdd;
	struct vpl_wdtc *wdev;
	int irq, ret;

	wdev = devm_kzalloc(dev, sizeof(*wdev), GFP_KERNEL);
	if (!wdev)
		return -ENOMEM;

	wdev->dev = dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "no memory resource specified\n");
		return -ENOENT;
	}

	wdev->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(wdev->base))
		return PTR_ERR(wdev->base);

	wdev->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(wdev->clk))
		return PTR_ERR(wdev->clk);

	wdev->clk_freq = clk_get_rate(wdev->clk);
	if (!wdev->clk_freq)
		return -EINVAL;

	ret = clk_prepare_enable(wdev->clk);
	if (ret) {
		dev_err(dev, "failed to prepare clock\n");
		return ret;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(dev, "no irq resource specified\n");
		return irq;
	}

	ret = devm_request_irq(dev, irq, vpl_wdt_isr, 0,
			       dev_name(dev), pdev);
	if (ret) {
		dev_err(dev, "fail to request irq (%d)\n", ret);
		return ret;
	}

	wdd = &wdev->wdd;

	wdd->info = &vpl_wdt_info;
	wdd->ops = &vpl_wdt_ops;
	wdd->timeout = timeout;
	wdd->min_timeout = 1;
	wdd->max_timeout = UINT_MAX / WDTC_TICKS(wdev->clk_freq);

	watchdog_init_timeout(wdd, timeout, dev);
	watchdog_set_drvdata(wdd, wdev);
	watchdog_set_nowayout(wdd, nowayout);

	platform_set_drvdata(pdev, wdd);

	ret = watchdog_register_device(wdd);
	if (ret) {
		dev_err(dev, "cannot register watchdog device: %d\n", ret);
		return ret;
	}

	dev_info(dev, "default timeout %u seconds\n", timeout);

	return 0;
}

static int vpl_wdt_remove(struct platform_device *pdev)
{
	struct watchdog_device *wdd = platform_get_drvdata(pdev);
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	watchdog_unregister_device(wdd);
	clk_disable_unprepare(wdev->clk);

	return 0;
}

#ifdef CONFIG_PM
static int vpl_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct watchdog_device *wdd = platform_get_drvdata(pdev);
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	if (watchdog_active(wdd))
		wdtc_disable(wdev);

	clk_disable(wdev->clk);

	return 0;
}

static int vpl_wdt_resume(struct platform_device *pdev)
{
	struct watchdog_device *wdd = platform_get_drvdata(pdev);
	struct vpl_wdtc *wdev = watchdog_get_drvdata(wdd);

	clk_enable(wdev->clk);

	wdtc_set_timer(wdev, wdd->timeout);
	wdtc_reload(wdev);

	if (watchdog_active(wdd))
		wdtc_enable(wdev);

	return 0;
}
#else
#define vpl_wdt_suspend		NULL
#define vpl_wdt_resume		NULL
#endif

static const struct of_device_id vpl_wdt_of_match[] = {
	{ .compatible = "vatics,vpl-wdt" },
	{ /* sentinel */ },
};
MODULE_DEVICE_TABLE(of, vpl_wdt_of_match);

static struct platform_driver vpl_wdt_driver = {
	.probe = vpl_wdt_probe,
	.remove = vpl_wdt_remove,
	.suspend = vpl_wdt_suspend,
	.resume = vpl_wdt_resume,
	.driver = {
		.name = "vpl_wdt",
		.owner = THIS_MODULE,
		.of_match_table = vpl_wdt_of_match,
	},
};

module_platform_driver(vpl_wdt_driver);

MODULE_DESCRIPTION("VPL Watchdog Timer driver");
MODULE_AUTHOR("Michael Wu <michael.wu@vatics.com>");
MODULE_LICENSE("GPL");
