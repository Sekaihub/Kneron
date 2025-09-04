// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2000-2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 */

/*
 * Misc boot support
 */
#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/arch/boot_param.h>

static unsigned long do_standalone_exec(ulong (*entry)(u64, u64, u64, u64),
					u64 arg0,
					u64 arg1,
					u64 arg2,
					u64 arg3)
{
	cleanup_before_linux();
	return entry(arg0, arg1, arg2, arg3);
}

static int do_standalone(struct cmd_tbl *cmdtp, int flag,
			 int argc, char *const argv[])
{
	ulong	addr, rc;
	int     rcode = 0;

	if (argc < 2)
		return CMD_RET_USAGE;

	addr = hextoul(argv[1], NULL);

	printf("## Starting application at 0x%08lX ...\n", addr);

	/*
	 * pass address parameter as argv[0] (aka command name),
	 * and all remaining args
	 */
	rc = do_standalone_exec((void *)addr,
				tfa_boot_args[ARG_MAGIC],
				tfa_boot_args[ARG_BOOTMODE],
				tfa_boot_args[ARG_SPI_PARAM],
				tfa_boot_args[3]
				);
	if (rc != 0)
		rcode = 1;

	printf("## Application terminated, rc = 0x%lX\n", rc);
	return rcode;
}

/* -------------------------------------------------------------------- */

U_BOOT_CMD(
	go_standalone, CONFIG_SYS_MAXARGS, 1,	do_standalone,
	"start application at address 'addr'",
	"addr [arg ...]\n    - start application at address 'addr'\n"
	"      passing 'arg' as arguments"
);
