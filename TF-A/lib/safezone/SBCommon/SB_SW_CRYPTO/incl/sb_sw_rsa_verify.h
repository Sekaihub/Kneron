/* sb_sw_rsa_verify.h
 *
 * Description: Secure Boot RSA Verify Interface.
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

#ifndef INCLUDE_GUARD_SB_SW_RSA_VERIFY_H
#define INCLUDE_GUARD_SB_SW_RSA_VERIFY_H

#include "sb_sw_rsa_common.h"

bool
SB_SW_RSA_Verify(
    uint8_t                 Digest[RSA_DIGEST_BYTES],
    SfzCryptoBigInt *       Signature_p,
    BIG_INT_EXP *           PubkeyExp_p,
    SfzCryptoBigInt *       Modulus_p,
    uint8_t                 AlgoType);

#endif /* INCLUDE_GUARD_SB_SW_RSA_VERIFY_H */

/* end of file sb_sw_rsa_verify.h */
