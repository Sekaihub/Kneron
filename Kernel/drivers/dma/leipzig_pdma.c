// SPDX-License-Identifier: GPL-2.0-only
/*
 * Core driver for the Leipzig PDMA Controller
 */

#include <linux/delay.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/init.h>
#include <linux/bits.h>
#include <linux/of.h>
#include <linux/of_dma.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>
#include <linux/platform_device.h>

#include <linux/dma/leipzig_pdma.h>
#include "dmaengine.h"

#define BITMASK(h, l)  GENMASK_ULL(h, l)
#define pdma_readl     readl
#define pdma_writel    writel

#define PDMA_MAX_DESC_BYTES SZ_32K
#define PDMA_MAX_DESC_CNT   256

/* PDMA MAC registers */
#define PDMA_MAC_VERSION        0x00
#define PDMA_MAC_CTRL0          0x04
#define PDMA_MAC_CTRL1          0x08
#define PDMA_MAC_INTERRUPT      0x0C
#define PDMA_MAC_BADDR0         0x10
#define PDMA_MAC_BADDR1         0x14
#define PDMA_MAC_BADDR2         0x18
#define PDMA_MAC_BADDR3         0x1C
#define PDMA_MAC_MEMDEP0        0x20
#define PDMA_MAC_MEMDEP1        0x24
#define PDMA_MAC_MEMDEP2        0x28
#define PDMA_MAC_MEMDEP3        0x2C

/* PDMA RX channel registers */
#define PDMA_RX_PER_BASE_ADDR          0x00000000
#define PDMA_RX_PER_CTRL               0x00000004
#define PDMA_RX_RING_READ_BASE_ADDR    0x00000008
#define PDMA_RX_RING_READ_CTRL         0x0000000C
#define PDMA_RX_RING_READ_EVENT_PU     0x00000010
#define PDMA_RX_SG_CTRL                0x00000014
#define PDMA_RX_INTR_CTRL              0x00000018
#define PDMA_RX_DMA_CTRL               0x0000001C
#define PDMA_RX_STATE                  0x00000020
#define PDMA_RX_BYTE_CNT               0x00000024
#define PDMA_RX_INTR                   0x00000028

/* PDMA TX channel registers */
#define PDMA_TX_PER_BASE_ADDR          0x00000000
#define PDMA_TX_PER_CTRL               0x00000004
#define PDMA_TX_RING_READ_BASE_ADDR    0x00000008
#define PDMA_TX_RING_READ_CTRL         0x0000000C
#define PDMA_TX_RING_READ_EVENT_PU     0x00000010
#define PDMA_TX_SG_CTRL                0x00000014
#define PDMA_TX_INTR_CTRL              0x00000018
#define PDMA_TX_RESET_CTRL             0x0000001C
#define PDMA_TX_STATE                  0x00000020
#define PDMA_TX_BYTE_CNT               0x00000024
#define PDMA_TX_INTR                   0x00000028

/* peripheral control bit fields (mmr offset:0x0004) */
#define PDMA_CH_PCTRL_HS                BIT(0)
#define PDMA_CH_PCTRL_DU(v)             ((v) << 1)
#define PDMA_CH_PCTRL_DU_MASK           BITMASK(2, 1)
#define PDMA_CH_PCTRL_FC                BIT(3)
#define PDMA_CH_PCTRL_BL(v)             ((v) << 4)
#define PDMA_CH_PCTRL_BL_MASK           BITMASK(8, 4)

/* ring read control bit fields (mmr offset:0x000C) */
#define PDMA_CH_RRCTRL_DEPTH(v)         ((v) << 0)
#define PDMA_CH_RRCTRL_DEPTH_MASK       BITMASK(13, 0)
#define PDMA_CH_RRCTRL_ES               BIT(14)
#define PDMA_CH_RRCTRL_WRAP             BIT(15)
#define PDMA_CH_RRCTRL_WRPTR(v)         ((v) << 16)
#define PDMA_CH_RRCTRL_WRPTR_MASK       BITMASK(29, 16)

/* channel interrupt_enable bit fields (mmr offset:0x0018) */
#define PDMA_TXCH_INTR_RCI_EN           BIT(0) /* Reset Complete */
#define PDMA_TXCH_INTR_SCI_EN           BIT(1) /* Section Complete */
#define PDMA_TXCH_INTR_BEI_EN           BIT(2) /* Bus Error */
#define PDMA_TXCH_INTR_SGSCI_EN         BIT(3) /* SG section Complete */

#define PDMA_RXCH_INTR_FCI_EN           BIT(0) /* Flush Complete */
#define PDMA_RXCH_INTR_RCI_EN           BIT(1) /* Reset Complete */
#define PDMA_RXCH_INTR_SCI_EN           BIT(3) /* Section Complete */
#define PDMA_RXCH_INTR_BEI_EN           BIT(5) /* Bus Error */

/* state bit fields (mmr offset:0x0020) */
#define PDMA_CH_STATE_IDLE              BIT(0)
#define PDMA_CH_STATE_HS_BUSY           BIT(1)
#define PDMA_CH_STATE_RR_RD_WRAP        BIT(2)
#define PDMA_CH_STATE_RR_RD_PTR         BITMASK(16, 3)
#define PDMA_CH_STATE_RR_CMPT_WRAP      BIT(17)
#define PDMA_CH_STATE_RR_CMPT_PTR       BITMASK(31, 18)

