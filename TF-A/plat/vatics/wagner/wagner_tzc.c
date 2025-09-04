/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <common/debug.h>
#include <lib/mmio.h>
#include <mbc.h>
#include "maps.h"
#include "wagner_private.h"

#if defined(IMAGE_BL1)
#define TZC_SRAM_DEV_CTRL MBC_TZC_DEV3_SLAVE_CTRL	//KDPU SRAM
#define TZC_NS_SRAM_DEV_CTRL MBC_TZC_DEV2_SLAVE_0_CTRL	//VQ7U SRAM
#else
#define TZC_SRAM_DEV_CTRL MBC_TZC_DEV3_SLAVE_CTRL	//TBD
#define TZC_NS_SRAM_DEV_CTRL MBC_TZC_DEV2_SLAVE_0_CTRL	//TBD
#endif

#define TZC_SSIC0_DEV_CTRL	MBC_TZC_DEV6_SLAVE_2_CTRL
#define	TZC_SSIC1_DEV_CTRL	MBC_TZC_DEV6_SLAVE_3_CTRL

//TBBR
#define TZC_USB2_MMR_CTRL	MBC_TZC_DEV5_SLAVE_2_CTRL
#define TZC_USB3_MMR_CTRL	MBC_TZC_DEV5_SLAVE_1_CTRL
#define TZC_USB2_DEV_CTRL	MBC_TZC_DEV12_SLAVE_10_CTRL
#define TZC_USB3_DEV_CTRL	MBC_TZC_DEV12_SLAVE_11_CTRL
#define TZC_SD_DEV_CTRL		MBC_TZC_DEV7_SLAVE_1_CTRL
#define TZC_NS_SYSC_DEV_CTRL	MBC_TZC_DEV15_SLAVE_13_CTRL

void wagner_tzc_bl1_init(void)
{
}

void wagner_tzc_bl1_dev1_init(uint32_t bootmode)
{
	uint32_t reg;

	reg = mmio_read_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL);
	switch (bootmode) {
	case BOOT_BYPASS:
	default:
		return;
	case BOOT_MSHC0_SD:
		reg &= ~(MSHC_S_R_WORKAROUND | MSHC_S_W_WORKAROUND);
		break;
	case BOOT_USB30:
	case BOOT_USB20:
		reg &= ~(USB_S_R_WORKAROUND | USB_S_W_WORKAROUND);
		break;
	}
	mmio_write_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL, reg);

}

