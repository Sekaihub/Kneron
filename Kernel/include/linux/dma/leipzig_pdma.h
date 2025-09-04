/* SPDX-License-Identifier: GPL-2.0 */
#ifndef LEIPZIG_PDMA_H
#define LEIPZIG_PDMA_H

#include <linux/dmaengine.h>
#include <linux/io.h>
#include <linux/dmapool.h>
#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/completion.h>

#define PDMA_CHANNELS	    14

enum pdma_channel_type {
	PDMA_RXCH = 0,
	PDMA_TXCH = 1,
};

enum pdma_device_type {
	PDMA_DEVICE_SSIC0 = 0,
	PDMA_DEVICE_SSIC1 = 1,
	PDMA_DEVICE_SSIC2 = 2,
	PDMA_DEVICE_SSIC3 = 3,
	PDMA_DEVICE_I2SSC = 4,
	PDMA_DEVICE_UART0 = 5,
	PDMA_DEVICE_UART1 = 6,
	PDMA_DEVICE_UART2 = 7,
	PDMA_DEVICE_UART3 = 8,
	PDMA_DEVICE_UART4 = 9,
};

enum pdma_data_unit {
	PDMA_DATAUNIT_1B = 0,
	PDMA_DATAUNIT_2B,
	PDMA_DATAUNIT_RESERVE,
	PDMA_DATAUNIT_4B,
};

enum pdma_channel_event {
	PDMA_CH_EVENT_UPDATE = 0,
	PDMA_CH_EVENT_FIRE = 1,
};

struct pdma_ch_info {
	u32 addr_offset;
	enum pdma_channel_type channel_type;
	enum pdma_device_type device_type;
};

struct pdma_desc {
	unsigned int section_addr;
	unsigned int section_size;
};

struct pdma_chan {
	struct dma_chan chan;
	struct dma_slave_config cfg;
	struct dma_async_tx_descriptor async_txd;

	void __iomem *regs;
	enum pdma_channel_type channel_type;
	enum pdma_device_type device_type;

	struct pdma_desc *pdma_descs;
	unsigned int head_idx;
	unsigned int tail_idx;
	unsigned int wrap;
	unsigned int pdma_descs_count;
	unsigned int swap_data;
	dma_addr_t pdma_descs_phys;
	dma_addr_t pdma_descs_tail_phys;

	struct tasklet_struct tasklet;
	spinlock_t ch_lock;
	unsigned int chan_id;
	struct pdma_device *pdma;
	struct completion reset_completion;
};

struct pdma_device {
	struct device			*dev;
	struct dma_device		dma;
	void __iomem			*regs;
	struct clk			*clk_axi_ddr;
	struct clk			*clk_apb;
	struct clk			*mem_pwr_pdmac;
	struct pdma_chan		chan[PDMA_CHANNELS];
	int				irq;
	bool				is_private;
	spinlock_t			phy_lock;
};

static inline struct pdma_chan *to_pdma_chan(struct dma_chan *chan)
{
	return container_of(chan, struct pdma_chan, chan);
}


#endif /* LEIPZIG_PDMA_H */