/* TX intr bit fields (mmr offset:0x0024) */
#define PDMA_TXCH_INTR_RST_CMPT         BIT(0) /* TX Reset Complete */
#define PDMA_TXCH_INTR_SEC_CMPT         BIT(1) /* TX Section Complete */
#define PDMA_TXCH_INTR_BUS_ERR          BIT(3) /* TX Bus Error */
#define PDMA_TXCH_INTR_SGSEC_CMPT       BIT(4) /* TX SG Section Complete */

/* RX intr bit fields (mmr offset:0x0028) */
#define PDMA_RXCH_INTR_FLU_CMPT         BIT(0) /* RX Flush Complete */
#define PDMA_RXCH_INTR_RST_CMPT         BIT(1) /* RX Reset Complete */
#define PDMA_RXCH_INTR_SEC_CMPT         BIT(3) /* RX Section Complete */
#define PDMA_RXCH_INTR_BUS_ERR          BIT(5) /* RX Bus Error */

/* PDMA channel base address */
#define PDMA_RXCH0_BASE         0x00000030
#define PDMA_RXCH1_BASE         0x00000088
#define PDMA_RXCH2_BASE         0x000000E0
#define PDMA_RXCH3_BASE         0x00000138
#define PDMA_RXCH4_BASE         0x00000190
#define PDMA_RXCH5_BASE         0x000001E8
#define PDMA_RXCH6_BASE         0x00000240

#define PDMA_TXCH0_BASE         0x0000005C
#define PDMA_TXCH1_BASE         0x000000B4
#define PDMA_TXCH2_BASE         0x0000010C
#define PDMA_TXCH3_BASE         0x00000164
#define PDMA_TXCH4_BASE         0x000001BC
#define PDMA_TXCH5_BASE         0x00000214
#define PDMA_TXCH6_BASE         0x0000026C

#define PDMA_DESC_SIE        BIT(31) /*Section interrupt enable*/
#define PDMA_DESC_SSGIE      BIT(30) /*Section SG interrupt enable*/
#define PDMA_DESC_DSE        BIT(29) /*Data swap enable*/

#define PDMA_TXCH_INTR_NORMAL  (PDMA_TXCH_INTR_RCI_EN | \
				PDMA_TXCH_INTR_SCI_EN | \
				PDMA_TXCH_INTR_BEI_EN | \
				PDMA_TXCH_INTR_SGSCI_EN)

#define PDMA_RXCH_INTR_NORMAL  (PDMA_RXCH_INTR_FCI_EN | \
				PDMA_RXCH_INTR_RCI_EN | \
				PDMA_RXCH_INTR_SCI_EN | \
				PDMA_RXCH_INTR_BEI_EN)

static enum pdma_data_unit
convert_dma_width(enum dma_slave_buswidth dma_width)
{
	if (dma_width == DMA_SLAVE_BUSWIDTH_1_BYTE)
		return PDMA_DATAUNIT_1B;
	else if (dma_width == DMA_SLAVE_BUSWIDTH_2_BYTES)
		return PDMA_DATAUNIT_2B;
	else if (dma_width == DMA_SLAVE_BUSWIDTH_4_BYTES)
		return PDMA_DATAUNIT_4B;

	return PDMA_DATAUNIT_RESERVE;
}

static void
pdma_channel_get_info(u32 channel, struct pdma_ch_info *channel_info)
{
	switch (channel) {
	case 0:
		channel_info->addr_offset = PDMA_RXCH0_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 1:
		channel_info->addr_offset = PDMA_TXCH0_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 2:
		channel_info->addr_offset = PDMA_RXCH1_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 3:
		channel_info->addr_offset = PDMA_TXCH1_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 4:
		channel_info->addr_offset = PDMA_RXCH2_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 5:
		channel_info->addr_offset = PDMA_TXCH2_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 6:
		channel_info->addr_offset = PDMA_RXCH3_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 7:
		channel_info->addr_offset = PDMA_TXCH3_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 8:
		channel_info->addr_offset = PDMA_RXCH4_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 9:
		channel_info->addr_offset = PDMA_TXCH4_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 10:
		channel_info->addr_offset = PDMA_RXCH5_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 11:
		channel_info->addr_offset = PDMA_TXCH5_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	case 12:
		channel_info->addr_offset = PDMA_RXCH6_BASE;
		channel_info->channel_type = PDMA_RXCH;
		break;
	case 13:
		channel_info->addr_offset = PDMA_TXCH6_BASE;
		channel_info->channel_type = PDMA_TXCH;
		break;
	default:
		break;
	}
}

