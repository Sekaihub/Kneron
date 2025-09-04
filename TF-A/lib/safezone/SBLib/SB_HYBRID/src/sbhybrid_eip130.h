/* sbhybrid_eip130.h
 *
 * Description: Secure boot library: Internal definitions for SB_HYBRID_EIP130
 *              implementation of Secure Boot API.
 *              SB_HYBRID allows to choose implementation of symmetric
 *              cryptography and asymmetric cryptography independently.
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

#ifndef INCLUDE_GUARD_SBHYBRID_EIP130_INTERNAL_H
#define INCLUDE_GUARD_SBHYBRID_EIP130_INTERNAL_H

#include "dmares_buf.h"
#include "dmares_types.h"          // DMAResource_Handle_t
#include "eip130.h"

#ifdef SBHYBRID_WITH_EIP130PK
#define SBHYBRID_IMMEDIATE_CERTIFICATE_CHECK
#endif

#define SBHYBRID_SHA2XX_Init       SBHYBRID_EIP130_Hash_Init
#define SBHYBRID_SHA2XX_AddBlock   SBHYBRID_EIP130_Hash_AddBlock
#define SBHYBRID_SHA2XX_RunFsm     SBHYBRID_EIP130_Hash_RunFsm
#define SBHYBRID_SHA2XX_GetDigest  SBHYBRID_EIP130_Hash_GetDigest
#define SBHYBRID_SHA2XX_DmaRelease SBHYBRID_EIP130_Common_DmaRelease

SB_Result_t
SBHYBRID_EIP130_Common_Initialize_HW(Device_Handle_t * const  Device_EIP130_p);

void
SBHYBRID_EIP130_Common_Uninitialize_HW(Device_Handle_t const Device_EIP130);

SB_Result_t
SBHYBRID_EIP130_Common_WriteCommand(Device_Handle_t const Device_EIP130,
                                    Eip130Token_Command_t * t_cmd_p,
                                    uint8_t MailboxNr);

SB_Result_t
SBHYBRID_EIP130_Common_ReadResultAndCheck(Device_Handle_t const Device_EIP130,
                                          Eip130Token_Result_t * t_res_p,
                                          uint8_t MailboxNr);

SB_Result_t
SBHYBRID_EIP130_Common_ProcessToken(Device_Handle_t const Device_EIP130,
                                    Eip130Token_Command_t * t_cmd_p,
                                    Eip130Token_Result_t * t_res_p,
                                    uint8_t MailboxNr);

uint64_t
SBHYBRID_EIP130_Common_GetDmaAddress(SBHYBRID_SymmContext_t * const Context_p,
                                     const void * Data_p,
                                     const uint32_t DataLength);

uint64_t
SBHYBRID_EIP130_Common_DmaAlloc(SBHYBRID_SymmContext_t * const Context_p,
                                const uint32_t DataLength,
                                void ** Host_pp);

void
SBHYBRID_EIP130_Common_DmaRelease(SBHYBRID_SymmContext_t * const Context_p);

void
SBHYBRID_EIP130_Common_PreDma(SBHYBRID_SymmContext_t * const Context_p,
                              const DMAResource_Handle_t Handle);

SB_Result_t
SBHYBRID_AssetCreate_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                 uint64_t Policy,
                                 uint32_t AssetSizeInBytes);

SB_Result_t
SBHYBRID_AssetSearch_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                 const uint32_t AssetNumber);

SB_Result_t
SBHYBRID_AssetCreateSearch_ReadResult(SBHYBRID_SymmContext_t * const Context_p,
                                      uint32_t * AssetId_p);

SB_Result_t
SBHYBRID_AssetDelete_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                 const uint32_t AssetId);

SB_Result_t
SBHYBRID_AssetDelete_ReadResult(SBHYBRID_SymmContext_t * const Context_p);

SB_Result_t
SBHYBRID_AssetLoadPlaintext_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                        const uint32_t AssetId,
                                        const uint8_t * Data_p,
                                        const uint16_t DataLengthInbytes);

SB_Result_t
SBHYBRID_AssetLoadAESUnwrap_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                        const uint32_t AssetId,
                                        const uint32_t KEKAssetId,
                                        const uint8_t * Data_p,
                                        const uint16_t DataLengthInbytes);

SB_Result_t
SBHYBRID_AssetLoadDerive_SendCommand(SBHYBRID_SymmContext_t * const Context_p,
                                     const uint32_t AssetId,
                                     const uint32_t KDKAssetId,
                                     const uint8_t * Aad_p,
                                     const uint16_t AadLengthInBytes);

SB_Result_t
SBHYBRID_AssetLoad_ReadResult(SBHYBRID_SymmContext_t * const Context_p);

SB_Result_t
SBHYBRID_EIP130_Hash_Init(SBHYBRID_SymmContext_t * const Context_p);

SB_Result_t
SBHYBRID_EIP130_Hash_AddBlock(SBHYBRID_SymmContext_t * const Context_p,
                              const uint8_t * DataBytes_p,
                              const uint32_t DataByteCount,
                              const bool fFinal);

SB_Result_t
SBHYBRID_EIP130_Hash_RunFsm(SBHYBRID_SymmContext_t * const Context_p);

void
SBHYBRID_EIP130_Hash_GetDigest(SBHYBRID_SymmContext_t * const Context_p,
                               uint8_t * Digest_p);

#ifdef SBIF_ECDSA
#define SBHYBRID_Verify_Init      SBHYBRID_EIP130_EcdsaVerify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_EIP130_EcdsaVerify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_EIP130_EcdsaVerify_SetDigest
void
SBHYBRID_EIP130_EcdsaVerify_Init(SBHYBRID_SymmContext_t * const Context_p,
                                 const SBIF_PublicKey_t * const PublicKey_p,
                                 const SBIF_Signature_t * const Signature_p);

SB_Result_t
SBHYBRID_EIP130_EcdsaVerify_RunFsm(SBHYBRID_SymmContext_t * const Context_p);

void
SBHYBRID_EIP130_EcdsaVerify_SetDigest(SBHYBRID_SymmContext_t * const Context_p,
                                      uint8_t * Digest_p);
#else
#define SBHYBRID_Verify_Init      SBHYBRID_EIP130_RsaVerify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_EIP130_RsaVerify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_EIP130_RsaVerify_SetDigest
void
SBHYBRID_EIP130_RsaVerify_Init(SBHYBRID_SymmContext_t * const Context_p,
                                 const SBIF_PublicKey_t * const PublicKey_p,
                                 const SBIF_Signature_t * const Signature_p);

SB_Result_t
SBHYBRID_EIP130_RsaVerify_RunFsm(SBHYBRID_SymmContext_t * const Context_p);

void
SBHYBRID_EIP130_RsaVerify_SetDigest(SBHYBRID_SymmContext_t * const Context_p,
                                      uint8_t * Digest_p);

#endif /* SBIF_ECDSA */

#endif /* INCLUDE_GUARD */

/* end of file sbhybrid_eip130.h */