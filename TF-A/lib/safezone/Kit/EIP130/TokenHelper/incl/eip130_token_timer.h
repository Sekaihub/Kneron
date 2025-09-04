/* eip130_token_timer.h
 *
 * Security Module Token helper functions
 * - Secure Timer related functions and definitions
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_TIMER_H
#define INCLUDE_GUARD_EIP130TOKEN_TIMER_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "eip130_token_common.h"    /* Eip130Token_Command/Result_t */


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SecureTimer
 *
 * This function initializes the command token for a Secure Timer (Re)Start,
 * Stop and read operation.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * AssetId (optional for start)
 *      AssetId of the secure timer to stop, read or restart.
 *
 * fSecond
 *      Second timer indication otherwise 100 us timer is used.
 *
 * Operation
 *      Secure timer operation to perform (re)start, stop or read.
 */
static inline void
Eip130Token_Command_SecureTimer(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t AssetId,
        const bool fSecond,
        const uint16_t Operation)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_ASSETMANAGEMENT |
                            EIP130TOKEN_SUBCODE_SECURETIMER);
    CommandToken_p->W[2] = (Eip130TokenWord_t)AssetId;
    CommandToken_p->W[3] = (Eip130TokenWord_t)Operation & MASK_2_BITS;
    if (fSecond)
    {
        CommandToken_p->W[3] |= BIT_15;
    }
}


/*----------------------------------------------------------------------------
 * Eip130Token_Result_SecureTimer
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * AssetId_p (optional)
 *      Pointer to the variable in which the AssetId must be returned.
 *
 * ElapsedTime_p (optional)
 *      Pointer to the variable in which the elapsed time must be returned.
 */
static inline void
Eip130Token_Result_SecureTimer(
        const Eip130Token_Result_t * const ResultToken_p,
        Eip130TokenAssetId_t * const AssetId_p,
        uint32_t * const ElapsedTime_p)
{
    if (AssetId_p != NULL)
    {
        *AssetId_p = ResultToken_p->W[1];
    }
    if (ElapsedTime_p != NULL)
    {
        *ElapsedTime_p = ResultToken_p->W[2];
    }
}


#endif /* INCLUDE_GUARD_EIP130TOKEN_TIMER_H */

/* end of file eip130_token_timer.h */