static void
pdma_intr_check_all(struct dma_chan *chan)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 intr;

	regs = pdma_ch->regs;
	if (pdma_ch->channel_type == PDMA_RXCH) {
		intr = pdma_readl(regs + PDMA_RX_INTR);
		if (intr & PDMA_RXCH_INTR_SEC_CMPT) {
			/* write 1 clear */
			pdma_writel(PDMA_RXCH_INTR_SEC_CMPT,
				regs + PDMA_RX_INTR);
			/* section complete callback */
			tasklet_schedule(&pdma_ch->tasklet);
		}
		if (intr & PDMA_RXCH_INTR_RST_CMPT) {
			/* write 1 clear */
			pdma_writel(PDMA_RXCH_INTR_RST_CMPT,
				regs + PDMA_RX_INTR);
			/* complete reset */
			complete(&pdma_ch->reset_completion);
		}
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		intr = pdma_readl(regs + PDMA_TX_INTR);
		if (intr & PDMA_TXCH_INTR_SEC_CMPT) {
			/* write 1 clear */
			pdma_writel(PDMA_TXCH_INTR_SEC_CMPT,
				regs + PDMA_TX_INTR);
			/* section complete callback */
			tasklet_schedule(&pdma_ch->tasklet);
		}
		if (intr & PDMA_TXCH_INTR_RST_CMPT) {
			/* write 1 clear */
			pdma_writel(PDMA_TXCH_INTR_RST_CMPT,
				regs + PDMA_TX_INTR);
			/* complete reset */
			complete(&pdma_ch->reset_completion);
		}
	}
}

static irqreturn_t
pdma_intr_handle(int irq, void *dev_id)
{
	struct pdma_device *pdma = dev_id;
	struct pdma_chan *pdma_ch;
	int ch_index;

	for (ch_index = 0; ch_index < PDMA_CHANNELS; ch_index++) {
		pdma_ch = &pdma->chan[ch_index];
		pdma_intr_check_all(&pdma_ch->chan);
	}
	return IRQ_HANDLED;
}

static void
pdma_clk_set(struct dma_chan *chan, u32 en)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	struct pdma_device *pdma = pdma_ch->pdma;

	void __iomem *regs;
	u32 channel = pdma_ch->chan_id;
	u32 ctl0;

	regs = pdma->regs;
	ctl0 = pdma_readl(regs + PDMA_MAC_CTRL0);

	/* 0:disable channel clock. 1:enable channel clock */
	if (en == 1)
		ctl0 |= (0x1 << channel);
	else
		ctl0 &= ~(0x1 << channel);

	pdma_writel(ctl0, regs + PDMA_MAC_CTRL0);
}

static void
pdma_clk_set_polarity(struct dma_chan *chan, u32 en)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	struct pdma_device *pdma = pdma_ch->pdma;
	void __iomem *regs;

	u32 channel = pdma_ch->chan_id;
	u32 ctl1;

	regs = pdma->regs;
	ctl1 = pdma_readl(regs + PDMA_MAC_CTRL1);

	/* 0:the same phase as peripheral. 1:inverse phase as peripheral */
	if (en == 1)
		ctl1 |= (0x1 << channel);
	else
		ctl1 &= ~(0x1 << channel);

	pdma_writel(ctl1, regs + PDMA_MAC_CTRL1);
}

static void
pdma_clk_set_gating_bpss(struct dma_chan *chan, u32 en)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	struct pdma_device *pdma = pdma_ch->pdma;
	void __iomem *regs;

	u32 channel = pdma_ch->chan_id;
	u32 ctl1;

	regs = pdma->regs;
	ctl1 = pdma_readl(regs + PDMA_MAC_CTRL1);

	/* 0:clock gating. 1:by pass clock gating */
	if (en == 1)
		ctl1 |= (0x1 << (channel+16));
	else
		ctl1 &= ~(0x1 << (channel+16));

	pdma_writel(ctl1, regs + PDMA_MAC_CTRL1);
}

static void
pdma_channel_set_irq(struct dma_chan *chan, u32 en)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 intc;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		intc = pdma_readl(regs + PDMA_RX_INTR_CTRL);

		if (en == 1)
			intc |= PDMA_RXCH_INTR_NORMAL;
		else
			intc &= ~PDMA_RXCH_INTR_NORMAL;

		pdma_writel(intc, regs + PDMA_RX_INTR_CTRL);

	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		intc = pdma_readl(regs + PDMA_TX_INTR_CTRL);

		if (en == 1)
			intc |= PDMA_TXCH_INTR_NORMAL;
		else
			intc &= ~PDMA_TXCH_INTR_NORMAL;

		pdma_writel(intc, regs + PDMA_RX_INTR_CTRL);
	}
}

static void
pdma_channel_set_handshake(struct dma_chan *chan, u32 en)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 pctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		pctl = pdma_readl(regs + PDMA_RX_PER_CTRL);

		if (en == 1)
			pctl |= PDMA_CH_PCTRL_HS;
		else
			pctl &= ~PDMA_CH_PCTRL_HS;

		pdma_writel(pctl, regs + PDMA_RX_PER_CTRL);

		while ((pdma_readl(regs + PDMA_RX_STATE) &
			PDMA_CH_STATE_HS_BUSY) != 0)
			;

	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		pctl = pdma_readl(regs + PDMA_TX_PER_CTRL);

		if (en == 1)
			pctl |= PDMA_CH_PCTRL_HS;
		else
			pctl &= ~PDMA_CH_PCTRL_HS;

		pdma_writel(pctl, regs + PDMA_RX_PER_CTRL);

		while ((pdma_readl(regs + PDMA_TX_STATE) &
			PDMA_CH_STATE_HS_BUSY) != 0)
			;
	}
}

