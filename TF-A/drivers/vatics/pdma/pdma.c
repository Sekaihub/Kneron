#include <platform_def.h>
#include <common/debug.h>
#include <drivers/delay_timer.h>
#include <drivers/clk.h>
#include <lib/mmio.h>
#include <wagner_buf.h>

#include <drivers/vatics/pdma.h>

/* channel base address */
#define PDMA_MMR_BASE    VPL_PDMAC_MMR_BASE

#define PDMA_RXCH0_BASE	(PDMA_MMR_BASE + 0x00000030)
#define PDMA_RXCH1_BASE	(PDMA_MMR_BASE + 0x00000088)
#define PDMA_RXCH2_BASE	(PDMA_MMR_BASE + 0x000000E0)
#define PDMA_RXCH3_BASE	(PDMA_MMR_BASE + 0x00000138)
#define PDMA_RXCH4_BASE	(PDMA_MMR_BASE + 0x00000190)
#define PDMA_RXCH5_BASE	(PDMA_MMR_BASE + 0x000001E8)
#define PDMA_RXCH6_BASE	(PDMA_MMR_BASE + 0x00000240)

#define PDMA_TXCH0_BASE	(PDMA_MMR_BASE + 0x0000005C)
#define PDMA_TXCH1_BASE	(PDMA_MMR_BASE + 0x000000B4)
#define PDMA_TXCH2_BASE	(PDMA_MMR_BASE + 0x0000010C)
#define PDMA_TXCH3_BASE	(PDMA_MMR_BASE + 0x00000164)
#define PDMA_TXCH4_BASE	(PDMA_MMR_BASE + 0x000001BC)
#define PDMA_TXCH5_BASE	(PDMA_MMR_BASE + 0x00000214)
#define PDMA_TXCH6_BASE	(PDMA_MMR_BASE + 0x0000026C)

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
#define PDMA_RX_PER_BASE_ADDR          0x00
#define PDMA_RX_PER_CTRL               0x04
#define PDMA_RX_RING_READ_BASE_ADDR    0x08
#define PDMA_RX_RING_READ_CTRL         0x0C
#define PDMA_RX_RING_READ_EVENT_PU     0x10
#define PDMA_RX_SG_CTRL                0x14
#define PDMA_RX_INTR_CTRL              0x18
#define PDMA_RX_DMA_CTRL               0x1C
#define PDMA_RX_STATE                  0x20
#define PDMA_RX_BYTE_CNT               0x24
#define PDMA_RX_INTR                   0x28

/* PDMA TX channel registers */
#define PDMA_TX_PER_BASE_ADDR          0x00
#define PDMA_TX_PER_CTRL               0x04
#define PDMA_TX_RING_READ_BASE_ADDR    0x08
#define PDMA_TX_RING_READ_CTRL         0x0C
#define PDMA_TX_RING_READ_EVENT_PU     0x10
#define PDMA_TX_SG_CTRL                0x14
#define PDMA_TX_INTR_CTRL              0x18
#define PDMA_TX_RESET_CTRL             0x1C
#define PDMA_TX_STATE                  0x20
#define PDMA_TX_BYTE_CNT               0x24
#define PDMA_TX_INTR                   0x28

#define BITMASK GENMASK

/* peripheral control bit fields (mmr offset:0x0004) */
#define PDMA_CH_PCTRL_HS           BIT(0)          /* Handshake Enable */
#define PDMA_CH_PCTRL_DU(v)        ((v) << 1)      /* Data Unit */
#define PDMA_CH_PCTRL_DU_MASK      BITMASK(2, 1)   /* Data Unit Bit Mask*/
#define PDMA_CH_PCTRL_FC           BIT(3)          /* Flow Control */
#define PDMA_CH_PCTRL_BL(v)        ((v) << 4)      /* Burst Length */
#define PDMA_CH_PCTRL_BL_MASK      BITMASK(8, 4)   /* Burst Length Bit Mask */


/* ring read control bit fields (mmr offset:0x000C) */
#define PDMA_CH_RRCTRL_DEPTH(v)    ((v) << 0)      /* Handshake Enable */
#define PDMA_CH_RRCTRL_DEPTH_MASK  BITMASK(13, 0)
#define PDMA_CH_RRCTRL_ES          BIT(14)         /* Event Select */
#define PDMA_CH_RRCTRL_WRAP        BIT(15)
#define PDMA_CH_RRCTRL_WRPTR(v)    ((v) << 16)
#define PDMA_CH_RRCTRL_WRPTR_MASK  BITMASK(29, 16)


