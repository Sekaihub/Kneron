// SPDX-License-Identifier: <SPDX License Expression>
/*
 * Copyright (c) 2020 VATICS Inc.
 *
 */

#include <linux/delay.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/mfd/syscon.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include <linux/mfd/core.h>
#include <linux/regmap.h>
#include <linux/types.h>
#include <linux/mfd/sgc22300.h>

#define PMU_RW_TIMEOUT		1000
enum pmu_trim_type {
	PMU_TRIM_CT = 0,
	PMU_TRIM_TT,
	PMU_TRIM_VT,
	PMU_TRIM_IT,
};


static struct mfd_cell sgc_sb_cells[] = {
	{
		.name = "sgc-rtc",
		.of_compatible = "vatics,sgc-rtc",
	},
	{
		.name = "sgc-gpadc",
		.of_compatible = "vatics,sgc-gpadc",
	},
};

static void sgc_pmu_check_start_stat(struct sgc_data *sgc, unsigned int val)
{
	struct regmap *regmap = sgc->rmap;
	u32 stat;

	do {
		regmap_write(regmap, PMU_CTRL_SHIFT, val);
		regmap_read(regmap, PMU_CTRL_SHIFT, &stat);
	} while ((stat & SHIFT_START_STAT) != SHIFT_START_STAT);

}

int sgc_pmu_shift_reg_read(struct sgc_data *sgc, unsigned int reg,
			   unsigned int *val)
{
	struct regmap *regmap = sgc->rmap;
	u32 stat, reg_shift = 0;
	int ret = 0, times = 0;

	mutex_lock(&sgc->lock);

	reg_shift = reg << SHIFT_ADDR_SHIFT;
	reg_shift |= SHIFT_START_MASK;

	/* avoid trigger start bit not work */
	sgc_pmu_check_start_stat(sgc, reg_shift);

	do {
		if (++times > PMU_RW_TIMEOUT) {
			dev_err(sgc->dev, "pmu shift reg read timeout error!!\n");
			ret = -1;
			break;
		}

		usleep_range(550, 600);
		regmap_read(regmap, PMU_GEN_STAT, &stat);
	} while ((stat & SHIFT_DONE_STAT) != SHIFT_DONE_STAT);

	regmap_read(regmap, PMU_RDATA_SHIFT, val);
	regmap_write(regmap, PMU_STAT_CLEAR, SHIFT_DONE_CLEAR);

	mutex_unlock(&sgc->lock);

	return ret;
}
EXPORT_SYMBOL_GPL(sgc_pmu_shift_reg_read);

int sgc_pmu_shift_reg_write(struct sgc_data *sgc, unsigned int reg,
			    unsigned int val)
{
	struct regmap *regmap = sgc->rmap;
	u32 stat, reg_shift = 0;
	int ret = 0, times = 0;

	mutex_lock(&sgc->lock);

	regmap_write(regmap, PMU_WDATA_SHIFT, val);
	reg_shift = reg << SHIFT_ADDR_SHIFT;
	reg_shift |= SHIFT_W_EN_MASK | SHIFT_START_MASK;

	/* avoid read/write trigger start bit not work */
	sgc_pmu_check_start_stat(sgc, reg_shift);

	do {
		if (++times > PMU_RW_TIMEOUT) {
			dev_err(sgc->dev, "pmu shift reg write timeout error!!\n");
			ret = -1;
			break;
		}

		usleep_range(550, 600);
		regmap_read(regmap, PMU_GEN_STAT, &stat);
	} while ((stat & SHIFT_DONE_STAT) != SHIFT_DONE_STAT);

	regmap_write(regmap, PMU_STAT_CLEAR, SHIFT_DONE_CLEAR);
	mutex_unlock(&sgc->lock);

	return ret;
}
EXPORT_SYMBOL_GPL(sgc_pmu_shift_reg_write);