static void
pdma_channel_set_perbaddr(struct dma_chan *chan, u32 perbaddr)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH)
		pdma_writel(perbaddr, regs + PDMA_RX_PER_BASE_ADDR);
	else if (pdma_ch->channel_type == PDMA_TXCH)
		pdma_writel(perbaddr, regs + PDMA_TX_PER_BASE_ADDR);
}

static void
pdma_channel_set_dataunit(struct dma_chan *chan, enum pdma_data_unit du)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 pctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		pctl = pdma_readl(regs + PDMA_RX_PER_CTRL);
		pctl &= ~PDMA_CH_PCTRL_DU_MASK;
		pctl |= PDMA_CH_PCTRL_DU(du);
		pdma_writel(pctl, regs + PDMA_RX_PER_CTRL);

	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		pctl = pdma_readl(regs + PDMA_TX_PER_CTRL);
		pctl &= ~PDMA_CH_PCTRL_DU_MASK;
		pctl |= PDMA_CH_PCTRL_DU(du);
		pdma_writel(pctl, regs + PDMA_TX_PER_CTRL);
	}
}

static void
pdma_channel_set_flowctrl(struct dma_chan *chan, u32 fc)
{
	/* 0:Peripheral DMA is flow controller.   */
	/* 1:Source peripheral is flow controller */

	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 pctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		pctl = pdma_readl(regs + PDMA_RX_PER_CTRL);

		if (fc == 1)
			pctl |= PDMA_CH_PCTRL_FC;
		else
			pctl &= ~PDMA_CH_PCTRL_FC;

		pdma_writel(pctl, regs + PDMA_RX_PER_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		pctl = pdma_readl(regs + PDMA_TX_PER_CTRL);

		if (fc == 1)
			pctl |= PDMA_CH_PCTRL_FC;
		else
			pctl &= ~PDMA_CH_PCTRL_FC;

		pdma_writel(pctl, regs + PDMA_TX_PER_CTRL);
	}
}

static void
pdma_channel_set_burstlen(struct dma_chan *chan, u32 bl)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 pctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		pctl = pdma_readl(regs + PDMA_RX_PER_CTRL);
		pctl &= ~PDMA_CH_PCTRL_BL_MASK;
		pctl |= PDMA_CH_PCTRL_BL(bl);
		pdma_writel(pctl, regs + PDMA_RX_PER_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		pctl = pdma_readl(regs + PDMA_TX_PER_CTRL);
		pctl &= ~PDMA_CH_PCTRL_BL_MASK;
		pctl |= PDMA_CH_PCTRL_BL(bl);
		pdma_writel(pctl, regs + PDMA_TX_PER_CTRL);
	}
}

static void
pdma_channel_set_sgctrl(struct dma_chan *chan, u32 sgctrl)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH)
		pdma_writel((sgctrl-1), regs + PDMA_RX_SG_CTRL);
	else if (pdma_ch->channel_type == PDMA_TXCH)
		pdma_writel((sgctrl-1), regs + PDMA_TX_SG_CTRL);
}

static void
pdma_channel_reset(struct dma_chan *chan)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	unsigned long long ms = 20;

	reinit_completion(&pdma_ch->reset_completion);

	regs = pdma_ch->regs;

	pdma_clk_set(chan, 1);
	pdma_channel_set_irq(chan, 1);
	pdma_channel_set_handshake(chan, 0);

	if (pdma_ch->channel_type == PDMA_RXCH) {
		pdma_writel(0x1, regs + PDMA_RX_DMA_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		pdma_writel(0x1, regs + PDMA_TX_RESET_CTRL);
	}
	ms = wait_for_completion_timeout(&pdma_ch->reset_completion,
					 msecs_to_jiffies(ms));

	if (ms == 0) {
		dev_err(&chan->dev->device,
			"pdma channel %d reset timed out\n", pdma_ch->chan_id);
	}
	pdma_clk_set(chan, 0);
}

static void
pdma_ring_set_baddr(struct dma_chan *chan, u32 baddr)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH)
		pdma_writel(baddr, regs + PDMA_RX_RING_READ_BASE_ADDR);
	else if (pdma_ch->channel_type == PDMA_TXCH)
		pdma_writel(baddr, regs + PDMA_TX_RING_READ_BASE_ADDR);
}

static void
pdma_ring_set_depth(struct dma_chan *chan, u32 depth)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 rctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		rctl = pdma_readl(regs + PDMA_RX_RING_READ_CTRL);
		rctl &= ~PDMA_CH_RRCTRL_DEPTH_MASK;
		rctl |= PDMA_CH_RRCTRL_DEPTH(depth);
		pdma_writel(rctl, regs + PDMA_RX_RING_READ_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		rctl = pdma_readl(regs + PDMA_TX_RING_READ_CTRL);
		rctl &= ~PDMA_CH_RRCTRL_DEPTH_MASK;
		rctl |= PDMA_CH_RRCTRL_DEPTH(depth);
		pdma_writel(rctl, regs + PDMA_TX_RING_READ_CTRL);
	}
}

