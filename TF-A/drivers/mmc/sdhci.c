#include <arch_helpers.h>
#include <drivers/vatics/mmc/sdhci.h>
#include <drivers/mmc.h>
#include <common/debug.h>
#include <drivers/delay_timer.h>
#include <lib/libc/errno.h>
#include <wagner_buf.h>
#include <linux/dma-mapping.h>


#define printf		VERBOSE

#ifdef SDHCI_DEBUG
#define pr_debug	VERBOSE
#define debug		VERBOSE
#else
#define debug(fmt, ...)
#define pr_debug(fmt, ...)
#endif

#define CONFIG_SYS_MMC_MAX_BLK_COUNT 65535

#define lower_32_bits(n) ((u32)(n))
#define upper_32_bits(n) ((u32)(((n) >> 16) >> 16))

static void sdhci_reset(struct sdhci_host *host, u8 mask)
{
	unsigned long timeout;

	/* Wait max 100 ms */
	timeout = 100;
	sdhci_writeb(host, mask, SDHCI_SOFTWARE_RESET);
	while (sdhci_readb(host, SDHCI_SOFTWARE_RESET) & mask) {
		if (timeout == 0) {
			printf("%s: Reset 0x%x never completed.\n",
			       __func__, (int)mask);
			return;
		}
		timeout--;
		udelay(1000);
	}
}
static void sdhci_cmd_done(struct sdhci_host *host, struct mmc_cmd *cmd)
{
	int i;
	if (cmd->resp_type & MMC_RSP_136) {
		/* CRC is stripped so we need to do some shifting. */
		for (i = 0; i < 4; i++) {
#if 0
			cmd->resp_data[i] = sdhci_readl(host,
					SDHCI_RESPONSE + (3-i)*4) << 8;
			if (i != 3)
				cmd->resp_data[i] |= sdhci_readb(host,
						SDHCI_RESPONSE + (3-i)*4-1);
#else
			cmd->resp_data[i] = sdhci_readl(host,
					SDHCI_RESPONSE + i*4) << 8;
			if (i != 0)
				cmd->resp_data[i] |= sdhci_readb(host,
						SDHCI_RESPONSE +  i*4-1);
#endif
		}
	} else {
		cmd->resp_data[0] = sdhci_readl(host, SDHCI_RESPONSE);
	}
}


static void sdhci_transfer_pio(struct sdhci_host *host, struct mmc_data *data)
{
	int i;
	char *offs;
	for (i = 0; i < data->blocksize; i += 4) {
		offs = data->dest + i;
		if (data->flags == MMC_DATA_READ)
			*(u32 *)offs = sdhci_readl(host, SDHCI_BUFFER);
		else
			sdhci_writel(host, *(u32 *)offs, SDHCI_BUFFER);
	}
}
#define MMC_SDHCI_ADMA
static void sdhci_prepare_dma(struct sdhci_host *host, struct mmc_data *data,
			      int *is_aligned, int trans_bytes)
{
	dma_addr_t dma_addr;
	unsigned char ctrl;
	void *buf;

	if (data->flags == MMC_DATA_READ)
		buf = data->dest;
	else
		buf = (void *)data->src;

	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
	ctrl &= ~SDHCI_CTRL_DMA_MASK;
	if (host->flags & USE_ADMA64)
		ctrl |= SDHCI_CTRL_ADMA64;
	else if (host->flags & USE_ADMA)
		ctrl |= SDHCI_CTRL_ADMA32;
	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);

#ifdef SDHCI_32BIT_DMA_ADDR
	if (host->flags & USE_SDMA &&
	    (host->force_align_buffer ||
	     (host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR &&
	      ((unsigned long)buf & 0x7) != 0x0))) {
		*is_aligned = 0;
		if (data->flags != MMC_DATA_READ)
			memcpy(host->align_buffer, buf, trans_bytes);
		buf = host->align_buffer;
	}
#endif
	//host->start_addr = (dma_addr_t)(uint64_t)buf;
	host->start_addr = (unsigned long)buf;

	host->start_addr = dma_map_single(buf, trans_bytes,
			mmc_get_dma_dir(data));

	if (host->flags & USE_SDMA) {
		dma_addr = host->start_addr;
		sdhci_writel(host, dma_addr, SDHCI_DMA_ADDRESS);
	}
