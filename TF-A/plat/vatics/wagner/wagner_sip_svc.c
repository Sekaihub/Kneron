/*
 * Copyright (c) 2016-2023, Vatics Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include <common/debug.h>
#include <common/runtime_svc.h>
#include <tools_share/uuid.h>
#include "wagner_private.h"
#include "vtx_sip_svc.h"

extern bool    wagner_PMU_disable;

/* WAGNER SiP Service UUID */
DEFINE_SVC_UUID2(vtx_sip_svc_uid,
	0xd90e2107, 0x2bb0, 0x4250, 0x9b, 0xf3,
	0x01, 0xef, 0xbc, 0x11, 0xf7, 0x56);

/*
 * This function handles WAGNER defined SiP Calls
 */
static uintptr_t wagner_sip_handler(unsigned int smc_fid,
			u_register_t x1,
			u_register_t x2,
			u_register_t x3,
			u_register_t x4,
			void *cookie,
			void *handle,
			u_register_t flags)
{
	switch (smc_fid) {
	case VTX_SIP_SVC_CALL_COUNT:
		SMC_RET1(handle, VTX_PLAT_SIP_NUM_CALLS);

	case VTX_SIP_SVC_UID:
		/* Return UID to the caller */
		SMC_UUID_RET(handle, vtx_sip_svc_uid);

	case VTX_SIP_SVC_VERSION:
		/* Return the version of current implementation */
		SMC_RET2(handle, VTX_SIP_SVC_VERSION_MAJOR,
				VTX_SIP_SVC_VERSION_MINOR);

	case VTX_SIP_SVC_SETBOOTDONE:
		wagner_clear_wdt_flag();
		SMC_RET0(handle);

	case VTX_SIP_SVC_CLEARBOOTDONE:
		wagner_set_wdt_flag();
		SMC_RET0(handle);

	case VTX_SIP_GET_PMU_GPR:
		if (wagner_PMU_disable) {
			SMC_RET1(handle, wagner_get_wdt_flag());
		} else {
			SMC_RET1(handle, read_pmu_reg(0x08));
		}

	default:
		break;
	}

	WARN("Unimplemented Leipzig SiP Service Call: 0x%x\n", smc_fid);
	SMC_RET1(handle, SMC_UNK);
}


/* Define a runtime service descriptor for fast SMC calls */
DECLARE_RT_SVC(
	wagner_sip_svc,
	OEN_SIP_START,
	OEN_SIP_END,
	SMC_TYPE_FAST,
	NULL,
	wagner_sip_handler
);