static void
pdma_ring_set_event(struct dma_chan *chan, enum pdma_channel_event event)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 rctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		rctl = pdma_readl(regs + PDMA_RX_RING_READ_CTRL);

		if (event == PDMA_CH_EVENT_FIRE)
			rctl |= PDMA_CH_RRCTRL_ES;
		else if (event == PDMA_CH_EVENT_UPDATE)
			rctl &= ~PDMA_CH_RRCTRL_ES;

		pdma_writel(rctl, regs + PDMA_RX_RING_READ_CTRL);
		pdma_writel(0x1, regs + PDMA_RX_RING_READ_EVENT_PU);

	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		rctl = pdma_readl(regs + PDMA_TX_RING_READ_CTRL);

		if (event == PDMA_CH_EVENT_FIRE)
			rctl |= PDMA_CH_RRCTRL_ES;
		else if (event == PDMA_CH_EVENT_UPDATE)
			rctl &= ~PDMA_CH_RRCTRL_ES;

		pdma_writel(rctl, regs + PDMA_TX_RING_READ_CTRL);
		pdma_writel(0x1, regs + PDMA_TX_RING_READ_EVENT_PU);
	}
}

static void
pdma_ring_set_wrap(struct dma_chan *chan, u32 warp)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 rctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		rctl = pdma_readl(regs + PDMA_RX_RING_READ_CTRL);
		if (warp == 1)
			rctl |= PDMA_CH_RRCTRL_WRAP;
		else
			rctl &= ~PDMA_CH_RRCTRL_WRAP;
		pdma_writel(rctl, regs + PDMA_RX_RING_READ_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		rctl = pdma_readl(regs + PDMA_TX_RING_READ_CTRL);
		if (warp == 1)
			rctl |= PDMA_CH_RRCTRL_WRAP;
		else
			rctl &= ~PDMA_CH_RRCTRL_WRAP;
		pdma_writel(rctl, regs + PDMA_TX_RING_READ_CTRL);
	}
}

static void
pdma_ring_set_wrptr(struct dma_chan *chan, u32 wrptr)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	void __iomem *regs;
	u32 rctl;

	regs = pdma_ch->regs;

	if (pdma_ch->channel_type == PDMA_RXCH) {
		rctl = pdma_readl(regs + PDMA_RX_RING_READ_CTRL);
		rctl &= ~PDMA_CH_RRCTRL_WRPTR_MASK;
		rctl |= PDMA_CH_RRCTRL_WRPTR(wrptr);
		pdma_writel(rctl, regs + PDMA_RX_RING_READ_CTRL);
	} else if (pdma_ch->channel_type == PDMA_TXCH) {
		rctl = pdma_readl(regs + PDMA_TX_RING_READ_CTRL);
		rctl &= ~PDMA_CH_RRCTRL_WRPTR_MASK;
		rctl |= PDMA_CH_RRCTRL_WRPTR(wrptr);
		pdma_writel(rctl, regs + PDMA_TX_RING_READ_CTRL);
	}
}

static void
pdma_desc_set_section_address(struct pdma_desc *desc, dma_addr_t addr)
{
	desc->section_addr = addr;
	desc->section_size = 0;
}

static void
pdma_desc_set_section_size(struct pdma_desc *desc, u32 size)
{
	if (size > 0)
		desc->section_size = size - 1;
}

static void
pdma_desc_set_section_interrupt(struct pdma_desc *desc, u32 en)
{

	/*0:disable section interrupt. 1:enable section interrupt*/
	if (en == 1)
		desc->section_size |= PDMA_DESC_SIE;
	else
		desc->section_size &= ~PDMA_DESC_SIE;
}

static void
pdma_desc_set_sg_interrupt(struct pdma_desc *desc, u32 en)
{

	/*0:disable sg interrupt. 1:enable sg interrupt*/
	if (en == 1)
		desc->section_size |= PDMA_DESC_SSGIE;
	else
		desc->section_size &= ~PDMA_DESC_SSGIE;
}

static void
pdma_desc_set_data_swap(struct pdma_desc *desc, u32 en)
{

	/*0:disable data swap. 1:enable data swap*/
	if (en == 1)
		desc->section_size |= PDMA_DESC_DSE;
	else
		desc->section_size &= ~PDMA_DESC_DSE;
}

static void
pdma_desc_clean_desc(struct pdma_desc *desc)
{
	memset(desc, 0, sizeof(struct pdma_desc));
}

static void
pdma_tasklet(unsigned long data)
{
	struct pdma_chan *pdma_ch = (struct pdma_chan *)data;
	struct dmaengine_desc_callback cb;
	struct dma_async_tx_descriptor *txd = &pdma_ch->async_txd;

	dmaengine_desc_get_callback(txd, &cb);
	dmaengine_desc_callback_invoke(&cb, NULL);
}

