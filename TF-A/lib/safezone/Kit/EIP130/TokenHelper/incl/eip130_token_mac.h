/* eip130_token_mac.h
 *
 * Security Module Token helper functions
 * - MAC token related functions and definitions
 *
 * This module can convert a set of parameters into a Security Module Command
 * token, or parses a set of parameters from a Security Module Result token.
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_MAC_H
#define INCLUDE_GUARD_EIP130TOKEN_MAC_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "eip130_token_common.h"    /* Eip130Token_Command/Result_t */


typedef enum
{
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA1 = 1U,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA224,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA256,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA384,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA512,
    EIP130TOKEN_MAC_ALGORITHM_SM3,
#if defined(EIP130_ENABLE_SYM_ALGO_SHA3) || \
    defined(EIP130_ENABLE_HASHMAC_LAYOUT_V2)
    EIP130TOKEN_MAC_ALGORITHM_POLY1305,
    EIP130TOKEN_MAC_ALGORITHM_AES_CMAC,
    EIP130TOKEN_MAC_ALGORITHM_AES_CBCMAC,
    EIP130TOKEN_MAC_ALGORITHM_ARIA_CMAC,
    EIP130TOKEN_MAC_ALGORITHM_ARIA_CBCMAC,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA3_224,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA3_256,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA3_384,
    EIP130TOKEN_MAC_ALGORITHM_HMAC_SHA3_512
#else
    EIP130TOKEN_MAC_ALGORITHM_AES_CMAC = 8U,
    EIP130TOKEN_MAC_ALGORITHM_AES_CBCMAC,
    EIP130TOKEN_MAC_ALGORITHM_ARIA_CMAC,
    EIP130TOKEN_MAC_ALGORITHM_ARIA_CBCMAC,
    EIP130TOKEN_MAC_ALGORITHM_POLY1305 = 14U
#endif
} Eip130Token_MAC_Algoritms_t;


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * MacAlgo
 *     Mac algorithm selection. Use one of EIP130TOKEN_MAC_ALGORITHM_*.
 *
 * fInit
 *     Set to true to have the MAC initialized with the default value
 *     according to the specification for the selected algorithm.
 *
 * fFinalize
 *     Set to true to have the hash finalized.
 *
 * InputDataAddress
 *     Input address of data to be MACed.
 *
 * InputDataLengthInBytes
 *     Input size/Length of the data block to be MACed.
 *     Note: For non-final MAC (fFinalize == false) this must be a multiple
 *           of the block size bytes, otherwise the request will be rejected.
 */
static inline void
Eip130Token_Command_Mac(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t MacAlgo,
        const bool fInit,
        const bool fFinalize,
        const Eip130TokenDmaAddress_t InputDataAddress,
        const Eip130TokenDmaSize_t InputDataLengthInBytes)
{
#ifdef EIP130_ENABLE_HASHMAC_LAYOUT_V2
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_MAC | ((Eip130TokenWord_t)1UL << 28));
#else
    CommandToken_p->W[0] = EIP130TOKEN_OPCODE_MAC;
#endif
    CommandToken_p->W[2] = (Eip130TokenWord_t)InputDataLengthInBytes;
    CommandToken_p->W[3] = (Eip130TokenWord_t)(InputDataAddress);
    CommandToken_p->W[4] = (Eip130TokenWord_t)(InputDataAddress >> 32);
    CommandToken_p->W[5] = (Eip130TokenWord_t)((InputDataLengthInBytes + 3U) & (uint32_t)~3UL);
    CommandToken_p->W[6] = (Eip130TokenWord_t)MacAlgo & MASK_4_BITS;
    if (!fInit)
    {
        CommandToken_p->W[6] |= BIT_4;
    }
    if (!fFinalize)
    {
        CommandToken_p->W[6] |= BIT_5;
    }
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetTotalMessageLength
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * TotalMessageLengthInBytes = Bits 60:0
 *     This is the total message length c.q. the length of all data blocks
 *     that are MACed, required for when MAC is finalized.
 */
static inline void
Eip130Token_Command_Mac_SetTotalMessageLength(
        Eip130Token_Command_t * const CommandToken_p,
        const uint64_t TotalMessageLengthInBytes)
{
#if defined(EIP130_ENABLE_SYM_ALGO_SHA3) || \
    defined(EIP130_ENABLE_HASHMAC_LAYOUT_V2)
    CommandToken_p->W[10] = (Eip130TokenWord_t)(TotalMessageLengthInBytes);
    CommandToken_p->W[11] = (Eip130TokenWord_t)(TotalMessageLengthInBytes >> 32);
#else
    CommandToken_p->W[24] = (Eip130TokenWord_t)(TotalMessageLengthInBytes);
    CommandToken_p->W[25] = (Eip130TokenWord_t)(TotalMessageLengthInBytes >> 32);
#endif
}


#if defined(EIP130_ENABLE_SYM_ALGO_SHA3) || \
    defined(EIP130_ENABLE_HASHMAC_LAYOUT_V2)
/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASIDKey
 *
 * This function sets the AssetId of the key Asset.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the key Asset.
 */
static inline void
Eip130Token_Command_Mac_SetASIDKey(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[8] = (Eip130TokenWord_t)AssetId;
}
#else
/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASLoadKey
 *
 * This function sets the Asset Store Load location for the key and activates
 * its use. This also disables the use of the key via the token.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the key to use.
 */
