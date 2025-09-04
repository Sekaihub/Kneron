// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */

#include "ie_locals.h"

unsigned int ie_getdevinfosize(void)
{
	return sizeof(struct ie_dev_info);
}

int ie_setmmrinfo(void *hdevinfo,
		   void __iomem *reg_base,
		   struct clk *clk,
		   unsigned int *rstenmmr)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	ptdevinfo->reg_base = reg_base;
	ptdevinfo->rstenmmr = rstenmmr;
	ptdevinfo->version = 0;

	return 0;
}

void config_ie_base(void *hdevinfo,
			unsigned int src_addr,
			unsigned int dst_addr,
			unsigned int inst_addr)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	// RDMA base address
	ie_writel(ptdevinfo, RDMA_SRC4, src_addr);
	// WDMA base address
	ie_writel(ptdevinfo, WDMA_DST4, dst_addr);
	// Instruction code start address
	ie_writel(ptdevinfo, CODE, inst_addr);
}

unsigned int ie_read_op_cycle(void *hdevinfo)
{
	unsigned int val = 0;

	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	val = ie_readl(ptdevinfo, PROF);
	return val;
}

void config_ie_inst_length(void *hdevinfo,
			unsigned int length)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	ie_writel(ptdevinfo, CLEN, length);
}


unsigned int init_ie(void *hdevinfo)
{

	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;


	//open debug mode
	ie_writel(ptdevinfo, DBG0, (((0x00000001)&0xffffffff)<<0));
	//enable profile counter
	ie_writel(ptdevinfo, PROF_CTL, (((0x00000001)&0xffffffff)<<0));
	//enable IE operation finish interrupt
	ie_writel(ptdevinfo, INTEN, (((0x00000001)&0xffffffff)<<0));

	return 0;
}

static void trigger_ie(void *hdevinfo)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	// NPU GO
	ie_writel(ptdevinfo, RUN, 1);

}

unsigned int ie_getversion(void *hdevinfo)
{
	unsigned int ver;
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	ver = ie_readl(ptdevinfo, VER);
	return ver;
}

unsigned int ie_starthead(void *hdevinfo)
{
	return 0;
}

void ie_starttail(void *hdevinfo,
		   unsigned int writeindex,
		   struct cmd_buf *cmdbuf)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;
	struct ie_info *ieinfo;

	ieinfo = cmdbuf->ieinfo;

	if (ptdevinfo->busy == false) {
		ptdevinfo->busy = true;
		config_ie_base(hdevinfo,
				(uint32_t)(uint64_t)ieinfo->src_addr,
				(uint32_t)(uint64_t)ieinfo->dst_addr,
				(uint32_t)(uint64_t)ieinfo->inst_addr);
		config_ie_inst_length(hdevinfo,
				       (unsigned int)ieinfo->inst_size);
		trigger_ie(hdevinfo);
	}

}

unsigned int ie_intrclear(void *hdevinfo)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;
	unsigned int sts;

	sts = ie_readl(ptdevinfo, INT);
	ie_writel(ptdevinfo, INT, sts);

	return sts;
}

void ie_open(void *hdevinfo)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;

	ptdevinfo->busy = false;
}

unsigned int ie_isrhead(void *hdevinfo)
{
	ie_intrclear(hdevinfo);

	return 0;
}

void ie_isrtail(void *hdevinfo, struct cmd_buf *cmdbuf)
{
	struct ie_dev_info *ptdevinfo = (struct ie_dev_info *)hdevinfo;
	struct ie_info *ieinfo;

	if (!cmdbuf)
		ptdevinfo->busy = false;
	else {
		ieinfo = cmdbuf->ieinfo;
		config_ie_base(hdevinfo,
				(uint32_t)(uint64_t)ieinfo->src_addr,
				(uint32_t)(uint64_t)ieinfo->dst_addr,
				(uint32_t)(uint64_t)ieinfo->inst_addr);
		config_ie_inst_length(hdevinfo,
				       (unsigned int)ieinfo->inst_size);
		trigger_ie(hdevinfo);
	}
}

bool ie_is_busy(void *hdevinfo)
{
	struct ie_dev_info *devinfo = (struct ie_dev_info *)hdevinfo;

	return devinfo->busy;
}