#ifdef MMC_SDHCI_ADMA
	else if (host->flags & (USE_ADMA | USE_ADMA64)) {
		sdhci_prepare_adma_table(host->adma_desc_table, data,
					 host->start_addr);

		sdhci_writel(host, lower_32_bits(host->adma_addr),
			     SDHCI_ADMA_ADDRESS);
		if (host->flags & USE_ADMA64)
			sdhci_writel(host, upper_32_bits(host->adma_addr),
				     SDHCI_ADMA_ADDRESS_HI);
	}
#endif
}

static int sdhci_transfer_data(struct sdhci_host *host, struct mmc_data *data)
{
	dma_addr_t start_addr = host->start_addr;
	unsigned int stat, rdy, mask, timeout, block = 0;
	bool transfer_done = false;

	timeout = 1000000;
	rdy = SDHCI_INT_SPACE_AVAIL | SDHCI_INT_DATA_AVAIL;
	mask = SDHCI_DATA_AVAILABLE | SDHCI_SPACE_AVAILABLE;
	debug("data->blocksize:%d blocks:%d\n", data->blocksize, data->blocks);
	debug("data->dest:%p\n", data->dest);
	debug("+++ %s host->flags:0x%x\n", __func__, host->flags);
	debug("reg SDHCI_HOST_CONTROL 0x%x=0x%x\n",
			SDHCI_HOST_CONTROL,
			sdhci_readb(host, SDHCI_HOST_CONTROL));

	debug("reg SDHCI_HOST_CONTROL2 0x%x=0x%x\n",
			SDHCI_HOST_CONTROL2,
			sdhci_readw(host, SDHCI_HOST_CONTROL2));

	debug("reg SDHCI_CLOCK 0x%x=0x%x\n",
			SDHCI_CLOCK_CONTROL,
			sdhci_readw(host, SDHCI_CLOCK_CONTROL));

	do {
		stat = sdhci_readl(host, SDHCI_INT_STATUS);
		if (stat & SDHCI_INT_ERROR) {
			pr_debug("%s: Error detected in status(0x%x)!\n",
				 __func__, stat);
			return -EIO;
		}
		if (!transfer_done && (stat & rdy)) {
			if (!(sdhci_readl(host, SDHCI_PRESENT_STATE) & mask))
				continue;
			sdhci_writel(host, rdy, SDHCI_INT_STATUS);
			sdhci_transfer_pio(host, data);
			data->dest += data->blocksize;
			if (++block >= data->blocks) {
				/* Keep looping until the SDHCI_INT_DATA_END is
				 * cleared, even if we finished sending all the
				 * blocks.
				 */
				transfer_done = true;
				continue;
			}
		}
		if ((host->flags & USE_DMA) && !transfer_done &&
		    (stat & SDHCI_INT_DMA_END)) {
			sdhci_writel(host, SDHCI_INT_DMA_END, SDHCI_INT_STATUS);
			if (host->flags & USE_SDMA) {
				start_addr &=
				~(SDHCI_DEFAULT_BOUNDARY_SIZE - 1);
				start_addr += SDHCI_DEFAULT_BOUNDARY_SIZE;
				sdhci_writel(host, start_addr, SDHCI_DMA_ADDRESS);
			}
		}
		if (timeout-- > 0)
			udelay(10);
		else {
			printf("%s: Transfer data timeout\n", __func__);
			return -ETIMEDOUT;
		}
	} while (!(stat & SDHCI_INT_DATA_END));

	dma_unmap_single(host->start_addr, data->blocks * data->blocksize,
			mmc_get_dma_dir(data));

	return 0;
}

unsigned int get_clk_div(int clock)
{
	unsigned int div;
	/* clock = 400000000 / 2(div+1)*/
	div = 400000000 / clock;
	div = div / 2;
	div = div - 1;
	return div;
}

