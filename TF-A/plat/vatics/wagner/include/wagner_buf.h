/*
 *   Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 *   SPDX-License-Identifier: BSD-3-Clause
 *
 *   Caution : We allow each Boot mode to share the same block of memory.
 *             Please make sure to only declare variables in this file that
 *             are intended to be placed in the BSS section
 *             (uninitialized or zero-initialized static and global variables)
 *
 *      注意 : 只能放未初始化的變數
 */

#ifndef WAGNER_BUF_H
#define WAGNER_BUF_H

#define CACHE_LINE_SIZE CONFIG_SYS_CACHELINE_SIZE

/* DWC3 USB related header files */
#include <drivers/vatics/usb/usbdevice.h>
#include <drivers/vatics/usb/dwc3/core.h>
#include <drivers/vatics/usb/gadget/udc.h>

/* SPI (NOR/NAMD) related header files*/
#include <drivers/spi_mem.h>
#include <drivers/vatics/pdma.h>
/* USB related header files*/
#include <drivers/vatics/usb/fastboot.h>
#include <linux/usb/composite.h>

/* MMC SDHCI related */
#include <drivers/vatics/mmc/sdhci.h>
#include <fs/fat.h>

/* scrtu related*/
#include <safezone.h>

/*
 *   USB Boot Related
 */
#define DWC3_MAX_REQ_CNT  3	// ep0, ep1-in, ep1-out

struct usb_related {
	/* dwc3/dwc3_gadget.c */
	struct dwc3_trb trb_pool_ep1in[DWC3_TRB_NUM] __aligned(CACHE_LINE_SIZE);
	struct dwc3_trb trb_pool_ep1out[DWC3_TRB_NUM] __aligned(CACHE_LINE_SIZE);
	struct usb_ctrlrequest ctrl_req __aligned(CACHE_LINE_SIZE);
	struct dwc3_trb	ep0_trb[2] __aligned(CACHE_LINE_SIZE);
	u8 setup_buf[DWC3_EP0_BOUNCE_SIZE] __aligned(CACHE_LINE_SIZE);
	u8 ep0_bounce[DWC3_EP0_BOUNCE_SIZE] __aligned(CACHE_LINE_SIZE);

	struct dwc3_ep dep[DWC3_ENDPOINTS_NUM];
	struct dwc3_request req[DWC3_MAX_REQ_CNT];

	/* gadget/udc/udc-core.c */
	struct usb_udc udc;

	/* dwc3/dwc3_core.c */
	struct dwc3_event_buffer evt;
	u8 evt_buf[DWC3_EVENT_BUFFERS_SIZE] __aligned(CACHE_LINE_SIZE);
	struct dwc3_event_buffer dwc_ev_buffs[1] __aligned(CACHE_LINE_SIZE); /* evt no.=1 */
	struct dwc3 dwc_mem __aligned(16);

	/* fastboot & composit */
	struct	f_fastboot f_fb __aligned(CACHE_LINE_SIZE);
	uint8_t	fb_req_buf_in[EP_BUFFER_SIZE] __aligned(CACHE_LINE_SIZE);
	uint8_t fb_req_buf_out[EP_BUFFER_SIZE] __aligned(CACHE_LINE_SIZE);
	struct	usb_configuration g_dnl_config __aligned(CACHE_LINE_SIZE);
	uint8_t composite_req_buf[USB_BUFSIZ] __aligned(CACHE_LINE_SIZE);
	struct	usb_composite_dev g_cdev __aligned(CACHE_LINE_SIZE);
	u32 fastboot_bytes_received;
	u32 fastboot_bytes_expected;
};

/*
 *   MSHC (SD/MMC) Boot Related
 */
struct mshc_related {
	char do_fat_read_block[fatroundup(FS_BLOCK_SIZE, sizeof(dir_entry))]
					__aligned(sizeof(dir_entry));
	char datablock[fatroundup(sizeof(fsdata), 4)] __aligned(4);
};

/*
 *   SPI (NOR/NAMD) Boot Related
 */
struct dw_qspi_res {
	uintptr_t reg_base;
	uintptr_t mm_base;
	size_t mm_size;
	unsigned int reset_id;
	struct pdma_chan tx_dma;
	struct pdma_chan rx_dma;
	struct dw_qspi_config qspi_config;
};

struct spi_related {
	struct dw_qspi_res qspi;
	uint64_t desc_rxbuf[10] __aligned(8);
	uint64_t desc_txbuf[10] __aligned(8);
};
struct scrtu_related {
};

/*
 *   Overlay Declare
 */
union OverlaidBuffer {
	struct usb_related usb_buf;
	struct mshc_related mshc_buf;
	struct spi_related spi_buf;
	struct scrtu_related scrtu_buf;
	// todo
};

#ifdef IMAGE_BL2
extern union OverlaidBuffer *overlaid_bufferp;
#endif

extern union OverlaidBuffer overlaid_buffer;

#endif /* WAGNER_BUF_H */
