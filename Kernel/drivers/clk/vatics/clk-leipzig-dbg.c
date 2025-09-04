// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>

#include "clk-leipzig.h"
#include "clk-pll.h"

static struct platform_device *vpl_clk_dbg_device;

static struct regmap *pll_regmap;
static struct regmap *sysc_regmap;

static u32 pll_reg[] = {
	PLL_0_BASE,
	PLL_1_BASE,
	PLL_2_BASE,
	PLL_3_BASE,
	PLL_4_BASE,
	PLL_5_BASE,
	PLL_6_BASE,
	PLL_7_BASE,
	PLL_8_BASE,
	PLL_9_BASE,
};

/*
 * PLLC type
 *
 * 1: fraction PLLC
 * 0: integer PLLC
 **/
static u32 check_pll_frac[] = {
	1, // pll_0
	0, // pll_1
	0, // pll_2
	0, // pll_3
	0, // pll_4
	1, // pll_5
	1, // pll_6
	1, // pll_7
	1, // pll_8
	1, // pll_9
};

static ssize_t pll_program_store(struct device *dev, struct device_attribute
				     *attr, const char *buf, size_t count)
{
	int rv = 0;
	unsigned int val = 0;
	unsigned int pll_num = 0;
	unsigned int ref_div = 0;
	unsigned int post_div1 = 0;
	unsigned int post_div2 = 0;
	unsigned int fb_int_div = 0;
	unsigned int fb_frac_div = 0;

	unsigned int frac_en = 0;
	unsigned int ssm_en = 0; /* enable ssm */
	unsigned int depth = 0;
	unsigned int fmod = 0;
	unsigned int ssm_type = 0;

	rv = sscanf(buf, "%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d\n", &pll_num,
		    &ref_div, &post_div1, &post_div2, &fb_int_div, &fb_frac_div,
		    &frac_en, &ssm_en, &depth, &fmod, &ssm_type);
	if (rv != 11) {
		pr_err("%s: expected 11 args, got %d\n", __func__, rv);
		return -EINVAL;
	}

	pr_info("pll_num: %d, ref_div: %d, post_div1: %d, post_div2: %d, ",
		pll_num, ref_div, post_div1, post_div2);
	pr_info("fb_int_div: %d, fb_frac_div: %d, frac_en: %d",
		fb_int_div, fb_frac_div, frac_en);
	pr_info("ssm_en: %d, depth: %d, fmod: %d, ssm_type: %d\n",
		ssm_en, depth, fmod, ssm_type);

	/* update divider control 0 */
	val = ((ref_div << PLL_REF_DIV_SHIFT) |
		(post_div1 << PLL_POST_DIV1_SHIFT) |
		(post_div2 << PLL_POST_DIV2_SHIFT) |
		(fb_int_div << PLL_FB_INT_DIV_SHIFT));

	regmap_write(pll_regmap, pll_reg[pll_num] + PLL_DIV_0, val);


	if (check_pll_frac[pll_num] == 1) {
		/* update divider control 1 */
		val = 0;
		val = (fb_frac_div << PLL_FB_FRAC_DIV_SHIFT);
		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_DIV_1, val);

		/* SSM */
		val = 0;
		val = (depth << PLL_SSM_DEPTH_SHIFT) |
			(fmod << PLL_SSM_FMODE_SHIFT) |
			(ssm_type << PLL_SSM_TYPE_SHIFT);

		if (ssm_en == 1)
			val |= BIT(PLL_SSM_EN_SHIFT);

		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_SSM, val);

		/* frac_en */
		regmap_read(pll_regmap, pll_reg[pll_num] + PLL_CTRL, &val);
		if (frac_en) {
			val |= (VTX_PLL_UPDATE | VTX_PLL_FRAC);
		} else {
			val &= ~(frac_en << 3);
			val |= (VTX_PLL_UPDATE);
		}
		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_CTRL, val);
	} else {
		regmap_read(pll_regmap, pll_reg[pll_num] + PLL_CTRL, &val);
		val |= (VTX_PLL_UPDATE);
		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_CTRL, val);
	}

	/* wait update complete */
	while (regmap_read(pll_regmap, pll_reg[pll_num] + PLL_CTRL, &val) &
	       VTX_PLL_UPDATE) {
		// do nothing
	}

	pr_info("PLL %d register:\n", pll_num);
	regmap_read(pll_regmap, pll_reg[pll_num] + PLL_CTRL, &val);
	pr_info("ctrl = %x, ", val);
	regmap_read(pll_regmap, pll_reg[pll_num] + PLL_DIV_0, &val);
	pr_info("div_0 = %x, ", val);
	regmap_read(pll_regmap, pll_reg[pll_num] + PLL_DIV_1, &val);
	pr_info("div_1 = %x, ", val);
	regmap_read(pll_regmap, pll_reg[pll_num] + PLL_SSM, &val);
	pr_info("ssm = %x, ", val);

	return count;
}

