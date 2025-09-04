#include <platform_def.h>
#include <common/debug.h>
#include <drivers/spi_mem.h>
#include <drivers/delay_timer.h>
#include <drivers/clk.h>
#include <drivers/vatics/pdma.h>
#include <wagner_buf.h>

#include <lib/mmio.h>

#define BITMASK GENMASK

/* dw_qspi registers offset */
#define QSPI_CTRLR0		0x00U
#define QSPI_CTRLR1		0x04U
#define QSPI_SSIENR		0x08U
#define QSPI_MWCR		0x0CU
#define QSPI_SER		0x10U
#define QSPI_BAUDR		0x14U
#define QSPI_TXFTLR		0x18U
#define QSPI_RXFTLR		0x1CU
#define QSPI_TXFLR		0x20U
#define QSPI_RXFLR		0x24U
#define QSPI_SR			0x28U
#define QSPI_IMR		0x2CU
#define QSPI_ISR		0x30U
#define QSPI_RISR		0x34U
#define QSPI_TXOICR		0x38U
#define QSPI_RXOICR		0x3CU
#define QSPI_RXUICR		0x40U
#define QSPI_MSTICR		0x44U
#define QSPI_ICR		0x48U
#define QSPI_DMACR		0x4CU
#define QSPI_DMATDLR		0x50U
#define QSPI_DMARDLR		0x54U
#define QSPI_IDR		0x58U
#define QSPI_SSI_VERSION_ID	0x5CU
#define QSPI_DRX		0x60U
#define QSPI_RX_SAMPLE_DLY	0xF0U
#define QSPI_SCTRLR0		0xF4U
#define QSPI_TXD_DRIVE_EDGE	0xF8U
#define QSPI_RSVD		0xFCU

/* dw_qspi BAUD register (0x14) */
#define QSPI_BAUDR_SCKDV_MASK	BITMASK(15, 0)

/* dw_qspi status register (0x28) */
#define QSPI_SR_BUSY		BIT(0)
#define QSPI_SR_TFNF		BIT(1)
#define QSPI_SR_TFE		BIT(2)
#define QSPI_SR_RFNE		BIT(3)
#define QSPI_SR_RFF		BIT(4)
#define QSPI_SR_TXE		BIT(5)
#define QSPI_SR_DCOL		BIT(6)

/* dw_qspi interrupt mask register (0x2c) */
#define QSPI_IMR_TXEIM		BIT(0)
#define QSPI_IMR_TXOIM		BIT(1)
#define QSPI_IMR_RXUIM		BIT(2)
#define QSPI_IMR_RXOIM		BIT(3)
#define QSPI_IMR_RXFIM		BIT(4)
#define QSPI_IMR_MSTIM		BIT(5)

/* dw_qspi RXDLY register (0xF0) */
#define QSPI_RXDLY_MASK         BITMASK(7, 0)

/* dw_qspi SPI_CTRLR0 register (0xf4) */
#define QSPI_SCR0_TRANT(v)          ((v) << 0)      /* transfer type */
#define QSPI_SCR0_TRANT_MASK        BITMASK(1, 0)   /* transfer type bit mask*/
#define QSPI_SCR0_ADDRL(v)          ((v) << 2)      /* address length */
#define QSPI_SCR0_ADDRL_MASK        BITMASK(5, 2)   /* address length bit mask*/
#define QSPI_SCR0_INSTL(v)          ((v) << 8)      /* inst length */
#define QSPI_SCR0_INSTL_MASK        BITMASK(9, 8)   /* inst length bit mask*/
#define QSPI_SCR0_WAITC(v)          ((v) << 11)     /* wait cycles */
#define QSPI_SCR0_WAITC_MASK        BITMASK(15, 11) /* wait cycles bit mask*/
#define QSPI_SCR0_SPIDDR            BIT(16)
#define QSPI_SCR0_INSTDDR           BIT(17)

/* CTRLR0 data */
#define CTRLR0_SECONV      0x2000000  // RX endian conversion
#define CTRLR0_SPIFRF_QUAD 0x400000   // spi enhanced mode (quad)
#define CTRLR0_SPIFRF_DUAL 0x200000   // spi enhanced mode (dual)
#define CTRLR0_DFS32_32    0x1f0000   // data frame size for 32-bits width
#define CTRLR0_DFS32_8     0x70000    // data frame size for 8-bits width
#define CTRLR0_CFS         0x7000     // control frame size 8-bit
#define CTRLR0_EEPROM      0x300      // transfer mod is EEPROM Read
#define CTRLR0_RXONLY      0x200      // transfer mod is RX only
#define CTRLR0_TXONLY      0x100      // transfer mod is TX only
#define CTRLR0_SCPOL       0x80       // inactive state of serial clock is high
#define CTRLR0_SCPH        0x40       // seriral clock toggles

