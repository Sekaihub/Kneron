#include <common/debug.h>
#include <assert.h>
#include <drivers/vatics/mmc/sdhci.h>
#include <fs/fat.h>
#include <fs/gpt.h>
#include <sysctrl.h>
#include <lib/libc/errno.h>
#include <drivers/delay_timer.h>

#include "maps.h"
#include "wagner_def.h"

/* These #define remove related QUIRKS */
//#define QUIRK_32BIT_DMA_ADDR //or host->force_align_buffer
//#define QUIRK_REG32_RW
//#define QUIRK_BROKEN_R1B
//#define QUIRK_NO_HISPD_BIT
//#define QUIRK_BROKEN_VOLTAGE
//#define QUIRK_BROKEN_HISPD_MODE
//#define QUIRK_USE_WIDE8
//#define QUIRK_NO_1_8_V

struct sdhci_host g_host;
struct mmc g_mmc;
struct mmc_data g_data;
struct mmc_data *data;
extern block_dev_desc_t   block_dev;

typedef struct emmc_block_info {
	char name[16];
	unsigned int image_id;
	__le64 start;
	__le64 end;

} emmc_block_info_t;

static emmc_block_info_t emmc_descs[] = {
	{
		.image_id = BL31_IMAGE_ID,
		.name = "bl31",
	},
	{
		.image_id = BL32_IMAGE_ID,
		.name = "bl32",
	},
	{
		.image_id = BL33_IMAGE_ID,
		.name = "bl33",
	}
};

void card_is_emmc(struct sdhci_host *host)
{
	u32 reg;

	VERBOSE("+++ using emmc mode\n");
	reg = sdhci_readw(host, SDHCI_EMMC_CTRL_R);
	reg |= 0x1; // card is emmc
	sdhci_writew(host, reg, SDHCI_EMMC_CTRL_R);

}

int card_insert(struct sdhci_host *host)
{
	u32 reg = 0;

	for (int i = 0 ; i < 20 ; i++) {
		reg = sdhci_readl(host, SDHCI_PRESENT_STATE);
		reg &= SDHCI_CARD_STATE_STABLE;
		if (reg)
			break;
		udelay(10);
	}

	reg = sdhci_readl(host, SDHCI_PRESENT_STATE);
	reg &= SDHCI_CARD_PRESENT;
	VERBOSE("card_present:%d\n", !!reg);
	return !!reg;
}

void wagner_sdhci_set_control_reg(struct sdhci_host *host)
{
	u32 reg;

	VERBOSE("%s +++\n", __func__);
	reg = sdhci_readw(host, SDHCI_HOST_CONTROL2);
	if (host->mmc->signal_voltage == MMC_SIGNAL_VOLTAGE_180)
		reg |= 0x1008; //version 4, 1.8v
	else
		reg |= 0x1000; //version 4, 3.3v
	sdhci_writew(host, reg, SDHCI_HOST_CONTROL2);
}

void wagner_sdhci_clk_enable(struct sdhci_host *host, int enable)
{
	u32 reg = 0;

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE)
		reg = MSHC_DEV_0_CLK_MASK;
	else
		reg = MSHC_DEV_1_CLK_MASK;

	if (!enable) {
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_3,
				reg);
	} else {
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_SET_REG_3,
				reg);
	}
}

void wagner_set_clock(struct sdhci_host *host, u32 div)
{
	// real clock control here
	VERBOSE("%s +++, sysc_mshc:0x%x\n", __func__,
			mmio_read_32(VPL_SYSC_SECURE_MMR_BASE
						+ SYSC_MSHC_CTRL));
	wagner_sdhci_clk_enable(host, 0);
	u32 reg = mmio_read_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL);

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		reg &= ~(MSHC_CTRL_DIV0_MASK);
		reg |= div << MSHC_CTRL_DIV0_OFFSET;
	} else {
		/* MSHC1 */
		reg &= ~(MSHC_CTRL_DIV1_MASK);
		reg |= div << MSHC_CTRL_DIV1_OFFSET;
	}

	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL, reg);

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE)
		reg |= MSHC_CTRL_DIV0_REQ;
	else
		reg |= MSHC_CTRL_DIV1_REQ;

	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL, reg);
