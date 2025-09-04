// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2023 VATICS Inc.
 *
 */

#include <linux/clk.h>
#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include "gpiolib.h"

#define MAX_GPIO_PER_BANK	32

#define GPIOC_VERSION			0x00
#define GPIOC_DATA_OUT			0x04
#define GPIOC_DATA_IN			0x08
#define GPIOC_PIN_DIR			0x0C
#define GPIOC_RESERVED			0x10
#define GPIOC_DATA_SET			0x14
#define GPIOC_DATA_CLR			0x18
#define GPIOC_PIN_PULL_ENABLE		0x1C
#define GPIOC_PIN_PULL_TYPE		0x20
#define GPIOC_INTR_ENABLE		0x24
#define GPIOC_INTR_RAW_STATE		0x28
#define GPIOC_INTR_MASK_STATE		0x2C
#define GPIOC_INTR_MASK			0x30
#define GPIOC_INTR_CLEAR		0x34
#define GPIOC_INTR_TRIGGER_TYPE		0x38
#define GPIOC_INTR_BOTH			0x3C
#define GPIOC_INTR_DIR			0x40
#define GPIOC_DEBOUNCE_ENABLE		0x44
#define GPIOC_DEBOUNCE_PERIOD		0x48

#define GPIOC_DEBOUNCE_PERIOD_BIT	24

#ifdef CONFIG_PM_SLEEP
struct gpio_save_regs {
	u32 dir;
	u32 data;
	u32 intr_en;
	u32 intr_trig_type;
	u32 intr_both;
	u32 intr_dir;
	u32 debounce_en;
	u32 debounce_period;
};
#endif

struct vpl_gpio_priv {
	struct gpio_chip	chip;
	void __iomem		*base;
	spinlock_t		lock;
	struct device		*dev;
	struct clk		*clk;
	unsigned long		clk_rate;
	int			virq;
#ifdef CONFIG_PM_SLEEP
	struct gpio_save_regs	gpio_data;
#endif
};

static int vpl_gpio_set_debounce(struct gpio_chip *chip, unsigned int offset,
				 unsigned long usecs)
{
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(chip);
	void __iomem *base = priv_data->base;
	unsigned long flags;
	unsigned long ticks;
	u32 enable;

	ticks = usecs * priv_data->clk_rate / 1000000;
	if (ticks > 0xffffffUL) {
		ticks = 0xffffffUL;

		dev_warn(chip->parent,
			 "debouncing time is too long, reduce to %lu ms\n",
			 ticks * 1000000 / priv_data->clk_rate);
	}

	spin_lock_irqsave(&priv_data->lock, flags);

	enable = readl_relaxed(base + GPIOC_DEBOUNCE_ENABLE);
	if (ticks) {
		enable |= BIT(offset);

		writel_relaxed(ticks, base + GPIOC_DEBOUNCE_PERIOD);
		writel_relaxed(enable, base + GPIOC_DEBOUNCE_ENABLE);
	} else {
		enable &= ~BIT(offset);

		writel_relaxed(enable, base + GPIOC_DEBOUNCE_ENABLE);
	}

	spin_unlock_irqrestore(&priv_data->lock, flags);

	return 0;
}

static int vpl_gpio_direction_input(struct gpio_chip *chip, unsigned int offset)
{
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(chip);
	void __iomem *base = priv_data->base;
	unsigned long flags;
	u32 val;

	spin_lock_irqsave(&priv_data->lock, flags);

	val = readl_relaxed(base + GPIOC_PIN_DIR);
	writel_relaxed(val & ~BIT(offset), base + GPIOC_PIN_DIR);

	spin_unlock_irqrestore(&priv_data->lock, flags);

	return 0;
}

static int vpl_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(chip);
	void __iomem *base = priv_data->base;
	u32 data;

	if (readl_relaxed(base + GPIOC_PIN_DIR) & BIT(offset))
		data = readl_relaxed(base + GPIOC_DATA_OUT);
	else
		data = readl_relaxed(base + GPIOC_DATA_IN);

	return (data >> offset) & 1;
}

static int vpl_gpio_direction_output(struct gpio_chip *chip, unsigned int offset,
					int value)
{
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(chip);
	void __iomem *base = priv_data->base;
	unsigned long flags;
	u32 val;

	spin_lock_irqsave(&priv_data->lock, flags);

	val = readl_relaxed(base + GPIOC_PIN_DIR);
	if (value)
		writel_relaxed(BIT(offset), base + GPIOC_DATA_SET);
	else
		writel_relaxed(BIT(offset), base + GPIOC_DATA_CLR);
	writel_relaxed(val | BIT(offset), base + GPIOC_PIN_DIR);

	spin_unlock_irqrestore(&priv_data->lock, flags);

	return 0;
}

