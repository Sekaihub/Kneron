// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2024 Kneron Inc.
 *
 * Author: ChangHsien Ho <vincent.ho@vatics.com>
 *         Evelyn Tsai <evelyn.tsai@vatics.com>
 *
 * PWM driver for Kneron SoCs
 */

#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/clk.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/vpl_agpo.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/irqdomain.h>
#include <linux/irqchip/chained_irq.h>

#define AGPO_DEV_MAX 256

static DEFINE_SPINLOCK(agpo_lock);

#if 0
static struct class *agpo_class;
static int agpo_major;
static dev_t agpo_devt;
struct cdev agpo_cdev;
#endif

struct vpl_agpo_chip;

#define	AGPOF_REQUESTED			0

/*
 * use flag to check if enabled does'nt make sence
 * since the enable bit will be clear once reach repeat time
 */
//#define	AGPOF_ENABLED			1
#define	AGPOF_INFINITE			2

struct agpo_desc {
	unsigned long		flags;
	const char		*label;
	unsigned int		hwagpo;
	struct vpl_agpo_chip	*chip;
};

struct vpl_agpo_chip {
	void __iomem		*base;
	struct clk		*clk;
	int			virq;
	struct irq_domain       *irqdomain;
	struct vpl_agpo_desc	*descs;
};

static struct agpo_desc agpo_desc[NR_AGPOS];

static inline void desc_set_label(struct agpo_desc *d, const char *label)
{
	d->label = label;
}

extern int vpl_agpo_pin_enable(unsigned int agpo, int pos);

static int agpo_device_request(struct agpo_desc *desc, const char *label)
{
	if (test_bit(AGPOF_REQUESTED, &desc->flags)) {
		pr_info("requested\n");
		return -EBUSY;
	}
	if (!try_module_get(THIS_MODULE))
		return -ENODEV;

	desc_set_label(desc, label ? label : "?");

	set_bit(AGPOF_REQUESTED, &desc->flags);

	return 0;
}

struct agpo_desc *agpo_request(int agpo, const char *label)
{
	struct agpo_desc *desc;
	unsigned long flags;
	int err;

	if (agpo < 0 || agpo >= NR_AGPOS)
		return ERR_PTR(-EINVAL);

	spin_lock_irqsave(&agpo_lock, flags);

	desc = &agpo_desc[agpo];
	if (!desc->chip) {
		desc = ERR_PTR(-EPROBE_DEFER);
		return desc;
	}

	err = agpo_device_request(desc, label);
	if (err < 0)
		desc = ERR_PTR(err);

	spin_unlock_irqrestore(&agpo_lock, flags);

	return desc;
}
EXPORT_SYMBOL_GPL(agpo_request);

void agpo_free(struct agpo_desc *desc)
{
	unsigned long flags;

	if (!desc) {
		pr_warn("%s: invalid AGPO\n", __func__);
		return;
	}

	spin_lock_irqsave(&agpo_lock, flags);

	if (!test_and_clear_bit(AGPOF_REQUESTED, &desc->flags)) {
		pr_warn("AGPO already freed\n");
		goto out;
	}

	desc_set_label(desc, NULL);

	module_put(THIS_MODULE);
out:
	/* TODO: vpl_agpo_pin_diable()?? */
	spin_unlock_irqrestore(&agpo_lock, flags);
}
EXPORT_SYMBOL(agpo_free);

/*
 * agpo_set_type() - set agpo port type
 * @desc: AGPO to set type
 * @type: new port type
 * @def_val: default value for data out between two pattern interval,
 *           i.e (@length ~ @interval)
 */
int agpo_set_type(struct agpo_desc *desc, enum agpo_port_type type,
		  unsigned int def_val)
{
	struct vpl_agpo_chip *chip = desc->chip;
	unsigned long flags;
	u32 data_offset, en_offset;
	u32 val, data;

	/*
	 * When PRT_CTRL_TYPE = 0,
	 * AGPOC_DEFAULT_DATA_OE_N is output enable (1'b0: enable)
	 * AGPOC_DEFAULT_DATA is default data between pattern interval
	 *
	 * When PRT_CTRL_TYPE = 1,
	 * AGPOC_DEFAULT_DATA is output enable controller (1'b0: enable)
	 * AGPOC_DEFAULT_DATA_OE_N is default data between pattern interval
	 *
	 */
	spin_lock_irqsave(&agpo_lock, flags);

	val = readl(chip->base + AGPOC_PORT_CTRL_TYPE);

	if (type == AGPO_PORT_TYPE_OPEN_SOURCE) {
		val &= ~BIT(desc->hwagpo);
		en_offset = AGPOC_DEFAULT_DATA_OE_N;
		data_offset = AGPOC_DEFAULT_DATA;
	} else {
		val |= BIT(desc->hwagpo);
		en_offset = AGPOC_DEFAULT_DATA;
		data_offset = AGPOC_DEFAULT_DATA_OE_N;
	}
	writel(val, chip->base + AGPOC_PORT_CTRL_TYPE);

	/*
	 * data enable
	 * NOTE: 1'b0: enabled; 1'b1: disabled
	 */
	val = readl(chip->base + en_offset);
	val &= ~BIT(desc->hwagpo);
	writel(val, chip->base + en_offset);

	/* set default data */
	data = readl(chip->base + data_offset);
	if (def_val)
		data |= BIT(desc->hwagpo);
	else
		data &= ~BIT(desc->hwagpo);
	writel(data, chip->base + data_offset);

	spin_unlock_irqrestore(&agpo_lock, flags);

	return 0;
}
EXPORT_SYMBOL(agpo_set_type);

