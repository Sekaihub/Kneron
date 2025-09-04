/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#ifndef __IE_H__
#define __IE_H__

#include <linux/ioctl.h>

#define IE_MAJOR   0
#define IE_MINOR   0
#define IE_BUILD   0
#define IE_REV     1
#define IE_VERSION      0x00000001

#define IE_MAX_CMDBUF 16

struct ie_info {
	unsigned int index;	////cmd buffer index
	unsigned char *inst_addr;
	unsigned char *inst_virt_addr;
	unsigned int inst_size;
	unsigned char *src_addr;
	unsigned char *src_virt_addr;
	unsigned int src_size;
	unsigned char *dst_addr;
	unsigned char *dst_virt_addr;
	unsigned int dst_size;
	unsigned int profile;
};

struct ie_req_cmd_buf {
	unsigned int buf_num;
	struct ie_info *buf_info[IE_MAX_CMDBUF];

	/* remap physical address to kernel virtual address*/
	unsigned int disable_remapping;
};

#define IE_IOC_MAGIC 182

#define IE_IOC_START		_IOWR(IE_IOC_MAGIC, 0, struct ie_info)
#define IE_IOC_WAIT_COMPLETE	_IO(IE_IOC_MAGIC, 1)
#define IE_IOC_REQ_BUF		_IOWR(IE_IOC_MAGIC, 2, struct ie_req_cmd_buf)
#define IE_IOC_GET_VERSION_NUMBER	_IOR(IE_IOC_MAGIC, 3, unsigned int)
#define IE_IOC_GET_BUS_CYCLE		_IOR(IE_IOC_MAGIC, 4, unsigned int)
#define IE_IOC_GET_DATA_CYCLE		_IOR(IE_IOC_MAGIC, 5, unsigned int)
#define IE_IOC_GET_REQ_TIMES		_IOR(IE_IOC_MAGIC, 6, unsigned int)
#define IE_IOC_CLEAR_PROFILE		_IO(IE_IOC_MAGIC, 7)
#define IE_IOC_CONFIG_ADDR		_IOW(IE_IOC_MAGIC, 8, struct ie_info)
#define IE_IOC_RESET_IE			_IO(IE_IOC_MAGIC, 9)
#define IE_IOC_CONFIG_TIMEOUT		_IOW(IE_IOC_MAGIC, 10, unsigned int)

#define IE_IOC_MAX_NUMBER	10

#endif //__IE_H__
