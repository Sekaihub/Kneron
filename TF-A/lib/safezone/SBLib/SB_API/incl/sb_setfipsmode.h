/* sb_setfipsmode.h
 *
 * Description: Secure Boot API: Set FIPS mode
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

#ifndef INCLUDE_GUARD_SB_SETFIPSMODE_H
#define INCLUDE_GUARD_SB_SETFIPSMODE_H

/* Internal includes. */
#include "public_defs.h"
#include "sb_result.h"

/** Enable/Set FIPS mode.

    @param COID
    The Crypto Officer identity (COID) value

    @param User1
    The User1 identity value

    @param User2
    The User1 identity value

    @param User3
    The User1 identity value

    @param User4
    The User1 identity value

    @return
    Returns SB_SUCCESS on success otherwise SB_ERROR_HARDWARE. In that case an
    error occurred while enabling the FIPS mode.
 */
SB_Result_t
SB_SetFipsMode(const uint32_t COID,
               const uint32_t User1,
               const uint32_t User2,
               const uint32_t User3,
               const uint32_t User4);

#endif /* INCLUDE_GUARD_SB_SETFIPSMODE_H */

/* end of file sb_setfipsmode.h */
