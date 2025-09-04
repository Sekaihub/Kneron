#ifndef __VPL_WDT_H__
#define __VPL_WDT_H__

#include <platform_def.h>

#define VPL_WDTC_OFFSET_VERSION			(VPL_WDTC_BASE + 0x00)
#define VPL_WDTC_OFFSET_CTRL			(VPL_WDTC_BASE + 0x04)
#define VPL_WDTC_OFFSET_STAT			(VPL_WDTC_BASE + 0x08)
#define VPL_WDTC_OFFSET_COUNT			(VPL_WDTC_BASE + 0x0C)
#define VPL_WDTC_OFFSET_RELOAD_VALUE		(VPL_WDTC_BASE + 0x10)
#define VPL_WDTC_OFFSET_MATCH_VALUE		(VPL_WDTC_BASE + 0x14)
#define VPL_WDTC_OFFSET_RELOAD_CTRL		(VPL_WDTC_BASE + 0x18)
#define VPL_WDTC_OFFSET_RST_LEN			(VPL_WDTC_BASE + 0x1C)

#define VPL_WDTC_RELOAD_PASSWD			0x28791166

#define VPL_WDTC_CTRL_OP_EN			0x4
#define VPL_WDTC_CTRL_ACK_EN			0x2
#define VPL_WDTC_CTRL_ACK			0x1

#define	VPL_WDTC_RESET_LEN			0xFFFF

int vpl_wdt_start(unsigned int sec);
int vpl_wdt_stop(void);
int vpl_wdt_ping(void);
int vpl_wdt_set_timeout(unsigned int sec);
#endif