#define QSPI_CTRLR0_RX   (CTRLR0_DFS32_8 + \
			  CTRLR0_CFS +     \
			  CTRLR0_EEPROM +  \
			  CTRLR0_SCPOL +   \
			  CTRLR0_SCPH)

#define QSPI_CTRLR0_TX   (CTRLR0_DFS32_8 + \
			  CTRLR0_CFS +     \
			  CTRLR0_TXONLY +  \
			  CTRLR0_SCPOL +   \
			  CTRLR0_SCPH)

#define QSPI_CTRLR0_4RX  (CTRLR0_SECONV +      \
			  CTRLR0_SPIFRF_QUAD + \
			  CTRLR0_DFS32_32 +    \
			  CTRLR0_CFS +         \
			  CTRLR0_RXONLY +      \
			  CTRLR0_SCPOL +       \
			  CTRLR0_SCPH)

#define QSPI_CTRLR0_2RX  (CTRLR0_SECONV +      \
			  CTRLR0_SPIFRF_DUAL + \
			  CTRLR0_DFS32_32 +    \
			  CTRLR0_CFS +         \
			  CTRLR0_RXONLY +      \
			  CTRLR0_SCPOL +       \
			  CTRLR0_SCPH)

#define QSPI_TXFIFO_LEN 0x20
#define QSPI_RXFIFO_LEN 0x20

/* dw_qspi compatible */
#define DT_QSPI_COMPAT		"vatics,dw-qspi"

/* dw_qspi timeout value */
#define QSPI_TFE_TIMEOUT_US	100U
#define QSPI_BUSY_TIMEOUT_US	100U
#define QSPI_CMD_TIMEOUT_US	1000U

#define QSPI_MAX_CHIP		2U

struct dw_qspi_res *dwqspi;

static int dw_qspi_wait_for_not_busy(void)
{
	uint64_t timeout = timeout_init_us(QSPI_BUSY_TIMEOUT_US);

	while ((mmio_read_32(dwqspi->reg_base + QSPI_SR)
		& QSPI_SR_BUSY) != 0U) {
		if (timeout_elapsed(timeout)) {
			ERROR("%s: busy timeout\n", __func__);
			return -ETIMEDOUT;
		}
	}
	return 0;
}

static int dw_qspi_wait_for_TFE(void)
{
	uint64_t timeout = timeout_init_us(QSPI_TFE_TIMEOUT_US);

	while ((mmio_read_32(dwqspi->reg_base + QSPI_SR)
		& QSPI_SR_TFE) == 0U) {
		if (timeout_elapsed(timeout)) {
			ERROR("%s: TFE timeout\n", __func__);
			return -ETIMEDOUT;
		}
	}
	return 0;
}

static int dw_qspi_ctrl_enhanced(const struct spi_mem_op *op)
{
	uint32_t trans_t = 0;
	uint32_t addr_l = 0;
	uint32_t inst_l = 0;
	uint32_t wait_c = 0;

	if ((op->cmd.buswidth > 1U) && (op->addr.buswidth > 1U))
		trans_t = 0x10;
	else if ((op->cmd.buswidth == 1U) && (op->addr.buswidth > 1U))
		trans_t = 0x01;
	else
		trans_t = 0x0;

	addr_l = (op->addr.nbytes << 3) >> 2;
	inst_l = 0x2;
	wait_c = (op->dummy.nbytes << 3) / op->dummy.buswidth;

	mmio_write_32(dwqspi->reg_base + QSPI_SCTRLR0,
		QSPI_SCR0_TRANT(trans_t) +
		QSPI_SCR0_ADDRL(addr_l) +
		QSPI_SCR0_INSTL(inst_l) +
		QSPI_SCR0_WAITC(wait_c));

	if (op->data.buswidth == 2U)
		mmio_write_32(dwqspi->reg_base + QSPI_CTRLR0, QSPI_CTRLR0_2RX);
	else if ((op->data.buswidth == 4U))
		mmio_write_32(dwqspi->reg_base + QSPI_CTRLR0, QSPI_CTRLR0_4RX);

	mmio_write_32(dwqspi->reg_base + QSPI_CTRLR1,
		(op->data.nbytes >> 2) - 1);

	return 0;
}