static void vpl_gpio_set(struct gpio_chip *chip, unsigned int offset, int value)
{
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(chip);
	void __iomem *base = priv_data->base;
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);

	if (value)
		writel_relaxed(BIT(offset), base + GPIOC_DATA_SET);
	else
		writel_relaxed(BIT(offset), base + GPIOC_DATA_CLR);

	spin_unlock_irqrestore(&priv_data->lock, flags);
}

static int vpl_gpio_set_config(struct gpio_chip *chip, unsigned int offset,
			       unsigned long config)
{
	unsigned long param = pinconf_to_config_param(config);
	u32 arg = pinconf_to_config_argument(config);

	switch (param) {
	case PIN_CONFIG_INPUT_DEBOUNCE:
		return vpl_gpio_set_debounce(chip, offset, arg);
	default:
	}

	return pinctrl_gpio_set_config(chip->base + offset, config);
}

/* interrupt handler */
static void vpl_gpio_irq_handler(struct irq_desc *desc)
{
	struct gpio_chip *gpio_chip = irq_desc_get_handler_data(desc);
	struct vpl_gpio_priv *priv_data = gpiochip_get_data(gpio_chip);
	struct irq_chip *chip = irq_desc_get_chip(desc);
	int offset;
	unsigned long status;

	chained_irq_enter(chip, desc);

	status = readl_relaxed(priv_data->base + GPIOC_INTR_MASK_STATE);

	if (status)
		for_each_set_bit(offset, &status, gpio_chip->ngpio)
			generic_handle_irq(irq_find_mapping(gpio_chip->irq.domain, offset));

	chained_irq_exit(chip, desc);
}

static unsigned int vpl_gpio_irq_startup(struct irq_data *d)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);
	writel_relaxed(readl_relaxed(base + GPIOC_INTR_ENABLE) | mask,
			base + GPIOC_INTR_ENABLE);

	writel_relaxed(readl_relaxed(base + GPIOC_INTR_MASK) & ~mask,
			base + GPIOC_INTR_MASK);
	spin_unlock_irqrestore(&priv_data->lock, flags);
	return 0;
}

static void vpl_gpio_irq_shutdown(struct irq_data *d)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);
	writel_relaxed(readl_relaxed(base + GPIOC_INTR_ENABLE) & ~mask,
			base + GPIOC_INTR_ENABLE);

	spin_unlock_irqrestore(&priv_data->lock, flags);
}

static void vpl_gpio_irq_ack(struct irq_data *d)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);
	writel_relaxed(mask, base + GPIOC_INTR_CLEAR);
	spin_unlock_irqrestore(&priv_data->lock, flags);
}

static void vpl_gpio_irq_mask(struct irq_data *d)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);
	writel_relaxed(readl_relaxed(base + GPIOC_INTR_MASK) | mask,
			base + GPIOC_INTR_MASK);
	spin_unlock_irqrestore(&priv_data->lock, flags);
}

static void vpl_gpio_irq_unmask(struct irq_data *d)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	spin_lock_irqsave(&priv_data->lock, flags);
	writel_relaxed(readl_relaxed(base + GPIOC_INTR_MASK) & ~mask,
			base + GPIOC_INTR_MASK);
	spin_unlock_irqrestore(&priv_data->lock, flags);
}

#define set_edge_triggered(val, mask) (val &= ~mask)
#define set_level_triggered(val, mask) (val |= mask)
#define set_single_edge(val, mask) (val &= ~mask)
#define set_both_edge(val, mask) (val |= mask)
#define set_rising_high(val, mask) (val &= ~mask)
#define set_falling_low(val, mask) (val |= mask)

