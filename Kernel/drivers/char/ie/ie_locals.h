/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#ifndef __IE_LOCALS_H__
#define __IE_LOCALS_H__

#include "ie_driver.h"
#include "ie_regs.h"

struct ie_dev_info {
	void __iomem *reg_base;
	unsigned int *rstenmmr;
	unsigned int version;

	bool busy;
};

/* Register access macros */
#define ie_readl(dev, reg)                     \
	readl_relaxed((dev)->reg_base + ADDR_IE_##reg)
#define ie_writel(dev, reg, value)                     \
	writel_relaxed((value), (dev)->reg_base + ADDR_IE_##reg)

#endif //__IE_LOCALS_H__
