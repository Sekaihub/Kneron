/* SPDX-License-Identifier: GPL-2.0-only
 *
 * VTX Secure Monitor driver
 *
 * Copyright (C) 2024 Kneron, Inc.
 * Author: Jun Chen <jun.chen@kneron.us>
 */

#ifndef __VTX_SIP_SMC_H
#define __VTX_SIP_SMC_H

/* SMC function IDs for SiP Service queries */

#define VTX_SIP_SVC_CALL_COUNT          0x8200ff00
#define VTX_SIP_SVC_UID                 0x8200ff01
/*                                      0x8200ff02 is reserved */
#define VTX_SIP_SVC_VERSION             0x8200ff03
/* VTX */
#define VTX_SIP_SVC_SETBOOTDONE         0x82000101
#define VTX_SIP_SVC_CLEARBOOTDONE       0x82000102
#define VTX_SIP_GET_PMU_GPR             0x82000103

#endif
