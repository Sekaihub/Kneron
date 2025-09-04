/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * VTX I2S Platform Driver
 */

#ifndef _VTX_I2S_H_
#define _VTX_I2S_H_

#include "vtx-asoc.h"

/* ========================================================================== */

/* Version Information*/
#define IIS_MAJOR  1
#define IIS_MINOR  0
#define IIS_BUILD  0
#define IIS_REV    0

#define VPL_IIS_VERSION     MAKEFOURCC(IIS_MAJOR, IIS_MINOR, IIS_BUILD, IIS_REV)
#define VPL_IIS_ID_VERSION  MAKEVERSTR(IIS_MAJOR, IIS_MINOR, IIS_BUILD, IIS_REV)

/* ========================================================================== */

/* I2S register access API */
#define VTX_VPL_SSP_READL(base, reg)        readl(base + reg)
#define VTX_VPL_SSP_WRITEL(base, reg, val)  writel(val, (base + reg))

/* ---------------------------------------------------------------------------*/

#define VPL_I2SSC_MMR_SIZE     0x400

#define VPL_I2SSC_RX_MMR_BASE  0xC5100000
#define VPL_I2SSC_TX_MMR_BASE  (VPL_I2SSC_RX_MMR_BASE + VPL_I2SSC_MMR_SIZE)

/* ========================================================================== */

/* v1.12a December 2020 */
#define I2S_IER    0x00000000 /* DW_apb_i2s Enable Register */
#define I2S_IRER   0x00000004 /* I2S Receiver Block Enable Register */
#define I2S_ITER   0x00000008 /* I2S Transmitter Block Enable Register */
#define I2S_CER    0x0000000c /* Clock Enable Register */
#define I2S_CCR    0x00000010 /* Clock Configuration Register */
#define I2S_RXFFR  0x00000014 /* Receiver Block FIFO Reset Register */
#define I2S_TXFFR  0x00000018 /* Transmitter Block FIFO Reset Register */
	/* channel x Rx/Tx - 0x20 + 0x40 * x */
	/* channel 0 Rx/Tx */
#define I2S_RER    0x00000028 /* Receive Enable Register x */
#define I2S_TER    0x0000002C /* Transmit Enable Register x */
#define I2S_RCR    0x00000030 /* Receive Configuration Register x */
#define I2S_TCR    0x00000034 /* Transmit Configuration Register x */
#define I2S_ISR    0x00000038 /* Interrupt status Register x */
#define I2S_IMR    0x0000003C /* Interrupt Mask Register x */
#define I2S_ROR    0x00000040 /* Receive Overrun Register x */
#define I2S_TOR    0x00000044 /* Transmit Overrun Register x */
	/* channel 0 - FIFO */
#define I2S_RFCR   0x00000048 /* Receive FIFO Configuration Register x */
#define I2S_TFCR   0x0000004C /* Transmit FIFO Configuration Register x */
#define I2S_RFF0   0x00000050 /* Receive FIFO Flush Register x */
#define I2S_TFF0   0x00000054 /* Transmit FIFO Flush Register x */

/* DMA */
#define I2S_RXDMA   0x000001C0 /* Receiver Block DMA Register */
#define I2S_RRXDMA  0x000001C4 /* Reset Receiver Block DMA Register. */
#define I2S_TXDMA   0x000001C8 /* Transmitter Block DMA Register */
#define I2S_RTXDMA  0x000001CC /* Reset Transmitter Block DMA Register */

/* Component Info */
#define I2S_COMP_PARAM_2  0x000001F0 /* Component Parameter Register 2 */
#define I2S_COMP_PARAM_1  0x000001F4 /* Component Parameter Register 1 */
#define I2S_COMP_VERSION  0x000001F8 /* I2S Component Version Register */
#define I2S_COMP_TYPE     0x000001FC /* I2S Component Type Register */

/* DMA Handshake Interface for TDM */
#define I2S_DMACR      0x00000200 /* DMA Control Register */
#define I2S_RXDMA_CH0  0x00000204 /* Receiver Block DMA Register */
#define I2S_TXDMA_CH0  0x00000214 /* Transmit Block DMA Register */
#define I2S_RSLOT      0x00000224 /* Receive Slot x Buffer Register */
#define I2S_TSLOT      0x00000224 /* Transmit Slot x Buffer Register */

/* ---------------------------------------------------------------------------*/

/* Bit Depth: only support 16 & 32 bits */
//#define I2S_DEPTH_12BIT  0x1
#define I2S_DEPTH_16BIT  0x2
//#define I2S_DEPTH_20BIT  0x3
//#define I2S_DEPTH_24BIT  0x4 // H/W support
#define I2S_DEPTH_32BIT  0x5

/* ========================================================================== */

#endif // #ifndef _VTX_I2S_H_


