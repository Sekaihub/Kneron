/* eip130_token_nop.h
 *
 * Security Module Token helper functions
 * - NOP token related functions and definitions
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_NOP_H
#define INCLUDE_GUARD_EIP130TOKEN_NOP_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "eip130_token_common.h"    /* Eip130Token_Command_t */

#ifdef EIP130_ENABLE_NOP
/*----------------------------------------------------------------------------
 * Eip130Token_Command_Nop
 *
 * CommandToken_p
 *      Pointer to the command token buffer.
 *
 * InputDataAddress
 *     Address of the input data buffer.
 *
 * InputDataLengthInBytes
 *     Size of the input data buffer being the number of bytes to copy.
 *     Must be a multiple of 4.
 *
 * OutputDataAddress
 *     Address of the output data buffer.
 *
 * OutputDataLengthInBytes
 *     Size of the output data buffer.
 *     Must be a multiple of 4.
 */
static inline void
Eip130Token_Command_Nop(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenDmaAddress_t InputDataAddress,
        const Eip130TokenDmaSize_t InputDataLengthInBytes,
        const Eip130TokenDmaAddress_t OutputDataAddress,
        const Eip130TokenDmaSize_t OutputDataLengthInBytes)
{
    CommandToken_p->W[0] = EIP130TOKEN_OPCODE_NOP;
    CommandToken_p->W[2] = (Eip130TokenWord_t)InputDataLengthInBytes;
    CommandToken_p->W[3] = (Eip130TokenWord_t)(InputDataAddress);
    CommandToken_p->W[4] = (Eip130TokenWord_t)(InputDataAddress >> 32);
    CommandToken_p->W[5] = (Eip130TokenWord_t)InputDataLengthInBytes;
    CommandToken_p->W[6] = (Eip130TokenWord_t)(OutputDataAddress);
    CommandToken_p->W[7] = (Eip130TokenWord_t)(OutputDataAddress >> 32);
    CommandToken_p->W[8] = (Eip130TokenWord_t)OutputDataLengthInBytes;
}
#endif


#endif /* INCLUDE_GUARD_EIP130TOKEN_NOP_H */

/* end of file eip130_token_nop.h */