static int dw_qspi_fillcp_enhanced(const struct spi_mem_op *op)
{
	/* send command */
	mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)op->cmd.opcode);

	/* send address byte */
	mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)op->addr.val);

	/* dummy bytes are not needed in enhanced mode */
	return 0;
}

static int dw_qspi_pio_enhanced(const struct spi_mem_op *op)
{
	uint32_t len, rxcount, readbyte = 0;
	uint64_t *buf;
	uint32_t *buf_32;
	register uintptr_t baddr;

	buf = (uint64_t *)op->data.buf;
	len = op->data.nbytes >> 3;
	baddr = dwqspi->reg_base;

	while (len > 0) {
		rxcount = mmio_read_32(baddr + QSPI_RXFLR) >> 1;
		while (rxcount > 0) {
			*buf++ = mmio_read_64(baddr + QSPI_DRX);
			rxcount--;
			len--;
			readbyte += 8;
		}
	}
	if (op->data.nbytes > readbyte) {
		while (mmio_read_32(baddr + QSPI_RXFLR) == 0)
			;
		buf_32 = (uint32_t *)buf;
		*buf_32 = mmio_read_32(baddr + QSPI_DRX);
	}

	return 0;
}

static int dw_qspi_ctrl_standard(const struct spi_mem_op *op)
{
	mmio_write_32(dwqspi->reg_base + QSPI_CTRLR0, QSPI_CTRLR0_RX);
	mmio_write_32(dwqspi->reg_base + QSPI_CTRLR1, (op->data.nbytes) - 1);

	return 0;
}

static int dw_qspi_fillcp_standard(const struct spi_mem_op *op)
{
	uint32_t len;
	uint8_t tmp;

	/* send command */
	mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)op->cmd.opcode);

	/* send address byte */
	for (len = op->addr.nbytes; len != 0U; len--) {
		tmp = (uint8_t)((op->addr.val >> (8 * (len - 1))) & 0xff);
		mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)tmp);
	}

	/* send dummy byte */
	for (len = op->dummy.nbytes; len != 0U; len--) {
		mmio_write_32(dwqspi->reg_base + QSPI_DRX, 0xff);
	}

	return 0;
}

static int dw_qspi_pio_standard(const struct spi_mem_op *op)
{
	uint32_t len, rxcount;
	uint8_t *buf;
	register uintptr_t baddr;

	buf = (uint8_t *)op->data.buf;
	len = op->data.nbytes;
	baddr = dwqspi->reg_base;

	while (len > 0) {
		rxcount = mmio_read_32(baddr + QSPI_RXFLR);
		while (rxcount > 0) {
			*buf++ = (uint8_t)mmio_read_32(baddr + QSPI_DRX);
			rxcount--;
			len--;
		}
	}
	return 0;
}

static int dw_qspi_rx(const struct spi_mem_op *op)
{
	int ret;
	bool enhanced_spi = 0;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addr:%lx len:%x\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	if (op->data.buswidth > 1U)
		enhanced_spi = 1;

	/* basic MMR */
	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_SER, 0x0);

	if (enhanced_spi)
		dw_qspi_ctrl_enhanced(op);
	else
		dw_qspi_ctrl_standard(op);

	mmio_write_32(dwqspi->reg_base + QSPI_TXFTLR, 0x1);
	mmio_write_32(dwqspi->reg_base + QSPI_RXFTLR, QSPI_RXFIFO_LEN - 1);
	mmio_write_32(dwqspi->reg_base + QSPI_IMR, QSPI_IMR_RXFIM);

	/* DMA related MMR */
	mmio_write_32(dwqspi->reg_base + QSPI_DMATDLR, 0x10);
	mmio_write_32(dwqspi->reg_base + QSPI_DMARDLR, 0x10 - 1);
	mmio_write_32(dwqspi->reg_base + QSPI_DMACR, 0x3);

	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x1);

	if (enhanced_spi)
		dw_qspi_fillcp_enhanced(op);
	else
		dw_qspi_fillcp_standard(op);

	mmio_setbits_32(dwqspi->reg_base + QSPI_SER, 0x1);

	ret = dw_qspi_wait_for_TFE();
	if (ret != 0) {
		return ret;
	}
