// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2024 VATICS Inc.
 *
 * Based on tps6586x-regulator
 * Copyright (C) 2010 Compulab Ltd.
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/regulator/of_regulator.h>
#include <linux/io.h>
#include <linux/syscore_ops.h>
#include <linux/regmap.h>
#include <linux/mfd/syscon.h>

#define VSEL_REG 0xE8

enum {
	LEIPZIG_REGULATOR_ID_PD_1,
	LEIPZIG_REGULATOR_ID_PD_5,
	LEIPZIG_REGULATOR_ID_PD_6,
	LEIPZIG_REGULATOR_ID_PD_9,
	LEIPZIG_REGULATOR_ID_PD_10,
	LEIPZIG_REGULATOR_ID_PD_11,
	LEIPZIG_REGULATOR_ID_PD_13,
	LEIPZIG_REGULATOR_ID_MAX_REGULATOR,
};

static unsigned int leipzig_default_vol[LEIPZIG_REGULATOR_ID_MAX_REGULATOR];

static unsigned int saved_vsel_reg;

struct leipzig_platform_data {
	struct regulator_init_data *reg_init_data[LEIPZIG_REGULATOR_ID_MAX_REGULATOR];
};

struct leipzig_regulator {
	struct regulator_desc desc;
	unsigned int default_vol;
	struct regmap *sysc_regmap;
};

static const unsigned int leipzig_pd_voltages[] = {
	3300000, 2500000, 1800000,
};

static int leipzig_do_set_voltage(const struct regulator_desc *desc,
				  struct regmap *sysc_regmap,
				  int min_uV)
{
	unsigned int val = 0;
	unsigned int idx = 0;

	if (min_uV == 3300000)
		idx = 0;
	else if (min_uV == 2500000)
		idx = 1;
	else /*2.5V or 1.2V*/
		idx = 2;
	regmap_read(sysc_regmap, desc->vsel_reg, &val);
	val &= ~desc->vsel_mask;
	val |= idx << (4 * desc->id);
	regmap_write(sysc_regmap, desc->vsel_reg, val);

	return 0;
}

static int leipzig_regulator_set_voltage(struct regulator_dev *dev,
					int min_uV, int max_uV,
					unsigned int *selector)
{
	return leipzig_do_set_voltage(dev->desc, dev->regmap, min_uV);
}

static int leipzig_regulator_get_voltage(struct regulator_dev *dev)
{
	unsigned int idx = 0;

	idx = regulator_get_voltage_sel_regmap(dev);
	return leipzig_pd_voltages[idx];
}

static const struct regulator_ops leipzig_regulator_ops = {
	.list_voltage = regulator_list_voltage_table,
	.map_voltage = regulator_map_voltage_ascend,
	.get_voltage = leipzig_regulator_get_voltage,
	.set_voltage = leipzig_regulator_set_voltage,
};

