// SPDX-License-Identifier: GPL-2.0-only
/*
 * VTX Secure Monitor driver
 *
 * Copyright (C) 2024 Kneron, Inc.
 * Author: Jun Chen <jun.chen@kneron.us>
 */

#include <linux/arm-smccc.h>
#include <linux/bug.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/sizes.h>
 #include <linux/slab.h>

#include "vtx-sip-smc.h"

static ssize_t boot_flag_store(struct device *dev,
		struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct arm_smccc_res res;

	if (strncmp(buf, "0", 1) == 0)
		arm_smccc_smc(VTX_SIP_SVC_SETBOOTDONE, 0, 0, 0, 0, 0, 0, 0, &res);
	else
		arm_smccc_smc(VTX_SIP_SVC_CLEARBOOTDONE, 0, 0, 0, 0, 0, 0, 0, &res);

	return count;
}

static ssize_t boot_flag_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct arm_smccc_res res;
	u32 ret;

	arm_smccc_smc(VTX_SIP_GET_PMU_GPR, 0, 0, 0, 0, 0, 0, 0, &res);

	if (!res.a0)
		ret = sprintf(buf, "(0x%lx) Flag clear\n", res.a0);
	else
		ret = sprintf(buf, "(0x%lx) Flag set\n", res.a0);


	return ret;
}

static DEVICE_ATTR_RW(boot_flag);

static struct attribute *vtx_sip_smc_sysfs_attributes[] = {
	&dev_attr_boot_flag.attr,
	NULL,
};

static const struct attribute_group vtx_sip_smc_attr_group = {
	.attrs = vtx_sip_smc_sysfs_attributes,
};

static const struct of_device_id vtx_sip_smc_ids[] = {
	{ .compatible = "vatics,vtx-sip-smc"},
	{ /* sentinel */ },
};

static int __init vtx_sip_smc_probe(struct platform_device *pdev)
{
	if (sysfs_create_group(&pdev->dev.kobj, &vtx_sip_smc_attr_group))
		return -EINVAL;

	pr_info("secure-monitor enabled\n");

	return 0;
}

static struct platform_driver vtx_sip_smc_driver = {
	.driver = {
		.name = "vtx-sip-smc",
		.of_match_table = of_match_ptr(vtx_sip_smc_ids),
	},
};
module_platform_driver_probe(vtx_sip_smc_driver, vtx_sip_smc_probe);
MODULE_LICENSE("GPL");