int agpo_config(struct agpo_desc *desc, struct agpo_pattern_cfg *cfg)
{
	struct vpl_agpo_chip *chip = desc->chip;
	unsigned int hwagpo = desc->hwagpo;
	unsigned long flags;
	u32 val;

	if (!desc)
		return -EINVAL;

	if (cfg->bits_length < 1 || cfg->bits_length > AGPO_MAX_BITS_LENGTH)
		return -EINVAL;

	if ((cfg->repeat != AGPO_REPEAT_INFINITE) &&
	    (cfg->repeat < 1 || cfg->repeat > AGPO_MAX_REPEAT_TIMES))
		return -EINVAL;

	val = (((cfg->repeat - 1) & AGPOC_REPEAT_MASK) <<
			AGPOC_REPEAT_SHIFT) |
		      ((cfg->interval - 1) & AGPOC_INTERVAL_MASK);

	if (test_bit(AGPOF_INFINITE, &desc->flags)) { /* under infinite */
		spin_lock_irqsave(&agpo_lock, flags);
		writel(cfg->pattern[0], chip->base + AGPOC_UPDATE_PATTERN_0);
		writel(cfg->pattern[1], chip->base + AGPOC_UPDATE_PATTERN_1);
		writel(cfg->pattern[2], chip->base + AGPOC_UPDATE_PATTERN_2);
		writel(cfg->pattern[3], chip->base + AGPOC_UPDATE_PATTERN_3);
		writel(cfg->period - 1, chip->base + AGPOC_UPDATE_PERIOD);
		writel(cfg->bits_length - 1, chip->base + AGPOC_UPDATE_LENGTH);
		writel(val, chip->base + AGPOC_UPDATE_INTERVAL_REPEAT);

		writel(BIT(desc->hwagpo), chip->base + AGPOC_UPDATE);

		spin_unlock_irqrestore(&agpo_lock, flags);
	} else {
		spin_lock_irqsave(&agpo_lock, flags);

		writel(cfg->pattern[0], chip->base + AGPOC_PATTERN_0(hwagpo));
		writel(cfg->pattern[1], chip->base + AGPOC_PATTERN_1(hwagpo));
		writel(cfg->pattern[2], chip->base + AGPOC_PATTERN_2(hwagpo));
		writel(cfg->pattern[3], chip->base + AGPOC_PATTERN_3(hwagpo));
		writel(cfg->period - 1, chip->base + AGPOC_PERIOD(hwagpo));
		writel(cfg->bits_length - 1, chip->base + AGPOC_LENGTH(hwagpo));
		writel(val, chip->base + AGPOC_INTERVAL_REPEAT(hwagpo));

		spin_unlock_irqrestore(&agpo_lock, flags);
	}

	if (cfg->repeat == AGPO_REPEAT_INFINITE)
		set_bit(AGPOF_INFINITE, &desc->flags);
	else
		clear_bit(AGPOF_INFINITE, &desc->flags);

	return 0;
}
EXPORT_SYMBOL(agpo_config);

int agpo_enable(struct agpo_desc *desc)
{
	struct vpl_agpo_chip *chip = desc->chip;
	u32 val;
	unsigned long flags;

	if (desc) {

		spin_lock_irqsave(&agpo_lock, flags);

		val = readl(chip->base + AGPOC_CTRL);
		val |= (1 << desc->hwagpo);
		writel(val, chip->base + AGPOC_CTRL);

		spin_unlock_irqrestore(&agpo_lock, flags);
	}

	return desc ? 0 : -EINVAL;
}
EXPORT_SYMBOL(agpo_enable);