void wagner_tzc_bl1_dev2_init(uint32_t bootmode)
{
	uint32_t reg, reg_spi0, reg_spi1;

	reg = mmio_read_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL);
	switch (bootmode) {
	case BOOT_NOR_P0_1BIT:
	case BOOT_NOR_P0_QUAD:
	case BOOT_NAND_P0_1BIT:
	case BOOT_NAND_P0_QUAD:
		reg_spi0 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL);
		reg_spi0 &= ~(PDMAC_S_R | PDMAC_S_W);
		reg &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL, reg_spi0);
		break;
	case BOOT_NOR_P1_1BIT:
	case BOOT_NAND_P1_1BIT:
		reg_spi1 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL);
		reg_spi1 &= ~(PDMAC_S_R | PDMAC_S_W);
		reg &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL, reg_spi1);
		break;
	case BOOT_MSHC1_MMC4:
	case BOOT_MSHC0_MMC8:
	case BOOT_MSHC0_SD:
		reg &= ~(MSHC_S_R_WORKAROUND | MSHC_S_W_WORKAROUND);
		break;
	case RECOVERY_USB30:
	case RECOVERY_USB20:
		reg &= ~(USB_S_R_WORKAROUND | USB_S_W_WORKAROUND);
		break;
	case RECOVERY_TBBR:
		/*
		 * 1. BL1 load NS_BL1U from SPI-1 to NS_SRAM
		 * 2. NS_BL1U load BL2U from SD/USB to NS_SRAM
		 * 3. CPU(BL1) copy BL2U from NS_SRAM to Secure_SRAM
		 */

		//Set PDMAC access SPI1
		reg_spi1 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL);
		reg_spi1 &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL, reg_spi1);
		//Disable SD TZC
		mmio_write_32(VPL_MBC_BASE + TZC_SD_DEV_CTRL, 0);
		//Disable USB TZC
		mmio_write_32(VPL_MBC_BASE + TZC_USB2_MMR_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB3_MMR_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB2_DEV_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB3_DEV_CTRL, 0);
		//Set NS_SYSC
		mmio_write_32(VPL_MBC_BASE + TZC_NS_SYSC_DEV_CTRL, 0);
		//SYSC ACCESS for NS_SYSC
		mmio_write_32(SYSC_S_BASE + SYSC_ACCESS_CTRL_REG_1,
				SYSC_ACCESS_MSHC_CTRL);
		mmio_write_32(SYSC_S_BASE + SYSC_ACCESS_CTRL_REG_3,
				(SYSC_ACCESS_CLR_CLK3 |
				SYSC_ACCESS_SET_CLK3 |
				SYSC_ACCESS_CLR_CLK5 |
				SYSC_ACCESS_SET_CLK5));
		//Set NS_SRAM
		mmio_write_32(VPL_MBC_BASE + TZC_NS_SRAM_DEV_CTRL, 0);
		//Don't need to set Secure_SRAM, keep original reg value.
		break;
	default:
		reg_spi0 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL);
		reg_spi0 &= ~(PDMAC_S_R | PDMAC_S_W);
		reg &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL, reg_spi0);
		return;
	}
	mmio_write_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL, reg);

}

void wagner_tzc_bl1_dev_finish(uint32_t bootmode)
{
	mmio_write_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL, TZC_CONTROL_DEFAULT);
}


void wagner_tzc_bl2_dev_init(uint32_t bootmode)
{
	uint32_t val, reg, reg_spi0, reg_spi1;

	/*BRC SRAM (DDR INIT)*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV1_SLAVE_CTRL);
	val &= ~(DMAC0_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV1_SLAVE_CTRL, val);

	/*PUB (DDR INIT)*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV13_SLAVE_CTRL);
	val &= ~(DMAC0_S_W);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV13_SLAVE_CTRL, val);

	/*Boot Dev*/
	reg = mmio_read_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL);
	switch (bootmode) {
	case BOOT_NOR_P0_1BIT:
	case BOOT_NOR_P0_QUAD:
	case BOOT_NAND_P0_1BIT:
	case BOOT_NAND_P0_QUAD:
		reg_spi0 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL);
		reg_spi0 &= ~(PDMAC_S_R | PDMAC_S_W);
		reg &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC0_DEV_CTRL, reg_spi0);
		break;
	case BOOT_NOR_P1_1BIT:
	case BOOT_NAND_P1_1BIT:
		reg_spi1 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL);
		reg_spi1 &= ~(PDMAC_S_R | PDMAC_S_W);
		reg &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL, reg_spi1);
		break;
	case BOOT_MSHC1_MMC4:
	case BOOT_MSHC0_MMC8:
		reg &= ~(MSHC_S_R_WORKAROUND | MSHC_S_W_WORKAROUND);
		break;
	case RECOVERY_USB30:
	case RECOVERY_USB20:
	case BOOT_USB30:
		reg &= ~(USB_S_R_WORKAROUND | USB_S_W_WORKAROUND);
		break;
	case RECOVERY_TBBR:
		/*
		 * 1. BL1 load NS_BL1U from SPI-1 to NS_SRAM
		 * 2. NS_BL1U load BL2U from SD/USB to NS_SRAM
		 * 3. CPU(BL1) copy BL2U from NS_SRAM to Secure_SRAM
		 */

		//Set PDMAC access SPI1
		reg_spi1 = mmio_read_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL);
		reg_spi1 &= ~(PDMAC_S_R | PDMAC_S_W);
		mmio_write_32(VPL_MBC_BASE + TZC_SSIC1_DEV_CTRL, reg_spi1);
		//Disable SD TZC
		mmio_write_32(VPL_MBC_BASE + TZC_SD_DEV_CTRL, 0);
		//Disable USB TZC
		mmio_write_32(VPL_MBC_BASE + TZC_USB2_MMR_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB3_MMR_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB2_DEV_CTRL, 0);
		mmio_write_32(VPL_MBC_BASE + TZC_USB3_DEV_CTRL, 0);
		//Set NS_SYSC
		mmio_write_32(VPL_MBC_BASE + TZC_NS_SYSC_DEV_CTRL, 0);
		//SYSC ACCESS for NS_SYSC
		mmio_write_32(SYSC_S_BASE + SYSC_ACCESS_CTRL_REG_1,
				SYSC_ACCESS_MSHC_CTRL);
		mmio_write_32(SYSC_S_BASE + SYSC_ACCESS_CTRL_REG_3,
				(SYSC_ACCESS_CLR_CLK3 |
				SYSC_ACCESS_SET_CLK3 |
				SYSC_ACCESS_CLR_CLK5 |
				SYSC_ACCESS_SET_CLK5));
		//Set NS_SRAM
		mmio_write_32(VPL_MBC_BASE + TZC_NS_SRAM_DEV_CTRL, 0);
		//Don't need to set Secure_SRAM, keep original reg value.
		break;
	default:
		return;
	}
	mmio_write_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL, reg);

}

