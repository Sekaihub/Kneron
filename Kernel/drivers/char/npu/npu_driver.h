/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#ifndef __NPU_DRIVER_H__
#define __NPU_DRIVER_H__

#include <linux/interrupt.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/slab.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/irqdomain.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <asm/irq.h>
#include <linux/uaccess.h>
#include <linux/cache.h>
#include <linux/dma-mapping.h>
#include <linux/cdev.h>
#include <linux/spinlock.h>
#include <linux/reset.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>
#include "npu.h"
#include <linux/vma_device.h>
#include <linux/devfreq.h>

#include <linux/platform_device.h>
#include <linux/of.h>

#define NPU_MMR_BUFF_NUM 16
#define NPU_MMR_BUFF_MASK 0x0000000F

struct npu_shared_info;

struct cmd_buf {
	struct list_head queued_entry;
	struct list_head done_entry;
	struct npu_info *npuinfo;

	void *inst_kvirt_addr;
	void *wt_kvirt_addr;
	void *src_kvirt_addr;
	void *dst_kvirt_addr;
};

struct cmd_queue {
	unsigned int type;
	struct list_head cmd_queued_list;
	unsigned int cmd_queued_count;
	struct list_head cmd_done_list;
	spinlock_t cmd_queue_lock;
	wait_queue_head_t cmd_done_wq;

	struct cmd_buf *cmdbuf[NPU_MAX_CMDBUF];
	unsigned int cmdbuf_num;

	/* remap phyical address to kernel virtual address*/
	unsigned int disable_remapping;
};

struct npu_obj_info {
	void *hprofileinfo;

	struct npu_mmr_info *ptmmrinfo;

	unsigned int mmrinfophyaddr;
	unsigned int writeindex;

	struct npu_shared_info *dev_info;

	struct list_head list;//fh_list

	struct cmd_queue obj_cmdqueue;
};

struct npu_hw_devfreq {
	struct devfreq *devfreq;
};

struct npu_shared_info {
	void *hdevinfo;

	unsigned int irq;

	struct clk *clk;
	struct clk *axi_clk;
	struct clk *apb_clk;
	struct clk *pwr_clk;
	struct reset_control *reset;
	struct regmap *sysc_regmap;
	struct npu_hw_devfreq npu_devfreq;
	struct mutex ioctl_lock;
	unsigned int mmr_addr;
	struct device *dev;
	struct cdev chrdev;
	unsigned int open_count;

	/*file handles*/
	spinlock_t fh_lock;
	struct list_head fh_list;

	spinlock_t isr_lock;

	struct npu_obj_info *curr_obj;/*the next processing obj*/
	unsigned int total_obj_num;

	/*
	 * unit: second
	 * 0: infinite wait
	 */
	unsigned int wait_timeout;
	unsigned int auto_rst_en;
};

unsigned int npu_getdevinfosize(void);
int npu_setmmrinfo(void *hdevinfo,
		   void __iomem *reg_base,
		   struct clk *clk,
		   unsigned int *rstenmmr);
int npu_initprofileinfo(struct npu_obj_info *ptObjInfo);
int npu_getprofileinfo(void *hdevinfo,
		       struct npu_obj_info *objinfo,
		       unsigned int writeindex);
int npu_initprofile(void *hdevinfo);
int npu_closeprofile(void *hdevinfo);
int npu_setupprofile(struct npu_obj_info *ptObjInfo,
		     unsigned int arg,
		     unsigned int cmd);
unsigned int npu_getversion(void *hdevinfo);
unsigned int npu_starthead(void *hdevinfo);
void npu_starttail(void *hdevinfo,
		   unsigned int writeindex,
		   struct cmd_buf *cmdbuf);
unsigned int npu_intrclear(void *hdevinfo);
void npu_open(void *hdevinfo);
unsigned int npu_isrhead(void *hdevinfo);
void npu_isrtail(void *hdevinfo,
		 struct cmd_buf *cmdbuf);
void get_board_magic_key(void *hDevInfo,
			 dma_addr_t phy_addr,
			 void *virt_addr,
			 unsigned int key_num);
void wait_busy(void *hDevInfo);
void tirgger_npu(void *hDevInfo);
unsigned int init_npu(void *hDevInfo);
void config_npu_base(void *hDevInfo,
			unsigned int src_addr,
			unsigned int dst_addr,
			unsigned int working_addr,
			unsigned int inst_addr,
			unsigned int wt_addr,
			unsigned int const_input_addr);
void config_npu_inst_length(void *hdevinfo,
			unsigned int length);

unsigned int npu_read_op_cycle(void *hdevinfo);

bool npu_is_busy(void *hdevinfo);
bool npu_is_pause(void *hdevinfo);
#endif //__NPU_DRIVER_H__