static int vpl_gpio_irq_type(struct irq_data *d, unsigned int flow_type)
{
	struct vpl_gpio_priv *priv_data =
			gpiochip_get_data(irq_data_get_irq_chip_data(d));
	void __iomem *base = priv_data->base;
	u32 intr_type, intr_both, intr_dir;
	u32 is_level = 0, is_both = 0, is_falling_low = 0;
	u32 mask = BIT(irqd_to_hwirq(d));
	unsigned long flags;

	switch (flow_type) {
	case IRQ_TYPE_EDGE_BOTH:
		is_both = 1;
		break;
	case IRQ_TYPE_EDGE_RISING:
		break;
	case IRQ_TYPE_EDGE_FALLING:
		is_falling_low = 1;
		break;
	case IRQ_TYPE_LEVEL_HIGH:
		is_level = 1;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		is_level = 1;
		is_falling_low = 1;
		break;
	default:
		return -EINVAL;
	}

	spin_lock_irqsave(&priv_data->lock, flags);

	intr_type = readl_relaxed(base + GPIOC_INTR_TRIGGER_TYPE);
	intr_both = readl_relaxed(base + GPIOC_INTR_BOTH);
	intr_dir = readl_relaxed(base + GPIOC_INTR_DIR);

	if (is_level)
		set_level_triggered(intr_type, mask);
	else
		set_edge_triggered(intr_type, mask);

	if (is_both)
		set_both_edge(intr_both, mask);
	else
		set_single_edge(intr_both, mask);

	if (is_falling_low)
		set_falling_low(intr_dir, mask);
	else
		set_rising_high(intr_dir, mask);

	writel_relaxed(intr_type, base + GPIOC_INTR_TRIGGER_TYPE);
	writel_relaxed(intr_both, base + GPIOC_INTR_BOTH);
	writel_relaxed(intr_dir, base + GPIOC_INTR_DIR);

	spin_unlock_irqrestore(&priv_data->lock, flags);

	if (flow_type & IRQ_TYPE_LEVEL_MASK)
		irq_set_handler_locked(d, handle_level_irq);
	else if (flow_type & IRQ_TYPE_EDGE_BOTH)
		irq_set_handler_locked(d, handle_edge_irq);

	return 0;
}

static int vpl_gpio_irq_reqres(struct irq_data *d)
{
	struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
	u32 offset = irqd_to_hwirq(d);

	vpl_gpio_direction_input(chip, offset);

	return gpiochip_reqres_irq(chip, d->hwirq);
}

static void vpl_gpio_irq_relres(struct irq_data *d)
{
	struct gpio_chip *chip = irq_data_get_irq_chip_data(d);

	gpiochip_relres_irq(chip, d->hwirq);
}

static struct irq_chip vpl_gpio_irqchip = {
	.name		= "VPL_GPIO",
	.irq_startup	= vpl_gpio_irq_startup,
	.irq_shutdown   = vpl_gpio_irq_shutdown,
	.irq_ack	= vpl_gpio_irq_ack,
	.irq_mask	= vpl_gpio_irq_mask,
	.irq_unmask	= vpl_gpio_irq_unmask,
	.irq_request_resources	= vpl_gpio_irq_reqres,
	.irq_release_resources	= vpl_gpio_irq_relres,
	.irq_set_type	= vpl_gpio_irq_type,
	.flags          = IRQCHIP_MASK_ON_SUSPEND | IRQCHIP_SKIP_SET_WAKE | IRQCHIP_IMMUTABLE,
};

static int vpl_gpio_probe(struct platform_device *pdev)
{
	struct vpl_gpio_priv *priv_data;
	struct device *dev = &pdev->dev;
	struct resource *res;
	int id, ret;
	struct gpio_irq_chip *girq;

	priv_data = devm_kzalloc(dev, sizeof(struct vpl_gpio_priv), GFP_KERNEL);
	if (!priv_data)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv_data);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv_data->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(priv_data->base))
		return PTR_ERR(priv_data->base);

	priv_data->virq = platform_get_irq(pdev, 0);
	if (priv_data->virq < 0) {
		dev_err(dev, "no irq resource specified\n");
		return priv_data->virq;
	}

	id = of_alias_get_id(pdev->dev.of_node, "gpio");
	if (id < 0) {
		dev_err(dev, "Couldn't get OF id\n");
		return id;
	}

	priv_data->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(priv_data->clk))
		return PTR_ERR(priv_data->clk);
	clk_prepare_enable(priv_data->clk);

	priv_data->clk_rate = clk_get_rate(priv_data->clk);
	priv_data->dev = dev;

	/* gpio chip setup */
	priv_data->chip.label            = dev_name(dev);
	priv_data->chip.of_node          = dev->of_node;
	priv_data->chip.parent           = dev;
	priv_data->chip.request          = gpiochip_generic_request;
	priv_data->chip.free             = gpiochip_generic_free;
	priv_data->chip.direction_input  = vpl_gpio_direction_input;
	priv_data->chip.direction_output = vpl_gpio_direction_output;
	priv_data->chip.get              = vpl_gpio_get;
	priv_data->chip.set              = vpl_gpio_set;
	priv_data->chip.set_config       = vpl_gpio_set_config;
	priv_data->chip.base             = id * MAX_GPIO_PER_BANK;
	priv_data->chip.ngpio            = MAX_GPIO_PER_BANK;

	spin_lock_init(&priv_data->lock);

	girq = &priv_data->chip.irq;
	girq->chip = &vpl_gpio_irqchip;
	girq->parent_handler = vpl_gpio_irq_handler;
	girq->num_parents = 1;
	girq->parents = devm_kcalloc(&pdev->dev, 1,
				     sizeof(*girq->parents),
				     GFP_KERNEL);
	if (!girq->parents)
		return -ENOMEM;
	girq->parents[0] = priv_data->virq;
	girq->default_type = IRQ_TYPE_NONE;
	girq->handler = handle_level_irq;
	girq->parent_handler_data = priv_data;

	ret = devm_gpiochip_add_data(&pdev->dev, &priv_data->chip, priv_data);
	if (ret) {
		dev_err(dev, "Could not register gpiochip");
		goto err_dis_clk;
	}

	return 0;

