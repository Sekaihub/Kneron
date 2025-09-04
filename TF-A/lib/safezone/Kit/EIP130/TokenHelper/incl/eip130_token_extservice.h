/* eip130_token_extservice.h
 *
 * Security Module Token helper functions
 * - External Service token related functions and definitions
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_EXTSERVICE_H
#define INCLUDE_GUARD_EIP130TOKEN_EXTSERVICE_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "eip130_token_common.h"    /* Eip130Token_Command/Result_t */

#ifdef EIP130_ENABLE_EXTSERVICE
/*----------------------------------------------------------------------------
 * Eip130Token_Command_ExtService
 *
 * This function initializes the External Service token.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * MacAlgo
 *     Mac algorithm selection. Use one of EIP130TOKEN_MAC_ALGORITHM_*.
 *
 * InputDataAddress
 *     Address of data to be MACed.
 *
 * InputDataLengthInBytes
 *     Size/Length of the data block to be MACed.
 */
static inline void
Eip130Token_Command_ExtService(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t MacAlgo,
        const Eip130TokenDmaAddress_t InputDataAddress,
        const Eip130TokenDmaSize_t InputDataLengthInBytes)
{
    CommandToken_p->W[0]  = EIP130TOKEN_OPCODE_EXT_SERVICE;
    CommandToken_p->W[2]  = (Eip130TokenWord_t)(InputDataLengthInBytes);
    CommandToken_p->W[3]  = (Eip130TokenWord_t)(InputDataAddress);
    CommandToken_p->W[4]  = (Eip130TokenWord_t)(InputDataAddress >> 32);
    CommandToken_p->W[5]  = (Eip130TokenWord_t)(InputDataLengthInBytes);
    CommandToken_p->W[6]  = ((Eip130TokenWord_t)MacAlgo & MASK_4_BITS);
    CommandToken_p->W[24] = (Eip130TokenWord_t)(InputDataLengthInBytes);
    CommandToken_p->W[25] = 0U;
}

/*----------------------------------------------------------------------------
 * Eip130Token_Command_ExtService_SetKeyAssetIDAndKeyLength
 *
 * This function sets the KEK Asset ID.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the KEK asset.
 *
 * KeyLengthInBytes
 *     The size of the key.
 */
static inline void
Eip130Token_Command_ExtService_SetKeyAssetIDAndKeyLength(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId,
        const uint32_t KeyLengthInBytes)
{
    CommandToken_p->W[6] |= (((Eip130TokenWord_t)KeyLengthInBytes & MASK_7_BITS) << 16);
    CommandToken_p->W[7]  = (Eip130TokenWord_t)AssetId;
}

/*----------------------------------------------------------------------------
 * Eip130Token_Command_ExtService_SetStateAssetID
 *
 * This function sets the eMMC State Asset ID.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId
 *     Asset ID of the eMMC State asset.
 */
static inline void
Eip130Token_Command_ExtService_SetStateAssetID(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId)
{
    CommandToken_p->W[28] = (Eip130TokenWord_t)AssetId;
}

/*----------------------------------------------------------------------------
 * Eip130Token_Command_ExtService_SetAssociatedData
 *
 * This function sets associated data for the keyblob import functionality.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssociatedData_p
 *      Associated Data address.
 *
 * AssociatedDataSizeInBytes
 *      Associated Data length.
 */
static inline void
Eip130Token_Command_ExtService_SetAssociatedData(
        Eip130Token_Command_t * const CommandToken_p,
        const uint8_t * const AssociatedData_p,
        const uint32_t AssociatedDataSizeInBytes)
{
    CommandToken_p->W[29] |= ((Eip130TokenWord_t)AssociatedDataSizeInBytes << 16);

    Eip130Token_Command_WriteByteArray(CommandToken_p, 30U,
                                       AssociatedData_p,
                                       AssociatedDataSizeInBytes);
}

/*----------------------------------------------------------------------------
 * Eip130Token_Result_ExtService_CopyMAC
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
Eip130Token_Result_ExtService_CopyMAC(
        Eip130Token_Result_t * const ResultToken_p,
        const uint32_t MACLenInBytes,
        uint8_t * MAC_p)
{
    Eip130Token_Result_ReadByteArray(ResultToken_p, 2U, MACLenInBytes, MAC_p);
}
#endif /* EIP130_ENABLE_EXTSERVICE */


#endif /* INCLUDE_GUARD_EIP130TOKEN_EXTSERVICE_H */

/* end of file eip130_token_extservice.h */