static const struct regmap_config sgc_regmap_config = {
	.reg_bits = 32,
	.reg_stride = 4,
	.val_bits = 32,
	.max_register = 0x1C,
};

static void sgc_set_trim_reg_trim_word(struct sgc_data *sgc, u32 val,
				       enum pmu_trim_type trim_type)
{
	int trim, trim_mask, trim_shift, ret;

	switch (trim_type) {
	case PMU_TRIM_CT:
		trim_mask = SGC_TRIM_CT_MASK;
		trim_shift = SGC_TRIM_CT_SHIFT;
		break;
	case PMU_TRIM_TT:
		trim_mask = SGC_TRIM_TT_MASK;
		trim_shift = SGC_TRIM_TT_SHIFT;
		break;
	case PMU_TRIM_VT:
		trim_mask = SGC_TRIM_VT_MASK;
		trim_shift = SGC_TRIM_VT_SHIFT;
		break;
	case PMU_TRIM_IT:
		trim_mask = SGC_TRIM_IT_MASK;
		trim_shift = SGC_TRIM_IT_SHIFT;
		break;
	default:
		dev_err(sgc->dev, "set sgc trim type error !!\n");
		return;
	};

	ret = sgc_pmu_shift_reg_read(sgc, SGC_TRIM, &trim);
	if (ret)
		goto failed;

	trim &= ~trim_mask;
	trim |= val << trim_shift;
	ret = sgc_pmu_shift_reg_write(sgc, SGC_TRIM, trim);
	if (ret)
		goto failed;

	return;
failed:
	dev_err(sgc->dev, "set sgc trim word failed !!\n");
}

static int sgc22300_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node, *node;
	struct device *dev = &pdev->dev;
	struct sgc_data *sgc;
	struct resource *res;
	struct regmap *sysc_rmap;
	u32 val;

	sgc = devm_kzalloc(dev, sizeof(*sgc), GFP_KERNEL);
	if (!sgc)
		return -ENOMEM;

	sgc->dev = dev;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	sgc->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(sgc->base))
		return PTR_ERR(sgc->base);

	sgc->rmap = devm_regmap_init_mmio(dev, sgc->base, &sgc_regmap_config);
	if (IS_ERR(sgc->rmap)) {
		dev_err(dev, "Failed to initialise regmap\n");
		return PTR_ERR(sgc->base);
	}

	node = of_parse_phandle(np, "sysc-regmap", 0);
	if (node) {
		sysc_rmap = syscon_node_to_regmap(node);
		if (IS_ERR(sysc_rmap))
			return PTR_ERR(sysc_rmap);
	} else {
		dev_err(dev, "Cannot find sysc regmap\n");
		return -EINVAL;
	}

	mutex_init(&sgc->lock);
	regcache_cache_bypass(sgc->rmap, true);
	platform_set_drvdata(pdev, sgc);

	/* set otp vt */
	regmap_read(sysc_rmap, SYSC_HW_CONFIG_INFO_0, &val);
	val = (val & SYSC_OPT_VT_MASK) >> SYSC_OPT_VT_SHIFT;
	sgc_set_trim_reg_trim_word(sgc, val, PMU_TRIM_VT);

	devm_mfd_add_devices(sgc->dev, -1, sgc_sb_cells,
			     ARRAY_SIZE(sgc_sb_cells), NULL, 0, NULL);

	return 0;
}

static const struct of_device_id sgc22300_of_match[] = {
	{ .compatible = "vatics,siga_pmu" },
	{ },
};
MODULE_DEVICE_TABLE(of, sgc22300_of_match);

static struct platform_driver sgc22300_driver = {
	.driver = {
		.name		= "siga_pmu",
		.of_match_table	= sgc22300_of_match,
	},
	.probe	= sgc22300_probe,
};
module_platform_driver(sgc22300_driver);

MODULE_DESCRIPTION("VTX SIGA KNR01 driver");
MODULE_LICENSE("GPL");
