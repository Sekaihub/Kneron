// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (C) 2016 The Android Open Source Project
 */

#include <drivers/vatics/usb/fastboot.h>
#include <drivers/vatics/usb/fastboot-internal.h>
#include <stdlib.h>
#include <stdio.h>
#include <common/debug.h>
#include <wagner_buf.h>
#include <wagner_log.h>

#define putc putchar
#define pr_err ERROR

/**
 * image_size - final fastboot image size
 */
static u32 image_size;
u32	android_header_received;

#ifdef IMAGE_BL2
#define fastboot_bytes_received \
		overlaid_bufferp->usb_buf.fastboot_bytes_received

#define fastboot_bytes_expected \
		overlaid_bufferp->usb_buf.fastboot_bytes_expected
#else
/**
 * fastboot_bytes_received - number of bytes received in the current download
 */
//static u32 fastboot_bytes_received;
#define fastboot_bytes_received overlaid_buffer.usb_buf.fastboot_bytes_received

/**
 * fastboot_bytes_expected - number of bytes expected in the current download
 */
//static u32 fastboot_bytes_expected;
#define fastboot_bytes_expected overlaid_buffer.usb_buf.fastboot_bytes_expected
#endif

static void okay(char *, char *);
static void download(char *, char *);

#ifdef IMAGE_BL2
static void reboot_bootloader(char *, char *);
static void reboot_fastbootd(char *, char *);
static void reboot_recovery(char *, char *);
#endif

static void getvar(char *, char *);

#ifdef FASTBOOT_UUU_SUPPORT
static void run_ucmd(char *, char *);
static void run_acmd(char *, char *);
#endif

static const struct {
	const char *command;
	void (*dispatch)(char *cmd_parameter, char *response);
} commands[FASTBOOT_COMMAND_COUNT] = {
	[FASTBOOT_COMMAND_GETVAR] = {
		.command = "getvar",
		.dispatch = getvar
	},
	[FASTBOOT_COMMAND_DOWNLOAD] = {
		.command = "download",
		.dispatch = download
	},
	[FASTBOOT_COMMAND_BOOT] =  {
		.command = "boot",
		.dispatch = okay
	},
	[FASTBOOT_COMMAND_CONTINUE] =  {
		.command = "continue",
		.dispatch = okay
	},
	[FASTBOOT_COMMAND_REBOOT] =  {
		.command = "reboot",
		.dispatch = okay
	},
#ifdef IMAGE_BL2
	[FASTBOOT_COMMAND_REBOOT_BOOTLOADER] =  {
		.command = "reboot-bootloader",
		.dispatch = reboot_bootloader
	},
	[FASTBOOT_COMMAND_REBOOT_FASTBOOTD] =  {
		.command = "reboot-fastboot",
		.dispatch = reboot_fastbootd
	},
	[FASTBOOT_COMMAND_REBOOT_RECOVERY] =  {
		.command = "reboot-recovery",
		.dispatch = reboot_recovery
	},
#endif
	[FASTBOOT_COMMAND_SET_ACTIVE] =  {
		.command = "set_active",
		.dispatch = okay
	},
#ifdef FASTBOOT_UUU_SUPPORT
	[FASTBOOT_COMMAND_UCMD] = {
		.command = "UCmd",
		.dispatch = run_ucmd,
	},
	[FASTBOOT_COMMAND_ACMD] = {
		.command = "ACmd",
		.dispatch = run_acmd,
	},
#endif
};

/**
 * fastboot_handle_command - Handle fastboot command
 *
 * @cmd_string: Pointer to command string
 * @response: Pointer to fastboot response buffer
 *
 * Return: Executed command, or -1 if not recognized
 */