/* state bit fields (mmr offset:0x0020) */
#define PDMA_CH_STATE_IDLE         BIT(0)          /* engine idle */
#define PDMA_CH_STATE_HS_BUSY      BIT(1)          /* Handshake Busy */
#define PDMA_CH_STATE_RR_RD_WRAP   BIT(2)          /* Ring Read WRAP flag */
#define PDMA_CH_STATE_RR_RD_PTR    BITMASK(16, 3)
#define PDMA_CH_STATE_RR_CMPT_WRAP BIT(17)
#define PDMA_CH_STATE_RR_CMPT_PTR  BITMASK(31, 18)


/* TX intr bit fields (mmr offset:0x0028) */
#define PDMA_TXCH_INTR_RST_CMPT    BIT(0)          /* Reset Complete */
#define PDMA_TXCH_INTR_SEC_CMPT    BIT(1)          /* Section Complete */
#define PDMA_TXCH_INTR_BUS_ERR     BIT(3)          /* Bus Error */
#define PDMA_TXCH_INTR_SGSEC_CMPT  BIT(4)          /* SG Section Complete */

/* RX intr bit fields (mmr offset:0x0028) */
#define PDMA_RXCH_INTR_FLU_CMPT    BIT(0)          /* Flush Complete */
#define PDMA_RXCH_INTR_RST_CMPT    BIT(1)          /* Reset Complete */
#define PDMA_RXCH_INTR_SEC_CMPT    BIT(3)          /* Section Complete */
#define PDMA_RXCH_INTR_BUS_ERR     BIT(5)          /* Bus Error */


/* channel interrupt_enable bit fields (mmr offset:0x0018) */
#define PDMA_TXCH_INTR_RCI_EN      BIT(0)          /* Reset Complete */
#define PDMA_TXCH_INTR_SCI_EN      BIT(1)          /* Section Complete */
#define PDMA_TXCH_INTR_BEI_EN      BIT(2)          /* Bus Error */
#define PDMA_TXCH_INTR_SGSCI_EN    BIT(3)          /* SG section Complete */

#define PDMA_RXCH_INTR_FCI_EN      BIT(0)          /* Flush Interrupt */
#define PDMA_RXCH_INTR_RCI_EN      BIT(1)          /* Reset Interrupt */
#define PDMA_RXCH_INTR_SCI_EN      BIT(3)          /* Section Interrupt */
#define PDMA_RXCH_INTR_BEI_EN      BIT(5)          /* Bus Error */

#define PDMA_DESC_SIE	BIT(31) /*Section interrupt enable*/
#define PDMA_DESC_SSGIE	BIT(30) /*Section SG interrupt enable*/
#define PDMA_DESC_DSE	BIT(29) /*Data swap enable*/

#define PDMA_MAX_DESC_BYTES           SZ_32K

#if PDMA_ENABLE

uint32_t pdma_get_version(void)
{
	return mmio_read_32(PDMA_MMR_BASE + PDMA_MAC_VERSION);
}

void pdma_channel_reset(struct pdma_chan *chan)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		mmio_setbits_32(addr + PDMA_RX_DMA_CTRL, 0x1);

		/* polling reset complete*/
		while (!(mmio_read_32(addr + PDMA_RX_INTR)
			& PDMA_RXCH_INTR_RST_CMPT))
			;
		/* write 1 clear */
		mmio_setbits_32(addr + PDMA_RX_INTR, PDMA_RXCH_INTR_RST_CMPT);
	} else if (type == PDMA_TXCH) {
		mmio_setbits_32(addr + PDMA_TX_RESET_CTRL, 0x1);

		/* polling reset complete*/
		while (!(mmio_read_32(addr + PDMA_TX_INTR)
			& PDMA_TXCH_INTR_RST_CMPT))
			;
		/* write 1 clear */
		mmio_setbits_32(addr + PDMA_TX_INTR, PDMA_TXCH_INTR_RST_CMPT);
	}
}

static void
pdma_channel_set_clk(struct pdma_chan *chan, uint32_t en)
{
	uint32_t ch = chan->chan_num;

	if (en)
		mmio_setbits_32(PDMA_MMR_BASE + PDMA_MAC_CTRL0, (0x1 << ch));
	else
		mmio_clrbits_32(PDMA_MMR_BASE + PDMA_MAC_CTRL0, (0x1 << ch));
}

