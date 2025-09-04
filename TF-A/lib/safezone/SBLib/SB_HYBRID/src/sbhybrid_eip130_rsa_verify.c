/* sbhybrid_eip130_rsa-verify.c
 *
 * Description: Secure Boot RSA-Verify acceleration using EIP-130.
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

#ifndef __MODULE__
#define __MODULE__ "sbhybrid_eip130_rsa_verify.c"
#endif

#include "sbhybrid_internal.h"

#ifdef SBHYBRID_WITH_EIP130
#ifdef SBHYBRID_WITH_EIP130PK
#include "c_lib.h"

#include "dmares_buf.h"
#include "dmares_addr.h"
#include "dmares_rw.h"
#include "device_swap.h"
#include "eip130.h"
#include "eip130_token_common.h"
#include "eip130_token_system.h"
#include "eip130_token_asset.h"
#include "eip130_token_pk.h"
#include "eip130_asset_policy.h"

// Enable logging for RSA parameters, public key and signature when debugging
// is enabled
#ifdef CFG_ENABLE_DEBUG
//#define ENABLE_KEY_INFO_LOGGING
#ifdef ENABLE_KEY_INFO_LOGGING
#define LOG_SEVERITY_MAX LOG_SEVERITY_INFO
#include "log.h"
#endif
#endif

#ifdef SBLIB_CFG_SM_SECURE_ACCESS
#define SBHYBRID_ACCESS_POLICY  0
#else
#ifdef EIP130_FW_ASSETPOLICY_V2
#define SBHYBRID_ACCESS_POLICY  EIP130_ASSET_POLICY_SOURCENONSECURE
#else
#define SBHYBRID_ACCESS_POLICY  EIP130_ASSET_POLICY_SOURCE_NON_SECURE
#endif
#endif

#if defined(SUPPORT_RSA_PKCS)
#define EIP130TOKEN_PK_ASSET_CMD_RSA_VER    EIP130TOKEN_PK_ASSET_CMD_RSA_PKCS_VER
#ifdef EIP130_FW_ASSETPOLICY_V2
#define SBHYBRID_PUBLICKEY_POLICY           (SBHYBRID_ACCESS_POLICY              | \
                                             EIP130_ASSET_POLICY_ASYM_SIGNVERIFY | \
                                             EIP130_ASSET_POLICY_ACA_RSAPKCS1V15 | \
                                             EIP130_ASSET_POLICY_ACH_SHA256)
#else
#define SBHYBRID_PUBLICKEY_POLICY           (SBHYBRID_ACCESS_POLICY                | \
                                             EIP130_ASSET_POLICY_PK_RSA_PKCS1_SIGN | \
                                             EIP130_ASSET_POLICY_PUBLIC_KEY        | \
                                             EIP130_ASSET_POLICY_SHA256)
#endif
#elif defined(SUPPORT_RSA_PSS)
#define EIP130TOKEN_PK_ASSET_CMD_RSA_VER    EIP130TOKEN_PK_ASSET_CMD_RSA_PSS_VER
#ifdef EIP130_FW_ASSETPOLICY_V2
#define SBHYBRID_PUBLICKEY_POLICY           (SBHYBRID_ACCESS_POLICY              | \
                                             EIP130_ASSET_POLICY_ASYM_SIGNVERIFY | \
                                             EIP130_ASSET_POLICY_ACA_RSAPSS      | \
                                             EIP130_ASSET_POLICY_ACH_SHA256)
#else
#define SBHYBRID_PUBLICKEY_POLICY           (SBHYBRID_ACCESS_POLICY              | \
                                             EIP130_ASSET_POLICY_PK_RSA_PSS_SIGN | \
                                             EIP130_ASSET_POLICY_PUBLIC_KEY      | \
                                             EIP130_ASSET_POLICY_SHA256)
#endif
#else
#error "SUPPORT_RSA_PKCS or SUPPORT_RSA_PSS must be defined"
#endif

#define SBHYBRID_RSAVerify_ReadResult  SBHYBRID_AssetLoad_ReadResult

/*------------------------------------------------------
 * RSA with asset send verify command
 *------------------------------------------------------*/