int fastboot_handle_command(char *cmd_string, char *response)
{
	int i;
	char *cmd_parameter;

	INFO("fb cmd :%s\n",cmd_string);
	strtok_r(cmd_string, ":", &cmd_parameter);

	for (i = 0; i < FASTBOOT_COMMAND_COUNT; i++) {
		if (!strcmp(commands[i].command, cmd_string)) {
			if (commands[i].dispatch) {
				commands[i].dispatch(cmd_parameter, response);
				return i;
			} else {
				break;
			}
		}
	}

	pr_err("command %s not recognized.\n", cmd_string);
	wagner_err(WAGNER_ERR_USB_FBCMD);
	fastboot_fail("unrecognized command", response);
	return -1;
}

/**
 * okay() - Send bare OKAY response
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 *
 * Send a bare OKAY fastboot response. This is used where the command is
 * valid, but all the work is done after the response has been sent (e.g.
 * boot, reboot etc.)
 */
static void okay(char *cmd_parameter, char *response)
{
	fastboot_okay(NULL, response);
}

/**
 * getvar() - Read a config/version variable
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void getvar(char *cmd_parameter, char *response)
{
	fastboot_getvar(cmd_parameter, response);
}

/**
 * fastboot_download() - Start a download transfer from the client
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void download(char *cmd_parameter, char *response)
{
	char *tmp;

	if (!cmd_parameter) {
		ERROR("FB: Expected command parameter\n");
		fastboot_fail("Expected command parameter", response);
		return;
	}
	fastboot_bytes_received = 0;
	android_header_received = 0;
	fastboot_bytes_expected = strtoul(cmd_parameter, &tmp, 16);
	if (fastboot_bytes_expected == 0) {
		ERROR("FB: Expected nonzero image size\n");
		fastboot_fail("Expected nonzero image size", response);
		return;
	}
	/*
	 * Nothing to download yet. Response is of the form:
	 * [DATA|FAIL]$cmd_parameter
	 *
	 * where cmd_parameter is an 8 digit hexadecimal number
	 */
	if (fastboot_bytes_expected > fastboot_buf_size) {
		ERROR("FB: bytes_expected(%d) > buf_size(%d)\n",
				fastboot_bytes_expected, fastboot_buf_size);
		fastboot_fail(cmd_parameter, response);
	} else {
		INFO("Starting download of %d bytes\n",
		       fastboot_bytes_expected);
		fastboot_response("DATA", response, "%s", cmd_parameter);
	}
}

/**
 * fastboot_data_remaining() - return bytes remaining in current transfer
 *
 * Return: Number of bytes left in the current download
 */
u32 fastboot_data_remaining(void)
{
	return fastboot_bytes_expected - fastboot_bytes_received;
}

/**
 * fastboot_data_download() - Copy image data to fastboot_buf_addr.
 *
 * @fastboot_data: Pointer to received fastboot data
 * @fastboot_data_len: Length of received fastboot data
 * @response: Pointer to fastboot response buffer
 *
 * Copies image data from fastboot_data to fastboot_buf_addr. Writes to
 * response. fastboot_bytes_received is updated to indicate the number
 * of bytes that have been transferred.
 *
 * On completion sets image_size and ${filesize} to the total size of the
 * downloaded image.
 */
void fastboot_data_download(const void *fastboot_data,
			    unsigned int fastboot_data_len,
			    char *response)
{
#if LOG_LEVEL >= LOG_LEVEL_INFO
#define BYTES_PER_DOT	0x20000
	u32 pre_dot_num, now_dot_num;
#endif

	if (fastboot_data_len == 0 ||
	    (fastboot_bytes_received + fastboot_data_len) >
	    fastboot_bytes_expected) {
		fastboot_fail("Received invalid data length",
			      response);
		return;
	}

#ifndef IMAGE_BL2
	/* Download data to fastboot_buf_addr */
	memcpy(fastboot_buf_addr + fastboot_bytes_received,
	       fastboot_data, fastboot_data_len);
#else
	u32 skip_size = 0;

	if (android_header_received < USB_FB_HEADER_SIZE) {
		skip_size = min(USB_FB_HEADER_SIZE - android_header_received,
				fastboot_data_len);
	}

	/* Download data to fastboot_buf_addr */
	memcpy(fastboot_buf_addr + fastboot_bytes_received -
				android_header_received,
	       fastboot_data + skip_size,
	       fastboot_data_len - skip_size);

	android_header_received += skip_size;
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
	pre_dot_num = fastboot_bytes_received / BYTES_PER_DOT;
#endif

	fastboot_bytes_received += fastboot_data_len;

#if LOG_LEVEL >= LOG_LEVEL_INFO
	now_dot_num = fastboot_bytes_received / BYTES_PER_DOT;
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
	if (pre_dot_num != now_dot_num) {
		putc('.');
		if (!(now_dot_num % 74))
			putc('\n');
	}
#endif
	DBGUSB("Received: %d\n", fastboot_bytes_received);
	*response = '\0';
}