static void
pdma_channel_set_handshake(struct pdma_chan *chan, uint32_t en)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		if (en)
			mmio_setbits_32(addr + PDMA_RX_PER_CTRL,
					PDMA_CH_PCTRL_HS);
		else
			mmio_clrbits_32(addr + PDMA_RX_PER_CTRL,
					PDMA_CH_PCTRL_HS);

		/* polling handshake busy */
		while ((mmio_read_32(addr + PDMA_RX_STATE) &
			PDMA_CH_STATE_HS_BUSY))
			;

	} else if (type == PDMA_TXCH) {
		if (en)
			mmio_setbits_32(addr + PDMA_TX_PER_CTRL,
					PDMA_CH_PCTRL_HS);
		else
			mmio_clrbits_32(addr + PDMA_TX_PER_CTRL,
					PDMA_CH_PCTRL_HS);

		/* polling handshake busy */
		while ((mmio_read_32(addr + PDMA_TX_STATE) &
			PDMA_CH_STATE_HS_BUSY))
			;
	}
}

static void
pdma_channel_set_perbaddr(struct pdma_chan *chan, uint32_t paddr)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_write_32(addr + PDMA_RX_PER_BASE_ADDR, paddr);
	else if (type == PDMA_TXCH)
		mmio_write_32(addr + PDMA_TX_PER_BASE_ADDR, paddr);
}


static void
pdma_channel_set_dataunit(struct pdma_chan *chan, enum pdma_data_unit du)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_clrsetbits_32(addr + PDMA_RX_PER_CTRL,
				PDMA_CH_PCTRL_DU_MASK,
				PDMA_CH_PCTRL_DU(du));
	else if (type == PDMA_TXCH)
		mmio_clrsetbits_32(addr + PDMA_TX_PER_CTRL,
				PDMA_CH_PCTRL_DU_MASK,
				PDMA_CH_PCTRL_DU(du));
}

static void
pdma_channel_set_flowctrl(struct pdma_chan *chan, uint32_t fc)
{
	/* 0:Peripheral DMA is flow controller.   */
	/* 1:Source peripheral is flow controller */

	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		if (fc)
			mmio_setbits_32(addr + PDMA_RX_PER_CTRL,
					PDMA_CH_PCTRL_FC);
		else
			mmio_clrbits_32(addr + PDMA_RX_PER_CTRL,
					PDMA_CH_PCTRL_FC);
	} else if (type == PDMA_TXCH) {
		if (fc)
			mmio_setbits_32(addr + PDMA_TX_PER_CTRL,
					PDMA_CH_PCTRL_FC);
		else
			mmio_clrbits_32(addr + PDMA_TX_PER_CTRL,
					PDMA_CH_PCTRL_FC);
	}
}

static void
pdma_channel_set_burstlen(struct pdma_chan *chan, uint32_t bl)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_clrsetbits_32(addr + PDMA_RX_PER_CTRL,
				PDMA_CH_PCTRL_BL_MASK,
				PDMA_CH_PCTRL_BL(bl));
	else if (type == PDMA_TXCH)
		mmio_clrsetbits_32(addr + PDMA_TX_PER_CTRL,
				PDMA_CH_PCTRL_BL_MASK,
				PDMA_CH_PCTRL_BL(bl));
}

static void
pdma_channel_set_sgctrl(struct pdma_chan *chan, uint32_t sgctrl)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_write_32(addr + PDMA_RX_SG_CTRL, (sgctrl-1));
	else if (type == PDMA_TXCH)
		mmio_write_32(addr + PDMA_TX_SG_CTRL, (sgctrl-1));
}

static void
pdma_channel_set_irq(struct pdma_chan *chan, uint32_t en)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		if (en)
			mmio_setbits_32(addr + PDMA_RX_INTR_CTRL,
					PDMA_RXCH_INTR_NORMAL);
		else
			mmio_clrbits_32(addr + PDMA_RX_INTR_CTRL,
					PDMA_RXCH_INTR_NORMAL);
	} else if (type == PDMA_TXCH) {
		if (en)
			mmio_setbits_32(addr + PDMA_TX_INTR_CTRL,
					PDMA_TXCH_INTR_NORMAL);
		else
			mmio_clrbits_32(addr + PDMA_TX_INTR_CTRL,
					PDMA_TXCH_INTR_NORMAL);
	}
}