#if PDMA_ENABLE

	struct pdma_conf conf = {0};
	struct pdma_prep prep = {0};

	if (dwqspi->qspi_config.rx_dma == 1 && op->data.nbytes > 16
		&& !((uintptr_t)op->data.buf & 0x3)) {
		/* dma mode read data fifo */
		if (enhanced_spi)
			conf.data_unit = PDMA_DATAUNIT_4B;
		else
			conf.data_unit = PDMA_DATAUNIT_1B;

		conf.intr_en = 1;
		conf.burstlen = 16;
		conf.sctrl = 1;
		conf.flowctrl = 0;
		dwqspi->rx_dma.conf(&dwqspi->rx_dma, &conf);

		prep.xfer_addr = (uint32_t)(uint64_t)op->data.buf;
		prep.xfer_len = op->data.nbytes;
		prep.sect_intr = 1;
		prep.sg_intr = 0;
		prep.data_swap = 0;
		dwqspi->rx_dma.prep(&dwqspi->rx_dma, &prep);
		dwqspi->rx_dma.xfer(&dwqspi->rx_dma);
	} else {
		if (enhanced_spi)
			dw_qspi_pio_enhanced(op);
		else
			dw_qspi_pio_standard(op);
	}
#else
	if (enhanced_spi)
		dw_qspi_pio_enhanced(op);
	else
		dw_qspi_pio_standard(op);
#endif
	ret = dw_qspi_wait_for_not_busy();
	if (ret != 0) {
		return ret;
	}

	mmio_write_32(dwqspi->reg_base + QSPI_SER, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_IMR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_DMACR, 0x0);

	return 0;
}

static int dw_qspi_tx(const struct spi_mem_op *op)
{
	uint32_t len;
	uint8_t *buf;
	uint8_t tmp;
	int ret;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addr:%lx len:%x\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	buf = (uint8_t *)op->data.buf;

	/* basic MMR */
	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_SER, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_CTRLR0, QSPI_CTRLR0_TX);
	mmio_write_32(dwqspi->reg_base + QSPI_TXFTLR, 0x1);
	mmio_write_32(dwqspi->reg_base + QSPI_RXFTLR, QSPI_RXFIFO_LEN - 1);
	mmio_write_32(dwqspi->reg_base + QSPI_IMR, QSPI_IMR_TXEIM);
	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x1);

	/* DMA related MMR */
	mmio_write_32(dwqspi->reg_base + QSPI_DMATDLR, 0x10);
	mmio_write_32(dwqspi->reg_base + QSPI_DMARDLR, 0x10 - 1);
	mmio_write_32(dwqspi->reg_base + QSPI_DMACR, 0x3);

	/* send command */
	mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)op->cmd.opcode);

	/* send address byte */
	for (len = op->addr.nbytes; len != 0U; len--) {
		tmp = (uint8_t)((op->addr.val >> (8 * (len - 1))) & 0xff);
		mmio_write_32(dwqspi->reg_base + QSPI_DRX, (uint32_t)tmp);
	}

	/* send dummy byte */
	for (len = op->dummy.nbytes; len != 0U; len--) {
		mmio_write_32(dwqspi->reg_base + QSPI_DRX, 0xff);
	}

	mmio_setbits_32(dwqspi->reg_base + QSPI_SER, 0x1);

	if (op->data.nbytes > 0U) {

#if PDMA_ENABLE
		struct pdma_conf conf = {0};
		struct pdma_prep prep = {0};

		if (dwqspi->qspi_config.tx_dma == 1 && op->data.nbytes > 16
			&& !((uintptr_t)op->data.buf & 0x3)) {
			/* dma mode send data fifo */
			conf.data_unit = PDMA_DATAUNIT_1B;
			conf.intr_en = 1;
			conf.burstlen = 16;
			conf.sctrl = 1;
			conf.flowctrl = 0;
			dwqspi->tx_dma.conf(&dwqspi->tx_dma, &conf);

			prep.xfer_addr = (uint32_t)(uint64_t)buf;
			prep.xfer_len = op->data.nbytes;
			prep.sect_intr = 1;
			prep.sg_intr = 0;
			prep.data_swap = 0;
			dwqspi->tx_dma.prep(&dwqspi->tx_dma, &prep);
			dwqspi->tx_dma.xfer(&dwqspi->tx_dma);
		} else {
			/* pio mode send data fifo */
			for (len = op->data.nbytes; len != 0U; len--) {
				mmio_write_32(dwqspi->reg_base + QSPI_DRX,
					(uint32_t)*buf++);
			}
		}
#else
		/* pio mode send data fifo */
		for (len = op->data.nbytes; len != 0U; len--) {
			mmio_write_32(dwqspi->reg_base + QSPI_DRX,
				(uint32_t)*buf++);
		}
#endif
	}
	mmio_write_32(dwqspi->reg_base + QSPI_IMR, 0x0);

	ret = dw_qspi_wait_for_TFE();
	if (ret != 0) {
		return ret;
	}

	ret = dw_qspi_wait_for_not_busy();
	if (ret != 0) {
		return ret;
	}

	mmio_write_32(dwqspi->reg_base + QSPI_SER, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_IMR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_DMACR, 0x0);

	return 0;
}

