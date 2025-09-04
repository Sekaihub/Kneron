/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <assert.h>
#include <string.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <common/desc_image_load.h>
#include <drivers/console.h>
#include <drivers/ti/uart/uart_16550.h>
#include <drivers/delay_timer.h>
#include <drivers/generic_delay_timer.h>
#include <drivers/vatics/wdt.h>
#include <lib/utils.h>
#include <plat/common/platform.h>
#include <safezone.h>

#ifdef SPD_opteed
#include <lib/optee_utils.h>
#endif

#include <wagner_buf.h>

#include "wagner_def.h"
#include "wagner_private.h"
#include "ddrc_init.h"

#define VATICS_BL2_MAGIC        (0xFACADE01)
#include "wagner_bl2_keys.c"

extern bl_header_info_t bl_header_info;

/* Data structure which holds the extents of the trusted SRAM for BL2 */
static meminfo_t bl2_tzram_layout __aligned(CACHE_WRITEBACK_GRANULE);
static console_t console;
uint32_t spi_attr, current_bootmode;

/* Declare overlay buffer for each boot mode */
union OverlaidBuffer *overlaid_bufferp;
union OverlaidBuffer overlaid_buffer;

/* OTP Info */
bool    wagner_USB3_clk_external;
bool    wagner_TZC_enable;
bool	wagner_PMU_disable;

meminfo_t *bl2_plat_sec_mem_layout(void)
{
	return &bl2_tzram_layout;
}

/*****************************************************************************
 * BL1 has passed the extents of the trusted SRAM that should be visible to BL2
 * in x0. This memory layout is sitting at the base of the free trusted SRAM.
 * Copy it to a safe location before its reclaimed by later BL2 functionality.
 *****************************************************************************
 */
void bl2_early_platform_setup2(u_register_t arg0, u_register_t arg1,
			       u_register_t arg2, u_register_t arg3)
{
	uint32_t otp_hw_cfg1;

	spi_attr = arg0;
	current_bootmode = arg2;
	overlaid_bufferp = (union OverlaidBuffer *)arg3;

	otp_hw_cfg1 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_1);
	wagner_USB3_clk_external = !!(otp_hw_cfg1 & USB3_CLK_EXTERNAL);
	wagner_TZC_enable = !!(otp_hw_cfg1 & SECUREBOOT_ENABLE);

	wagner_pinmux_init();

	if (wagner_TZC_enable)
		wagner_tzc_bl2_dev_init(current_bootmode);

	wagner_eqosc_pinmux_init();
	wagner_mshc_pinmux_init();

	generic_delay_timer_init();
	/* Initialize the console to provide early debug support */
	console_16550_register(UART_0, UART_CLOCK,
				115200, &console);

	VERBOSE("*** wagner_TZC_enable = %d\n", wagner_TZC_enable);

	wagner_ddr_init();
	/* Setup the BL2 memory layout */
	bl2_tzram_layout.total_base = BL2_BASE;
	//include share buffer in BL1
	bl2_tzram_layout.total_size = BL2_LIMIT - BL2_BASE + BL1_RW_SIZE;

	/* Initialise the IO layer and register platform IO devices */
	//wagner_io_setup();
}

void bl2_platform_setup(void)
{
#if !WAGNER_FPGA
	uint32_t otp_hw_cfg0;

	otp_hw_cfg0 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0);
	if (otp_hw_cfg0 & SCRTU_EIP130_ENABLE)
		eip130_force_unlink();
#endif
}

/*****************************************************************************
 * Perform the very early platform specific architectural setup here. At the
 * moment this is only initializes the mmu in a quick and dirty way.
 *****************************************************************************
 */
void bl2_plat_arch_setup(void)
{
	uint32_t chip_id_info, production_mode;

	chip_id_info = mmio_read_32(SYSC_S_BASE + SYSC_CHIP_ID_INFO);
	wagner_PMU_disable = !!(chip_id_info & PMU_BOOT_DISABLE);
	production_mode = (mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0))
		& PRODUCTION_MODE;
	if (production_mode)
		wagner_PMU_disable = 1;

#if 0
	/* Clear Watchdog flag */
	if (wagner_get_wdt_flag() == 1)
		wagner_clear_wdt_flag();
#endif

	WARN("*****************************\n");
	WARN("* Watchdog Disable For TEST *\n");
	WARN("*****************************\n");
	/* Stop Watchdog */
	vpl_wdt_stop();


#if BL2_ENABLE_MMU
	wagner_init_mmu_el1(bl2_tzram_layout.total_base,
			    bl2_tzram_layout.total_size,
			    BL_CODE_BASE,
			    BL_CODE_END);
#endif

	bl_header_info.spi_bl33_addr = UNKNOWN_ADDR;
	bl_header_info.spi_bl33_size = UNKNOWN_SIZE;
}

void bl2_plat_preload_setup(void)
{
}