static SB_Result_t
SBHYBRID_RSAVerify_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                               const uint32_t KeyAssetId,
                               const uint32_t IOAssetId,
                               const uint8_t * Signature_p,
                               const uint16_t SignatureLengthInBytes,
                               const uint8_t * HashData_p,
                               const uint16_t HashDataLengthInBytes,
                               const uint64_t TotalHashLengthInBytes)
{
    Eip130Token_Command_t t_cmd;
    uint64_t HashDataAddr;
    uint64_t SigDataAddr;

    // Get the DMA address of the data
    HashDataAddr = SBHYBRID_EIP130_Common_GetDmaAddress(Context_p,
                                                        HashData_p,
                                                        (uint32_t)HashDataLengthInBytes);
    if (HashDataAddr == 0)
    {
        void * Host_p;

        HashDataAddr = SBHYBRID_EIP130_Common_DmaAlloc(Context_p,
                                                       (uint32_t)HashDataLengthInBytes,
                                                       &Host_p);
        if (HashDataAddr == 0)
        {
            return SB_ERROR_HARDWARE;
        }

        c_memcpy(Host_p, HashData_p, HashDataLengthInBytes);
        SBHYBRID_EIP130_Common_PreDma(Context_p, NULL);
    }

    SigDataAddr = SBHYBRID_EIP130_Common_GetDmaAddress(Context_p,
                                                       Signature_p,
                                                       (uint32_t)SignatureLengthInBytes);
    if (SigDataAddr == 0)
    {
        void * Host_p;

        SigDataAddr = SBHYBRID_EIP130_Common_DmaAlloc(Context_p,
                                                      (uint32_t)SignatureLengthInBytes,
                                                      &Host_p);
        if (SigDataAddr == 0)
        {
            return SB_ERROR_HARDWARE;
        }

        c_memcpy(Host_p, Signature_p, SignatureLengthInBytes);
        SBHYBRID_EIP130_Common_PreDma(Context_p, NULL);
    }

    // Create token
    Eip130Token_Command_Pk_Asset_Command(&t_cmd,
                                         EIP130TOKEN_PK_ASSET_CMD_RSA_VER,
                                         SBIF_RSA_WORDS,
                                         SBIF_RSA_WORDS,
                                         RSA_DIGEST_BYTES,
                                         KeyAssetId,
                                         0,
                                         IOAssetId,
                                         HashDataAddr,
                                         HashDataLengthInBytes,
                                         SigDataAddr,
                                         SignatureLengthInBytes);
    Eip130Token_Command_Pk_Asset_SetAdditionalLength(&t_cmd,
                                                     TotalHashLengthInBytes);
    Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
    Eip130Token_Command_SetTokenID(&t_cmd, ++Context_p->TokenId, false);

    return SBHYBRID_EIP130_Common_WriteCommand(Context_p->Device_EIP130,
                                               &t_cmd,
                                               SBLIB_CFG_XM_MAILBOXNR);
}

/*----------------------------------------------------------------------------
 * SBHYBRID_EIP130_RsaVerify_Init
 */