#if !WAGNER_FPGA
	/* fpga does not clear request bit */
	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		do {
			reg = mmio_read_32(VPL_SYSC_SECURE_MMR_BASE
							+ SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV0_REQ) != 0);
	} else {
		do {
			reg = mmio_read_32(VPL_SYSC_SECURE_MMR_BASE
							+ SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV1_REQ) != 0);
	}
#endif
	wagner_sdhci_clk_enable(host, 1);

	VERBOSE("sysc_mshc_clk:0x%x div:0x%x\n", reg, div);
	VERBOSE("read from sysc_mshc_clk:0x%x\n",
		mmio_read_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL));

}

static struct sdhci_ops wagner_sdhci_ops = {
	.set_control_reg = wagner_sdhci_set_control_reg,
	.set_clock = wagner_set_clock,
};

static void vtx_init(void)
{
	VERBOSE("%s +++\n", __func__);
	data = NULL;
}

static void enable_data(void)
{
	VERBOSE("%s +++\n", __func__);
	data = &g_data;
}

int vtx_send_cmd(struct mmc_cmd *cmd)
{
	VERBOSE("%s cmd=%d\n", __func__, cmd->cmd_idx);
	// read blocks, SEND_EXT_CSD, SWITCH_FUNC
	if (cmd->cmd_idx == 17 || cmd->cmd_idx == 18 || cmd->cmd_idx == 51)
		enable_data();

	return g_host.cfg.ops->send_cmd(&g_mmc, cmd, data);
}

static int vtx_set_ios(unsigned int clk, unsigned int width)
{
	VERBOSE("%s, clk:%d width (1:4bit, 2:8bit):%d\n", __func__, clk, width);
	if (width == MMC_BUS_WIDTH_1)
		g_mmc.bus_width = 1;
	else if (width == MMC_BUS_WIDTH_4)
		g_mmc.bus_width = 4;
	else if (width == MMC_BUS_WIDTH_8)
		g_mmc.bus_width = 8;
	else {
		VERBOSE("%s, not supported width: %d\n", __func__, width);
	}
	g_mmc.clock = clk;
	g_host.cfg.ops->set_ios(&g_mmc);
	return 0;
}

static int vtx_prepare(int lba, uintptr_t buf, size_t size)
{
	VERBOSE("%s +++, size:%ld\n", __func__, size);
	g_data.flags = MMC_DATA_READ;
	if (size < 512) {
		g_data.blocksize = size;
		g_data.blocks = 1;
	} else {
		// block read, should be 512 aligned
		g_data.blocksize = 512;
		g_data.blocks = size / 512;
	}
	g_data.dest = (void *)buf;
	return 0;
}


static int vtx_read(int lba, uintptr_t buf, size_t size)
{
	VERBOSE("%s +++\n", __func__);
	data = NULL;
	return 0;
}

static int vtx_write(int lba, uintptr_t buf, size_t size)
{
	VERBOSE("%s +++\n", __func__);
	data = NULL;
	return 0;
}

static const struct mmc_ops vtx_mmc_ops = {
	.init           = vtx_init,
	.send_cmd       = vtx_send_cmd,
	.set_ios        = vtx_set_ios,
	.prepare        = vtx_prepare,
	.read           = vtx_read,
	.write          = vtx_write,
};

void enable_wagner_sdhci_clk(void)
{

}

unsigned long sd_read_wrapper(unsigned long blknr,
				unsigned long blkcnt, void *buffer)
{
	int ret;

	VERBOSE("%s, blknr:%ld blkcnt:%ld buff:0x%p\n", __func__,
						blknr, blkcnt, buffer);
	if (blkcnt == 0)
		return 0;
	ret = mmc_read_blocks(blknr, (uintptr_t)buffer, 512 * blkcnt);
	return ret;
}