int sdhci_set_clock(struct mmc *mmc, unsigned int clock)
{
	struct sdhci_host *host = mmc->priv;
	unsigned int div, clk = 0, timeout;
	int ret;

	/* Wait max 20 ms */
	timeout = 200;
	while (sdhci_readl(host, SDHCI_PRESENT_STATE) &
			   (SDHCI_CMD_INHIBIT | SDHCI_DATA_INHIBIT)) {
		if (timeout == 0) {
			printf("%s: Timeout to wait cmd & data inhibit\n",
			       __func__);
			return -EBUSY;
		}

		timeout--;
		udelay(100);
	}

	sdhci_writew(host, 0, SDHCI_CLOCK_CONTROL);

	if (clock == 0)
		return 0;

	if (host->ops && host->ops->set_delay) {
		ret = host->ops->set_delay(host);
		if (ret) {
			printf("%s: Error while setting tap delay\n", __func__);
			return ret;
		}
	}
	div = get_clk_div(clock);
	if (host->ops && host->ops->set_clock)
		host->ops->set_clock(host, div);

	clk |= (div & SDHCI_DIV_MASK) << SDHCI_DIVIDER_SHIFT;
	clk |= ((div & SDHCI_DIV_HI_MASK) >> SDHCI_DIV_MASK_LEN)
		<< SDHCI_DIVIDER_HI_SHIFT;
	clk |= SDHCI_CLOCK_INT_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

	/* Wait max 20 ms */
	timeout = 20;
	while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
		& SDHCI_CLOCK_INT_STABLE)) {
		if (timeout == 0) {
			printf("%s: Internal clock never stabilised.\n",
			       __func__);
			return -EBUSY;
		}
		timeout--;
		udelay(1000);
	}

	clk |= SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
	return 0;
}
static int sdhci_set_ios(struct mmc *mmc)
{
	u32 ctrl;
	struct sdhci_host *host = mmc->priv;
	bool no_hispd_bit = false;

	if (host->ops && host->ops->set_control_reg)
		host->ops->set_control_reg(host);

	if (mmc->clock != host->clock)
		sdhci_set_clock(mmc, mmc->clock);

	if (mmc->clk_disable)
		sdhci_set_clock(mmc, 0);

	/* Set bus width */
	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
	if (mmc->bus_width == 8) {
		ctrl &= ~SDHCI_CTRL_4BITBUS;
#ifndef WAGNER_DEF_H
		if ((SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) ||
				(host->quirks & SDHCI_QUIRK_USE_WIDE8))
#endif
			ctrl |= SDHCI_CTRL_8BITBUS;
	} else {
#ifndef WAGNER_DEF_H
		if ((SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) ||
				(host->quirks & SDHCI_QUIRK_USE_WIDE8))
#endif
			ctrl &= ~SDHCI_CTRL_8BITBUS;
		if (mmc->bus_width == 4)
			ctrl |= SDHCI_CTRL_4BITBUS;
		else
			ctrl &= ~SDHCI_CTRL_4BITBUS;
	}

#ifdef QUIRK_NO_HISPD_BIT
#ifdef QUIRK_BROKEN_HISPD_MODE
	if ((host->quirks & SDHCI_QUIRK_NO_HISPD_BIT) ||
	    (host->quirks & SDHCI_QUIRK_BROKEN_HISPD_MODE)) {
		ctrl &= ~SDHCI_CTRL_HISPD;
		no_hispd_bit = true;
	}
#endif
#endif

	if (!no_hispd_bit) {
		if (mmc->selected_mode == MMC_HS ||
		    mmc->selected_mode == SD_HS ||
		    mmc->selected_mode == MMC_DDR_52 ||
		    mmc->selected_mode == MMC_HS_200 ||
		    mmc->selected_mode == MMC_HS_400 ||
		    mmc->selected_mode == UHS_SDR25 ||
		    mmc->selected_mode == UHS_SDR50 ||
		    mmc->selected_mode == UHS_SDR104 ||
		    mmc->selected_mode == UHS_DDR50)
			ctrl |= SDHCI_CTRL_HISPD;
		else
			ctrl &= ~SDHCI_CTRL_HISPD;
	}
	debug("SDHCI_HOST_CONTROL:0x%x\n", ctrl);
	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);

	/* If available, call the driver specific "post" set_ios() function */
	if (host->ops && host->ops->set_ios_post)
		return host->ops->set_ios_post(host);

	return 0;
}
/*
 * No command will be sent by driver if card is busy, so driver must wait
 * for card ready state.
 * Every time when card is busy after timeout then (last) timeout value will be
 * increased twice but only if it doesn't exceed global defined maximum.
 * Each function call will use last timeout value.
 */
#define SDHCI_CMD_MAX_TIMEOUT			3200
#define SDHCI_CMD_DEFAULT_TIMEOUT		100
#define SDHCI_READ_STATUS_TIMEOUT		1000

static int sdhci_send_command(struct mmc *mmc, struct mmc_cmd *cmd,
			      struct mmc_data *data)
{
	struct sdhci_host *host = mmc->priv;
	unsigned int stat = 0;
	int ret = 0;
	int trans_bytes = 0, is_aligned = 1;
	u32 mask, flags, mode;
	unsigned int time = 0;
	//NOTE: is this changed?
	int mmc_dev = 0;
	uint64_t timeout;

