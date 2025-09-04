/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#ifndef __NPU_H__
#define __NPU_H__

#include <linux/ioctl.h>

#define NPU_MAJOR   0
#define NPU_MINOR   0
#define NPU_BUILD   0
#define NPU_REV     1
#define NPU_VERSION      0x00000001

#define NPU_MAX_CMDBUF 16

struct npu_info {
	unsigned int index;    //cmd buffer index
	unsigned char *work_addr;
	unsigned char *work_virt_addr;
	unsigned int work_size;
	unsigned char *inst_addr;
	unsigned char *inst_virt_addr;
	unsigned int inst_size;
	unsigned char *wt_addr;
	unsigned char *wt_virt_addr;
	unsigned int wt_size;
	unsigned char *src_addr;
	unsigned char *src_virt_addr;
	unsigned int src_size;
	unsigned char *dst_addr;
	unsigned char *dst_virt_addr;
	unsigned int dst_size;
	unsigned char *const_input_addr;
	unsigned char *const_input_virt_addr;
	unsigned int const_input_size;
	unsigned int profile;
	unsigned int interrupt_status;
};

struct npu_req_cmd_buf {
	unsigned int buf_num;
	struct npu_info *buf_info[NPU_MAX_CMDBUF];

	/* remap physical address to kernel virtual address*/
	unsigned int disable_remapping;
};

#define NPU_IOC_MAGIC 181

#define NPU_IOC_START		_IOWR(NPU_IOC_MAGIC, 0, struct npu_info)
#define NPU_IOC_WAIT_COMPLETE	_IO(NPU_IOC_MAGIC, 1)
#define NPU_IOC_REQ_BUF		_IOWR(NPU_IOC_MAGIC, 2, struct npu_req_cmd_buf)
#define NPU_IOC_GET_VERSION_NUMBER	_IOR(NPU_IOC_MAGIC, 3, unsigned int)
#define NPU_IOC_GET_BUS_CYCLE		_IOR(NPU_IOC_MAGIC, 4, unsigned int)
#define NPU_IOC_GET_DATA_CYCLE		_IOR(NPU_IOC_MAGIC, 5, unsigned int)
#define NPU_IOC_GET_REQ_TIMES		_IOR(NPU_IOC_MAGIC, 6, unsigned int)
#define NPU_IOC_CLEAR_PROFILE		_IO(NPU_IOC_MAGIC, 7)
#define NPU_IOC_CONFIG_ADDR		_IOW(NPU_IOC_MAGIC, 8, struct npu_info)
#define NPU_IOC_RESET_NPU		_IO(NPU_IOC_MAGIC, 9)
#define NPU_IOC_CONFIG_TIMEOUT		_IOW(NPU_IOC_MAGIC, 10, unsigned int)
#define NPU_IOC_AUTO_RST_EN		_IOW(NPU_IOC_MAGIC, 11, unsigned int)


#define NPU_IOC_MAX_NUMBER	11



#endif //__NPU_H__