/**
 * fastboot_data_complete() - Mark current transfer complete
 *
 * @response: Pointer to fastboot response buffer
 *
 * Set image_size and ${filesize} to the total size of the downloaded image.
 */
uint32_t fastboot_data_complete(char *response)
{
	/* Download complete. Respond with "OKAY" */
	fastboot_okay(NULL, response);
	DBGUSB("\ndownloading of %d bytes finished\n", fastboot_bytes_received);
	image_size = fastboot_bytes_received;
	//env_set_hex("filesize", image_size);
	fastboot_bytes_expected = 0;
	fastboot_bytes_received = 0;
	android_header_received = 0;
	return image_size;
}

#ifdef FASTBOOT_UUU_SUPPORT
/**
 * run_ucmd() - Execute the UCmd command
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void run_ucmd(char *cmd_parameter, char *response)
{
	if (!cmd_parameter) {
		pr_err("missing slot suffix\n");
		fastboot_fail("missing command", response);
		return;
	}

	if (run_command(cmd_parameter, 0))
		fastboot_fail("", response);
	else
		fastboot_okay(NULL, response);
}

static char g_a_cmd_buff[64];

void fastboot_acmd_complete(void)
{
	run_command(g_a_cmd_buff, 0);
}

/**
 * run_acmd() - Execute the ACmd command
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void run_acmd(char *cmd_parameter, char *response)
{
	if (!cmd_parameter) {
		pr_err("missing slot suffix\n");
		fastboot_fail("missing command", response);
		return;
	}

	if (strlen(cmd_parameter) > sizeof(g_a_cmd_buff)) {
		pr_err("too long command\n");
		fastboot_fail("too long command", response);
		return;
	}

	strcpy(g_a_cmd_buff, cmd_parameter);
	fastboot_okay(NULL, response);
}
#endif

#ifdef IMAGE_BL2
/**
 * reboot_bootloader() - Sets reboot bootloader flag.
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void reboot_bootloader(char *cmd_parameter, char *response)
{
	if (fastboot_set_reboot_flag(FASTBOOT_REBOOT_REASON_BOOTLOADER))
		fastboot_fail("Cannot set reboot flag", response);
	else
		fastboot_okay(NULL, response);
}

/**
 * reboot_fastbootd() - Sets reboot fastboot flag.
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void reboot_fastbootd(char *cmd_parameter, char *response)
{
	if (fastboot_set_reboot_flag(FASTBOOT_REBOOT_REASON_FASTBOOTD))
		fastboot_fail("Cannot set fastboot flag", response);
	else
		fastboot_okay(NULL, response);
}

/**
 * reboot_recovery() - Sets reboot recovery flag.
 *
 * @cmd_parameter: Pointer to command parameter
 * @response: Pointer to fastboot response buffer
 */
static void reboot_recovery(char *cmd_parameter, char *response)
{
	if (fastboot_set_reboot_flag(FASTBOOT_REBOOT_REASON_RECOVERY))
		fastboot_fail("Cannot set recovery flag", response);
	else
		fastboot_okay(NULL, response);
}

#endif