void wagner_tzc_bl2_dev_finish(uint32_t bootmode)
{
	mmio_write_32(VPL_MBC_BASE + TZC_SRAM_DEV_CTRL, TZC_CONTROL_DEFAULT);

	/* DDR INIT */
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV1_SLAVE_CTRL, TZC_CONTROL_DEFAULT);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV13_SLAVE_CTRL, TZC_CONTROL_DEFAULT);
}

void wagner_tzc_disable(void)
{
	uint32_t val;

	/*DEV 0*/
	//ROM
	/*
	 * val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV0_SLAVE_CTRL);
	 * val &= ~(CONTROL_S_W | CONTROL_S_R);
	 * mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV0_SLAVE_CTRL, val);
	 */

	/*DEV 1*/
	//BRC SRAM
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV1_SLAVE_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV1_SLAVE_CTRL, val);

	/*DEV 2*/
	//VQ7U SRAM
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV2_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV2_SLAVE_0_CTRL, val);
	//VQ7U DECMPR MMR
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV2_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV2_SLAVE_1_CTRL, val);

	/*DEV 3*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV3_SLAVE_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV3_SLAVE_CTRL, val);

	/*DEV 4*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV4_SLAVE_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV4_SLAVE_CTRL, val);

	/*DEV 5*/
	/*EQOSC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_0_CTRL, val);
	/*USB30C*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_1_CTRL, val);
	/*USB20C*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV5_SLAVE_2_CTRL, val);

	/*DEV 6*/
	/*PDMA*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_0_CTRL, val);
	/*I2S*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_1_CTRL, val);
	/*SSIC0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_2_CTRL, val);
	/*SSIC1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_3_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_3_CTRL, val);
	/*SSIC2*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_4_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_4_CTRL, val);
	/*SSIC3*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_5_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_5_CTRL, val);
	/*UART0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_6_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_6_CTRL, val);
	/*UART1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_7_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_7_CTRL, val);
	/*UART2*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_8_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_8_CTRL, val);
	/*UART3*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_9_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_9_CTRL, val);
	/*UART4*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_10_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV6_SLAVE_10_CTRL, val);

	/*DEV 7*/
	/*INTC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_0_CTRL, val);
	/*MSHC0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_1_CTRL, val);
	/*MSHC1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV7_SLAVE_2_CTRL, val);

	/*DEV 8*/
	/*DMAC0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_0_CTRL, val);
	/*DMAC1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_1_CTRL, val);
	/*JDBE*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_2_CTRL, val);
	/*JEBE*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_3_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV8_SLAVE_3_CTRL, val);

	/*DEV 9*/
	/*DDRNSDMC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV9_SLAVE_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV9_SLAVE_CTRL, val);

	/*DEV 10*/
	/*IFPE*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV10_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV10_SLAVE_0_CTRL, val);
	/*ISPE*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV10_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV10_SLAVE_1_CTRL, val);

	/*DEV 11*/
	/*VIC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_0_CTRL, val);
	/*VOC 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_1_CTRL, val);
	/*VOC 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV11_SLAVE_2_CTRL, val);

	/*DEV 12*/
	/*uMCTL*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_0_CTRL, val);
	/*kDPU*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_1_CTRL, val);
	/*SCRTU*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_2_CTRL, val);
	/*CDCE DEMP*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_3_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_3_CTRL, val);
	/*CDCE WAVE521*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_4_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_4_CTRL, val);
	/*IEU 0 DECMP*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_5_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_5_CTRL, val);
	/*IEU 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_6_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_6_CTRL, val);
	/*IEU 1 DECMP*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_7_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_7_CTRL, val);
	/*IEU 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_8_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_8_CTRL, val);
	/*DDR APM*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_9_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_9_CTRL, val);
	/*USB 20C*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_10_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_10_CTRL, val);
	/*USB 30C*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_11_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_11_CTRL, val);
	/*MBC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_12_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV12_SLAVE_12_CTRL, val);

	/*DEV 13*/
	/*PUB*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV13_SLAVE_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV13_SLAVE_CTRL, val);

	/*DEV 14*/
	/*MIPIRC 0 2L*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_0_CTRL, val);
	/*MIPIRC 0 4L*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_1_CTRL, val);
	/*MIPIRC 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_2_CTRL, val);
	/*MIPIRC 1 2L*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_3_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_3_CTRL, val);
	/*MIPIRC 1 4L*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_4_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_4_CTRL, val);
	/*MIPIRC 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_5_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_5_CTRL, val);
	/*MIPITC CSI-2*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_6_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_6_CTRL, val);
	/*MIPITC DSI*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_7_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_7_CTRL, val);
	/*MIPITC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_8_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV14_SLAVE_8_CTRL, val);

	/*DEV 15*/
	/*ACDCC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_0_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_0_CTRL, val);
	/*AGPOC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_1_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_1_CTRL, val);
	/*GPIOC 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_2_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_2_CTRL, val);
	/*GPIOC 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_3_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_3_CTRL, val);
	/*GPIOC 2*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_4_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_4_CTRL, val);
	/*I2C 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_5_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_5_CTRL, val);
	/*I2C 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_6_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_6_CTRL, val);
	/*I2C 2*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_7_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_7_CTRL, val);
	/*IRDA*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_8_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_8_CTRL, val);
	/*PMU*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_9_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_9_CTRL, val);
	/*TMRC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_10_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_10_CTRL, val);
	/*WDTC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_11_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_11_CTRL, val);
	/*PLLC*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_12_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_12_CTRL, val);
	/*SYSC PORT 0*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_13_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_13_CTRL, val);
	/*SYSC PORT 1*/
	val = mmio_read_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_14_CTRL);
	val &= ~(CONTROL_S_W | CONTROL_S_R);
	mmio_write_32(VPL_MBC_BASE + MBC_TZC_DEV15_SLAVE_14_CTRL, val);

	/* SYSC */
	/*MMR 31-06*/
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_ACCESS_CTRL_REG_0,
			0xFFFFFFFF);
	/*MMR 63-32*/
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_ACCESS_CTRL_REG_1,
			0xFFFFFFFF);
	/*MMR 95-64*/
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_ACCESS_CTRL_REG_2,
			0xFFFFFFFF);
	/*MMR 127-96*/
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_ACCESS_CTRL_REG_3,
			0xFFFFFFFF);
	/*MMR 147-128*/
	mmio_write_32(VPL_SYSC_SECURE_MMR_BASE + SYSC_ACCESS_CTRL_REG_4,
			0x00FFFFFF);
}