static int
pdma_config(struct dma_chan *chan, struct dma_slave_config *sconfig)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);

	if (!chan)
		return -EINVAL;

	if (!is_slave_direction(sconfig->direction))
		dev_warn(&chan->dev->device,
		"Non-Slave channel configuration\n");

	memcpy(&pdma_ch->cfg, sconfig, sizeof(struct dma_slave_config));

	if (sconfig->direction == DMA_DEV_TO_MEM) {
		pdma_channel_set_flowctrl(chan, sconfig->device_fc);
		pdma_channel_set_burstlen(chan, sconfig->src_maxburst);
		pdma_channel_set_dataunit(chan,
			convert_dma_width(sconfig->src_addr_width));
		pdma_channel_set_perbaddr(chan, sconfig->src_addr);

	} else if (sconfig->direction == DMA_MEM_TO_DEV) {
		pdma_channel_set_flowctrl(chan, sconfig->device_fc);
		pdma_channel_set_burstlen(chan, sconfig->dst_maxburst);
		pdma_channel_set_dataunit(chan,
			convert_dma_width(sconfig->dst_addr_width));
		pdma_channel_set_perbaddr(chan, sconfig->dst_addr);
	}

	return 0;
}


static enum dma_status
pdma_tx_status(struct dma_chan *chan,
	      dma_cookie_t cookie,
	      struct dma_tx_state *txstate)
{
	enum dma_status	ret;

	ret = DMA_IN_PROGRESS;

	return ret;
}

static void pdma_issue_pending(struct dma_chan *chan)
{
	pdma_ring_set_event(chan, PDMA_CH_EVENT_UPDATE);
}

static int
pdma_alloc_chan_resources(struct dma_chan *chan)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);

	dma_cookie_init(chan);

	if (pdma_ch->pdma_descs)
		return pdma_ch->pdma_descs_count;

	pdma_ch->pdma_descs_count = PDMA_MAX_DESC_CNT;
	pdma_ch->head_idx = 0;
	pdma_ch->tail_idx = 0;
	pdma_ch->wrap = 0;

	pdma_ch->pdma_descs = dma_alloc_coherent(
			chan->device->dev,
			pdma_ch->pdma_descs_count * sizeof(struct pdma_desc),
			&pdma_ch->pdma_descs_phys,
			GFP_KERNEL | __GFP_ZERO);

	if (!pdma_ch->pdma_descs)
		return -ENOMEM;

	pdma_ch->pdma_descs_tail_phys = pdma_ch->pdma_descs_phys +
			pdma_ch->pdma_descs_count * sizeof(struct pdma_desc);

	pdma_channel_reset(chan);

	pdma_clk_set(chan, 1);
	pdma_clk_set_polarity(chan, 0);
	pdma_clk_set_gating_bpss(chan, 0);

	pdma_channel_set_sgctrl(chan, 4);
	pdma_channel_set_irq(chan, 1);
	pdma_channel_set_handshake(chan, 1);

	pdma_ring_set_baddr(chan, pdma_ch->pdma_descs_phys);
	pdma_ring_set_depth(chan, pdma_ch->pdma_descs_count);
	pdma_ring_set_event(chan, PDMA_CH_EVENT_FIRE);

	dev_dbg(&chan->dev->device, "pdma_descs = %p\n",
			pdma_ch->pdma_descs);
	dev_dbg(&chan->dev->device, "pdma_descs_phys = %lld\n",
			pdma_ch->pdma_descs_phys);
	dev_dbg(&chan->dev->device, "pdma_descs_tail_phys = %lld\n",
			pdma_ch->pdma_descs_tail_phys);
	dev_dbg(&chan->dev->device, "pdma_descs_count = %d\n",
			pdma_ch->pdma_descs_count);

	return pdma_ch->pdma_descs_count;
}

static void
pdma_free_chan_resources(struct dma_chan *chan)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);

	if (pdma_ch->pdma_descs)
		dma_free_coherent(chan->device->dev,
			pdma_ch->pdma_descs_count * sizeof(struct pdma_desc),
			pdma_ch->pdma_descs,
			pdma_ch->pdma_descs_phys);

	pdma_clk_set(chan, 0);
	pdma_clk_set_polarity(chan, 0);
	pdma_clk_set_gating_bpss(chan, 0);

	pdma_ch->pdma_descs = NULL;
	pdma_ch->pdma_descs_phys = 0;
	pdma_ch->pdma_descs_tail_phys = 0;
	pdma_ch->pdma_descs_count = 0;
	pdma_ch->head_idx = 0;
	pdma_ch->tail_idx = 0;
	pdma_ch->wrap = 0;
}

static dma_cookie_t
pdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(tx->chan);
	dma_cookie_t		cookie;
	unsigned long		flags;

	spin_lock_irqsave(&pdma_ch->ch_lock, flags);
	cookie = dma_cookie_assign(tx);

	/*
	 * REVISIT: We should attempt to chain as many descriptors as
	 * possible, perhaps even appending to those already submitted
	 * for DMA. But this is hard to do in a race-free manner.
	 */

	pdma_ring_set_wrptr(tx->chan, pdma_ch->tail_idx);
	pdma_ring_set_wrap(tx->chan, pdma_ch->wrap);
	spin_unlock_irqrestore(&pdma_ch->ch_lock, flags);
	return cookie;
}