	host->start_addr = 0;
	/* Timeout unit - ms */
	static unsigned int cmd_timeout = SDHCI_CMD_DEFAULT_TIMEOUT;

	mask = SDHCI_CMD_INHIBIT | SDHCI_DATA_INHIBIT;


	/* We shouldn't wait for data inihibit for stop commands, even
	   though they might use busy signaling */
	if (cmd->cmd_idx == MMC_CMD_STOP_TRANSMISSION ||
	    ((cmd->cmd_idx == MMC_CMD_SEND_TUNING_BLOCK ||
	      cmd->cmd_idx == MMC_CMD_SEND_TUNING_BLOCK_HS200) && !data))
		mask &= ~SDHCI_DATA_INHIBIT;

	while (sdhci_readl(host, SDHCI_PRESENT_STATE) & mask) {
		if (time >= cmd_timeout) {
			printf("%s: MMC: %d busy ", __func__, mmc_dev);
			if (2 * cmd_timeout <= SDHCI_CMD_MAX_TIMEOUT) {
				cmd_timeout += cmd_timeout;
				printf("timeout increasing to: %u ms.\n",
				       cmd_timeout);
			} else {
				puts("timeout.\n");
				return -ENOTCONN;
			}
		}
		time++;
		udelay(1000);
	}

	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);

	mask = SDHCI_INT_RESPONSE;
	if ((cmd->cmd_idx == MMC_CMD_SEND_TUNING_BLOCK ||
	     cmd->cmd_idx == MMC_CMD_SEND_TUNING_BLOCK_HS200) && !data)
		mask = SDHCI_INT_DATA_AVAIL;

	if (!(cmd->resp_type & MMC_RSP_PRESENT))
		flags = SDHCI_CMD_RESP_NONE;
	else if (cmd->resp_type & MMC_RSP_136)
		flags = SDHCI_CMD_RESP_LONG;
	else if (cmd->resp_type & MMC_RSP_BUSY) {
		flags = SDHCI_CMD_RESP_SHORT_BUSY;
		mask |= SDHCI_INT_DATA_END;
	} else
		flags = SDHCI_CMD_RESP_SHORT;

	if (cmd->resp_type & MMC_RSP_CRC)
		flags |= SDHCI_CMD_CRC;
	if (cmd->resp_type & MMC_RSP_OPCODE)
		flags |= SDHCI_CMD_INDEX;
	if (data || cmd->cmd_idx ==  MMC_CMD_SEND_TUNING_BLOCK ||
	    cmd->cmd_idx == MMC_CMD_SEND_TUNING_BLOCK_HS200)
		flags |= SDHCI_CMD_DATA;

	/* Set Transfer mode regarding to data flag */
	if (data) {
		sdhci_writeb(host, 0xe, SDHCI_TIMEOUT_CONTROL);
		mode = SDHCI_TRNS_BLK_CNT_EN;
		trans_bytes = data->blocks * data->blocksize;
		if (data->blocks > 1)
			mode |= SDHCI_TRNS_MULTI;

		if (data->flags == MMC_DATA_READ)
			mode |= SDHCI_TRNS_READ;

		if (host->flags & USE_DMA) {
			mode |= SDHCI_TRNS_DMA;
			sdhci_prepare_dma(host, data, &is_aligned, trans_bytes);
		}

		sdhci_writew(host, SDHCI_MAKE_BLKSZ(SDHCI_DEFAULT_BOUNDARY_ARG,
				data->blocksize),
				SDHCI_BLOCK_SIZE);
		sdhci_writew(host, data->blocks, SDHCI_BLOCK_COUNT);
		sdhci_writew(host, mode, SDHCI_TRANSFER_MODE);
	} else if (cmd->resp_type & MMC_RSP_BUSY) {
		sdhci_writeb(host, 0xe, SDHCI_TIMEOUT_CONTROL);
	}

	sdhci_writel(host, cmd->cmd_arg, SDHCI_ARGUMENT);
	sdhci_writew(host, SDHCI_MAKE_CMD(cmd->cmd_idx, flags), SDHCI_COMMAND);

	timeout = timeout_init_us(SDHCI_READ_STATUS_TIMEOUT*5);
	do {
		stat = sdhci_readl(host, SDHCI_INT_STATUS);
		if (stat & SDHCI_INT_ERROR)
			break;

		if (timeout_elapsed(timeout)) {
#ifdef QUIRK_BROKEN_R1B
			if (host->quirks & SDHCI_QUIRK_BROKEN_R1B) {
				return 0;
			} else {
				printf("%s: Timeout for status update!\n",
				       __func__);
				return -ETIMEDOUT;
			}
#else
			return -ETIMEDOUT;
#endif
		}
	} while ((stat & mask) != mask);

	if ((stat & (SDHCI_INT_ERROR | mask)) == mask) {
		sdhci_cmd_done(host, cmd);
		sdhci_writel(host, mask, SDHCI_INT_STATUS);
	} else
		ret = -1;

	if (!ret && data)
		ret = sdhci_transfer_data(host, data);

	if (host->quirks & SDHCI_QUIRK_WAIT_SEND_CMD)
		udelay(1000);

	stat = sdhci_readl(host, SDHCI_INT_STATUS);
	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);
	if (!ret) {
#ifdef QUIRK_32BIT_DMA_ADDR
		if ((host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR) &&
				!is_aligned && (data->flags == MMC_DATA_READ))
			memcpy(data->dest, host->align_buffer, trans_bytes);
#endif
		return 0;
	}

	sdhci_reset(host, SDHCI_RESET_CMD);
	sdhci_reset(host, SDHCI_RESET_DATA);
	if (stat & SDHCI_INT_TIMEOUT)
		return -ETIMEDOUT;
	else
		return -ENOTCONN;
}