static void
pdma_wait_section_complete(struct pdma_chan *chan)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {

		while (!(mmio_read_32(addr + PDMA_RX_INTR) &
			PDMA_RXCH_INTR_SEC_CMPT))
			;
		/* write 1 clear */
		mmio_write_32(addr + PDMA_RX_INTR, PDMA_RXCH_INTR_SEC_CMPT);
	} else if (type == PDMA_TXCH) {
		while (!(mmio_read_32(addr + PDMA_TX_INTR) &
			PDMA_TXCH_INTR_SEC_CMPT))
			;
		/* write 1 clear */
		mmio_write_32(addr + PDMA_TX_INTR, PDMA_TXCH_INTR_SEC_CMPT);
	}
}

static void
pdma_ring_set_baddr(struct pdma_chan *chan, uint32_t baddr)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_write_32(addr + PDMA_RX_RING_READ_BASE_ADDR, baddr);
	else if (type == PDMA_TXCH)
		mmio_write_32(addr + PDMA_TX_RING_READ_BASE_ADDR, baddr);
}

static void
pdma_ring_set_depth(struct pdma_chan *chan, uint32_t depth)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_clrsetbits_32(addr + PDMA_RX_RING_READ_CTRL,
				PDMA_CH_RRCTRL_DEPTH_MASK,
				PDMA_CH_RRCTRL_DEPTH(depth));
	else if (type == PDMA_TXCH)
		mmio_clrsetbits_32(addr + PDMA_TX_RING_READ_CTRL,
				PDMA_CH_RRCTRL_DEPTH_MASK,
				PDMA_CH_RRCTRL_DEPTH(depth));
}

static void
pdma_ring_set_event(struct pdma_chan *chan, enum pdma_channel_event event)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		if (event == PDMA_CH_EVENT_FIRE)
			mmio_setbits_32(addr + PDMA_RX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_ES);
		else if (event == PDMA_CH_EVENT_UPDATE)
			mmio_clrbits_32(addr + PDMA_RX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_ES);

		mmio_write_32(addr + PDMA_RX_RING_READ_EVENT_PU, 0x1);

	} else if (type == PDMA_TXCH) {
		if (event == PDMA_CH_EVENT_FIRE)
			mmio_setbits_32(addr + PDMA_TX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_ES);
		else if (event == PDMA_CH_EVENT_UPDATE)
			mmio_clrbits_32(addr + PDMA_TX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_ES);

		mmio_write_32(addr + PDMA_TX_RING_READ_EVENT_PU, 0x1);
	}
}

static void
pdma_ring_set_wrap(struct pdma_chan *chan, uint32_t warp)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH) {
		if (warp == 1)
			mmio_setbits_32(addr + PDMA_RX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_WRAP);
		else
			mmio_clrbits_32(addr + PDMA_RX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_WRAP);
	} else if (type == PDMA_TXCH) {
		if (warp == 1)
			mmio_setbits_32(addr + PDMA_TX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_WRAP);
		else
			mmio_clrbits_32(addr + PDMA_TX_RING_READ_CTRL,
					PDMA_CH_RRCTRL_WRAP);
	}
}

static void
pdma_ring_set_wrptr(struct pdma_chan *chan, uint32_t wrptr)
{
	uint32_t addr = chan->base_addr;
	enum pdma_channel_type type = chan->chan_type;

	if (type == PDMA_RXCH)
		mmio_clrsetbits_32(addr + PDMA_RX_RING_READ_CTRL,
				PDMA_CH_RRCTRL_WRPTR_MASK,
				PDMA_CH_RRCTRL_WRPTR(wrptr));
	else if (type == PDMA_TXCH)
		mmio_clrsetbits_32(addr + PDMA_TX_RING_READ_CTRL,
				PDMA_CH_RRCTRL_WRPTR_MASK,
				PDMA_CH_RRCTRL_WRPTR(wrptr));
}

static void
pdma_ring_alloc(struct pdma_chan *chan, uint32_t len)
{
	if (chan->chan_type == PDMA_RXCH)
		chan->pdma_descs =
		(struct pdma_desc *)overlaid_buffer.spi_buf.desc_rxbuf;
	else
		chan->pdma_descs =
		(struct pdma_desc *)overlaid_buffer.spi_buf.desc_txbuf;

	chan->pdma_descs_count = len;
	chan->tail_idx = 0;
	chan->wrap = 0;
}