static struct dma_async_tx_descriptor *
pdma_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
		   unsigned int sg_len, enum dma_transfer_direction dir,
		   unsigned long flags, void *context)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	struct pdma_desc *desc_cur;
	struct dma_async_tx_descriptor *async_tx;
	size_t len, avail;
	struct scatterlist *sg;
	dma_addr_t dma_addr;
	int cur_idx, pre_idx;
	int i;

	if (unlikely(!is_slave_direction(dir)))
		return NULL;

	if ((sgl == NULL) || (sg_len == 0))
		return NULL;

	cur_idx = pdma_ch->tail_idx;

	for_each_sg(sgl, sg, sg_len, i) {
		dma_addr = sg_dma_address(sg);
		avail = sg_dma_len(sg);

		do {
			desc_cur = &pdma_ch->pdma_descs[cur_idx];

			len = min_t(size_t, avail, PDMA_MAX_DESC_BYTES);
			pdma_desc_clean_desc(desc_cur);
			pdma_desc_set_section_address(desc_cur, dma_addr);
			pdma_desc_set_section_size(desc_cur, len);
			pdma_desc_set_section_interrupt(desc_cur, 0);
			pdma_desc_set_sg_interrupt(desc_cur, 0);
			pdma_desc_set_data_swap(desc_cur, pdma_ch->swap_data);
			pre_idx = cur_idx;
			cur_idx++;

			if (cur_idx == pdma_ch->pdma_descs_count) {
				cur_idx = 0;
				pdma_ch->wrap = pdma_ch->wrap ? 0 : 1;
			}

			dma_addr += len;
			avail -= len;
		} while (avail);

		desc_cur = &pdma_ch->pdma_descs[pre_idx];
	}

	pdma_desc_set_section_interrupt(desc_cur, 1);

	pdma_ch->tail_idx = cur_idx;
	async_tx = &pdma_ch->async_txd;
	async_tx->cookie = -EBUSY;
	async_tx->flags = DMA_CTRL_ACK;
	async_tx->phys = pdma_ch->pdma_descs_phys +
				pre_idx * sizeof(struct pdma_desc);
	async_tx->chan = chan;
	async_tx->tx_submit = pdma_tx_submit;

	return async_tx;
}


struct pdma_of_dma_filter_args {
	struct pdma_device *pdma;
	unsigned int req;
	unsigned int channel;
	unsigned int slave;
	unsigned int swap_data;
};

static bool pdma_of_dma_filter(struct dma_chan *chan, void *param)
{
	struct pdma_chan *pdma_ch = to_pdma_chan(chan);
	struct pdma_of_dma_filter_args *fargs = param;

	/* Check dma device */
	if (chan->device != &fargs->pdma->dma)
		return false;

	/* Check channel ID */
	if (pdma_ch->chan.chan_id != fargs->channel)
		return false;

	dev_dbg(&chan->dev->device, "%s: filter found channel %u\n", __func__,
			pdma_ch->chan.chan_id);

	pdma_ch->swap_data = fargs->swap_data;

	return true;
}

static struct dma_chan *pdma_of_dma_xlate(struct of_phandle_args *dma_spec,
					   struct of_dma *ofdma)
{
	struct pdma_device *pdma = ofdma->of_dma_data;
	struct pdma_of_dma_filter_args fargs;
	struct dma_chan *chan;
	dma_cap_mask_t cap;

	if (dma_spec->args_count != 3)
		return NULL;

	fargs.pdma = pdma;
	fargs.channel = dma_spec->args[0];
	fargs.slave = dma_spec->args[1];
	fargs.swap_data = dma_spec->args[2];

	dev_dbg(&chan->dev->device, "channel=%d, slave=%d, swap_data=%d\n",
			fargs.channel, fargs.slave, fargs.swap_data);

	dma_cap_zero(cap);

	/* DMA_SLAVE capability is not finished yet */
	dma_cap_set(DMA_SLAVE, cap);

	return dma_request_channel(cap, pdma_of_dma_filter, &fargs);
}

