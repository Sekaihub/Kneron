
#define MMC_VDD_165_195		0x00000080	/* VDD voltage 1.65 - 1.95 */
#define MMC_VDD_20_21		0x00000100	/* VDD voltage 2.0 ~ 2.1 */
#define MMC_VDD_21_22		0x00000200	/* VDD voltage 2.1 ~ 2.2 */
#define MMC_VDD_22_23		0x00000400	/* VDD voltage 2.2 ~ 2.3 */
#define MMC_VDD_23_24		0x00000800	/* VDD voltage 2.3 ~ 2.4 */
#define MMC_VDD_24_25		0x00001000	/* VDD voltage 2.4 ~ 2.5 */
#define MMC_VDD_25_26		0x00002000	/* VDD voltage 2.5 ~ 2.6 */
#define MMC_VDD_26_27		0x00004000	/* VDD voltage 2.6 ~ 2.7 */
#define MMC_VDD_27_28		0x00008000	/* VDD voltage 2.7 ~ 2.8 */
#define MMC_VDD_28_29		0x00010000	/* VDD voltage 2.8 ~ 2.9 */
#define MMC_VDD_29_30		0x00020000	/* VDD voltage 2.9 ~ 3.0 */
#define MMC_VDD_30_31		0x00040000	/* VDD voltage 3.0 ~ 3.1 */
#define MMC_VDD_31_32		0x00080000	/* VDD voltage 3.1 ~ 3.2 */
#define MMC_VDD_32_33		0x00100000	/* VDD voltage 3.2 ~ 3.3 */
#define MMC_VDD_33_34		0x00200000	/* VDD voltage 3.3 ~ 3.4 */
#define MMC_VDD_34_35		0x00400000	/* VDD voltage 3.4 ~ 3.5 */
#define MMC_VDD_35_36		0x00800000	/* VDD voltage 3.5 ~ 3.6 */

#define MMC_CAP(mode)		(1 << mode)
#define MMC_MODE_HS		(MMC_CAP(MMC_HS) | MMC_CAP(SD_HS))
#define MMC_MODE_HS_52MHz	MMC_CAP(MMC_HS_52)
#define MMC_MODE_DDR_52MHz	MMC_CAP(MMC_DDR_52)
#define MMC_MODE_HS200		MMC_CAP(MMC_HS_200)
#define MMC_MODE_HS400		MMC_CAP(MMC_HS_400)
#define MMC_MODE_HS400_ES	MMC_CAP(MMC_HS_400_ES)

#define MMC_CAP_NONREMOVABLE	BIT(14)
#define MMC_CAP_NEEDS_POLL	BIT(15)
#define MMC_CAP_CD_ACTIVE_HIGH  BIT(16)

#define MMC_MODE_8BIT		BIT(30)
#define MMC_MODE_4BIT		BIT(29)
#define MMC_MODE_1BIT		BIT(28)
#define MMC_MODE_SPI		BIT(27)

#define MMC_DATA_READ		1
#define MMC_DATA_WRITE		2

#define MMC_CMD_GO_IDLE_STATE		0
#define MMC_CMD_SEND_OP_COND		1
#define MMC_CMD_ALL_SEND_CID		2
#define MMC_CMD_SET_RELATIVE_ADDR	3
#define MMC_CMD_SET_DSR			4
#define MMC_CMD_SWITCH			6
#define MMC_CMD_SELECT_CARD		7
#define MMC_CMD_SEND_EXT_CSD		8
#define MMC_CMD_SEND_CSD		9
#define MMC_CMD_SEND_CID		10
#define MMC_CMD_STOP_TRANSMISSION	12
#define MMC_CMD_SEND_STATUS		13
#define MMC_CMD_SET_BLOCKLEN		16
#define MMC_CMD_READ_SINGLE_BLOCK	17
#define MMC_CMD_READ_MULTIPLE_BLOCK	18
#define MMC_CMD_SEND_TUNING_BLOCK		19
#define MMC_CMD_SEND_TUNING_BLOCK_HS200	21
#define MMC_CMD_SET_BLOCK_COUNT         23
#define MMC_CMD_WRITE_SINGLE_BLOCK	24
#define MMC_CMD_WRITE_MULTIPLE_BLOCK	25
#define MMC_CMD_ERASE_GROUP_START	35
#define MMC_CMD_ERASE_GROUP_END		36
#define MMC_CMD_ERASE			38
#define MMC_CMD_APP_CMD			55
#define MMC_CMD_SPI_READ_OCR		58
#define MMC_CMD_SPI_CRC_ON_OFF		59
#define MMC_CMD_RES_MAN			62

#define MMC_CMD62_ARG1			0xefac62ec
#define MMC_CMD62_ARG2			0xcbaea7


#define SD_CMD_SEND_RELATIVE_ADDR	3
#define SD_CMD_SWITCH_FUNC		6
#define SD_CMD_SEND_IF_COND		8
#define SD_CMD_SWITCH_UHS18V		11