static void
pdma_ring_free(struct pdma_chan *chan)
{
	//if (chan->pdma_descs)
		//free(chan->pdma_descs);

	chan->pdma_descs = 0;
	chan->pdma_descs_count = 0;
	chan->tail_idx = 0;
	chan->wrap = 0;
}

static void
pdma_desc_set_section_address(struct pdma_desc *desc, uint32_t addr)
{
	desc->section_addr = addr;
	desc->section_size = 0;
}

static void
pdma_desc_set_section_size(struct pdma_desc *desc, uint32_t size)
{
	if (size > 0)
		desc->section_size = size - 1;
}

static void
pdma_desc_set_section_interrupt(struct pdma_desc *desc, uint32_t en)
{
	/*0:disable section interrupt. 1:enable section interrupt*/
	if (en)
		desc->section_size |= PDMA_DESC_SIE;
	else
		desc->section_size &= ~PDMA_DESC_SIE;
}

static void
pdma_desc_set_sg_interrupt(struct pdma_desc *desc, uint32_t en)
{
	/*0:disable sg interrupt. 1:enable sg interrupt*/
	if (en)
		desc->section_size |= PDMA_DESC_SSGIE;
	else
		desc->section_size &= ~PDMA_DESC_SSGIE;
}

static void
pdma_desc_set_data_swap(struct pdma_desc *desc, uint32_t en)
{
	/*0:disable data swap. 1:enable data swap*/
	if (en)
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
pdma_ops_init(struct pdma_chan *chan, struct pdma_init *init)
{
	pdma_channel_set_clk(chan, 0x1);
	pdma_ring_alloc(chan, init->pdma_descs_count);
	pdma_ring_set_baddr(chan, (uint32_t)(uint64_t)chan->pdma_descs);
	pdma_ring_set_depth(chan, init->pdma_descs_count);
	pdma_channel_set_perbaddr(chan, init->paddr);
	pdma_channel_set_handshake(chan, 0x1);
	pdma_ring_set_event(chan, PDMA_CH_EVENT_FIRE);
}

static void
pdma_ops_conf(struct pdma_chan *chan, struct pdma_conf *conf)
{
	pdma_channel_set_dataunit(chan, conf->data_unit);
	pdma_channel_set_burstlen(chan, conf->burstlen);
	pdma_channel_set_sgctrl(chan, conf->sctrl);
	pdma_channel_set_flowctrl(chan, conf->flowctrl);
	pdma_channel_set_irq(chan, conf->intr_en);

	chan->data_unit = conf->data_unit;
	chan->burstlen = conf->burstlen;
	chan->sctrl = conf->sctrl;
	chan->flowctrl = conf->flowctrl;
	chan->intr_en = conf->intr_en;
}

static void
pdma_ops_prep(struct pdma_chan *chan, struct pdma_prep *prep)
{
	struct pdma_desc *desc_cur;
	uint32_t len, avail;
	uint32_t cur_idx, pre_idx;
	uint32_t dma_addr;

	if ((!prep->xfer_addr) || (prep->xfer_len == 0))
		return;

	cur_idx = chan->tail_idx;
	avail = prep->xfer_len;
	dma_addr = prep->xfer_addr;

	do {
		desc_cur = &chan->pdma_descs[cur_idx];

		len = MIN(avail, (uint32_t)PDMA_MAX_DESC_BYTES);
		pdma_desc_clean_desc(desc_cur);
		pdma_desc_set_section_address(desc_cur, dma_addr);
		pdma_desc_set_section_size(desc_cur, len);
		pdma_desc_set_section_interrupt(desc_cur, 0);
		pdma_desc_set_sg_interrupt(desc_cur, 0);
		pdma_desc_set_data_swap(desc_cur, prep->data_swap);
		pre_idx = cur_idx;
		cur_idx++;

		if (cur_idx == chan->pdma_descs_count) {
			cur_idx = 0;
			chan->wrap = chan->wrap ? 0 : 1;
		}

		dma_addr += len;
		avail -= len;
	} while (avail);

	desc_cur = &chan->pdma_descs[pre_idx];
	pdma_desc_set_section_interrupt(desc_cur, prep->sect_intr);

	flush_dcache_range((uintptr_t)chan->pdma_descs,
		sizeof(struct pdma_desc) * chan->pdma_descs_count);

	chan->tail_idx = cur_idx;

	pdma_ring_set_wrap(chan, chan->wrap);
	pdma_ring_set_wrptr(chan, chan->tail_idx);
}

static void
pdma_ops_xfer(struct pdma_chan *chan)
{
	pdma_ring_set_event(chan, PDMA_CH_EVENT_UPDATE);
	pdma_wait_section_complete(chan);
}

static void
pdma_ops_exit(struct pdma_chan *chan)
{
	pdma_channel_set_handshake(chan, 0x0);
	pdma_channel_reset(chan);
	pdma_channel_set_clk(chan, 0x0);
	pdma_ring_free(chan);
}

static void
pdma_pad_conf(enum pdma_device_type dev_type)
{
	switch (dev_type) {

	case PDMA_DEVICE_SSIC2:
		/*clear bit 0,4*/
		mmio_clrbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00000011);
		break;
	case PDMA_DEVICE_SSIC3:
		/*set bit 0,4*/
		mmio_setbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00000011);
		break;
	case PDMA_DEVICE_UART2:
		/*clear bit 8,9,12,13*/
		mmio_clrbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00003300);
		break;
	case PDMA_DEVICE_UART3:
		/*clear bit 9,13 set 8,12*/
		mmio_clrbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00002200);
		mmio_setbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00001100);
		break;
	case PDMA_DEVICE_UART4:
		/*set bit 9,13, don't care 8,12*/
		mmio_setbits_32(VPL_SYSC_SECURE_MMR_BASE + 0xCC, 0x00002200);
		break;
	default:
		break;
	}
}

