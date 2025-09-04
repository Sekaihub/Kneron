/* sbhybrid_sw_setfipsmode.c
 *
 * Description: Stub implementation of Secure Boot API.
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

#include "sbhybrid_internal.h"

/* This SB_SetFipsMode stub implementation is for non-EIP130 implementations */
#if !defined(SBHYBRID_WITH_EIP130)
#ifndef SBLIB_CF_REMOVE_SETFIPSMODE

#include "implementation_defs.h"
#include "sb_setfipsmode.h"             /* API to implement */

/* Interface function for enabling FIPS mode. */
SB_Result_t
SB_SetFipsMode(const uint32_t COID,
               const uint32_t User1,
               const uint32_t User2,
               const uint32_t User3,
               const uint32_t User4)
{
    PARAMETER_NOT_USED(COID);
    PARAMETER_NOT_USED(User1);
    PARAMETER_NOT_USED(User2);
    PARAMETER_NOT_USED(User3);
    PARAMETER_NOT_USED(User4);

    return SB_ERROR_HARDWARE;
}

#endif /* !SBLIB_CF_REMOVE_SETFIPSMODE */
#endif /* !defined(SBHYBRID_WITH_EIP130) */

/* end of file sbhybrid_sw_setfipsmode.c */
