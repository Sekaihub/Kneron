// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */

#include "npu_locals.h"

unsigned int npu_getdevinfosize(void)
{
	return sizeof(struct npu_dev_info);
}

int npu_setmmrinfo(void *hdevinfo,
		   void __iomem *reg_base,
		   struct clk *clk,
		   unsigned int *rstenmmr)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	ptdevinfo->reg_base = reg_base;
	ptdevinfo->rstenmmr = rstenmmr;
	ptdevinfo->version = 0;

	return 0;
}

void config_npu_base(void *hdevinfo,
			unsigned int src_addr,
			unsigned int dst_addr,
			unsigned int working_addr,
			unsigned int inst_addr,
			unsigned int wt_addr,
			unsigned int const_input_addr)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	// RDMA0 base address
	npu_writel(ptdevinfo, RDMA0_SRC4, NPU_RDMA0_SRC4_base(working_addr));
	// WDMA0 base address
	npu_writel(ptdevinfo, WDMA0_DST4, NPU_WDMA0_DST4_base(working_addr));
	// RDMA1 base address
	npu_writel(ptdevinfo, RDMA1_SRC4, NPU_RDMA1_SRC4_base(dst_addr));
	// WDMA1 base address
	npu_writel(ptdevinfo, WDMA1_DST4, NPU_WDMA1_DST4_base(dst_addr));
	// RDMA2 base address
	npu_writel(ptdevinfo, RDMA2_SRC4, NPU_RDMA2_SRC4_base(src_addr));
	// WDMA2 base address
	npu_writel(ptdevinfo, WDMA2_DST4, NPU_WDMA2_DST4_base(wt_addr));
	// RDMA3 base address: Const Input start address
	npu_writel(ptdevinfo, RDMA3_SRC4, NPU_RDMA3_SRC4_base(const_input_addr));
	// GETW base address
	npu_writel(ptdevinfo, GETW4, NPU_GETW4_base(wt_addr));
	// Instruction code start address
	npu_writel(ptdevinfo, CODE, NPU_CODE_a(inst_addr));
}

unsigned int npu_read_op_cycle(void *hdevinfo)
{
	unsigned int val = 0;

	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	val = npu_readl(ptdevinfo, DBG1);
	return val;
}

void config_npu_inst_length(void *hdevinfo,
			unsigned int length)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	// Instruction code length 0x1560
	npu_writel(ptdevinfo, CLEN, NPU_CLEN_l(length));
}


unsigned int init_npu(void *hdevinfo)
{

	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;
	uint32_t val = 0;


	// Turn on interrupt enable bit
	npu_writel(ptdevinfo, INTEN, 0x7fff);
	// config debug port(performance monitor
	npu_writel(ptdevinfo, DBG0, 0x000100f0);

	val = npu_readl(ptdevinfo, NMEM);
	val &= ~0x6;
	val |= NPU_NMEM_arb_mode(2);
	npu_writel(ptdevinfo, NMEM, val);

	/* config dma burst length to 32 */
	val = npu_readl(ptdevinfo, DMA);
	val &= ~(0x1ff);
	val |= NPU_DMA_bl(32);
	npu_writel(ptdevinfo, DMA, val);

	return 0;
}

static void trigger_npu(void *hdevinfo)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	// NPU GO
	npu_writel(ptdevinfo, RUN, NPU_RUN_go(1) |
				   NPU_RUN_conv_rmode(1) |
				   NPU_RUN_pconv_rmode(1) |
				   NPU_RUN_pfunc_rmode(1));

}

static void resume_npu(void *hdevinfo)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	// NPU conti
	npu_writel(ptdevinfo, RUN, NPU_RUN_conti(1) |
				   NPU_RUN_conv_rmode(1) |
				   NPU_RUN_pconv_rmode(1) |
				   NPU_RUN_pfunc_rmode(1));

}

bool npu_is_pause(void *hdevinfo)
{
	bool npu_is_pause = false;
	unsigned int status;
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	status = npu_readl(ptdevinfo, RUN);
	pr_debug("npu run status = 0x%x\n", status);

	npu_is_pause = (bool)(status & 0x20000);
	pr_debug("npu_is_pause = %d\n", npu_is_pause);
	return npu_is_pause;
}

unsigned int npu_getversion(void *hdevinfo)
{
	unsigned int ver;
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	ver = npu_readl(ptdevinfo, VER);
	return ver;
}

unsigned int npu_starthead(void *hdevinfo)
{
	return 0;
}

void npu_starttail(void *hdevinfo,
		   unsigned int writeindex,
		   struct cmd_buf *cmdbuf)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;
	struct npu_info *npuinfo;

	npuinfo = cmdbuf->npuinfo;

	if (ptdevinfo->busy == false) {
		ptdevinfo->busy = true;
		//wfc: 0: Normal. 1: NPU is paused and wait for continue event to resume.
		if (npu_is_pause(hdevinfo)) {
			pr_debug("%s, resume_npu\n", __func__);
			resume_npu(hdevinfo);
		} else {
			config_npu_base(hdevinfo,
				(uint32_t)(uint64_t)npuinfo->src_addr,
				(uint32_t)(uint64_t)npuinfo->dst_addr,
				(uint32_t)(uint64_t)npuinfo->work_addr,
				(uint32_t)(uint64_t)npuinfo->inst_addr,
				(uint32_t)(uint64_t)npuinfo->wt_addr,
				(uint32_t)(uint64_t)npuinfo->const_input_addr);
			config_npu_inst_length(hdevinfo,
						(unsigned int)npuinfo->inst_size);
			trigger_npu(hdevinfo);
		}

	}

}

unsigned int npu_intrclear(void *hdevinfo)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;
	unsigned int sts;

	sts = npu_readl(ptdevinfo, INT);
	npu_writel(ptdevinfo, INT, sts);

	return sts;
}

void npu_open(void *hdevinfo)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;

	ptdevinfo->busy = false;
}

unsigned int npu_isrhead(void *hdevinfo)
{
	npu_intrclear(hdevinfo);

	return 0;
}

void npu_isrtail(void *hdevinfo, struct cmd_buf *cmdbuf)
{
	struct npu_dev_info *ptdevinfo = (struct npu_dev_info *)hdevinfo;
	struct npu_info *npuinfo;

	if (!cmdbuf)
		ptdevinfo->busy = false;
	else {
		npuinfo = cmdbuf->npuinfo;
		config_npu_base(hdevinfo,
				(uint32_t)(uint64_t)npuinfo->src_addr,
				(uint32_t)(uint64_t)npuinfo->dst_addr,
				(uint32_t)(uint64_t)npuinfo->work_addr,
				(uint32_t)(uint64_t)npuinfo->inst_addr,
				(uint32_t)(uint64_t)npuinfo->wt_addr,
				(uint32_t)(uint64_t)npuinfo->const_input_addr);
		config_npu_inst_length(hdevinfo,
				       (unsigned int)npuinfo->inst_size);
		trigger_npu(hdevinfo);
	}
}

bool npu_is_busy(void *hdevinfo)
{
	struct npu_dev_info *devinfo = (struct npu_dev_info *)hdevinfo;

	return devinfo->busy;
}
