// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2023 VATICS Inc.
 */

#include <common.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <asm-generic/gpio.h>
#include <dm/pinctrl.h>

static int vpl_gpio_set_value(struct udevice *dev, u32 gpio, s32 value)
{
	u32 offset = gpio;
	struct gpio_bank *bank = dev_get_priv(dev);
	u8 *base = bank->base;

	if (value)
		writel(BIT(offset), base + GPIOC_DATA_SET);
	else
		writel(BIT(offset), base + GPIOC_DATA_CLR);

	return 0;
}

static int vpl_gpio_get_value(struct udevice *dev, u32 gpio)
{
	u32 offset = gpio;
	struct gpio_bank *bank = dev_get_priv(dev);
	u8 *base = bank->base;
	u32 data;

	if (readl(base + GPIOC_PIN_DIR) & BIT(offset))
		data = readl(base + GPIOC_DATA_OUT);
	else
		data = readl(base + GPIOC_DATA_IN);

	return (data >> offset) & 1;
}

static int vpl_gpio_request(struct udevice *dev,
			    u32 gpio, const char *label)
{
	u32 ret = 0;

	if (gpio >= LEIPZIG_GPIO_COUNT)
		return -EINVAL;

	ret = pinctrl_gpio_request(dev, gpio);
	return ret;
}

static int vpl_gpio_free(struct udevice *dev, u32 gpio)
{
	u32 ret = 0;

	if (gpio >= LEIPZIG_GPIO_COUNT)
		return -EINVAL;

	ret = pinctrl_gpio_free(dev, gpio);

	return ret;
}

inline void vpl_gpio_toggle_value(u32 gpio)
{
	gpio_set_value(gpio, !gpio_get_value(gpio));
}

static int vpl_gpio_direction_input(struct udevice *dev, u32 gpio)
{
	u32 offset = gpio;
	struct gpio_bank *bank = dev_get_priv(dev);
	u8 *base = bank->base;
	u32 val;

	val = readl(base + GPIOC_PIN_DIR);
	writel(val & ~BIT(offset), base + GPIOC_PIN_DIR);

	return 0;
}

static int vpl_gpio_direction_output(struct udevice *dev, u32 gpio,
				     s32 value)
{
	u32 offset = gpio;
	struct gpio_bank *bank = dev_get_priv(dev);
	u8 *base = bank->base;
	u32 val;

	val = readl(base + GPIOC_PIN_DIR);
	if (value)
		writel(BIT(offset), base + GPIOC_DATA_SET);
	else
		writel(BIT(offset), base + GPIOC_DATA_CLR);

	writel(val | BIT(offset), base + GPIOC_PIN_DIR);

	return 0;
}

static int vpl_gpio_probe(struct udevice *dev)
{
	struct gpio_bank *bank = dev_get_priv(dev);
	struct vpl_gpio_plat *plat = dev_get_plat(dev);
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	char name[18], *str;

	sprintf(name, "GPIO%d_", plat->bank_index);

	str = strdup(name);
	if (!str)
		return -ENOMEM;

	uc_priv->bank_name = str;
	uc_priv->gpio_count = LEIPZIG_GPIO_COUNT_PER_BANK;

	bank->base = dev_read_addr_ptr(dev);

	return 0;
}

static const struct dm_gpio_ops gpio_leipzig_ops = {
	.request		= vpl_gpio_request,
	.rfree			= vpl_gpio_free,
	.direction_input	= vpl_gpio_direction_input,
	.direction_output	= vpl_gpio_direction_output,
	.get_value		= vpl_gpio_get_value,
	.set_value		= vpl_gpio_set_value,
};

static const struct udevice_id vpl_gpio_ids[] = {
	{ .compatible = "vatics,vpl-gpio" },
	{ }
};

U_BOOT_DRIVER(gpio_leipzig) = {
	.name	= "vatics_gpio",
	.id	= UCLASS_GPIO,
	.of_match = vpl_gpio_ids,
	.ops	= &gpio_leipzig_ops,
	.probe	= vpl_gpio_probe,
	.priv_auto	= sizeof(struct gpio_bank),
};