int bl2_plat_load_auth_image(unsigned int image_id, image_info_t *image_data)
{
	uintptr_t image_base;
	//size_t image_size;
	int ret = -1;
	uint32_t otp_hw_cfg0, otp_hw_cfg1;
	uint8_t *sbpk, *sbph;

	bl_mem_params_node_t *bl_mem_params = get_bl_mem_params_node(image_id);

	assert(image_data != NULL);
	assert(image_data->h.version >= VERSION_2);

	image_base = image_data->image_base;

	INFO("Image id=%u load to 0x%lx, MaxSize:%d\n", image_id, image_base,
	     image_data->image_max_size);

	switch (current_bootmode) {
	case BOOT_NOR_P0_1BIT:
		INFO("BL2 BOOT_NOR_P0_1BIT boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nor_read(image_id,
				image_data, 0, 1);
		break;
	case BOOT_NOR_P0_QUAD:
		INFO("BL2 BOOT_NOR_P0_QUAD boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nor_read(image_id,
				image_data, 0, 4);
		break;
	case BOOT_NAND_P0_1BIT:
		INFO("BL2 BOOT_NAND_P0_1BIT boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nand_read(image_id,
				image_data, 0, 1);
		break;
	case BOOT_NAND_P0_QUAD:
		INFO("BL2 BOOT_NAND_P0_QUAD boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nand_read(image_id,
				image_data, 0, 4);
		break;
	case BOOT_NOR_P1_1BIT:
		INFO("BL2 BOOT_NOR_P1_1BIT boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nor_read(image_id,
				image_data, 1, 1);
		break;
	case BOOT_NAND_P1_1BIT:
		INFO("BL2 BOOT_NAND_P1_1BIT boot mode(%x)", current_bootmode);
		ret = bl2_plat_spi_nand_read(image_id,
				image_data, 1, 1);
		break;
	case BOOT_USB30:
	/* case BOOT_USB20: BOOT_USB20 overridden by RECOVERY_USB20 in BL1 */
	case RECOVERY_USB30:
	case RECOVERY_USB20:
		ret = wagner_usb_boot_bl2(image_id, image_data,
					current_bootmode);
		break;
	case BOOT_MSHC0_SD:
		INFO("BL2 BOOT_MSHC0_SD(%x)\n", current_bootmode);
		ret = wagner_sdhci_bl2(VPL_MSHC_0_MMR_BASE, image_id,
					image_data, MODE_NORMAL_MSHC, 4);
		break;
	case BOOT_MSHC1_MMC4:
		INFO("BL2 BOOT_MSHC1_MMC4(%x)\n", current_bootmode);
		ret = wagner_sdhci_bl2(VPL_MSHC_1_MMR_BASE, image_id,
					image_data, MODE_EMMC_BOOT, 4);
		break;
	case BOOT_MSHC0_MMC8:
		INFO("BL2 BOOT_MSHC0_MMC8(%x)\n", current_bootmode);
		ret = wagner_sdhci_bl2(VPL_MSHC_0_MMR_BASE, image_id,
					image_data, MODE_EMMC_BOOT, 8);
		break;
	default:
		ret = bl2_plat_spi_nor_read(image_id,
				image_data, 0, 1);
	break;
	}

	if (ret < 0) {
		ERROR("BL2: Image ID(%d) load fail\n", image_id);
		return ret;
	}

	eip130_headerInfo((SBIF_Header_t *)image_data->image_base);

	otp_hw_cfg0 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_0);
	otp_hw_cfg1 = mmio_read_32(SYSC_S_BASE + SYSC_HW_CFG_1);

	//Check Non-secure Boot
	if (!(otp_hw_cfg0 & SCRTU_EIP130_ENABLE) ||
		!(otp_hw_cfg1 & SECUREBOOT_ENABLE)) {
		if ((current_bootmode == BOOT_USB30) ||
				(current_bootmode == RECOVERY_USB30) ||
				(current_bootmode == RECOVERY_USB20)) {

			bl_header_info.bl_image_size = ret;
		} else if (bl_header_info.bl_offset == 0) {
			switch (image_id) {
			case BL31_IMAGE_ID:
				bl_header_info.bl_image_size =
				BL31_LIMIT - BL31_BASE;
				break;
			case BL32_IMAGE_ID:
				bl_header_info.bl_image_size =
				BL32_DRAM_LIMIT - BL32_DRAM_BASE;
				break;
			case BL33_IMAGE_ID:
				bl_header_info.bl_image_size =
				BL33_LIMIT - BL33_BASE;
				break;
			default:
				ERROR("BL2: Unknown Image ID(%d)\n", image_id);
				break;
			}
		}

		if (bl_mem_params->ep_info.pc !=
			image_data->image_base + bl_header_info.bl_offset) {
			wagner_memcpy((void *)bl_mem_params->ep_info.pc,
					(const void *)(image_data->image_base +
						bl_header_info.bl_offset),
					bl_header_info.bl_image_size);
		}

		goto finish_load;
	}
	VERBOSE("Verify Image %d\n", image_id);

