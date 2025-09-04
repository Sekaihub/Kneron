/* sb_sw_rsa_sign.h
 *
 * Description: Secure Boot RSA Sign Interface.
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

#ifndef INCLUDE_GUARD_SB_SW_RSA_SIGN_H
#define INCLUDE_GUARD_SB_SW_RSA_SIGN_H

#include "sb_sw_rsa_common.h"

bool
SB_SW_RSA_Sign(SfzCryptoBigInt * const p_modulus,
               SfzCryptoBigInt * const p_privexp,
               SfzCryptoBigInt * const p_signature,
               uint8_t * digest,
               uint32_t digest_len,
               SfzRsaAlgo algo);

SfzCryptoStatus
sb_sw_pkcs1_sign(uint16_t hash_algo,
                 uint8_t * digest_p,
                 uint32_t digest_len,
                 size_t max_output_msg_len,
                 uint8_t * output_msg_p,
                 size_t * const output_msg_len_p);

SfzCryptoStatus
sb_sw_pss_encode(uint8_t hash_algo,
                 size_t salt_len,
                 size_t maximal_bit_length,
                 uint8_t * msg_digest_p,
                 size_t msg_digest_len,
                 uint8_t * emsg_p,
                 size_t emsg_len);

#endif /* INCLUDE_GUARD_SB_SW_RSA_SIGN_H */

/* end of file sb_sw_rsa_sign.h */
