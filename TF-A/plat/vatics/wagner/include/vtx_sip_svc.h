/*
 * Copyright (c) 2016-2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef VTX_SIP_SVC_H
#define VTX_SIP_SVC_H

/* SMC function IDs for SiP Service queries */
#define VTX_PLAT_SIP_NUM_CALLS		6	//available service calls.
#define VTX_SIP_SVC_CALL_COUNT		0x8200ff00
#define VTX_SIP_SVC_UID			0x8200ff01
/*					0x8200ff02 is reserved */
#define VTX_SIP_SVC_VERSION		0x8200ff03
/* VTX */
#define VTX_SIP_SVC_SETBOOTDONE		0x82000101
#define VTX_SIP_SVC_CLEARBOOTDONE	0x82000102
#define VTX_SIP_GET_PMU_GPR		0x82000103

/* HISI SiP Service Calls version numbers */
#define VTX_SIP_SVC_VERSION_MAJOR		0x0
#define VTX_SIP_SVC_VERSION_MINOR		0x1

#endif /* HISI_SIP_SVC_H */