#if 0	// For test if BL1 skip verify
	uintptr_t gpfw_base;
	uint32_t fips_disable;

	fips_disable = !(otp_hw_cfg1 & FIPS_ENABLE);
	gpfw_base = VPL_SCRTU_EIP130_GPFW_BASE;
	ret = eip130_initfw(gpfw_base, fips_disable);
	if (ret == 0)
		NOTICE("FW INIT OK\n");
	else
		NOTICE("FW INIT FAIL\n");
#endif

	//Load image success, start verify
	switch (image_id) {
	case BL31_IMAGE_ID:
		sbpk = sbpk_bl31;
		sbph = sbph_bl31;
		break;
	case BL32_IMAGE_ID:
		sbpk = sbpk_bl32;
		sbph = sbph_bl32;
		break;
	case BL33_IMAGE_ID:
		sbpk = sbpk_bl33;
		sbph = sbph_bl33;
		break;
	default:
		ERROR("BL2: Unknown Image ID(%d)\n", image_id);
		return -1;
	}
	ret = eip130_verifyImage_with_key(image_id,
			image_data->image_base,
			bl_mem_params->ep_info.pc, sbpk, sbph);

	if (ret == 0)
		vpl_wdt_ping();
	else {
		ERROR("BL2: Image ID(%d) verify fail\n", image_id);
		return ret;
	}

finish_load:
	// flush dcache for BL1 because Wagner BL1 is cache-off
	flush_dcache_range(image_data->image_base,
			bl_header_info.bl_image_size);

	return 0;
}

#ifdef IMAGE_BL32
/*******************************************************************************
 * Gets SPSR for BL32 entry
 ******************************************************************************/
static uint32_t ls_get_spsr_for_bl32_entry(void)
{
	/*
	 * The Secure Payload Dispatcher service is responsible for
	 * setting the SPSR prior to entry into the BL32 image.
	 */
	return 0U;
}
#endif


int wagner_bl2_handle_post_image_load(unsigned int image_id)
{
	int err = 0;
	bl_mem_params_node_t *bl_mem_params = get_bl_mem_params_node(image_id);

#ifdef SPD_opteed
//	bl_mem_params_node_t *pager_mem_params = NULL;
//	bl_mem_params_node_t *paged_mem_params = NULL;
#endif /* SPD_opteed */
	assert(bl_mem_params);

	switch (image_id) {
	case BL31_IMAGE_ID:
		set_got_header_info(0); //clear got_header_info
		break;
#if defined(AARCH64)
	case BL32_IMAGE_ID:
#ifdef SPD_opteed
/*
		pager_mem_params = get_bl_mem_params_node(BL32_EXTRA1_IMAGE_ID);
		assert(pager_mem_params);

		paged_mem_params = get_bl_mem_params_node(BL32_EXTRA2_IMAGE_ID);
		assert(paged_mem_params);

		err = parse_optee_header(&bl_mem_params->ep_info,
					 &pager_mem_params->image_info,
					 &paged_mem_params->image_info);
*/

		err = parse_optee_header(&bl_mem_params->ep_info,
					 NULL, NULL);
		if (err != 0)
			WARN("OPTEE header parse error.\n");
#endif /* SPD_opteed */
		bl_mem_params->ep_info.spsr = wagner_get_spsr_for_bl32_entry();
		set_got_header_info(0); //clear got_header_info
		break;
#endif
	case BL33_IMAGE_ID:
		bl_mem_params->ep_info.args.arg0 = VATICS_BL2_MAGIC;
		bl_mem_params->ep_info.args.arg1 = current_bootmode;
		bl_mem_params->ep_info.args.arg2 = spi_attr;
		set_got_header_info(0); //clear got_header_info
		break;
	default:
		/* Do nothing in default case */
		break;
	}

	return err;

}

/*******************************************************************************
 * This function can be used by the platforms to update/use image
 * information for given `image_id`.
 ******************************************************************************/
int bl2_plat_handle_post_image_load(unsigned int image_id)
{
	return wagner_bl2_handle_post_image_load(image_id);
}

int bl2_plat_handle_pre_image_load(unsigned int image_id)
{
	return 0;
}

/*******************************************************************************
 * This function flushes the data structures so that they are visible
 * in memory for the next BL image.
 ******************************************************************************/
void plat_flush_next_bl_params(void)
{
	flush_bl_params_desc();

	if (wagner_TZC_enable)
		wagner_tzc_bl2_dev_finish(current_bootmode);

	WARN("************************\n");
	WARN("* TZC Disable For TEST *\n");
	WARN("************************\n");
	wagner_tzc_disable();

	wagner_clk_init();
}

/*******************************************************************************
 * This function returns the list of loadable images.
 ******************************************************************************/
bl_load_info_t *plat_get_bl_image_load_info(void)
{
	return get_bl_load_info_from_mem_params_desc();
}

/*******************************************************************************
 * This function returns the list of executable images.
 ******************************************************************************/
bl_params_t *plat_get_next_bl_params(void)
{
	return get_next_bl_params_from_mem_params_desc();
}

