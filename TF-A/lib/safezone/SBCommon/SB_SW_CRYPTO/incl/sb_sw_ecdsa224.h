/* sb_sw_ecdsa224.h
 *
 * Description: Secure Boot ECDSA P-224 Interface.
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
    it uses to interact with ECDSA signing/verification using curve P-224.

    Other software may also use this interface to access other parts of
    the ECDSA functionality, including key generation and signing.

    The interface defines SBIF_ECDSA224_WORDS, which declares the size of
    ECDSA calculated (and therefore) the size of output of output signature
    and domain parameters. The value is always 8.
*/

#ifndef INCLUDE_GUARD_SB_SW_ECDSA224_H
#define INCLUDE_GUARD_SB_SW_ECDSA224_H

#include "public_defs.h"
#include "sbif.h"
#include "sb_sw_ecdsa_common.h"

#define SBIF_ECDSA224_WORDS 7
#define SBIF_ECDSA224_BYTES 28

/* Point */
struct SB_SW_ECDSA_Point224
{
    uint32_t x[SBIF_ECDSA224_WORDS];
    uint32_t y[SBIF_ECDSA224_WORDS];
};

/* Handle R+S pair as alias for point. */
#define SB_SW_ECDSA_RS224 SB_SW_ECDSA_Point224


/* Prototypes of ECDSA functions (with P-224). */
bool
SB_SW_ECDSA_KeyPair224(
    uint32_t * randomVal,
    struct SB_SW_ECDSA_Point224 * const Q_p,
    bool * const again);

bool
SB_SW_ECDSA_Sign224(
    const uint8_t * e,
    const uint32_t e_size,
    const uint32_t da[SBIF_ECDSA224_WORDS],
    struct SB_SW_ECDSA_RS224 * const RS_p,
    bool * const again);

bool
SB_SW_ECDSA_Verify224(
    SB_SW_ECDSA_Verify_Workspace_t * const wks_p,
    const uint32_t e[SBIF_ECDSA224_WORDS],
    const struct SB_SW_ECDSA_RS224 * const RS_p,
    const struct SB_SW_ECDSA_Point224 * const Q_p);

bool
SB_SW_ECDSA_Point_Check224(
    const uint8_t * const Q_p);


#endif /* INCLUDE_GUARD_SB_SW_ECDSA224_H */

/* end of file sb_sw_ecdsa224.h */
