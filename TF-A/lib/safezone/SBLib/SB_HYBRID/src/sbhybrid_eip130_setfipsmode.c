/* sbhybrid_eip130_setfipsmode.c
 *
 * Description: Implementation of Secure Boot set FIPS mode API for EIP130
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
#ifndef SBLIB_CF_REMOVE_SETFIPSMODE

#include "basic_defs.h"
#include "device_mgmt.h"
#include "eip130.h"
#include "eip130_token_system.h"
#include "eip130_token_result.h"
#include "sb_setfipsmode.h"              // API to implement

#define EIP130_REMOVE_MAILBOXGETOPTIONS
#define EIP130_REMOVE_MAILBOXACCESSVERIFY
#define EIP130_REMOVE_MAILBOXACCESSCONTROL
#define EIP130_REMOVE_MAILBOXLINK
#define EIP130_REMOVE_MAILBOXLINKRESET
#define EIP130_REMOVE_MAILBOXUNLINK
#define EIP130_REMOVE_MAILBOXCANWRITETOKEN
#define EIP130_REMOVE_MAILBOXRAWSTATUS
#define EIP130_REMOVE_MAILBOXRESET
#define EIP130_REMOVE_MAILBOXLINKID
#define EIP130_REMOVE_MAILBOXOUTID
#define EIP130_REMOVE_WRITEMAILBOXCONTROL
#define EIP130_REMOVE_READMAILBOXSTATUS
#define EIP130_REMOVE_MODULEFIRMWAREWRITTEN
#define EIP130_REMOVE_FIRMWARECHECK
#define EIP130_REMOVE_FIRMWAREDOWNLOAD
#define EIP130_REMOVE_VERSION_OPTION
/*#define EIP130_REMOVE_MODULESTATUS*/
#include "eip130_level0.h"

static SB_Result_t
CheckUsedIdentity(Device_Handle_t Device,
                  Eip130Token_Command_t * pCmd,
                  uint16_t TokenId,
                  const uint32_t COID,
                  Eip130Token_Result_t * pRes)
{
    SB_Result_t sbres;

    /* Get System Information to check Identity */
    Eip130Token_Command_SystemInfo(pCmd);
    Eip130Token_Command_Identity(pCmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
    Eip130Token_Command_SetTokenID(pCmd, TokenId, false);
    sbres = SBHYBRID_EIP130_Common_ProcessToken(Device, pCmd, pRes,
                                                SBLIB_CFG_XM_MAILBOXNR);
    if (sbres == SB_SUCCESS)
    {
        if ((pRes->W[3] & BIT_19) != 0)
        {
            L_DEBUG(LF_SBHYBRID,
                    "ERROR: Expected secure connection with EIP-130.");
            sbres = SB_ERROR_HARDWARE;
        }
        else if (SBLIB_CFG_XM_TOKEN_IDENTITY != COID)
        {
            L_DEBUG(LF_SBHYBRID,
                    "ERROR: SBLIB_CFG_XM_TOKEN_IDENTITY (%d) shall be COID (%d).",
                    SBLIB_CFG_XM_TOKEN_IDENTITY, COID);
            sbres = SB_ERROR_HARDWARE;
        }
    }
    else
    {
        L_DEBUG(LF_SBHYBRID, "ERROR: System Info token failed.");
    }

    return sbres;
}


/*----------------------------------------------------------------------------
 * SB_SetFipsMode
 */
SB_Result_t
SB_SetFipsMode(const uint32_t COID,
               const uint32_t User1,
               const uint32_t User2,
               const uint32_t User3,
               const uint32_t User4)
{
    Device_Handle_t Device_EIP130;
    SB_Result_t sbres;

    sbres = SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
    if (sbres == SB_SUCCESS)
    {
        Eip130Token_Command_t t_cmd;
        Eip130Token_Result_t t_res;
        uint16_t TokenId = 0x5100;
        uint32_t Value;

        while (1)
        {
            Value = EIP130_RegisterReadModuleStatus(Device_EIP130);
            if (((Value & BIT_31) != 0) || ((Value & BIT_10)!= 0))
            {
                /* Error situation active */
                L_DEBUG(LF_SBHYBRID, "ERROR: Hardware error state (0x%X).", (int)Value);
                sbres = SB_ERROR_HARDWARE;
                break;
            }

            if (((Value & BIT_0) == 0) && ((Value & BIT_1) != 0))
            {
                /* Non-FIPS mode active */
                L_DEBUG(LF_SBHYBRID, "Detected non-FIPS mode.");
                sbres = CheckUsedIdentity(Device_EIP130, &t_cmd, TokenId++, COID, &t_res);
                if (sbres == SB_SUCCESS)
                {
                    /* Define Users */
                    Eip130Token_Command_SystemDefineUsers(&t_cmd, User1, User2, User3, User4);
                    Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
                    Eip130Token_Command_SetTokenID(&t_cmd, TokenId++, false);
                    sbres = SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
                                                                &t_cmd, &t_res,
                                                                SBLIB_CFG_XM_MAILBOXNR);
                    if (sbres != SB_SUCCESS)
                    {
                        L_DEBUG(LF_SBHYBRID, "ERROR: Define Users token failed.");
                    }
                }

                if (sbres == SB_SUCCESS)
                {
#ifdef EIP130_ENABLE_SYSTEM_ENTERFIPSMODE
                    /* Perform Enter FIPS mode to switch to FIPS mode */
                    /* Note: Assumes that (Power On) Self-Test has been performed */
                    Eip130Token_Command_EnterFipsMode(&t_cmd);
#else
                    /* Perform Self-test to switch to FIPS mode */
                    Eip130Token_Command_SystemSelfTest(&t_cmd);
#endif
                    Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
                    Eip130Token_Command_SetTokenID(&t_cmd, TokenId++, false);
                    sbres = SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
                                                                &t_cmd, &t_res,
                                                                SBLIB_CFG_XM_MAILBOXNR);
                    Value = EIP130_RegisterReadModuleStatus(Device_EIP130);
                    if ((sbres == SB_SUCCESS) && ((Value & BIT_31) == 0) &&
                        ((Value & BIT_0) != 0) && ((Value & BIT_1) == 0))
                    {
                        L_DEBUG(LF_SBHYBRID, "FIPS mode is set.");
                    }
                    else
                    {
                        L_DEBUG(LF_SBHYBRID,
                                "ERROR: Set FIPS mode failed. (%d, 0x%X)",
                                (int)sbres, Value);
                        sbres = SB_ERROR_HARDWARE; /* make sure error is set */
                    }
                }
                break;
            }

            if (((Value & BIT_0) != 0) && ((Value & BIT_1) == 0))
            {
                /* FIPS mode active */
                L_DEBUG(LF_SBHYBRID, "Detected FIPS mode.");
                sbres = CheckUsedIdentity(Device_EIP130, &t_cmd, TokenId++, COID, &t_res);
                break;
            }

            if ((((Value & BIT_9) != 0) || ((Value & BIT_8) != 0))  &&
                ((Value & BIT_0) == 0) && ((Value & BIT_1) == 0))
            {
                /* Wait for firmware to reach non-FIPS state */
            }
            else
            {
                L_DEBUG(LF_SBHYBRID, "ERROR: Hardware not expected state (0x%X).", (int)Value);
                sbres = SB_ERROR_HARDWARE;
                break;
            }
        }
    }

    SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);
    return sbres;
}

#endif /* !SBLIB_CF_REMOVE_SETFIPSMODE */
#endif /* SBHYBRID_WITH_EIP130 */

/* end of file sbhybrid_eip130_setfipsmode.c */