static inline void
Eip130Token_Command_Mac_SetASLoadKey(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[6] |= BIT_8;
    CommandToken_p->W[28] = (Eip130TokenWord_t)AssetId;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_CopyKey
 *
 * This function copies the key from the buffer provided by the caller into
 * the command token.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * Key_p
 *     Pointer to the buffer with the key.
 *
 * KeyLengthInBytes
 *     The size of the key to copy.
 */
static inline void
Eip130Token_Command_Mac_CopyKey(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t * const Key_p,
        const uint32_t KeyLengthInBytes)
{
    CommandToken_p->W[6] |= (((Eip130TokenWord_t)KeyLengthInBytes & MASK_8_BITS) << 16);

    Eip130Token_Command_WriteByteArray(CommandToken_p, 28U,
                                       Key_p, KeyLengthInBytes);
}
#endif


#if defined(EIP130_ENABLE_SYM_ALGO_SHA3) || \
    defined(EIP130_ENABLE_HASHMAC_LAYOUT_V2)
/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASTempMAC
 *
 * This function sets the AssetId of the intermedaite state Asset.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the intermediate MAC Asset.
 */
static inline void
Eip130Token_Command_Mac_SetASIDState(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[7] = (Eip130TokenWord_t)AssetId;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASIDVerifyMAC
 *
 * This function sets the AssetId of the verify MAC Asset that shall be used
 * to verify the calculated final MAC and activates its use.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the verify MAC Asset.
 */
static inline void
Eip130Token_Command_Mac_SetASIDVerifyMAC(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[6] |= BIT_9;
    CommandToken_p->W[14] = (Eip130TokenWord_t)AssetId;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_CopyVerifyMAC
 *
 * This function copies the verify MAC from the buffer provided by the caller
 * into the command token. The requested number of bytes are copied.
 * Note that the length depends on the algorithm that is used.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * VerifyMAC_p
 *     Pointer to the verify MAC buffer.
 *
 * VerifyMACLenInBytes
 *     The size of the verify MAC to copy.
 */
static inline void
Eip130Token_Command_Mac_CopyVerifyMAC(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t * const VerifyMAC_p,
        const uint32_t VerifyMACLenInBytes)
{
    CommandToken_p->W[6] &= ~(Eip130TokenWord_t)BIT_9;
    Eip130Token_Command_WriteByteArray(CommandToken_p, 14U,
                                       VerifyMAC_p, VerifyMACLenInBytes);
}
#else
/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASTempMAC
 *
 * This function sets the Asset Store Save location for the MAC and activates
 * its use.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the intermediate MAC asset.
 */
static inline void
Eip130Token_Command_Mac_SetASTempMAC(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[7] = (Eip130TokenWord_t)AssetId;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_SetASLoadMAC
 *
 * This function sets the Asset Store Load location for the MAC and activates
 * its use. This also disables the use of the MAC via the token.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the final MAC asset to verify.
 */
static inline void
Eip130Token_Command_Mac_SetASLoadMAC(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[6] |= BIT_9;
    CommandToken_p->W[8] = (Eip130TokenWord_t)AssetId;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Mac_CopyMAC
 *
 * This function copies the MAC from the buffer provided by the caller into
 * the command token. The requested number of bytes are copied (length depends
 * on the algorithm that will be used).
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * MAC_p
 *     Pointer to the MAC buffer.
 *
 * MACLenInBytes
 *     The size of the MAC to copy.
 */
static inline void
Eip130Token_Command_Mac_CopyMAC(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t * const MAC_p,
        const uint32_t MACLenInBytes)
{
    Eip130Token_Command_WriteByteArray(CommandToken_p, 8U,
                                       MAC_p, MACLenInBytes);
}
#endif


#if defined(EIP130_ENABLE_SYM_ALGO_SHA3) || \
    defined(EIP130_ENABLE_HASHMAC_LAYOUT_V2)
/*----------------------------------------------------------------------------
 * Eip130Token_Result_Mac_CopyFinalMAC
 *
 * This function copies the final MAC from the result token to the buffer
 * provided by the caller. The requested number of bytes are copied.
 * Note that the length depends on the algorithm that is used.
 *
 * The final MAC is written to the destination buffer, Byte 0 first.
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * MACLenInBytes
 *     The size of the final MAC to copy.
 *
 * MAC_p
 *     Pointer to the final MAC buffer.
 */
static inline void
Eip130Token_Result_Mac_CopyFinalMAC(
        const Eip130Token_Result_t * const ResultToken_p,
        const uint32_t MACLenInBytes,
        uint8_t * MAC_p)
{
    Eip130Token_Result_ReadByteArray(ResultToken_p, 2U, MACLenInBytes, MAC_p);
}
#else
/*----------------------------------------------------------------------------
 * Eip130Token_Result_Mac_CopyMAC
 *
 * This function copies the MAC from the result token to the buffer provided
 * by the caller. The requested number of bytes are copied (length depends on
 * the algorithm that was used).
 *
 * The MAC is written to the destination buffer, Byte 0 first.
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * MACLenInBytes
 *     The size of the MAC to copy.
 *
 * MAC_p
 *     Pointer to the MAC buffer.
 */
static inline void
Eip130Token_Result_Mac_CopyMAC(
        const Eip130Token_Result_t * const ResultToken_p,
        const uint32_t MACLenInBytes,
        uint8_t * MAC_p)
{
    Eip130Token_Result_ReadByteArray(ResultToken_p, 2U, MACLenInBytes, MAC_p);
}
#endif


#endif /* INCLUDE_GUARD_EIP130TOKEN_MAC_H */

/* end of file eip130_token_mac.h */