void
SBHYBRID_EIP130_RsaVerify_Init(SBHYBRID_SymmContext_t * const Context_p,
                               const SBIF_PublicKey_t * const PublicKey_p,
                               const SBIF_Signature_t * const Signature_p)
{
    // Create Public Key representation for plaintext asset load
    Context_p->PublicKey_Buffer[0] = (uint8_t)(SBIF_RSA_BITS >> 0);
    Context_p->PublicKey_Buffer[1] = (uint8_t)(SBIF_RSA_BITS >> 8);
    Context_p->PublicKey_Buffer[2] = 0;
    Context_p->PublicKey_Buffer[3] = 2;
    reverse_memcpy(&Context_p->PublicKey_Buffer[4],
                   PublicKey_p->modulus,
                   SBIF_RSA_BYTES);

    Context_p->PublicKey_Buffer[SBIF_RSA_BYTES + 4] = (uint8_t)(SBIF_RSA_MAX_PUBEXP_BITS >> 0);
    Context_p->PublicKey_Buffer[SBIF_RSA_BYTES + 5] = (uint8_t)(SBIF_RSA_MAX_PUBEXP_BITS >> 8);
    Context_p->PublicKey_Buffer[SBIF_RSA_BYTES + 6] = 1;
    Context_p->PublicKey_Buffer[SBIF_RSA_BYTES + 7] = 2;
    reverse_memcpy(&Context_p->PublicKey_Buffer[SBIF_RSA_BYTES + 8],
                   PublicKey_p->pubkeyExp,
                   4);

    Context_p->PublicKeyInBytes = 8 + SBIF_RSA_BYTES + 4;

    // Create Signature representation
    Context_p->Signature_Buffer[0] = (uint8_t)(SBIF_RSA_BITS >> 0);
    Context_p->Signature_Buffer[1] = (uint8_t)(SBIF_RSA_BITS >> 8);
    Context_p->Signature_Buffer[2] = 0;
    Context_p->Signature_Buffer[3] = 1;
    reverse_memcpy(&Context_p->Signature_Buffer[4],
                   Signature_p->signature,
                   SBIF_RSA_BYTES);

    Context_p->SignatureInBytes = 4 + SBIF_RSA_BYTES;

#ifdef ENABLE_KEY_INFO_LOGGING
    Log_HexDump("Public Key", 0, Context_p->PublicKey_Buffer, Context_p->PublicKeyInBytes);
    Log_HexDump("Signature", 0, Context_p->Signature_Buffer, Context_p->SignatureInBytes);
#endif
    L_DEBUG(LF_SBHYBRID, "Successful");
}


/*----------------------------------------------------------------------------
 * SBHYBRID_EIP130_RsaVerify_RunFsm
 *
 */