static int dw_qspi_exec_op(const struct spi_mem_op *op)
{
	int ret = 0;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addr:%lx len:%x\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	if ((op->data.dir == SPI_MEM_DATA_IN)
		&& (op->data.nbytes != 0U)) {
		ret = dw_qspi_rx(op);
	} else if ((op->data.dir == SPI_MEM_DATA_OUT)
		&& (op->data.nbytes != 0U)) {
		ret = dw_qspi_tx(op);
	} else if (op->cmd.opcode != 0x0) {
		ret = dw_qspi_tx(op);
	}
	return ret;
}

static int dw_qspi_claim_bus(unsigned int cs)
{
	return 0;
}

static void dw_qspi_release_bus(void)
{

}

static int dw_qspi_set_speed(unsigned int hz)
{

#if WAGNER_FPGA
	unsigned long qspi_clk = 50000000U;  //50M (fpga)
#else
	unsigned long qspi_clk = 400000000U; //400M (real chip)
#endif
	uint32_t sckdv = UINT16_MAX;

	if (qspi_clk == 0U) {
		return -EINVAL;
	}

	if (hz > 0U) {
		sckdv = div_round_up(qspi_clk, hz);
		if (sckdv > UINT16_MAX) {
			sckdv = UINT16_MAX;
		}
	}

	mmio_clrsetbits_32(dwqspi->reg_base + QSPI_BAUDR,
				QSPI_BAUDR_SCKDV_MASK, sckdv);

	VERBOSE("%s: sckdv=%d\n", __func__, sckdv);

	return 0;
}

int dw_qspi_set_sckdv(unsigned int sckdv)
{
	mmio_clrsetbits_32(dwqspi->reg_base + QSPI_BAUDR,
				QSPI_BAUDR_SCKDV_MASK, sckdv);

	VERBOSE("%s: sckdv=%d\n", __func__, sckdv);

	return 0;
}

int dw_qspi_set_rxdelay(unsigned int clk_nb)
{
	mmio_clrsetbits_32(dwqspi->reg_base + QSPI_RX_SAMPLE_DLY,
				QSPI_RXDLY_MASK, clk_nb);

	VERBOSE("%s: clk_nb=%d\n", __func__, clk_nb);

	return 0;
}


static int dw_qspi_set_mode(unsigned int mode)
{
	return 0;
}

static uintptr_t dw_qspi_get_regbase(int bus_id)
{
	if (bus_id == 0)
		return VPL_SSI_0_MMR_BASE;
	else if (bus_id == 1)
		return VPL_SSI_1_MMR_BASE;
	else {
		VERBOSE("%s unsupported spi bus for booting %d\n", __func__, bus_id);
		return 0;
	}
}

