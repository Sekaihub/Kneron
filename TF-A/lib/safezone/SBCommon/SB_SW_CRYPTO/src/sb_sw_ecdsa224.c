/* sb_sw_ecdsa224.c
 *
 * Description: ECDSA related calculations
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

#include "implementation_defs.h"
#include "sb_sw_ecdsa224.h"
#include "uECC.h"

#include <stdio.h>
#include <string.h>

#ifdef SUPPORT_POINT_VALIDATION
bool
SB_SW_ECDSA_Point_Check224(
    const uint8_t * const Q_p)
{
    int status = 0;
    bool ret = false;
    const struct uECC_Curve_t * curve = uECC_secp224r1();

    status = uECC_valid_public_key((const uint8_t*)Q_p, curve);
    if (status == 1)
    {
        ret = true;
    }
    /* Point order is incorrect. */
    return ret;
}
#endif

bool
SB_SW_ECDSA_Verify224(
    SB_SW_ECDSA_Verify_Workspace_t * const wks_p,
    const uint32_t e[SBIF_ECDSA224_WORDS],
    const struct SB_SW_ECDSA_RS224 * const RS_p,
    const struct SB_SW_ECDSA_Point224 * const Q_p)
{
    int status = 0;
    bool ret = false;
    const struct uECC_Curve_t * curve = uECC_secp224r1();

    IDENTIFIER_NOT_USED(wks_p);

    status = uECC_verify((const uint8_t*)Q_p, (const uint8_t*)e, SBIF_ECDSA224_BYTES, (const uint8_t*)RS_p, curve);
    if (status == 1)
    {
        ret = true;
    }
    /* Point order is incorrect. */
    return ret;
}

/* end of file sb_sw_ecdsa224.c */