SB_Result_t
SBHYBRID_EIP130_RsaVerify_RunFsm(SBHYBRID_SymmContext_t * const Context_p)
{
    unsigned int Step = 0;              // FSM step
    SB_Result_t sbres;
    SB_Result_t pass_fail = SB_SUCCESS;

    if (!Context_p->HashInitialize && !Context_p->HashFinalize)
    {
        // Last hash block not yet handled
        return SBHYBRID_PENDING;
    }

    L_TRACE(LF_SBHYBRID, "Step %u", Step);
    for (;;)
    {
        if ((Step & 1) == 0)
        {
            // Command step
            if (EIP130_MailboxCanWriteToken(Context_p->Device_EIP130,
                                            SBLIB_CFG_XM_MAILBOXNR, NULL))
            {
                switch (Step)
                {
                case 0:
                    // Create asset for Public Key
                    sbres = SBHYBRID_AssetCreate_SendCommand(Context_p,
                                                             SBHYBRID_PUBLICKEY_POLICY,
                                                             Context_p->PublicKeyInBytes);
                    break;

                case 2:
                    // Load asset with Public Key
                    sbres = SBHYBRID_AssetLoadPlaintext_SendCommand(Context_p,
                                                                    Context_p->KeyAssetId,
                                                                    Context_p->PublicKey_Buffer,
                                                                    (uint16_t)Context_p->PublicKeyInBytes);
                    break;

                case 4:
                    {
                        uint32_t HashTempAssetId = Context_p->HashTempAssetId;
                        if (Context_p->HashInitialize)
                        {
                            // Complete hash required (init -> final),
                            // so no temporary hash digest asset use
                            HashTempAssetId = 0;
                            L_DEBUG(LF_SBHYBRID, "Complete hash");
                        }
                        sbres = SBHYBRID_RSAVerify_SendCommand(Context_p,
                                                               Context_p->KeyAssetId,
                                                               HashTempAssetId,
                                                               Context_p->Signature_Buffer,
                                                               (uint16_t)Context_p->SignatureInBytes,
                                                               Context_p->HashData_p,
                                                               Context_p->HashDataLength,
                                                               Context_p->HashTotalLength);
                    }
                    break;

                case 6:
                    sbres = SBHYBRID_AssetDelete_SendCommand(Context_p,
                                                             Context_p->KeyAssetId);
                    break;

                case 8:
                    if (!Context_p->HashInitialize)
                    {
                        // Clean-up used temporary hash digest asset
                        sbres = SBHYBRID_AssetDelete_SendCommand(Context_p,
                                                                 Context_p->HashTempAssetId);
                        break;
                    }
                    // RSA Verify sequence ready
                    L_DEBUG(LF_SBHYBRID, "Skipped HashTempAssetId delete");
                    return pass_fail;

                case 10:
                    // RSA Verify sequence ready
                    return pass_fail;

                default:
                    return SB_ERROR_HARDWARE;
                }

                if (sbres != SBHYBRID_PENDING)
                {
                    return SB_ERROR_HARDWARE;
                }
                Step++;
                L_TRACE(LF_SBHYBRID, "Step %u", Step);
            }
            else
            {
                // Command not yet ready
            }
        }
        else
        {
            // Response step
            if (EIP130_MailboxCanReadToken(Context_p->Device_EIP130,
                                           SBLIB_CFG_XM_MAILBOXNR))
            {
                switch (Step)
                {
                case 1:                 // Asset create
                                        // Validate response and read AssetId of Public Key
                    sbres = SBHYBRID_AssetCreateSearch_ReadResult(Context_p,
                                                                  &Context_p->KeyAssetId);
                    break;

                case 3:                 // Asset load
                case 5:                 // RSA Verify
                case 7:                 // Asset delete
                case 9:                 // Asset delete
                                        // Validate asset load/asset delete/RSA verify response
                    sbres = SBHYBRID_AssetLoad_ReadResult(Context_p);
                    break;

                default:
                    return SB_ERROR_HARDWARE;
                }

                // Clean-up asset references if needed
                switch (Step)
                {
                default:
                    break;
                case 7:
                    Context_p->KeyAssetId = 0;
                    break;
                case 9:
                    Context_p->HashTempAssetId = 0;
                    break;
                }

                if (sbres != SB_SUCCESS)
                {
                    L_DEBUG(LF_SBHYBRID, "Step %u Result %d", Step, sbres);

                    // Control clean-up in case of an error
                    // - Select the next applicable step
                    switch (Step)
                    {
                    case 1:             // Asset create
                        pass_fail = SB_ERROR_HARDWARE;
                        Step = 8;
                        break;
                    case 3:             // Asset load
                        pass_fail = SB_ERROR_HARDWARE;
                        Step = 6;
                        break;
                    case 5:             // RSA Verify failed
                        pass_fail = SB_ERROR_VERIFICATION;
                        Step++;
                        break;
                    case 7:             // Asset delete
                    case 9:             // Asset delete
                        pass_fail = SB_ERROR_HARDWARE;
                        Step++;
                        break;
                    default:
                        return SB_ERROR_HARDWARE;
                    }
                }
                else
                {
                    // Simple goto the next step
                    Step++;
                }
                L_TRACE(LF_SBHYBRID, "Step %u", Step);
            }
            else
            {
                // Command not yet ready
            }
        }
    }
    // Will never be reached
}


/*----------------------------------------------------------------------------
 * SBHYBRID_EIP130_RsaVerify_SetDigest
 *
 * This function is called when the Digest is available.
 * For the EIP130 this is a dummy function.
 */
void
SBHYBRID_EIP130_RsaVerify_SetDigest(SBHYBRID_SymmContext_t * const Context_p,
                                    uint8_t * Digest_p)
{
    IDENTIFIER_NOT_USED(Context_p);
    IDENTIFIER_NOT_USED(Digest_p);
}

#endif /* SBHYBRID_WITH_EIP130PK */
#endif /* SBHYBRID_WITH_EIP130 */

/* end of file sbhybrid_eip130_rsa_verify.c */
