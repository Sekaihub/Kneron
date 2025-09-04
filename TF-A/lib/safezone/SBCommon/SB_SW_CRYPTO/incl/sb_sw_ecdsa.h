/* sb_sw_ecdsa.h
 *
 * Description: Secure Boot ECDSA Interface.
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

/*
    Secure Boot ECDSA Verification uses this header to specify interface
    it uses to interact with ECDSA verification.

    Other software may also use this interface to access other parts of
    the ECDSA functionality, including key generation and signing.

    The interface depends on SBIF_ECDSA_WORDS, which declares the size of
    ECDSA calculated (and therefore) the size of output of output signature
    and domain parameters. The SBIF_ECDSA_WORDS parameter shall be 7/8/12/17
    for this source.
*/

#ifndef INCLUDE_GUARD_SB_SW_ECDSA_H
#define INCLUDE_GUARD_SB_SW_ECDSA_H

#include "public_defs.h"
#include "sbif.h"

#if SBIF_ECDSA_WORDS == 7               /* P-224 */
#include "sb_sw_ecdsa224.h"
#elif SBIF_ECDSA_WORDS == 8             /* P-256 */
#include "sb_sw_ecdsa256.h"
#elif SBIF_ECDSA_WORDS == 12            /* P-384 */
#include "sb_sw_ecdsa384.h"
#elif SBIF_ECDSA_WORDS == 17            /* P-521 */
#include "sb_sw_ecdsa521.h"
#else
#error "Unsupported SBIF_ECDSA_WORDS"
#endif

#endif /* INCLUDE_GUARD_SB_SW_ECDSA_H */

/* end of file sb_sw_ecdsa.h */