void agpo_disable(struct agpo_desc *desc)
{
	struct vpl_agpo_chip *chip = desc->chip;
	unsigned int hwagpo = desc->hwagpo;
	unsigned long flags;
	u32 old_value;
	/*
	 * To disable by AGPOC_CTRL is invalid while output is running
	 * Set AGPOC_INTERVAL_REPEAT by key value instead.
	 */
	if (desc) {
		spin_lock_irqsave(&agpo_lock, flags);

		old_value = readl(chip->base + AGPOC_INTERVAL_REPEAT(hwagpo));

		writel(AGPOC_REPEAT_STOP_NOW << AGPOC_REPEAT_SHIFT,
		       chip->base + AGPOC_INTERVAL_REPEAT(hwagpo));

		writel(old_value, chip->base + AGPOC_INTERVAL_REPEAT(hwagpo));

		clear_bit(AGPOF_INFINITE, &desc->flags);

		spin_unlock_irqrestore(&agpo_lock, flags);
	}
}
EXPORT_SYMBOL(agpo_disable);

unsigned long agpo_get_clk_rate(struct agpo_desc *desc)
{
	struct vpl_agpo_chip *chip = desc->chip;

	return clk_get_rate(chip->clk);
}
EXPORT_SYMBOL(agpo_get_clk_rate);

int agpo_to_irq(struct agpo_desc *desc)
{
	struct vpl_agpo_chip *chip = desc->chip;
	int hwagpo = desc->hwagpo;

	return irq_find_mapping(chip->irqdomain, hwagpo);
}
EXPORT_SYMBOL(agpo_to_irq);

#if 0
static int agpo_register_device(struct device *parent, int minor)
{
	dev_t devt;

	if (minor >= AGPO_DEV_MAX)
		return -EINVAL;

	devt = MKDEV(agpo_major, minor);
	device_create(agpo_class, parent, devt, NULL, "agpo%d", minor);

	return 0;
}

static int agpo_dev_init(void)
{
	int ret;

	agpo_class = class_create(THIS_MODULE, "agpo");
	if (IS_ERR(agpo_class)) {
		pr_err("couldn't create class\n");
		return PTR_ERR(agpo_class);
	}

	ret = alloc_chrdev_region(&agpo_devt, 0, AGPO_DEV_MAX, "agpo");
	if (ret) {
		pr_err("failed to allocate char dev region\n");
		goto out_destroy_class;
	}

	agpo_major = MAJOR(agpo_devt);

	cdev_init(&agpo_cdev, &agpo_dev_fops);
	ret = cdev_add(&agpo_cdev, agpo_devt, AGPO_DEV_MAX);
	if (ret) {
		pr_err("failed to allocate char dev region\n");
		goto out_unreg_chrdev;
	}

	return 0;

out_unreg_chrdev:
	unregister_chrdev_region(agpo_devt, AGPO_DEV_MAX);
out_destroy_class:
	class_destroy(agpo_class);

	return ret;
}

static void agpo_dev_exit(void)
{
	if (agpo_devt)
		unregister_chrdev_region(agpo_devt, AGPO_DEV_MAX);

	class_destroy(agpo_class);
}
#endif
static void vpl_agpo_ack_irq(struct irq_data *d)
{
	struct vpl_agpo_chip *chip_priv = irq_data_get_irq_chip_data(d);
	void __iomem *base = chip_priv->base;
	uintptr_t mask = (uintptr_t) irq_data_get_irq_handler_data(d);
	unsigned long flags;

	spin_lock_irqsave(&agpo_lock, flags);
	writel_relaxed(mask, base + AGPOC_STATUS);
	spin_unlock_irqrestore(&agpo_lock, flags);
}

static void vpl_agpo_mask_irq(struct irq_data *d)
{
	struct vpl_agpo_chip *chip_priv = irq_data_get_irq_chip_data(d);
	void __iomem *base = chip_priv->base;
	uintptr_t mask = (uintptr_t) irq_data_get_irq_handler_data(d);
	unsigned long flags;

	spin_lock_irqsave(&agpo_lock, flags);
	writel_relaxed(readl_relaxed(base + AGPOC_INTR_MASK) | mask, base + AGPOC_INTR_MASK);
	spin_unlock_irqrestore(&agpo_lock, flags);
}

static void vpl_agpo_unmask_irq(struct irq_data *d)
{
	struct vpl_agpo_chip *chip_priv = irq_data_get_irq_chip_data(d);
	void __iomem *base = chip_priv->base;
	uintptr_t mask = (uintptr_t) irq_data_get_irq_handler_data(d);
	unsigned long flags;

	spin_lock_irqsave(&agpo_lock, flags);
	writel_relaxed(readl_relaxed(base + AGPOC_INTR_MASK) & ~mask, base + AGPOC_INTR_MASK);
	spin_unlock_irqrestore(&agpo_lock, flags);
}

static struct irq_chip agpo_irqchip = {
	.name           = "AGPO",
	.irq_ack        = vpl_agpo_ack_irq,
	.irq_mask       = vpl_agpo_mask_irq,
	.irq_unmask     = vpl_agpo_unmask_irq,
};