#define LEIPZIG_REGULATOR(_id, _pin_name, vdata, vreg, shift, nbits)	\
	.desc	= {							\
		.supply_name = _pin_name,				\
		.name	= "REG-" #_id,					\
		.ops	= &leipzig_regulator_ops,			\
		.type	= REGULATOR_VOLTAGE,				\
		.id	= LEIPZIG_REGULATOR_ID_##_id,			\
		.n_voltages = ARRAY_SIZE(leipzig_##vdata##_voltages),	\
		.volt_table = leipzig_##vdata##_voltages,		\
		.owner	= THIS_MODULE,					\
		.enable_reg = 0,			\
		.enable_mask = 0,				\
		.vsel_reg = VSEL_REG,				\
		.vsel_mask = ((1 << (nbits)) - 1) << (shift),		\
	},								\

#define LEIPZIG_PD(_id, _pname, vdata, vreg, shift, nbits)		\
{									\
	LEIPZIG_REGULATOR(_id, _pname, vdata, vreg, shift, nbits)	\
}
static struct leipzig_regulator leipzig_regulator[] = {
	LEIPZIG_PD(PD_1, "PD_1", pd, VSEL, 0, 2),
	LEIPZIG_PD(PD_5, "PD_5", pd, VSEL, 4, 2),
	LEIPZIG_PD(PD_6, "PD_6", pd, VSEL, 8, 2),
	LEIPZIG_PD(PD_9, "PD_9", pd, VSEL, 12, 2),
	LEIPZIG_PD(PD_10, "PD_10", pd, VSEL, 16, 2),
	LEIPZIG_PD(PD_11, "PD_11", pd, VSEL, 20, 2),
	LEIPZIG_PD(PD_13, "PD_13", pd, VSEL, 24, 2),
};

static inline struct leipzig_regulator *find_regulator_info(int id)
{
	struct leipzig_regulator *ri;
	int i;

	for (i = 0; i < ARRAY_SIZE(leipzig_regulator); i++) {
		ri = &leipzig_regulator[i];
		if (ri->desc.id == id)
			return ri;
	}
	return NULL;
}

#ifdef CONFIG_OF
static struct of_regulator_match leipzig_matches[] = {
	{ .name = "pd_1",    .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_1},
	{ .name = "pd_5",    .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_5},
	{ .name = "pd_6",    .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_6},
	{ .name = "pd_9",    .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_9},
	{ .name = "pd_10",   .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_10},
	{ .name = "pd_11",   .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_11},
	{ .name = "pd_13",   .driver_data = (void *)LEIPZIG_REGULATOR_ID_PD_13},
};

static struct leipzig_platform_data *leipzig_parse_regulator_dt(
		struct platform_device *pdev,
		struct of_regulator_match **leipzig_reg_matches)
{
	const unsigned int num = ARRAY_SIZE(leipzig_matches);
	struct device_node *np = pdev->dev.of_node;
	struct device_node *regs;
	unsigned int i;
	struct leipzig_platform_data *pdata;
	int err;

	regs = of_get_child_by_name(np, "regulators");
	if (!regs) {
		dev_err(&pdev->dev, "regulator node not found\n");
		return NULL;
	}

	err = of_regulator_match(&pdev->dev, regs, leipzig_matches, num);
	of_node_put(regs);
	if (err < 0) {
		dev_err(&pdev->dev, "Regulator match failed, e %d\n", err);
		return NULL;
	}

	pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	for (i = 0; i < num; i++) {
		if (!leipzig_matches[i].init_data)
			continue;

		pdata->reg_init_data[i] = leipzig_matches[i].init_data;
	}
	*leipzig_reg_matches = leipzig_matches;
	return pdata;
}
#else
static struct leipzig_platform_data *leipzig_parse_regulator_dt(
		struct platform_device *pdev,
		struct of_regulator_match **leipzig_reg_matches)
{
	*leipzig_reg_matches = NULL;
	return NULL;
}
#endif

static int leipzig_regulator_probe(struct platform_device *pdev)
{
	struct leipzig_regulator *ri = NULL;
	struct regulator_config config = { };
	struct regulator_dev **rdev;
	struct regulator_init_data *reg_data;
	struct leipzig_platform_data *pdata;
	struct of_regulator_match *leipzig_reg_matches = NULL;
	int id;
	int err;
	struct device_node *np = pdev->dev.of_node;
	unsigned int val;
	unsigned int i = 0;
	struct regmap *sysc_regmap;

	dev_dbg(&pdev->dev, "Probing regulator\n");

	sysc_regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
						      "sysc-regmap");

	for (i = 0; i < LEIPZIG_REGULATOR_ID_MAX_REGULATOR; ++i)
		leipzig_default_vol[i] = 3300000;

	if (!of_property_read_u32(np, "pd1-default", &val))
		leipzig_default_vol[0] = val;
	if (!of_property_read_u32(np, "pd5-default", &val))
		leipzig_default_vol[1] = val;
	if (!of_property_read_u32(np, "pd6-default", &val))
		leipzig_default_vol[2] = val;
	if (!of_property_read_u32(np, "pd9-default", &val))
		leipzig_default_vol[3] = val;
	if (!of_property_read_u32(np, "pd10-default", &val))
		leipzig_default_vol[4] = val;
	if (!of_property_read_u32(np, "pd11-default", &val))
		leipzig_default_vol[5] = val;
	if (!of_property_read_u32(np, "pd13-default", &val))
		leipzig_default_vol[6] = val;

	pdata = leipzig_parse_regulator_dt(pdev,
			&leipzig_reg_matches);

	if (!pdata) {
		dev_err(&pdev->dev, "Platform data not available, exiting\n");
		return -ENODEV;
	}

	rdev = devm_kzalloc(&pdev->dev, LEIPZIG_REGULATOR_ID_MAX_REGULATOR *
				sizeof(*rdev), GFP_KERNEL);
	if (!rdev)
		return -ENOMEM;

	for (id = 0; id < LEIPZIG_REGULATOR_ID_MAX_REGULATOR; ++id) {
		reg_data = pdata->reg_init_data[id];

		ri = find_regulator_info(id);

		if (!ri) {
			dev_err(&pdev->dev, "invalid regulator ID specified\n");
			err = -EINVAL;
			goto fail;
		}
		ri->default_vol = leipzig_default_vol[id];

		// preinit default voltage
		err = leipzig_do_set_voltage(&ri->desc, sysc_regmap, ri->default_vol);
		if (err) {
			dev_err(&pdev->dev,
				"regulator %d preinit failed, e %d\n", id, err);
			goto fail;
		}

		config.dev = pdev->dev.parent;
		config.init_data = reg_data;
		config.driver_data = ri;
		config.regmap = sysc_regmap;

		if (leipzig_reg_matches)
			config.of_node = leipzig_reg_matches[id].of_node;

		rdev[id] = devm_regulator_register(&pdev->dev, &ri->desc, &config);
		if (IS_ERR(rdev[id])) {
			dev_err(&pdev->dev, "failed to register regulator %s\n",
					ri->desc.name);
			err = PTR_ERR(rdev[id]);
			goto fail;
		}

	}

	platform_set_drvdata(pdev, rdev);
	return 0;

fail:
	while (--id >= 0)
		regulator_unregister(rdev[id]);
	return err;
}