void
pdma_request_channel(struct pdma_chan *chan)
{
	switch (chan->dev_type) {
	case PDMA_DEVICE_SSIC0:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH0_BASE;
			chan->chan_num = 0;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH0_BASE;
			chan->chan_num = 1;
			break;
		}
		break;
	case PDMA_DEVICE_SSIC1:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH1_BASE;
			chan->chan_num = 2;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH1_BASE;
			chan->chan_num = 3;
			break;
		}
		break;
	case PDMA_DEVICE_SSIC2:
	case PDMA_DEVICE_SSIC3:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH2_BASE;
			chan->chan_num = 4;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH2_BASE;
			chan->chan_num = 5;
			break;
		}
		break;
	case PDMA_DEVICE_I2SSC:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH3_BASE;
			chan->chan_num = 6;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH3_BASE;
			chan->chan_num = 7;
			break;
		}
		break;
	case PDMA_DEVICE_UART0:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH4_BASE;
			chan->chan_num = 8;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH4_BASE;
			chan->chan_num = 9;
			break;
		}
		break;
	case PDMA_DEVICE_UART1:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH5_BASE;
			chan->chan_num = 10;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH5_BASE;
			chan->chan_num = 11;
			break;
		}
		break;
	case PDMA_DEVICE_UART2:
	case PDMA_DEVICE_UART3:
	case PDMA_DEVICE_UART4:
		switch (chan->chan_type) {
		case PDMA_RXCH:
			chan->base_addr = PDMA_RXCH6_BASE;
			chan->chan_num = 12;
			break;
		case PDMA_TXCH:
			chan->base_addr = PDMA_TXCH6_BASE;
			chan->chan_num = 13;
			break;
		}
		break;
	default:
		break;
	}

	/* pdma pad config */
	pdma_pad_conf(chan->dev_type);

	/* ring info init*/
	chan->pdma_descs = 0;
	chan->paddr = 0;
	chan->pdma_descs_count = 0;
	chan->tail_idx = 0;
	chan->wrap = 0;

	/* parameters init*/
	chan->data_unit = 0;
	chan->intr_en = 0;
	chan->burstlen = 0;
	chan->sctrl = 0;
	chan->flowctrl = 0;
	chan->xfer_addr = 0;
	chan->xfer_len = 0;
	chan->sect_intr = 0;
	chan->sg_intr = 0;
	chan->data_swap = 0;

	/* assign ops */
	chan->init = pdma_ops_init;
	chan->conf = pdma_ops_conf;
	chan->prep = pdma_ops_prep;
	chan->xfer = pdma_ops_xfer;
	chan->exit = pdma_ops_exit;
}

#endif

