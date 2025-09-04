/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WAGNER_PRIVATE_H
#define WAGNER_PRIVATE_H

#include <common/bl_common.h>
#include "sysctrl.h"

typedef struct bootselect_t {
	uint8_t		boot_1st;
	uint8_t		boot_2nd;
} bootselect_t;

typedef struct bl_header_info_t {
	uint32_t	spi_attr;
	uint32_t	scrtu_fw_offset;
	uint32_t	ddr_fw_offset;
	uint32_t	bl_image_size;
	uint32_t	bl_offset;
	uint32_t	total_size;
	uint32_t	spi_bl33_addr;
	uint32_t	spi_bl33_size;
} bl_header_info_t;
/*
 * Function and variable prototypes
 */
void wagner_init_mmu_el1(unsigned long total_base,
			unsigned long total_size,
			unsigned long ro_start,
			unsigned long ro_limit);
void wagner_init_mmu_el3(unsigned long total_base,
			unsigned long total_size,
			unsigned long ro_start,
			unsigned long ro_limit);
void wagner_io_setup(void);
int wagner_set_fip_addr(unsigned int image_id, const char *name);
void wagner_clk_init(void);
void wagner_pmu_init(void);
void wagner_regulator_enable(void);
void wagner_tzc_bl1_init(void);
void wagner_tzc_bl1_dev1_init(uint32_t bootmode);
void wagner_tzc_bl1_dev2_init(uint32_t bootmode);
void wagner_tzc_bl1_dev_finish(uint32_t bootmode);
void wagner_tzc_bl2_dev_init(uint32_t bootmode);
void wagner_tzc_bl2_dev_finish(uint32_t bootmode);
void wagner_tzc_disable(void);
void wagner_peri_init(void);
void wagner_pinmux_init(void);
void wagner_enable_q7_sram(void);
void wagner_eqosc_pinmux_init(void);
void wagner_mshc_pinmux_init(void);
void wagner_gpio_init(void);
void set_retention_ticks(unsigned int val);
void clr_retention_ticks(unsigned int val);
void clr_ex(void);
void nop(void);
unsigned int plat_wagner_calc_core_pos(u_register_t mpidr);
void wagner_get_boot_select(bootselect_t *bootselect);

int dw_qspi_init(int bus_id, unsigned int buswidth);
int dw_qspi_set_sckdv(unsigned int sckdv);
int dw_qspi_set_rxdelay(unsigned int clk_nb);
int dw_qspi_dma_release(void);
int bl1_plat_spi_nor_read(unsigned int image_id, image_info_t *image_data,
			  int bus_id, unsigned int buswidth);
int bl2_plat_spi_nor_read(unsigned int image_id, image_info_t *image_data,
			  int bus_id, unsigned int buswidth);
int bl1_plat_spi_nand_read(unsigned int image_id, image_info_t *image_data,
			   int bus_id, unsigned int buswidth);
int bl2_plat_spi_nand_read(unsigned int image_id, image_info_t *image_data,
			   int bus_id, unsigned int buswidth);

int wagner_usb_boot(unsigned int image_id, image_info_t *image_data,
			unsigned int bootmode);
int wagner_usb_boot_bl2(unsigned int image_id, image_info_t *image_data,
			unsigned int bootmode);
void *wagner_memcpy(void *dest, const void *src, unsigned int length);

/* PMU, Warm boot */
uint32_t read_pmu_reg(uint32_t addr);
void write_pmu_reg(uint32_t addr, uint32_t data);
uint32_t check_voltage_in(void);

/* Watchdog */
bool wagner_get_wdt_flag(void);
void wagner_set_wdt_flag(void);
void wagner_clear_wdt_flag(void);

#endif /* WAGNER_PRIVATE_H */