static void sdhci_set_power(struct sdhci_host *host, unsigned short power)
{
	u8 pwr = 0;

#ifndef WAGNER_DEF_H
	if (power != (unsigned short)-1) {
		switch (1 << power) {
		case MMC_VDD_165_195:
			pwr = SDHCI_POWER_180;
			break;
		case MMC_VDD_29_30:
		case MMC_VDD_30_31:
			pwr = SDHCI_POWER_300;
			break;
		case MMC_VDD_32_33:
		case MMC_VDD_33_34:
			pwr = SDHCI_POWER_330;
			break;
		}
	}

	if (pwr == 0) {
		sdhci_writeb(host, 0, SDHCI_POWER_CONTROL);
		return;
	}
#else
	pwr = SDHCI_POWER_330;
#endif
	pwr |= SDHCI_POWER_ON;

	sdhci_writeb(host, pwr, SDHCI_POWER_CONTROL);
}

static int sdhci_init(struct mmc *mmc)
{
	struct sdhci_host *host = mmc->priv;

	VERBOSE("%s +++\n", __func__);

	sdhci_reset(host, SDHCI_RESET_ALL);

	//sdhci_set_power(host, fls(mmc->cfg->voltages) - 1);
	// MMC_VDD_32_33 = 0x100000, bit20;
	sdhci_set_power(host, 20);

	if (host->ops && host->ops->get_cd)
		host->ops->get_cd(host);

	/* Enable only interrupts served by the SD controller */
	sdhci_writel(host, SDHCI_INT_DATA_MASK | SDHCI_INT_CMD_MASK,
		     SDHCI_INT_ENABLE);
	/* Mask all sdhci interrupt sources */
	sdhci_writel(host, 0x0, SDHCI_SIGNAL_ENABLE);

	return 0;
}

static const struct uboot_sdhci_ops sdhci_ops = {
	.send_cmd	= sdhci_send_command,
	.set_ios	= sdhci_set_ios,
	.init		= sdhci_init,
};