static ssize_t pll_ssm_en_store(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	int rv = 0;
	unsigned int val = 0;
	unsigned int pll_num = 0;
	unsigned int ssm_en = 0; /* enable ssm */

	rv = sscanf(buf, "%d:%d\n", &pll_num, &ssm_en);
	if (rv != 2) {
		pr_err("%s: expected 2 args, got %d\n", __func__, rv);
		return -EINVAL;
	}

	if (check_pll_frac[pll_num] == 1) {
		regmap_read(pll_regmap, pll_reg[pll_num] + PLL_SSM, &val);

		if (ssm_en == 0)
			val &= ~BIT(PLL_SSM_EN_SHIFT);
		else
			val |= BIT(PLL_SSM_EN_SHIFT);

		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_SSM, val);
	}

	return count;
}

static ssize_t monitor_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	unsigned int val = 0;
	unsigned int monitor_num = 0;
	unsigned int monitor_div = 0;

	regmap_read(sysc_regmap, 0xC4, &val);
	monitor_num = val & 0x7F;
	monitor_div = (val & 0x700) >> 8;

	return sprintf(buf, "num:div=%d:%d\n", monitor_num, monitor_div);
}

static ssize_t monitor_store(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	int rv = 0;
	unsigned int val = 0;
	unsigned int monitor_num = 0;
	unsigned int monitor_div = 0;
	unsigned int pll_num = 0;

	rv = sscanf(buf, "%d:%d\n", &monitor_num, &monitor_div);
	if (rv != 2) {
		pr_err("%s: expected 2 args, got %d\n", __func__, rv);
		return -EINVAL;
	}

	if (monitor_div > 7) {
		pr_info("ERROR: monitor divider is a wrong value %d\n",
		       monitor_div);
		pr_info("ERROR: valid range is from 0 to 7\n");
		return -EINVAL;
	}

	if (monitor_num > 111 || monitor_num == 0) {
		pr_info("ERROR: monitor number is a wrong value %d\n",
		       monitor_num);
		pr_info("ERROR: valid range is from 1 to 111\n");
		return -EINVAL;
	}

	/* For PLL, need to enable slow clock output */
	if (monitor_num >= 14 && monitor_num <= 23) {
		pll_num = monitor_num - 14;

		regmap_read(pll_regmap, pll_reg[pll_num] + PLL_CTRL, &val);
		val |= VTX_PLL_SLOW_CLK_OUT;
		regmap_write(pll_regmap, pll_reg[pll_num] + PLL_CTRL, val);
	}

	val = 0;
	val = (monitor_div << 8) | (monitor_num);
	regmap_write(sysc_regmap, 0xC4, val);

	return count;
}

static DEVICE_ATTR_WO(pll_program);
static DEVICE_ATTR_WO(pll_ssm_en);
static DEVICE_ATTR_RW(monitor);

static struct attribute *clk_attrs[] = {
	&dev_attr_pll_program.attr,
	&dev_attr_pll_ssm_en.attr,
	&dev_attr_monitor.attr,
	NULL,
};

static const struct attribute_group clk_attr_group = {
	.name = "clk_dbg",
	.attrs = clk_attrs,
};

static int vpl_clk_dbg_probe(struct platform_device *device)
{
	struct device *dev = &device->dev;
	int err = 0;

	err = sysfs_create_group(&device->dev.kobj, &clk_attr_group);
	if (err) {
		dev_err(dev, "Unable to export clk_dbg sysfs, error: %d\n",
			err);
		goto fail_sysfs;
	}

	pll_regmap = syscon_regmap_lookup_by_compatible("vatics,leipzig-pll");
	if (IS_ERR(pll_regmap)) {
		dev_err(dev, "missing pll-regmap phandle\n");
		return PTR_ERR(pll_regmap);
	}

	sysc_regmap =
		syscon_regmap_lookup_by_compatible("vatics,leipzig-syscon");
	if (IS_ERR(sysc_regmap))
		return PTR_ERR(sysc_regmap);


	return 0;

fail_sysfs:
	sysfs_remove_group(&device->dev.kobj, &clk_attr_group);
	return err;
}

static struct platform_driver vpl_clk_dbg_driver = {
	.probe          = vpl_clk_dbg_probe,
	.driver         = {
		.name   = "vpl_clk_dbg",
		.owner  = THIS_MODULE,
	}
};

static int __init vpl_clk_dbg_init(void)
{
	vpl_clk_dbg_device = platform_device_alloc("vpl_clk_dbg", -1);
	platform_device_add(vpl_clk_dbg_device);
	return platform_driver_register(&vpl_clk_dbg_driver);
}
late_initcall(vpl_clk_dbg_init);
