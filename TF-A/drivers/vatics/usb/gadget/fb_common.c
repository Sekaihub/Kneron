// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2008 - 2009
 * Windriver, <www.windriver.com>
 * Tom Rix <Tom.Rix@windriver.com>
 *
 * Copyright 2011 Sebastian Andrzej Siewior <bigeasy@linutronix.de>
 *
 * Copyright 2014 Linaro, Ltd.
 * Rob Herring <robh@kernel.org>
 */

#include <drivers/vatics/usb/fastboot.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * fastboot_buf_addr - base address of the fastboot download buffer
 */
void *fastboot_buf_addr;

/**
 * fastboot_buf_size - size of the fastboot download buffer
 */
u32 fastboot_buf_size;

/**
 * fastboot_response() - Writes a response of the form "$tag$reason".
 *
 * @tag: The first part of the response
 * @response: Pointer to fastboot response buffer
 * @format: printf style format string
 */
void fastboot_response(const char *tag, char *response,
		       const char *format, ...)
{
	va_list args;

	strlcpy(response, tag, FASTBOOT_RESPONSE_LEN);
	if (format) {
		va_start(args, format);
		vsnprintf(response + strlen(response),
			  FASTBOOT_RESPONSE_LEN - strlen(response) - 1,
			  format, args);
		va_end(args);
	}
}

/**
 * fastboot_fail() - Write a FAIL response of the form "FAIL$reason".
 *
 * @reason: Pointer to returned reason string
 * @response: Pointer to fastboot response buffer
 */
void fastboot_fail(const char *reason, char *response)
{
	fastboot_response("FAIL", response, "%s", reason);
}

/**
 * fastboot_okay() - Write an OKAY response of the form "OKAY$reason".
 *
 * @reason: Pointer to returned reason string, or NULL to send a bare "OKAY"
 * @response: Pointer to fastboot response buffer
 */
void fastboot_okay(const char *reason, char *response)
{
	if (reason)
		fastboot_response("OKAY", response, "%s", reason);
	else
		fastboot_response("OKAY", response, NULL);
}

#pragma weak fastboot_set_reboot_flag

/**
 * fastboot_set_reboot_flag() - Set flag to indicate reboot-bootloader
 *
 * Set flag which indicates that we should reboot into the bootloader
 * following the reboot that fastboot executes after this function.
 *
 * This function should be overridden in your board file with one
 * which sets whatever flag your board specific Android bootloader flow
 * requires in order to re-enter the bootloader.
 */
int fastboot_set_reboot_flag(enum fastboot_reboot_reason reason)
{
#if (FASTBOOT_FLASH_MMC_DEV)
	static const char * const boot_cmds[] = {
		[FASTBOOT_REBOOT_REASON_BOOTLOADER] = "bootonce-bootloader",
		[FASTBOOT_REBOOT_REASON_FASTBOOTD] = "boot-fastboot",
		[FASTBOOT_REBOOT_REASON_RECOVERY] = "boot-recovery"
	};

	if (reason >= FASTBOOT_REBOOT_REASONS_COUNT)
		return -EINVAL;

	return bcb_write_reboot_reason(CONFIG_FASTBOOT_FLASH_MMC_DEV, "misc", boot_cmds[reason]);
#else
    return -EINVAL;
#endif
}

/*
 * fastboot_init() - initialise new fastboot protocol session
 *
 * @buf_addr: Pointer to download buffer, or NULL for default
 * @buf_size: Size of download buffer, or zero for default
 */
void fastboot_init(void *buf_addr, u32 buf_size)
{
	fastboot_buf_addr = buf_addr;
	fastboot_buf_size = buf_size;
}