long sd_fat_read(const char *filename, struct sdhci_host *host,
							uint32_t maxsize)
{
	long size;

	block_dev.block_read = sd_read_wrapper;
#if 0
	size = file_fat_read(LOADER_NAME, (void *)LOADER_START_ADDR, maxsize);
#endif
	size = file_fat_read(filename, (void *)host->align_buffer, maxsize);
	VERBOSE("fat_read complete, file:%s size:%ld ,dest_addr:%p\n",
					filename, size, host->align_buffer);
	return size;
}

static int phy_init(struct sdhci_host *host, int mode)
{
	u32 reg = 0, val = 0;
	u16 v16 = 0;
	u8 v8 = 0;
	int i = 0;

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		reg |= MSHC_DEV_0_CLK_TX;
	} else {
		/* MSHC1 */
		reg |= MSHC_DEV_1_CLK_TX;
	}
	// disable Tx clock
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_3, reg);
	val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
	val |= 0x9 << PAD_SP_OFFSET;
	val |= 0x8 << PAD_SN_OFFSET;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

	if (mode == MODE_EMMC_BOOT) {
		// from table 8-6, recommended PAD setting
		// for EMMC PHY 1.8V mode
		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CMDPAD_CNFG);

		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_DATAPAD_CNFG);

		v16 = 0;
		v16 |= 0x0 << RXSEL_OFFSET;
		v16 |= 0x0 << WAKEPULL_EN_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CLKPAD_CNFG);


		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_RSTNPAD_CNFG);
	} else {

		// set phy value from soc team simulation
		// from table 8-8, recommended PAD setting
		// for SD PHY 1.8V mode
		// other values are from golden waveform
		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CMDPAD_CNFG);

		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_DATAPAD_CNFG);

		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x0 << WAKEPULL_EN_OFFSET;
		v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CLKPAD_CNFG);


		v16 = 0;
		v16 |= 0x2 << RXSEL_OFFSET;
		v16 |= 0x1 << WAKEPULL_EN_OFFSET;
		v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
		v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
		sdhci_writew(host, v16, PTR_PHY_REGS + PHY_RSTNPAD_CNFG);
	}

	v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_SMPLDL_CNFG);
	v8 &= ~(INSPEL_CNFG_BITS);
	v8 |= 0x2 << INSPEL_CNFG_OFFSET;
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_SMPLDL_CNFG);

	v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_ATDL_CNFG);
	v8 &= ~(INSPEL_CNFG_BITS);
	v8 |= 0x2 << INSPEL_CNFG_OFFSET;
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_ATDL_CNFG);

	// polling powergood to 1
#define TIMEOUT_CNT	5000
	for (i = 0 ; i < TIMEOUT_CNT ; i++) {
		val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
		if (val & PHY_PWRGOOD)
			break;
		mdelay(1);
	}
	if (i == TIMEOUT_CNT)
		return -1;

	// de-assert phy reset, also keep other bits same
	val |= PHY_RSTN;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

	// enable Tx clock
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_SET_REG_3, reg);
	return 0;
}

/*
 *	mshc0_cd_pad_pull(void): pull-up mshc0 card detect pad
 *	MSHC_0_IB_CARD_nDETECT,	INOUT 89
 *	bus_o_data_rw_072[19:18] = 2'b01: Pull-up.
 */
int mshc0_cd_pad_pull(void)
{
	u32 reg = 0;

	reg = mmio_read_32(VPL_SYSC_SECURE_MMR_BASE +
			SYSC_GEN_INOUT_PAD_PULL_CTRL_5);
	reg &= (unsigned int)~BIT_32(19);
	reg |= BIT_32(18);
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE +
			SYSC_GEN_INOUT_PAD_PULL_CTRL_5, reg);
	return 0;
}

