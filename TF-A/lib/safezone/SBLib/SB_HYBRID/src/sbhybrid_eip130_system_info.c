/* sbhybrid_eip130_system_info.c
 *
 * Reads EIP130 system info.
 */

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*   Module        : SecureBoot                                               */
/*   Version       : 4.5                                                      */
/*   Configuration : SecureBoot                                               */
/*                                                                            */
/*   Date          : 2023-Feb-14                                              */
/*                                                                            */
/* Copyright (c) 2007-2023 by Rambus, Inc. and/or its subsidiaries.           */
/* All rights reserved. Unauthorized use (including, without limitation,      */
/* distribution and copying) is strictly prohibited. All use requires,        */
/* and is subject to, explicit written authorization and nondisclosure        */
/* agreements with Rambus, Inc. and/or its subsidiaries.                      */
/*                                                                            */
/* For more information or support, please go to our online support system at */
/* https://sipsupport.rambus.com.                                             */
/* In case you do not have an account for this system, please send an e-mail  */
/* to sipsupport@rambus.com.                                                  */
/* -------------------------------------------------------------------------- */

#include "implementation_defs.h"
#include "sbhybrid_internal.h"

#ifdef SBHYBRID_WITH_EIP130
#ifndef SBLIB_CF_REMOVE_SYSTEMINFO_READ

#include "basic_defs.h"
#include "sb_system.h"                  // API to implement
#include "eip130.h"
#include "device_mgmt.h"
#include "eip130_token_common.h"
#include "eip130_token_system.h"


/*----------------------------------------------------------------------------
 * SB_OTP_Read_PublicData
 */
SB_Result_t
SB_SystemInfo_Read(uint32_t * const HWVersion,
                   uint32_t * const FWVersion,
                   uint32_t * const MemSize,
                   uint32_t * const ErrorInfo)
{
    Device_Handle_t Device_EIP130;
    SB_Result_t sbres;

    sbres = SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
    if (sbres == SB_SUCCESS)
    {
        Eip130Token_Command_t t_cmd;
        Eip130Token_Result_t t_res;

        /* Format and process the token */
        Eip130Token_Command_SystemInfo(&t_cmd);
        Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
        Eip130Token_Command_SetTokenID(&t_cmd, 0x5000, false);

        sbres = SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
                                                    &t_cmd, &t_res,
                                                    SBLIB_CFG_XM_MAILBOXNR);
        if (sbres != SB_SUCCESS)
        {
            L_DEBUG(LF_SBHYBRID, "System info command failed.");
        }
        else
        {
            *FWVersion = t_res.W[1];
            *HWVersion = t_res.W[2];
            *MemSize   = (uint16_t)t_res.W[3];
            *ErrorInfo = t_res.W[5];
        }
    }

    SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);

    return sbres;
}

#endif /* !SBLIB_CF_REMOVE_SYSTEMINFO_READ */
#endif /* SBHYBRID_WITH_EIP130 */

/* end of file sbhybrid_eip130_system_info.c */