int sdhci_setup_cfg(struct mmc_config *cfg, struct sdhci_host *host,
		u32 f_max, u32 f_min)
{
	u32 caps, caps_1 = 0;
#ifdef DM_MMC
	u64 dt_caps, dt_caps_mask;

	dt_caps_mask = dev_read_u64_default(host->mmc->dev,
					    "sdhci-caps-mask", 0);
	dt_caps = dev_read_u64_default(host->mmc->dev,
				       "sdhci-caps", 0);
	caps = ~lower_32_bits(dt_caps_mask) &
	       sdhci_readl(host, SDHCI_CAPABILITIES);
	caps |= lower_32_bits(dt_caps);
#else
	caps = sdhci_readl(host, SDHCI_CAPABILITIES);
#endif
	debug("%s, caps: 0x%x\n", __func__, caps);

#ifdef CONFIG_MMC_SDHCI_SDMA
	if ((caps & SDHCI_CAN_DO_SDMA)) {
		host->flags |= USE_SDMA;
	} else {
		debug("%s: Your controller doesn't support SDMA!!\n",
		      __func__);
	}
#endif
#ifdef MMC_SDHCI_ADMA
	if (!(caps & SDHCI_CAN_DO_ADMA2)) {
		printf("%s: Your controller doesn't support SDMA!!\n",
		       __func__);
		return -EINVAL;
	}
	host->adma_desc_table = sdhci_adma_init();
	host->adma_addr = (unsigned long)host->adma_desc_table;

#ifdef QUIRK_DMA_ADDR_T_64BIT
	host->flags |= USE_ADMA64;
#else
	host->flags |= USE_ADMA;
#endif
#endif
#ifdef QUIRK_REG32_RW
	if (host->quirks & SDHCI_QUIRK_REG32_RW)
		host->version =
			sdhci_readl(host, SDHCI_HOST_VERSION - 2) >> 16;
	else
#endif
		host->version = sdhci_readw(host, SDHCI_HOST_VERSION);

	cfg->name = host->name;
#ifndef CONFIG_DM_MMC
	cfg->ops = &sdhci_ops;
#endif

	/* Check whether the clock multiplier is supported or not */
	if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) {
#ifdef DM_MMC
		caps_1 = ~upper_32_bits(dt_caps_mask) &
			 sdhci_readl(host, SDHCI_CAPABILITIES_1);
		caps_1 |= upper_32_bits(dt_caps);
#else
		caps_1 = sdhci_readl(host, SDHCI_CAPABILITIES_1);
#endif
		debug("%s, caps_1: 0x%x\n", __func__, caps_1);
		host->clk_mul = (caps_1 & SDHCI_CLOCK_MUL_MASK) >>
				SDHCI_CLOCK_MUL_SHIFT;
	}

	if (host->max_clk == 0) {
#ifdef	WAGNER_DEF_H
		host->max_clk = (caps & SDHCI_CLOCK_V3_BASE_MASK) >>
				SDHCI_CLOCK_BASE_SHIFT;
#else
		if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300)
			host->max_clk = (caps & SDHCI_CLOCK_V3_BASE_MASK) >>
				SDHCI_CLOCK_BASE_SHIFT;
		else
			host->max_clk = (caps & SDHCI_CLOCK_BASE_MASK) >>
				SDHCI_CLOCK_BASE_SHIFT;
#endif
		host->max_clk *= 1000000;
		if (host->clk_mul)
			host->max_clk *= host->clk_mul;
	}
	if (host->max_clk == 0) {
		printf("%s: Hardware doesn't specify base clock frequency\n",
		       __func__);
		return -EINVAL;
	}
	if (f_max && (f_max < host->max_clk))
		cfg->f_max = f_max;
	else
		cfg->f_max = host->max_clk;
	if (f_min)
		cfg->f_min = f_min;
	else {
#ifdef	WAGNER_DEF_H
		cfg->f_min = cfg->f_max / SDHCI_MAX_DIV_SPEC_300;
#else
		if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300)
			cfg->f_min = cfg->f_max / SDHCI_MAX_DIV_SPEC_300;
		else
			cfg->f_min = cfg->f_max / SDHCI_MAX_DIV_SPEC_200;
#endif
	}
	cfg->voltages = 0;
	if (caps & SDHCI_CAN_VDD_330)
		cfg->voltages |= MMC_VDD_32_33 | MMC_VDD_33_34;
	if (caps & SDHCI_CAN_VDD_300)
		cfg->voltages |= MMC_VDD_29_30 | MMC_VDD_30_31;
	if (caps & SDHCI_CAN_VDD_180)
		cfg->voltages |= MMC_VDD_165_195;

#ifdef QUIRK_BROKEN_VOLTAGE
	if (host->quirks & SDHCI_QUIRK_BROKEN_VOLTAGE)
		cfg->voltages |= host->voltages;
#endif

	if (caps & SDHCI_CAN_DO_HISPD)
		cfg->host_caps |= MMC_MODE_HS | MMC_MODE_HS_52MHz;

	cfg->host_caps |= MMC_MODE_4BIT;

#ifndef	WAGNER_DEF_H
	/* Since Host Controller Version3.0 */
	if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) {
		if (!(caps & SDHCI_CAN_DO_8BIT))
			cfg->host_caps &= ~MMC_MODE_8BIT;
	}
#endif