static int leipzig_regulator_remove(struct platform_device *pdev)
{
	struct regulator_dev **rdev = platform_get_drvdata(pdev);
	int id = LEIPZIG_REGULATOR_ID_MAX_REGULATOR;

	while (--id >= 0)
		regulator_unregister(rdev[id]);

	return 0;
}

#if defined(CONFIG_OF)
static const struct of_device_id leipzig_regulator_of_match[] = {
	{ .compatible = "vatics,regulator", },
	{},
};
#endif

static int leipzig_regulator_suspend(void)
{
	saved_vsel_reg = readl_relaxed((void *)VSEL_REG);
	return 0;
}

static void leipzig_regulator_resume(void)
{
	writel_relaxed(saved_vsel_reg, (void *)VSEL_REG);
}

static struct syscore_ops leipzig_regulator_syscore_ops = {
	.suspend = leipzig_regulator_suspend,
	.resume = leipzig_regulator_resume,
};

static struct platform_driver leipzig_regulator_driver = {
	.driver	= {
		.name	= "vatics,regulator",
		.owner	= THIS_MODULE,
		.of_match_table = of_match_ptr(leipzig_regulator_of_match),
	},
	.probe		= leipzig_regulator_probe,
	.remove		= leipzig_regulator_remove,
};

static int __init leipzig_regulator_init(void)
{
	register_syscore_ops(&leipzig_regulator_syscore_ops);
	return platform_driver_register(&leipzig_regulator_driver);
}
subsys_initcall(leipzig_regulator_init);

static void __exit leipzig_regulator_exit(void)
{
	platform_driver_unregister(&leipzig_regulator_driver);
}
module_exit(leipzig_regulator_exit);

MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:leipzig-regulator");