static int dw_qspi_pinctrl_config(int bus_id, bool quad_en)
{
	if ((bus_id == 0) & quad_en) {
		/*SSIC 0 four bit master mode*/

		/*clear GPIO_1 26, 27, 28, 29, 30, 31*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1EC, 0xFC000000);
		/*clear GPIO_2 0*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1F4, 0x00000001);
		/*PAD 6: clear SPI0-SLAVE bit 27, SPI0-SINGLE bit 26*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x214, 0x0C000000);
		/*PAD 6:Set SPI0-QUAD bit 25*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x210, 0x02000000);
	} else if (bus_id == 0) {
		/*SSIC 0 one bit master mode*/

		/*clear GPIO_1 29, 30, 31*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1EC, 0xE0000000);
		/*clear GPIO_2 0*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1F4, 0x00000001);
		/*PAD 6: clear SPI0-QUAD bit 25, SPI0-SLAVE bit 27*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x214, 0x0A000000);
		/*PAD 6:Set SPI0-SINGLE bit 26*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x210, 0x04000000);
	} else if (bus_id == 1){
		/*SSIC 1 one bit master mode*/

		/*clear GPIO_2 1,2,3,4*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1F4, 0x0000001E);
		/*clear AGPO_POS0 1,2,3,4*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x1FC, 0x0000001E);
		/*PAD 6:Set SPI1 bit 28*/
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + 0x210, 0x10000000);
	}
	return 0;
}

static int dw_qspi_dma_init(int bus_id)
{
#if PDMA_ENABLE
	struct pdma_init init;
	enum pdma_device_type dev_type = 0;

	init.paddr = dw_qspi_get_regbase(bus_id) + QSPI_DRX;
	init.pdma_descs_count = 10;

	if (bus_id == 0)
		dev_type = PDMA_DEVICE_SSIC0;
	else if (bus_id == 1)
		dev_type = PDMA_DEVICE_SSIC1;

	if (dwqspi->qspi_config.rx_dma == 1) {
		dwqspi->rx_dma.dev_type = dev_type;
		dwqspi->rx_dma.chan_type = PDMA_RXCH;
		pdma_request_channel(&dwqspi->rx_dma);
		dwqspi->rx_dma.init(&dwqspi->rx_dma, &init);
	}

	if (dwqspi->qspi_config.tx_dma == 1) {
		dwqspi->tx_dma.dev_type = dev_type;
		dwqspi->tx_dma.chan_type = PDMA_TXCH;
		pdma_request_channel(&dwqspi->tx_dma);
		dwqspi->tx_dma.init(&dwqspi->tx_dma, &init);
	}
#endif
	return 0;
}

int dw_qspi_dma_release(void)
{
#if PDMA_ENABLE
	if (dwqspi->qspi_config.rx_dma == 1)
		dwqspi->rx_dma.exit(&dwqspi->rx_dma);

	if (dwqspi->qspi_config.tx_dma == 1)
		dwqspi->tx_dma.exit(&dwqspi->tx_dma);

#endif
	return 0;
}

static const struct spi_bus_ops dw_qspi_bus_ops = {
	.claim_bus = dw_qspi_claim_bus,
	.release_bus = dw_qspi_release_bus,
	.set_speed = dw_qspi_set_speed,
	.set_mode = dw_qspi_set_mode,
	.exec_op = dw_qspi_exec_op,
};

int dw_qspi_init(int bus_id, unsigned int buswidth)
{
	void *fdt = NULL;
	bool quad_en = 0;

	dwqspi = &overlaid_buffer.spi_buf.qspi;
	memset(dwqspi, 0, sizeof(*dwqspi));

	dwqspi->qspi_config.cs = 0;
	dwqspi->qspi_config.max_hz = 12500000U; //12.5M SPI baudrate
	dwqspi->qspi_config.cpol = 0;
	dwqspi->qspi_config.cpha = 0;
	dwqspi->qspi_config.cs_high = 1;
	dwqspi->qspi_config.three_wire = 0;
	dwqspi->qspi_config.half_duplex = 0;
	dwqspi->qspi_config.tx_bus_width = buswidth;
	dwqspi->qspi_config.rx_bus_width = buswidth;
	dwqspi->qspi_config.tx_dma = 1;
	dwqspi->qspi_config.rx_dma = 1;

	fdt = (void *)&dwqspi->qspi_config;

	dwqspi->reg_base = dw_qspi_get_regbase(bus_id);

	if (dwqspi->qspi_config.tx_bus_width > 1 ||
	    dwqspi->qspi_config.rx_bus_width > 1)
		quad_en = 1;

	dw_qspi_pinctrl_config(bus_id, quad_en);

	dw_qspi_dma_init(bus_id);

	mmio_write_32(dwqspi->reg_base + QSPI_SSIENR, 0x0);
	mmio_write_32(dwqspi->reg_base + QSPI_SER, 0x0);

	return spi_mem_init_slave(fdt, 0, &dw_qspi_bus_ops);
};
