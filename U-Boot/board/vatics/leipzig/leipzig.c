// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021 VATICS Inc.
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/soc.h>
#include <asm/arch/boot_param.h>
#include <asm/global_data.h>
#include <env.h>
#include <env_internal.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	/* enable ctrlc */
	//console_init_f();

	/* address of boot parameters */
	gd->bd->bi_arch_number = MACH_TYPE_EVM;
	gd->bd->bi_boot_params = BOOT_PARAMS_ADDR;

	return 0;
}

#if (IS_ENABLED(CONFIG_BOARD_EARLY_INIT_F))
int board_early_init_f(void)
{
	/* enable ctrlc */
	console_init_f();

	return 0;
}
#endif

unsigned int VPL_SNPS_MCTL_SIZE(void)
{
	uintptr_t ddrctrl = LEIPZIG_DDRNSDMC_MCTL_BASE;
	int i;
	unsigned int v, rows = 0, cols = 2, banks = 0, dw = 0;

	v = readl(ddrctrl);
	dw = ((v & (3 << 12)) == 0) ? 2 : 1; //FULL, half

	v = readl(ddrctrl + 0x204);
	banks += !(v & (0x20 << 16)) + !(v & (0x20 << 8)) + !(v & (0x20 << 0));

	for (i = 0x208; i <= 0x20c; i += 4) {  // column = 10
		v = readl(ddrctrl + i);
		cols += !(v & (0x18 << 24)) + !(v & (0x18 << 16))
				 + !(v & (0x18 << 8)) + !(v & (0x18 << 0));
	}

	v = readl(ddrctrl + 0x214);
	rows += (((v >> 24) & 0xF) <= 11) + ((((v >> 16) & 0xF) <= 11) ? 9 : 0)
			 + (((v >> 8) & 0xF) <= 11) + (((v >> 0) & 0xF) <= 11);
	v = readl(ddrctrl + 0x218);
	rows += (((v >> 24) & 0xF) <= 11) + (((v >> 16) & 0xF) <= 11)
			 + (((v >> 8) & 0xF) <= 11) + (((v >> 0) & 0xF) <= 11);

	return (1 << (banks + cols + rows + dw));
}

/* Override the weak symbol in board_f.c */
int dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = 0;
	gd->bd->bi_dram[0].size = gd->ram_size;

	return 0;
}

/*
 * Do not save dram address to gd->bd->bi_dram, bacause the pointer gd->bd
 * is not allocated yet.
 * Just calculate and store complete ramsize in gd->ram_size.
 */
int dram_init(void)
{
	gd->ram_size = VPL_SNPS_MCTL_SIZE();

	return 0;
}

int print_cpuinfo(void)
{
	printf("CPU: Kneron Wagner\n");

#ifdef DEBUG
	for (int i = 0; i < 4; i++)
		printf("     Arg #%d = 0x%llx\n", i, tfa_boot_args[i]);
#endif

	return 0;
}

unsigned int is_boot_param_valid(void)
{
	unsigned int ret;

	ret = 0;

	if (tfa_boot_args[ARG_MAGIC] == VATICS_BL2_MAGIC)
		ret = 1;

	return ret;
}


unsigned int get_bootmode(void)
{
	/*
	 * To compatible with old loader in FPGA,
	 * check ARG_MAGiC before getting boot mode.
	 * Old loader only support spi nor boot,
	 * so return BOOT_NOR_P0_1BIT.
	 */
	if (is_boot_param_valid() == 1)
		return tfa_boot_args[ARG_BOOTMODE];
	else //read from spi0 nand if boot param is invalid
		return BOOT_NOR_P0_1BIT;
}

enum env_location env_get_location(enum env_operation op, int prio)
{
	unsigned int bootmode = get_bootmode();

	if (prio)
		return ENVL_UNKNOWN;

	switch (bootmode) {
	case BOOT_NOR_P0_1BIT:
		return ENVL_SPI_FLASH;
	break;
	case BOOT_NOR_P0_QUAD:
		return ENVL_SPI_FLASH;
	break;
	case BOOT_NAND_P0_1BIT:
		return ENVL_NAND;
	break;
	case BOOT_NAND_P0_QUAD:
		return ENVL_NAND;
	break;
	case BOOT_NOR_P1_1BIT:
		return ENVL_SPI_FLASH;
	break;
	case BOOT_NAND_P1_1BIT:
		return ENVL_NAND;
	break;
	case BOOT_USB30:
	case RECOVERY_USB30:
	case RECOVERY_USB20:
		return ENVL_NOWHERE;
	break;

	/*
	 * read env from spi nor flash
	 * before these boot devices are implemented
	 */
	case BOOT_MSHC1_MMC4:
	case BOOT_MSHC0_MMC8:
		return ENVL_MMC;
	case BOOT_MSHC0_SD:
		return ENVL_FAT;
	break;

	default:
		return ENVL_NOWHERE;
	}
}

int mmc_get_env_dev(void)
{
	if (get_bootmode() == BOOT_MSHC1_MMC4)
		return 1; // eMMC1 boot

	return 0; // eMMC0 boot or else
}