#define SD_CMD_APP_SET_BUS_WIDTH	6
#define SD_CMD_APP_SD_STATUS		13
#define SD_CMD_ERASE_WR_BLK_START	32
#define SD_CMD_ERASE_WR_BLK_END		33
#define SD_CMD_APP_SEND_OP_COND		41
#define SD_CMD_APP_SEND_SCR		51

#define R1_ILLEGAL_COMMAND		(1 << 22)
#define R1_APP_CMD			(1 << 5)

// response that uboot sdhci use
#define MMC_RSP_PRESENT (1 << 0)
#define MMC_RSP_OPCODE	(1 << 4)		/* response contains opcode */
enum mmc_voltage {
	MMC_SIGNAL_VOLTAGE_000 = 0,
	MMC_SIGNAL_VOLTAGE_120 = 1,
	MMC_SIGNAL_VOLTAGE_180 = 2,
	MMC_SIGNAL_VOLTAGE_330 = 4,
};

enum bus_mode {
	MMC_LEGACY,
	MMC_HS,
	SD_HS,
	MMC_HS_52,
	MMC_DDR_52,
	UHS_SDR12,
	UHS_SDR25,
	UHS_SDR50,
	UHS_DDR50,
	UHS_SDR104,
	MMC_HS_200,
	MMC_HS_400,
	MMC_HS_400_ES,
	MMC_MODES_END
};
struct mmc_config {
	const char *name;
	const struct uboot_sdhci_ops *ops;
	uint host_caps;
	uint voltages;
	uint f_min;
	uint f_max;
	uint b_max;
	unsigned char part_type;
};

struct mmc_data {
	union {
		char *dest;
		const char *src; /* src buffers don't get written to */
	};
	uint flags;
	uint blocks;
	uint blocksize;
};


struct mmc {
#if 0
	struct list_head link;
#endif
	const struct mmc_config *cfg;	/* provided configuration */
	uint version;
	void *priv;
	uint has_init;
	int high_capacity;
	int clk_disable; /* true if the clock can be turned off */
	uint bus_width;
	uint clock;
	uint saved_clock;
	enum mmc_voltage signal_voltage;
	uint card_caps;
	uint host_caps;
	uint ocr;
	uint dsr;
	uint dsr_imp;
	uint scr[2];
	uint csd[4];
	uint cid[4];
	uint16_t rca;
	u8 part_support;
	u8 part_attr;
	u8 wr_rel_set;
	u8 part_config;
	u8 gen_cmd6_time;	/* units: 10 ms */
	u8 part_switch_time;	/* units: 10 ms */
	uint tran_speed;
	uint legacy_speed; /* speed for the legacy mode provided by the card */
	uint read_bl_len;
#if 0
	uint write_bl_len;
	uint erase_grp_size;	/* in 512-byte sectors */
#endif
#if 0
	uint hc_wp_grp_size;	/* in 512-byte sectors */
#endif
#if 0
	struct sd_ssr	ssr;	/* SD status register */
#endif
	u64 capacity;
	u64 capacity_user;
	u64 capacity_boot;
	u64 capacity_rpmb;
	u64 capacity_gp[4];
#ifndef CONFIG_SPL_BUILD
	u64 enh_user_start;
	u64 enh_user_size;
#endif
#if 0
	struct blk_desc block_dev;
#endif
	char op_cond_pending;	/* 1 if we are waiting on an op_cond command */
	char init_in_progress;	/* 1 if we have done mmc_start_init() */
	char preinit;		/* start init as early as possible */
	int ddr_mode;
#if 0
	struct udevice *dev;	/* Device for this MMC controller */
#if 0
	struct udevice *vmmc_supply;	/* Main voltage regulator (Vcc)*/
	struct udevice *vqmmc_supply;	/* IO voltage regulator (Vccq)*/
#endif
#endif
	u8 *ext_csd;
	u32 cardtype;		/* cardtype read from the MMC */
	enum mmc_voltage current_voltage;
	enum bus_mode selected_mode; /* mode currently used */
	enum bus_mode best_mode; /* best mode is the supported mode with the
				  * highest bandwidth. It may not always be the
				  * operating mode due to limitations when
				  * accessing the boot partitions
				  */
	u32 quirks;
	u8 hs400_tuning;

	enum bus_mode user_speed_mode; /* input speed mode from user */
};

struct uboot_sdhci_ops {
	int (*send_cmd)(struct mmc *mmc,
			struct mmc_cmd *cmd, struct mmc_data *data);
	int (*set_ios)(struct mmc *mmc);
	int (*init)(struct mmc *mmc);
	int (*getcd)(struct mmc *mmc);
	int (*getwp)(struct mmc *mmc);
	int (*host_power_cycle)(struct mmc *mmc);
};

#define MODE_EMMC_BOOT		0
#define MODE_NORMAL_MSHC	1