static int pdma_platform_probe(struct platform_device *pdev)
{
	struct pdma_device	*pdma;
	struct resource		*io;
	int i, ret;

	const enum dma_slave_buswidth widths =
		DMA_SLAVE_BUSWIDTH_1_BYTE   | DMA_SLAVE_BUSWIDTH_2_BYTES |
		DMA_SLAVE_BUSWIDTH_4_BYTES;

	pdma = devm_kzalloc(&pdev->dev,
			sizeof(struct pdma_device), GFP_KERNEL);
	if (!pdma)
		return -ENOMEM;

	pdma->dev = &pdev->dev;

	spin_lock_init(&pdma->phy_lock);

	io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!io)
		return -EINVAL;

	pdma->regs = devm_ioremap_resource(&pdev->dev, io);
	if (IS_ERR(pdma->regs))
		return PTR_ERR(pdma->regs);

	pdma->clk_axi_ddr = devm_clk_get(&pdev->dev, "pdma_axi_ddr");
	if (IS_ERR(pdma->clk_axi_ddr)) {
		dev_err(&pdev->dev, "pdma_axi_ddr clock not found.\n");
		return PTR_ERR(pdma->clk_axi_ddr);
	}
	ret = clk_prepare_enable(pdma->clk_axi_ddr);
	if (ret) {
		dev_err(&pdev->dev, "failed to enable pdma_axi_ddr clock: %d\n",
			ret);
		return ret;
	}

	pdma->clk_apb = devm_clk_get(&pdev->dev, "pdma_apb");
	if (IS_ERR(pdma->clk_apb)) {
		dev_err(&pdev->dev, "pdma_apb clock not found.\n");
		return PTR_ERR(pdma->clk_apb);
	}
	ret = clk_prepare_enable(pdma->clk_apb);
	if (ret) {
		dev_err(&pdev->dev, "failed to enable pdma_apb clock: %d\n",
			ret);
		return ret;
	}

	pdma->mem_pwr_pdmac = devm_clk_get(&pdev->dev, "pwr_pdmac");
	if (IS_ERR(pdma->mem_pwr_pdmac)) {
		dev_err(&pdev->dev, "pwr_pdmac clock not found.\n");
		return PTR_ERR(pdma->mem_pwr_pdmac);
	}
	ret = clk_prepare_enable(pdma->mem_pwr_pdmac);
	if (ret) {
		dev_err(&pdev->dev, "failed to enable pwr_pdmac clock: %d\n",
			ret);
		return ret;
	}

	pdma->irq = platform_get_irq(pdev, 0);
	if (pdma->irq < 0)
		return pdma->irq;

	ret = request_irq(pdma->irq, &pdma_intr_handle,
			IRQF_TRIGGER_HIGH, "pdma_irq", pdma);
	if (ret) {
		dev_err(&pdev->dev, "failed to get irq\n");
		return ret;
	}

	INIT_LIST_HEAD(&pdma->dma.channels);

	for (i = PDMA_CHANNELS - 1 ; i >= 0; i--) {

		struct pdma_chan *pdma_ch = &pdma->chan[i];
		struct pdma_ch_info ch_info;

		pdma_channel_get_info(i, &ch_info);

		pdma_ch->chan.device = &pdma->dma;
		pdma_ch->regs = pdma->regs + ch_info.addr_offset;
		pdma_ch->channel_type = ch_info.channel_type;
		pdma_ch->device_type = ch_info.device_type;
		pdma_ch->chan_id = i;
		pdma_ch->pdma = pdma;

		dma_cookie_init(&pdma_ch->chan);
		spin_lock_init(&pdma_ch->ch_lock);
		tasklet_init(&pdma_ch->tasklet,
			pdma_tasklet, (unsigned long)pdma_ch);
		init_completion(&pdma_ch->reset_completion);
		list_add(&pdma_ch->chan.device_node, &pdma->dma.channels);
	}

	dma_cap_set(DMA_SLAVE, pdma->dma.cap_mask);

	pdma->dma.copy_align = 0;
	pdma->dma.dev = &pdev->dev;
	pdma->dma.device_alloc_chan_resources = pdma_alloc_chan_resources;
	pdma->dma.device_free_chan_resources = pdma_free_chan_resources;
	pdma->dma.device_prep_dma_memcpy = NULL;
	pdma->dma.device_prep_slave_sg = pdma_prep_slave_sg;
	pdma->dma.device_config = pdma_config;
	pdma->dma.device_pause = NULL;
	pdma->dma.device_resume = NULL;
	pdma->dma.device_terminate_all = NULL;
	pdma->dma.device_prep_dma_cyclic = NULL;

	pdma->dma.device_tx_status = pdma_tx_status;
	pdma->dma.device_issue_pending = pdma_issue_pending;

	pdma->dma.src_addr_widths = widths;
	pdma->dma.dst_addr_widths = widths;
	pdma->dma.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
	pdma->dma.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;

	ret = dma_async_device_register(&pdma->dma);
	if (ret) {
		dev_err(&pdev->dev, "unable to register pdma\n");
		return ret;
	}

	if (pdev->dev.of_node) {
		ret = of_dma_controller_register(pdev->dev.of_node,
						 pdma_of_dma_xlate, pdma);
		if (ret < 0) {
			dev_err(&pdev->dev, "of register failed\n");
			return ret;
		}
	}

	platform_set_drvdata(pdev, pdma);

	dev_info(&pdev->dev, "PDMA Controller probe done\n");

	return 0;
}

static int pdma_platform_remove(struct platform_device *pdev)
{
	struct pdma_device	*pdma = platform_get_drvdata(pdev);

	dma_async_device_unregister(&pdma->dma);

	clk_disable_unprepare(pdma->clk_axi_ddr);
	clk_disable_unprepare(pdma->clk_apb);
	clk_disable_unprepare(pdma->mem_pwr_pdmac);

	devm_kfree(&pdev->dev, pdma);

	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id pdma_of_id_table[] = {
	{ .compatible = "leipzig-pdma" },
	{}
};
MODULE_DEVICE_TABLE(of, pdma_of_id_table);
#endif

static const struct platform_device_id pdma_id_table[] = {
	{ "leipzig-pdma", },
	{ },
};

static struct platform_driver pdma_platform_driver = {
	.driver = {
		.name	= "leipzig-pdma",
		.of_match_table = of_match_ptr(pdma_of_id_table),
	},
	.id_table	= pdma_id_table,
	.probe		= pdma_platform_probe,
	.remove		= pdma_platform_remove,
};

static int __init pdma_init(void)
{
	return platform_driver_register(&pdma_platform_driver);
}
module_init(pdma_init);

static void __exit pdma_exit(void)
{
	platform_driver_unregister(&pdma_platform_driver);
}
module_exit(pdma_exit);

MODULE_DESCRIPTION("Leipzig Peripheral DMA Driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");