#ifdef QUIRK_BROKEN_HISPD_MODE
	if (host->quirks & SDHCI_QUIRK_BROKEN_HISPD_MODE) {
		cfg->host_caps &= ~MMC_MODE_HS;
		cfg->host_caps &= ~MMC_MODE_HS_52MHz;
	}
#endif

#ifndef WAGNER_DEF_H	// Don't support 1.8V in boot code
	if (!(cfg->voltages & MMC_VDD_165_195) ||
	    (host->quirks & SDHCI_QUIRK_NO_1_8_V))
		caps_1 &= ~(SDHCI_SUPPORT_SDR104 | SDHCI_SUPPORT_SDR50 |
			    SDHCI_SUPPORT_DDR50);

	if (caps_1 & (SDHCI_SUPPORT_SDR104 | SDHCI_SUPPORT_SDR50 |
		      SDHCI_SUPPORT_DDR50))
		cfg->host_caps |= MMC_CAP(UHS_SDR12) | MMC_CAP(UHS_SDR25);

	if (caps_1 & SDHCI_SUPPORT_SDR104) {
		cfg->host_caps |= MMC_CAP(UHS_SDR104) | MMC_CAP(UHS_SDR50);
		/*
		 * SD3.0: SDR104 is supported so (for eMMC) the caps2
		 * field can be promoted to support HS200.
		 */
		cfg->host_caps |= MMC_CAP(MMC_HS_200);
	} else if (caps_1 & SDHCI_SUPPORT_SDR50) {
		cfg->host_caps |= MMC_CAP(UHS_SDR50);
	}

	if (caps_1 & SDHCI_SUPPORT_DDR50)
		cfg->host_caps |= MMC_CAP(UHS_DDR50);
#endif

	if (host->host_caps)
		cfg->host_caps |= host->host_caps;

	cfg->b_max = CONFIG_SYS_MMC_MAX_BLK_COUNT;

	return 0;
}

int add_sdhci(struct sdhci_host *host, u32 f_max, u32 f_min)
{
	int ret;

	ret = sdhci_setup_cfg(&host->cfg, host, f_max, f_min);
	if (ret)
		return ret;
#if 0
	host->mmc = mmc_create(&host->cfg, host);
	if (host->mmc == NULL) {
		printf("%s: mmc create fail!\n", __func__);
		return -ENOMEM;
	}
#endif
	sdhci_init(host->mmc);
	return 0;
}

void mshc_init_flow_mmc(struct sdhci_host *host, struct mmc *mmc,
				unsigned int clock, unsigned int reg_host_ctrl)
{
	u32 reg;
	// card is emmc, BIT_0
	reg = sdhci_readw(host, SDHCI_EMMC_CTRL_R);
	reg |= 0x1;
	sdhci_writew(host, reg, SDHCI_EMMC_CTRL_R);
	debug("SDHCI_EMMC_CTRL_R = 0x%x\n",
			sdhci_readw(host, SDHCI_EMMC_CTRL_R));

	sdhci_set_clock(mmc, clock);

	// HOST_VER4_ENABLE, BIT_12
	// 1.8V Signalling, BIT_3
	reg = sdhci_readw(host, SDHCI_HOST_CONTROL2);
	if (host->mmc->signal_voltage == MMC_SIGNAL_VOLTAGE_180)
		reg |= 0x1008; //version 4, 1.8v
	else
		reg |= 0x1000; //version 4, 3.3v
	sdhci_writew(host, reg, SDHCI_HOST_CONTROL2);

	sdhci_writeb(host, reg_host_ctrl, SDHCI_HOST_CONTROL);

}

