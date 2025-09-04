/* sbhybrid_eip130_publicdata.c
 *
 * Description: Implementation of Secure Boot Public Data API for EIP130
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
#ifndef SBLIB_CF_REMOVE_PUBLICDATA

#include "basic_defs.h"
#include "sbif_attributes.h"
#include "sb_publicdata.h"              // API to implement

#include "eip130.h"
#include "device_mgmt.h"
#include "dmares_mgmt.h"
#include "dmares_buf.h"
#include "dmares_addr.h"
#include "dmares_rw.h"
#include "eip130_token_common.h"
#include "eip130_token_asset.h"
#include "eip130_token_publicdata.h"
#include "eip130_token_result.h"

// For tracing/debugging purpose, dump the command and result tokens
//#define TOKENS_VERBOSE

// Types locally used for clarity.
typedef uint32_t assetid_t;


/*----------------------------------------------------------------------------
 * SBHYBRID_PublicData_ReadData
 *
 * This function reads the Public Data from the SM into the buffer within the
 * context and returns the length of the OTP data.
 */
static SB_Result_t
SBHYBRID_PublicData_ReadData(const Device_Handle_t Device_EIP130,
                             const assetid_t AssetId,
                             uint8_t * Data_p,
                             const uint32_t DataLen)
{
    Eip130Token_Command_t t_cmd;
    Eip130Token_Result_t t_res;
    DMAResource_Properties_t Props = { 0, 0, 0, 0 };
    DMAResource_AddrPair_t AddrPair;
    DMAResource_Handle_t DMAHandle;
    uint64_t DataAddr;
    SB_Result_t sbres = SB_ERROR_HARDWARE;
    int res;

    // Get the DMA address of the data (DMA handle)
    Props.Alignment = 4;
    Props.Size = ((DataLen + 3) & ~3U);

    AddrPair.Domain = DMARES_DOMAIN_HOST;
    AddrPair.Address.Native_p = Data_p;

    res = DMAResource_CheckAndRegister(Props, AddrPair, 'R', &DMAHandle);
    if (res != 0)
    {
        return sbres;
    }

    res = DMAResource_Translate(DMAHandle, DMARES_DOMAIN_EIP13xDMA, &AddrPair);
    if (res != 0)
    {
        return sbres;
    }
    DataAddr = AddrPair.Address.Value64;

    // Format and process token
    Eip130Token_Command_PublicData_Read(&t_cmd, AssetId, DataAddr, DataLen);
    Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
    Eip130Token_Command_SetTokenID(&t_cmd, 0x5011, false);

    sbres = SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
                                                &t_cmd, &t_res,
                                                SBLIB_CFG_XM_MAILBOXNR);
    if (sbres != SB_SUCCESS)
    {
        res = Eip130Token_Result_Code(&t_res);
        if ((res == EIP130TOKEN_RESULT_INVALID_ASSET) ||
            (res == EIP130TOKEN_RESULT_ACCESS_ERROR))
        {
            sbres = SB_ERROR_ARGUMENTS;
        }

        L_DEBUG(LF_SBHYBRID, "SBHYBRID_PublicData_ReadData failed (%d, %d).",
                res, sbres);
    }

    // Release DMA handle
    DMAResource_Release(DMAHandle);

    return sbres;
}


/*----------------------------------------------------------------------------
 * SBHYBRID_PublicData_Search
 */
static
SB_Result_t
SBHYBRID_PublicData_Search(const Device_Handle_t Device_EIP130,
                           uint32_t ObjectNr,
                           assetid_t * const AssetId_p,
                           uint32_t * const DataLen_p)
{
    Eip130Token_Command_t t_cmd;
    Eip130Token_Result_t t_res;
    SB_Result_t sbres;
    int res;

    *AssetId_p = 0;

    // Format and process token
    Eip130Token_Command_AssetSearch(&t_cmd, (uint8_t)ObjectNr);
    Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
    Eip130Token_Command_SetTokenID(&t_cmd, 0x5010, false);

    sbres = SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
                                                &t_cmd, &t_res,
                                                SBLIB_CFG_XM_MAILBOXNR);
    res = Eip130Token_Result_Code(&t_res);
    if (sbres != SB_SUCCESS)
    {
        if (res == EIP130TOKEN_RESULT_INVALID_ASSET)
        {
            L_DEBUG(LF_SBHYBRID,
                    "SBHYBRID_PublicData_Search asset number %u invalid.",
                    (unsigned int)ObjectNr);
            sbres = SB_ERROR_ARGUMENTS;
        }
        else
        {        L_DEBUG(LF_SBHYBRID, "SBHYBRID_PublicData_ReadData failed (%d, %d).",
                res, sbres);

        }

        L_DEBUG(LF_SBHYBRID, "SBHYBRID_PublicData_Search failed (%d, %d).",
                res, sbres);
    }
    else
    {
        // Read the AssetId and Length from the response
        Eip130Token_Result_AssetSearch(&t_res, AssetId_p, DataLen_p);
    }

    return sbres;
}


/*----------------------------------------------------------------------------
 * SBHYBRID_PublicData_Read
 *
 * Uses the OTP_Read token to retrieve OTP data from the SM.
 */
static SB_Result_t
SBHYBRID_PublicData_Read(const Device_Handle_t Device_EIP130,
                         const uint32_t ObjectNr,
                         uint8_t * Data_p,
                         uint32_t * const DataLen_p)
{
    assetid_t AssetId = 0;
    uint32_t FoundLen = 0;
    SB_Result_t sbres;

    if (DataLen_p == NULL)
    {
        return SB_ERROR_ARGUMENTS;
    }

#ifdef EIP130_FW_ASSETPOLICY_V2
    /* Up to AssetNumber 126 supported */
    if (ObjectNr > 126)
#else
    /* Up to AssetNumber 62 supported */
    if (ObjectNr > 62)
#endif
    {
        return SB_ERROR_ARGUMENTS;
    }

    sbres = SBHYBRID_PublicData_Search(Device_EIP130,
                                       ObjectNr, &AssetId, &FoundLen);
    if (sbres != SB_SUCCESS)
    {
        return sbres;
    }

    if (AssetId == 0)
    {
        /* OTP object was not found */
        return SB_ERROR_ARGUMENTS;
    }

    if (Data_p == NULL)
    {
        /* Only update the length */
        *DataLen_p = FoundLen;
    }
    else
    {
        sbres = SBHYBRID_PublicData_ReadData(Device_EIP130,
                                             AssetId, Data_p, *DataLen_p);
    }
    return sbres;
}


/*----------------------------------------------------------------------------
 * SB_PublicData_Read
 */
SB_Result_t
SB_PublicData_Read(const uint32_t ObjectNr,
                   uint8_t * Data_p,
                   uint32_t * const DataLen_p)
{
    Device_Handle_t Device_EIP130;
    SB_Result_t sbres;

    L_TRACE(LF_SBHYBRID, "SB_PublicData_Read: ObjectNr = %d", ObjectNr);

    sbres = SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
    if (sbres == SB_SUCCESS)
    {
        /* Retrieve the Public Data */
        sbres = SBHYBRID_PublicData_Read(Device_EIP130,
                                         ObjectNr, Data_p, DataLen_p);
    }

    SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);

    return sbres;
}

#endif /* !SBLIB_CF_REMOVE_PUBLICDATA */
#endif /* SBHYBRID_WITH_EIP130 */

/* end of file sbhybrid_eip130_publicdata.c */