extern int emmc_boot(struct sdhci_host *host, int is_dma, int bus_width);
int wagner_sdhci_init(unsigned long base, image_info_t *image_data,
						int mode, int bus_width)
{
	int ret = 0;
	u32 reg = 0;
	struct sdhci_host *host = &g_host;

	host->mmc = &g_mmc;
	host->mmc->priv = host;
	host->ops = &wagner_sdhci_ops;
	host->mmc->cfg = &host->cfg;

	if (mode == MODE_EMMC_BOOT)
//		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_180;
		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_330;
	else
		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_330;

	host->ioaddr = (void *)base;
	host->bus_width = bus_width;
	host->index = 0;
	host->max_clk = 0;
	host->quirks = SDHCI_QUIRK_WAIT_SEND_CMD;
	host->align_buffer = (void *)image_data->image_base;
	VERBOSE("SDHCI_TRANSFER_SIZE:%d image_max_size:%d\n",
			    SDHCI_TRANSFER_SIZE, image_data->image_max_size);
	assert(image_data->image_max_size >= SDHCI_TRANSFER_SIZE);

	/* set clock to 400k*/
	wagner_set_clock(host, 499);
	if (host->bus_width == 8) {
		reg = mmio_read_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL);
		reg &= ~(MSHC_CTRL_4BIT_8BIT);
		mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_MSHC_CTRL, reg);
	}

	ret = add_sdhci(host, 0, 0);
	VERBOSE("add sdhci ret:%d\n", ret);
	ret = phy_init(host, mode);
	if (ret)
		return -1;

	wagner_sdhci_set_control_reg(host);
	vtx_set_ios(400000, MMC_BUS_WIDTH_1);
	host->clock = 400000;

	return ret;
}

int card_init(int mode, int bus_width)
{
	int ret = 0;
	struct sdhci_host *host = &g_host;
	struct mmc_device_info mmc_dev;

	// mmc_dev.device_size = 1024 * 1024 * 32; // auto fill
	mmc_dev.block_size = 512;
	mmc_dev.max_bus_freq = 25;
	mmc_dev.ocr_voltage = OCR_3_2_3_3 | OCR_3_3_3_4;
	mmc_dev.mmc_dev_type = MMC_IS_SD;

	if ((mode == MODE_NORMAL_MSHC) && !card_insert(host))
		return -ENODEV;

	if (mode == MODE_EMMC_BOOT) {
		VERBOSE("%s, as EMMC\n", __func__);
		card_is_emmc(host);
		mmc_dev.mmc_dev_type = MMC_IS_EMMC;
	}
	VERBOSE("%s +++\n", __func__);

	if (bus_width == 8)
		ret =  mmc_init(&vtx_mmc_ops, 25000000, MMC_BUS_WIDTH_8,
				0, &mmc_dev);
	else
		ret =  mmc_init(&vtx_mmc_ops, 25000000, MMC_BUS_WIDTH_4,
				0, &mmc_dev);
	return ret;
}

int wagner_sdhci_bl1(unsigned long base, unsigned int image_id,
			image_info_t *image_data, int mode, int bus_width)
{
	int ret = 0;
	struct sdhci_host *host = &g_host;

	VERBOSE("%s +++\n", __func__);
	ret = wagner_sdhci_init(base, image_data, mode, bus_width);
	if (ret < 0) {
		VERBOSE("wagner_sdhci_init fail\n");
		return ret;
	}

	if (mode == MODE_EMMC_BOOT) {
		card_is_emmc(host);
		ret = emmc_boot(host, 1, bus_width);
		if (ret < 0)
			return ret;
	} else if (mode == MODE_NORMAL_MSHC) {
		ret = card_init(MODE_NORMAL_MSHC, bus_width);
		if (ret < 0) {
			VERBOSE("card init fail\n");
			return ret;
		}
		ret = sd_fat_read("bl2.bin", host, image_data->image_max_size);
		if (ret < 0) {
			VERBOSE("FAT read fail");
			return ret;
		}
#if 0
		VERBOSE("read DATA #######################################");
		mmc_read_blocks(0x0, (uintptr_t)host->align_buffer,
							SDHCI_TRANSFER_SIZE);
#endif
		// NOTE: do we need to enable MMC_FLAG_CMD23 here?
		//mmc_init(&vtx_mmc_ops, 25000000, MMC_BUS_WIDTH_4,
		//				MMC_FLAG_SD_CMD6, &mmc_dev);
	} else {
		VERBOSE("%s, mode not support", __func__);
		return -1;
	}
	VERBOSE("%s ---\n", __func__);

	return 0;
}