static void vpl_agpo_irq_handler(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	struct vpl_agpo_chip *chip_priv = irq_desc_get_handler_data(desc);
	unsigned long status;
	unsigned int pin;

	chained_irq_enter(chip, desc);
	status = readl(chip_priv->base + AGPOC_STATUS);
	for_each_set_bit(pin, &status, NR_AGPOS) {
		generic_handle_irq(irq_find_mapping(chip_priv->irqdomain, pin));
	}
	chained_irq_exit(chip, desc);
}

static int vpl_agpo_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct vpl_agpo_chip *chip_priv;
	struct resource *res;
	int i;

	chip_priv = devm_kzalloc(dev, sizeof(*chip_priv), GFP_KERNEL);

	if (!chip_priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	chip_priv->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(chip_priv->base))
		return PTR_ERR(chip_priv->base);

	chip_priv->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(chip_priv->clk))
		return PTR_ERR(chip_priv->clk);

	clk_prepare_enable(chip_priv->clk);

	chip_priv->virq = platform_get_irq(pdev, 0);
	if (chip_priv->virq < 0) {
		dev_err(dev, "no irq resource specified\n");
		return chip_priv->virq;
	}

	platform_set_drvdata(pdev, chip_priv);

#if 0
	/* agpo class and device */
	ret = agpo_dev_init();
	if (ret)
		return ret;
#endif
	for (i = 0; i < NR_AGPOS; i++) {
		agpo_desc[i].hwagpo = i;
		agpo_desc[i].chip = chip_priv;
	}

	writel(0xFFFFFFFF, chip_priv->base + AGPOC_INTR_MASK);

	chip_priv->irqdomain = irq_domain_add_linear(dev->of_node, NR_AGPOS,
			&irq_domain_simple_ops, chip_priv);
	if (!chip_priv->irqdomain)
		return -EINVAL;

	for (i = 0; i < NR_AGPOS; i++) {
		int irq = irq_create_mapping(chip_priv->irqdomain, i);

		irq_set_chip_data(irq, chip_priv);
		irq_set_chip_and_handler(irq, &agpo_irqchip, handle_level_irq);
		irq_set_handler_data(irq, (void *)BIT(i));
	}

	irq_set_chained_handler_and_data(chip_priv->virq, vpl_agpo_irq_handler,
					 chip_priv);

	dev_info(dev, "module loaded\n");
	return 0;
}

/*-------------------------------------------------------*/
static int vpl_agpo_remove(struct platform_device *pdev)
{
	struct vpl_agpo_chip *chip_priv = platform_get_drvdata(pdev);
	int hwirq;
#if 0
	for (i = 0; i < NR_AGPOS; i++)
		device_destroy(agpo_class, MKDEV(agpo_major, i));
#endif
	for (hwirq = 0; hwirq < NR_AGPOS; hwirq++)
		irq_dispose_mapping(irq_find_mapping(chip_priv->irqdomain, hwirq));

	if (chip_priv->virq) {
		irq_set_handler_data(chip_priv->virq, NULL);
		irq_set_chained_handler(chip_priv->virq, NULL);
		irq_domain_remove(chip_priv->irqdomain);
	}

	clk_disable_unprepare(chip_priv->clk);
#if 0
	agpo_dev_exit();
#endif
	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int vpl_agpo_suspend_late(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct vpl_agpo_chip *priv_data = platform_get_drvdata(pdev);

	clk_disable_unprepare(priv_data->clk);

	return 0;
}

static int vpl_agpo_resume_early(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct vpl_agpo_chip *priv_data = platform_get_drvdata(pdev);
	int ret;

	ret = clk_prepare_enable(priv_data->clk);

	return ret;
}
#endif
/*-------------------------------------------------------*/
static const struct dev_pm_ops vpl_agpo_pm_ops = {
	SET_LATE_SYSTEM_SLEEP_PM_OPS(vpl_agpo_suspend_late,
		vpl_agpo_resume_early)
};

static const struct of_device_id vpl_agpo_of_match[] = {
	{ .compatible = "vatics,vpl-agpo", },
	{}
};
MODULE_DEVICE_TABLE(of, vpl_agpo_of_match);

static struct platform_driver vpl_agpo_driver = {
	.probe = vpl_agpo_probe,
	.remove	= vpl_agpo_remove,
	.driver = {
		.name = "vpl_agpo",
		.owner = THIS_MODULE,
		.pm = &vpl_agpo_pm_ops,
		.of_match_table = vpl_agpo_of_match,
	},
};
module_platform_driver(vpl_agpo_driver);

MODULE_DESCRIPTION("VATICS VPL AGPOC driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:agpo");
