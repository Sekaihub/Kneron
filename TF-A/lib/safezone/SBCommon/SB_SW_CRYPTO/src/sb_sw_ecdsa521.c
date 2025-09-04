/* sb_sw_ecdsa521.c
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
#include "sb_sw_ecdsa521.h"
#include "uECC.h"
#include "c_lib.h"

#ifdef SUPPORT_POINT_VALIDATION
bool
SB_SW_ECDSA_Point_Check521(
    const uint8_t * const Q_p)
{
    int status = 0;
    bool ret = false;
    const struct uECC_Curve_t * curve = uECC_secp521r1();
    uint8_t PublicKey[2*((SBIF_ECDSA521_BYTES+3)&~3)];

    c_memcpy(PublicKey, ((const uint8_t *)Q_p), SBIF_ECDSA521_BYTES);
    c_memcpy(PublicKey + SBIF_ECDSA521_BYTES + 2, ((const uint8_t *)Q_p) + SBIF_ECDSA521_BYTES, SBIF_ECDSA521_BYTES);
    PublicKey[66] = 0;
    PublicKey[67] = 0;
    PublicKey[134] = 0;
    PublicKey[135] = 0;

    status = uECC_valid_public_key((const uint8_t *)PublicKey, curve);
    if (status == 1)
    {
        ret = true;
    }
    /* Point order is incorrect. */
    return ret;
}
#endif

bool
SB_SW_ECDSA_Verify521(
    SB_SW_ECDSA_Verify_Workspace_t * const wks_p,
    uint8_t e[SBIF_ECDSA521_BYTES],
    const struct SB_SW_ECDSA_RS521 * const RS_p,
    const struct SB_SW_ECDSA_Point521 * const Q_p)
{
    int status = 0;
    bool ret = false;
    const struct uECC_Curve_t * curve = uECC_secp521r1();
    uint8_t PublicKey[2*((SBIF_ECDSA521_BYTES+3)&~3)];

    IDENTIFIER_NOT_USED(wks_p);

    c_memcpy(PublicKey, ((const uint8_t *)Q_p), SBIF_ECDSA521_BYTES);
    c_memcpy(PublicKey + SBIF_ECDSA521_BYTES + 2, ((const uint8_t *)Q_p) + SBIF_ECDSA521_BYTES, SBIF_ECDSA521_BYTES);
    PublicKey[66] = 0;
    PublicKey[67] = 0;
    PublicKey[134] = 0;
    PublicKey[135] = 0;
    e[64] = 0;
    e[65] = 0;

    status = uECC_verify(PublicKey, (const uint8_t *)e, SBIF_ECDSA521_BYTES, (const uint8_t *)RS_p, curve);
    if (status == 1)
    {
        ret = true;
    }
    /* Point order is incorrect. */
    return ret;
}

/* end of file sb_sw_ecdsa256.c */
