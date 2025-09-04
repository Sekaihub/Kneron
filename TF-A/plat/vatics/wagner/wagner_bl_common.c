/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <common/debug.h>
#include <drivers/delay_timer.h>
#include <lib/mmio.h>
#include <lib/utils.h>
#include <tools_share/uuid.h>

#include <drivers/vatics/wdt.h>
#include <dt-bindings/clock/kl730-clk.h>
#include "wagner_private.h"

extern	bool    wagner_PMU_disable;
extern void memcpy16(void *dest, const void *src, unsigned int length);
static const uuid_t wdt_boot_uuid = WAGNER_WDT_BOOT_UUID;

void wagner_clk_init(void)
{
	kl730_clk_init();
}

void wagner_pmu_init(void)
{
#if 0
	/* clear np_xo_abb_dig_START bit in PMIC_CLK_TOP_CTRL7 register */
	mmio_clrbits_32(PMU_SSI0_CLK_TOP_CTRL7_REG, NP_XO_ABB_DIG);
#endif
}

static void set_vcodec_power_up(void)
{
}

static void set_vdec_power_up(void)
{
}

static void set_venc_power_up(void)
{
}

static void set_isp_power_up(void)
{
}


static void set_audio_power_up(void)
{
}


static void set_isp_srt_power_up(void)
{
}

void wagner_regulator_enable(void)
{
#if 1
	set_vcodec_power_up();
	set_vdec_power_up();
	set_venc_power_up();
	set_isp_power_up();
	set_audio_power_up();
	set_isp_srt_power_up();

#endif
}

void wagner_enable_q7_sram(void)
{
#if WAGNER_FPGA == 0
	/*Halt DSP(RunStallOnReset = 1)*/
	mmio_write_32(VQ7U_SRAM_BASE + 0x800004, 0x1 << 1);
#endif
	/*release reset*/
	mmio_write_32(SYSC_S_BASE + SYSC_RST_RELEASE_SET_REG_4, 0x1 << 19);
}

void wagner_peri_init(void)
{
}

void *wagner_memcpy(void *dest, const void *src, unsigned int length)
{
	if ((((uintptr_t)dest | (uintptr_t)src) & 0xf)
			| (length < 16))
		memcpy(dest, src, length);
	else
		memcpy16(dest, src, length);

	return dest;
}


void wagner_pinmux_init(void)
{
#if ENABLE_UART_PIN == 1
	/************************/
	/*	Enable UART	*/
	/************************/
	// disable share pin GPIO 0 [23:22] (PAD 0)
	// status : bus_o_data_ro_030 (0x78)
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_0, 0x3<<22);
	// enable uart 0 location 0 section 0, reg_7 bit_0
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_SET_REG_7, 0x1);
#endif

}
void wagner_eqosc_pinmux_init(void)
{
	/*EQOSC*/
	/*clear VOC*/
	/*voc1 sec0: pad8 bit 16
	 * voc1 sec3 loc0: pad8 bit 20
	 * voc1 sec1: pad8 bit 17
	 * voc1 sec2 loc 0: pad8 bit 18
	 * voc1 sec4: pad8 bit 22
	 * voc1 sec7 loc0 : pad8 bit 25
	 * voc1 clk loc0: pad8 bit 14
	 * voc1 sec2 loc1: pad8 bit 19
	 */
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_8, 0x005F4000);

	/*clear GPIO1 0~17*/
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_1, 0x0003FFFF);

	/*clear AGPO LOC4 0~11 Pad 5*/
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_5, 0x00000FFF);

	/*enable eqosc*/
	/*Pad 6 bit 3~10*/
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_SET_REG_6, 0x000007F8);
}

void wagner_mshc_pinmux_init(void)
{
	/*MSHC*/
	/* All MSHC pinmux settings default to MSHC,
	 * except for SD_0_I_WP, which is set to GPIO_1_io_D[19].
	 * This function clear GPIO_1_io_D[19] to maintain consistency
	 * across all MSHC pin settings before handing them over to
	 * the next stage.*/

	/*clear GPIO1 bit 19*/
	mmio_write_32(SYSC_S_BASE + SYSC_PAD_EN_CLR_REG_1, (0x1<<19));
}

void wagner_gpio_init(void)
{

}