void get_partition_name(gpt_entry *entry, char *pname)
{
	for (int i = 0 ; i < PARTNAME_SZ ; i++)
		pname[i] = entry->partition_name[i];
}

void scan_gpt_entry(gpt_entry *entry)
{
	char pname[PARTNAME_SZ];

	for (int i = 0 ; i < ENTRY_COUNT ; i++) {
		get_partition_name(&entry[i], pname);
		VERBOSE("name:%s start:%ld end:%ld\n", pname,
				entry[i].starting_lba, entry[i].ending_lba);
		for (int j = 0 ; j < ARRAY_SIZE(emmc_descs); j++) {
		//	VERBOSE("block:%s\n", emmc_block_params_descs[j].name);
			if (strcmp(pname, emmc_descs[j].name) == 0) {
				emmc_descs[j].start = entry[i].starting_lba;
				emmc_descs[j].end = entry[i].ending_lba;
				break;
			}
		}
	}
}

int get_emmc_block_info_idx(unsigned int image_id)
{
	for (int i = 0 ; i < ARRAY_SIZE(emmc_descs) ; i++) {
		if (emmc_descs[i].image_id == image_id)
			return i;
	}
	return -1;
}

int wagner_sdhci_bl2(unsigned long base, unsigned int image_id,
			image_info_t *image_data, int mode, int bus_width)
{
	int ret = 0, idx;
	unsigned long start, end, count;
	struct sdhci_host *host = &g_host;
	static int init_done;
	gpt_entry *entry;

	VERBOSE("%s +++\n", __func__);
	if (!init_done) {
		// init sdhci controller and card here
		ret = wagner_sdhci_init(base, image_data, mode, bus_width);
		if (ret < 0) {
			ERROR("wagner_sdhci_init fail\n");
			return ret;
		}
		ret = card_init(mode, bus_width);
		if (ret < 0) {
			ERROR("card init fail\n");
			return ret;
		}
		if (mode == MODE_EMMC_BOOT) {
			/* read 1 LBA of entry info */
			host->align_buffer = (void *)image_data->image_base;
			ret = mmc_read_blocks(0x2,
						(uintptr_t)host->align_buffer,
							GPT_PAGE_SIZE);
			if (ret != GPT_PAGE_SIZE) {
				ERROR("read gpt table failed\n");
				return -1;
			}
			entry = host->align_buffer;
			scan_gpt_entry(entry);
		}
		init_done = 1;
	}

	host->align_buffer = (void *)image_data->image_base;

	if (mode == MODE_EMMC_BOOT) {
		idx = get_emmc_block_info_idx(image_id);
		if (idx < 0) {
			ERROR("fail to find target partition name\n");
			return -1;
		}
		start = emmc_descs[idx].start;
		end = emmc_descs[idx].end;
		count = (end - start + 1) * 512;
		if (count > image_data->image_max_size)
			count = image_data->image_max_size;
		INFO("emmc load, image:%d idx:%d start:%ld end:%ld\n",
					image_id, idx, start, end);

		ret = mmc_read_blocks(start,
					(uintptr_t)host->align_buffer, count);
		if (ret != count) {
			ERROR("read fail, image_id:%d\n", image_id);
			return -1;
		}
	} else if (mode == MODE_NORMAL_MSHC) {
		switch (image_id) {
		case BL31_IMAGE_ID:
			INFO("sd load BL31\n");
			ret = sd_fat_read("bl31.bin",
					host, image_data->image_max_size);
			break;
		case BL32_IMAGE_ID:
			INFO("sd load BL32\n");
			ret = sd_fat_read("bl32.bin",
					host, image_data->image_max_size);
			break;
		case BL33_IMAGE_ID:
			INFO("sd load BL33\n");
			ret = sd_fat_read("bl33.bin",
					host, image_data->image_max_size);
			break;
		}
		if (ret < 0)
			ERROR("sd load fail");
	}
	VERBOSE("%s ---\n", __func__);
	return ret;
}
