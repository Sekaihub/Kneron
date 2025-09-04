/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <lib/mmio.h>
#include <platform_def.h>

#define SHOWSTEP 0

static __unused void string_print(const char *str)
{
	assert(str != NULL);

	for ( ; *str != '\0'; str++) {
		(void)putchar(*str);
	}
}

static __unused void unsigned_num_print(unsigned long long int unum,
					unsigned int radix)
{
	/* Just need enough space to store 64 bit decimal integer */
	char num_buf[20];
	int i = 0;
	unsigned int rem;

	/* num_buf is only large enough for radix >= 10 */
	if (radix < 10) {
		assert(0);
		return;
	}

	do {
		rem = unum % radix;
		if (rem < 0xa)
			num_buf[i] = '0' + rem;
		else
			num_buf[i] = 'a' + (rem - 0xa);
		i++;
		unum /= radix;
	} while (unum > 0U);

	while (--i >= 0) {
		(void)putchar(num_buf[i]);
	}
}

#if LOG_LEVEL > 0
//Use complex tf-a log for development
void wagner_log_init(void)
{
	//empty
}

void wagner_err(uint32_t err_no)
{
	//empty
}

void wagner_bootstep(uint8_t step_no)
{
	//empty
}

void wagner_log_ep_addr(uint8_t step_no, uintptr_t addr)
{
	//empty
}

void wagner_log_bootselect(uint8_t sel1, uint8_t sel2)
{
	//empty
}

#else	// LOG_LEVEL == 0
//Use simple wagner log for release
void wagner_log_init(void)
{
	uint32_t err_no;

	err_no = mmio_read_32(WAGNER_BOOTERR_ADDR);
	err_no = err_no << 16;
	mmio_write_32(WAGNER_BOOTERR_ADDR, err_no); //Err backup & clear
	memcpy((void *)WAGNER_BACKUPSTEP_ADDR,
		(void *)WAGNER_BOOTSTEP_ADDR, 8); //Step backup
	mmio_write_64(WAGNER_BOOTSTEP_ADDR, 0); //Step clear
}

void wagner_bootstep(uint8_t step_no)
{
	uint64_t steps;

	steps = mmio_read_64(WAGNER_BOOTSTEP_ADDR);
	steps = ((steps << 8) | step_no);
	mmio_write_64(WAGNER_BOOTSTEP_ADDR, steps);
#if SHOWSTEP
	string_print("\rROM: ");
	unsigned_num_print(step_no, 10);
	string_print("  "); //clear 2 space
#endif
}

void wagner_err(uint16_t err_no)
{
	mmio_write_16(WAGNER_BOOTERR_ADDR, err_no);
	string_print("\nERR(");
	unsigned_num_print(err_no, 10);
	string_print(")\n");
}

void wagner_log_ep_addr(uint8_t step_no, uintptr_t addr)
{
	/* Pass all steps, log next ep address */
	uint64_t steps;

	steps = mmio_read_64(WAGNER_BOOTSTEP_ADDR);
	steps = ((steps << 8) | step_no);
	steps = ((steps << 32) | (uint32_t)addr);
	mmio_write_64(WAGNER_BOOTSTEP_ADDR, steps);
}

void wagner_log_bootselect(uint8_t sel1, uint8_t sel2)
{
#if ENABLE_UART_PIN == 1
	/* Boot select already store in SRAM, just print it */
#if SHOWSTEP
	string_print("\r(");
#endif //SHOWSTEP
	unsigned_num_print(sel1, 10);
	(void)putchar(',');
	unsigned_num_print(sel2, 10);
#if SHOWSTEP
#if (ENABLE_WATCHDOG == 1)
	string_print(",WDT)\n");
#else
	string_print(")\n");
#endif //ENABLE_WATCHDOG
#else
	(void)putchar('\n');
#endif //SHOWSTEP
#endif //ENABLE_UART_PIN
}

#endif