/* ------------------------------------------------------------ */
/* wagner_get_wdt_flag(), Check Watchdog Reset Flag		*/
/* retuen 0: normal reset					*/
/*	  1: watchdog reset (means boot fail, also clear mem)	*/
/* ------------------------------------------------------------ */
bool wagner_get_wdt_flag(void)
{
#ifdef IMAGE_BL1
	if (wagner_PMU_disable) {	// use SRAM
		if (memcmp((void *)WAGNER_WDT_BOOT_ADDR, (void *)&wdt_boot_uuid,
					sizeof(wdt_boot_uuid)) == 0) {
			zeromem((void *)WAGNER_WDT_BOOT_ADDR,
					sizeof(wdt_boot_uuid));
			mmio_setbits_32(SYSC_S_BASE + SYSC_CORE0_SPIN,
					WATCHDOG_STATUS_BIT);
			return 1;
		}
	} else {	// use PMU
		return(!!(mmio_read_32(SYSC_S_BASE + SYSC_CORE0_SPIN)
					& WATCHDOG_STATUS_BIT));
	}
	return 0;
#else
	return(!!(mmio_read_32(SYSC_S_BASE + SYSC_CORE0_SPIN)
					& WATCHDOG_STATUS_BIT));
#endif
}


void wagner_set_wdt_flag(void)
{
	if (wagner_PMU_disable) {	// use SRAM
		wagner_memcpy((void *)WAGNER_WDT_BOOT_ADDR,
				(void *)&wdt_boot_uuid,
				sizeof(wdt_boot_uuid));
	} else {	// use PMU (gpr ofs = 0x08)
			// Only cold boot BL1 use this function
			// readback is not necessary
		write_pmu_reg(0x08, WATCHDOG_STATUS_BIT);
	}
}


void wagner_clear_wdt_flag(void)
{
	if (wagner_PMU_disable) {	// use SRAM
		zeromem((void *)WAGNER_WDT_BOOT_ADDR,
				sizeof(wdt_boot_uuid));
	} else {	// use PMU (gpr ofs = 0x08)
			// Only cold boot use this function
			// readback is not necessary
		write_pmu_reg(0x08, 0);
	}
	mmio_clrbits_32(SYSC_S_BASE + SYSC_CORE0_SPIN,
			WATCHDOG_STATUS_BIT);
}

void wagner_get_boot_select(bootselect_t *bootselect)
{
	bool	flag_boot_fail = wagner_get_wdt_flag();
	unsigned int reg_boot_sel =
		mmio_read_32(WAGNER_BOOTMODE_ADDR) & SYSC_BOOT_MODE_MASK;

	bootselect->boot_2nd = (reg_boot_sel & SYSC_NORMAL_MODE_MASK);
	if ((reg_boot_sel & SYSC_ENGINEER_FIRST_DISABLE) == 0) {
	// Engineer Boot First
		VERBOSE("Engineer First\n");
		bootselect->boot_1st =
			(reg_boot_sel & SYSC_ENGINEER_MODE_MASK);
	} else { // Normal Boot First
		bootselect->boot_1st = BOOT_BYPASS;
		if ((reg_boot_sel & SYSC_TBBR_ENABLE) == 0) {
		// Normal -> Engineer
			if (flag_boot_fail == 0) {
				wagner_set_wdt_flag();
				vpl_wdt_set_timeout(NORMAL_FIRST_TIMEOUT);
				VERBOSE("Normal First\n");
			} else {	// Boot fail from watchdog
				VERBOSE("Normal Fail\n");
				if (bootselect->boot_2nd != BOOT_MSHC0_MMC8)
					bootselect->boot_1st =
						BOOT_MSHC0_SD;
				bootselect->boot_2nd =
					reg_boot_sel & SYSC_ENGINEER_MODE_MASK;
			}
		} else { // SYSC_TBBR_ENABLE == 1
			if ((reg_boot_sel & SYSC_TBBR_RECOVERY) == 0) {
				if (flag_boot_fail == 0) {
					wagner_set_wdt_flag();
					VERBOSE("TBBR Normal\n");
				} else { // Boot fail from watchdog
					VERBOSE("TBBR Recovery\n");
					bootselect->boot_2nd = RECOVERY_TBBR;
				}
			} else { // SYSC_TBBR_RECOVERY == 1
				VERBOSE("TBBR Recovery\n");
				bootselect->boot_2nd = RECOVERY_TBBR;
			}
		}
	}
}