err_dis_clk:
	clk_disable_unprepare(priv_data->clk);

	return ret;
}

#ifdef CONFIG_PM_SLEEP
static int vpl_gpio_suspend_late(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct vpl_gpio_priv *priv_data = platform_get_drvdata(pdev);
	void __iomem *base = priv_data->base;

	/* save gpioc direction and data */
	priv_data->gpio_data.dir = readl_relaxed(base + GPIOC_PIN_DIR);
	priv_data->gpio_data.data = readl_relaxed(base + GPIOC_DATA_OUT);
	priv_data->gpio_data.intr_en = readl_relaxed(base + GPIOC_INTR_ENABLE);
	priv_data->gpio_data.intr_trig_type =
				readl_relaxed(base + GPIOC_INTR_TRIGGER_TYPE);
	priv_data->gpio_data.intr_both =
				readl_relaxed(base + GPIOC_INTR_BOTH);
	priv_data->gpio_data.intr_dir =
				readl_relaxed(base + GPIOC_INTR_DIR);
	priv_data->gpio_data.debounce_en =
				readl_relaxed(base + GPIOC_DEBOUNCE_ENABLE);
	priv_data->gpio_data.debounce_period =
				readl_relaxed(base + GPIOC_DEBOUNCE_PERIOD);

	clk_disable_unprepare(priv_data->clk);

	return 0;
}

static int vpl_gpio_resume_early(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct vpl_gpio_priv *priv_data = platform_get_drvdata(pdev);
	void __iomem *base = priv_data->base;
	int ret;

	ret = clk_prepare_enable(priv_data->clk);

	/* restore gpioc direction and data */
	writel_relaxed(priv_data->gpio_data.data, base + GPIOC_DATA_OUT);
	writel_relaxed(priv_data->gpio_data.dir, base + GPIOC_PIN_DIR);

	writel_relaxed(
			priv_data->gpio_data.intr_trig_type,
			base + GPIOC_INTR_TRIGGER_TYPE);
	writel_relaxed(
			priv_data->gpio_data.intr_both,
			base + GPIOC_INTR_BOTH);
	writel_relaxed(
			priv_data->gpio_data.intr_dir,
			base + GPIOC_INTR_DIR);
	writel_relaxed(
			priv_data->gpio_data.debounce_period,
			base + GPIOC_DEBOUNCE_PERIOD);
	writel_relaxed(
			priv_data->gpio_data.debounce_en,
			base + GPIOC_DEBOUNCE_ENABLE);
	writel_relaxed(
			priv_data->gpio_data.intr_en,
			base + GPIOC_INTR_ENABLE);

	return ret;
}
#endif

static const struct dev_pm_ops vpl_gpio_pm_ops = {
	SET_LATE_SYSTEM_SLEEP_PM_OPS(vpl_gpio_suspend_late,
		vpl_gpio_resume_early)
};

static const struct of_device_id vpl_gpio_of_match[] = {
	{ .compatible = "vatics,vpl-gpio", },
	{}
};
MODULE_DEVICE_TABLE(of, vpl_gpio_of_match);

static struct platform_driver vpl_gpio_driver = {
	.probe = vpl_gpio_probe,
	.driver = {
		.name = "vpl_gpio",
		.pm = &vpl_gpio_pm_ops,
		.of_match_table = vpl_gpio_of_match,
	},
};
module_platform_driver(vpl_gpio_driver);

MODULE_AUTHOR("Vincent Ho <vincent.ho@vatics.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("VATICS VPL GPIOC driver");
