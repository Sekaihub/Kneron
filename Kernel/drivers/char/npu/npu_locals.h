/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#ifndef __NPU_LOCALS_H__
#define __NPU_LOCALS_H__

#include "npu_driver.h"
#include "npu_regs.h"

struct npu_dev_info {
	void __iomem *reg_base;
	unsigned int *rstenmmr;
	unsigned int version;

	bool busy;
};

/* Register access macros */
#define npu_readl(dev, reg)                     \
	readl_relaxed((dev)->reg_base + ADDR_NPU_##reg)
#define npu_writel(dev, reg, value)                     \
	writel_relaxed((value), (dev)->reg_base + ADDR_NPU_##reg)

#endif //__NPU_LOCALS_H__