int emmc_boot(struct sdhci_host *host, int is_dma, int bus_width)
{
	u32 mode, state;
	int ret = 0;
	__maybe_unused u32 reg;

	printf("%s +++", __func__);
	int flags = 0; //default PIO
	struct mmc *mmc = host->mmc;
	struct mmc_cmd cmd;
	struct mmc_data data;
	int trans_bytes = 0, is_aligned = 1;

	if (is_dma == 1) {
		flags |= USE_DMA;
	}

	mmc->priv = host;
	mmc->bus_width = bus_width;

	if (bus_width == 4)  // 4bit mode, HIGH_SPEED_EN
		mshc_init_flow_mmc(host, mmc, 25000000, 0x16);
	else if (bus_width == 8) // EXT_DATA_XFER = 1, means 8bit width
		mshc_init_flow_mmc(host, mmc, 25000000, 0x34);
	else //1bit mode, HIGH_SPEED_EN
		mshc_init_flow_mmc(host, mmc, 25000000, 0x14);

	sdhci_writeb(host, 0xe, SDHCI_TIMEOUT_CONTROL);
	data.blocks = SDHCI_TRANSFER_SIZE / 512;
	data.dest = (void *)host->align_buffer;
	data.blocksize = 512;
	data.flags = MMC_DATA_READ;

	trans_bytes = data.blocks * data.blocksize;

	mode = SDHCI_TRNS_BLK_CNT_EN;
	if (data.blocks > 1)
		mode |= SDHCI_TRNS_MULTI;

	// only read here
	mode |= SDHCI_TRNS_READ;

	if (flags & USE_DMA) {
		printf("+++ use dma\n");
		mode |= SDHCI_TRNS_DMA;
		sdhci_prepare_dma(host, &data, &is_aligned, trans_bytes);

	} else {
		printf("+++ use PIO\n");
	}

	sdhci_writew(host, data.blocksize, SDHCI_BLOCK_SIZE);
	sdhci_writew(host, data.blocks, SDHCI_BLOCK_COUNT);
	debug("dest:%p blocks:%d mode:0x%x\n",
				data.dest, data.blocks, mode);
	debug("+++ ERROR_INT_STAT_EN_R:0x%x\n",
				sdhci_readl(host, SDHCI_INT_ENABLE));
	sdhci_writew(host, mode, SDHCI_TRANSFER_MODE);

	debug("reg SDHCI_HOST_CONTROL 0x%x=0x%x\n",
		SDHCI_HOST_CONTROL, sdhci_readb(host, SDHCI_HOST_CONTROL));

	debug("reg SDHCI_HOST_CONTROL2 0x%x=0x%x\n",
		SDHCI_HOST_CONTROL2, sdhci_readw(host, SDHCI_HOST_CONTROL2));

	debug("reg SDHCI_CLOCK 0x%x=0x%x\n",
		SDHCI_CLOCK_CONTROL, sdhci_readw(host, SDHCI_CLOCK_CONTROL));
#if 0
#ifndef USE_BOOTACK
	printf("emmc boot, NO bootack\n");
	// 0x81 = bit0 and bit 7 = Man_BOOT_EN and VALIDATE_BOOT
	reg = 0x81;
	sdhci_writew(host, 0x81, SDHCI_BOOT_CTRL_R);
#else
	printf("emmc boot, bootack\n");
	// 0x81 = bit0 and bit 7 = Man_BOOT_EN and VALIDATE_BOOT
	reg = 0x181;
	reg |= 0xE << 12; // max bootack timeout
	sdhci_writew(host, reg, SDHCI_BOOT_CTRL_R);
	sdhci_transfer_data(host, &data);
#endif
#else
	// alternative boot mode
	cmd.cmd_idx = MMC_CMD_GO_IDLE_STATE;
	cmd.cmd_arg = 0xF0F0F0F0;
	cmd.resp_type = 0;
	ret = sdhci_send_command(mmc, &cmd, NULL);
	if (ret < 0)
		return ret;

	cmd.cmd_arg = 0xFFFFFFFA;
	ret = sdhci_send_command(mmc, &cmd, &data);
	if (ret < 0)
		return ret;

#endif

	debug("transfer complete\n");
	// issue stop at block gap
	sdhci_writeb(host, 0x1, SDHCI_BLOCK_GAP_CONTROL);

	if (flags & USE_DMA) {
		printf("wait for pending DMA\n");
	} else {
		/* wait for
		 * INT_STATUS (XFER_COMPLETE bit_1 / CMD_COMPLETE bit_0)
		 */
		printf("wait for pending PIO\n");
		do {
			state = sdhci_readl(host, SDHCI_INT_STATUS);
			printf("state:0x%x\n", state);
			mdelay(10);
		} while ((state&0x3) != 0x3);
		// clear INT_STATUS (XFER_COMPLETE bit_1 / CMD_COMPLETE bit_0)
		sdhci_writel(host, 0x3, SDHCI_INT_STATUS);
	}

	// clear transfer complete interrupt and clear block gap request
	sdhci_writeb(host, 0x0, SDHCI_BLOCK_GAP_CONTROL);

	// issue software reset for command and data line
	cmd.cmd_arg = 0x0;
	ret = sdhci_send_command(mmc, &cmd, NULL);
	if (ret < 0)
		return ret;

	sdhci_reset(host, SDHCI_RESET_DATA);
	sdhci_reset(host, SDHCI_RESET_CMD);
	return 0;
}
