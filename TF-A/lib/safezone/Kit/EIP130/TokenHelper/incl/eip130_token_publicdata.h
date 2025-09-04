/* eip130_token_publicdata.h
 *
 * Security Module Token helper functions
 * - Public Data token related functions and definitions
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_PUBLICDATA_H
#define INCLUDE_GUARD_EIP130TOKEN_PUBLICDATA_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "eip130_token_common.h"    /* Eip130Token_Command/Result_t */


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Publicdata_Read
 *
 * CommandToken_p
 *      Pointer to the command token buffer.
 *
 * AssetID
 *      ID of Asset of the public data object to read
 *
 * DataAddress
 *      Output data address
 *
 * DataLengthInBytes
 *      Output data length
 *      Must be a multiple of 4.
 */
static inline void
Eip130Token_Command_PublicData_Read(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetID,
        const Eip130TokenDmaAddress_t DataAddress,
        const Eip130TokenDmaSize_t DataLengthInBytes)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_ASSETMANAGEMENT |
                            EIP130TOKEN_SUBCODE_PUBLICDATA);
    CommandToken_p->W[2] = (Eip130TokenWord_t)AssetID;
    CommandToken_p->W[3] = (Eip130TokenWord_t)DataLengthInBytes;
    CommandToken_p->W[4] = (Eip130TokenWord_t)(DataAddress);
    CommandToken_p->W[5] = (Eip130TokenWord_t)(DataAddress >> 32);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Result_Publicdata_Read
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * DataLengthInBytes_p
 *      Pointer to the variable in which the data length must be returned.
 */
static inline void
Eip130Token_Result_Publicdata_Read(
        const Eip130Token_Result_t * const ResultToken_p,
        uint32_t * const DataLengthInBytes_p)
{
    *DataLengthInBytes_p = ResultToken_p->W[1] & MASK_10_BITS;
}


#endif /* INCLUDE_GUARD_EIP130TOKEN_PUBLICDATA_H */

/* end of file eip130_token_publicdata.h */
