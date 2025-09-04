/* sb_sw_rsa_sign.c
 *
 * Description: RSA signing related calculations
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
#include "c_lib.h"
#include "sb_sw_rsa_sign.h"

/*!***************************************************************************
 * Function name:   sb_sw_rsa_sign                                           *
 *****************************************************************************/
bool
SB_SW_RSA_Sign(SfzCryptoBigInt * const p_modulus,
               SfzCryptoBigInt * const p_privexp,
               SfzCryptoBigInt * const p_signature,
               uint8_t * digest,
               uint32_t digest_len,
               SfzRsaAlgo algo)
{
    bool rv = false;
    SfzCryptoStatus status = SFZCRYPTO_OPERATION_FAILED;
    uint32_t max_output_msg_len = 0;
    size_t output_msg_len = 0;
    SfzCryptoBigInt big_text;

    c_memset(big_text.data, 0, sizeof(big_text.data));
    big_text.byteLen = 0;

    if ((p_modulus->byteLen == 0) || (p_privexp->byteLen == 0) ||
        (digest == NULL) || (digest_len == 0))
    {
        return false;
    }

    max_output_msg_len = p_modulus->byteLen & (uint32_t)(~1);

    if (algo == SFZRSA_ALGO_PKCS)
    {
        status = sb_sw_pkcs1_sign(SFZCRYPTO_ALGO_HASH_SHA256,
                                  digest,
                                  digest_len,
                                  max_output_msg_len,
                                  (uint8_t*)big_text.data,
                                  &output_msg_len);
        big_text.byteLen = (uint32_t)output_msg_len;
    }
    else if (algo == SFZRSA_ALGO_PSS)
    {
        uint32_t maximal_bit_length = max_output_msg_len * 8;
        uint32_t salt_len = digest_len;
        status = sb_sw_pss_encode(SFZCRYPTO_ALGO_HASH_SHA256,
                                  salt_len,
                                  maximal_bit_length - 1,
                                  digest,
                                  digest_len,
                                  (uint8_t*)big_text.data,
                                  max_output_msg_len);
        big_text.byteLen = (uint32_t)max_output_msg_len;
    }
    else
    {
        status = SFZCRYPTO_INVALID_ALGORITHM;
    }

    if (status == SFZCRYPTO_SUCCESS)
    {
        /* RSA encryption operation done here */
        status = sb_sw_big_exp_act4(&big_text,
                                    p_privexp,
                                    p_modulus,
                                    p_signature);

        if (p_signature->byteLen & 1)
        {
            p_signature->byteLen--;
            c_memmove(&p_signature->data[0],
                      &p_signature->data[1],
                      p_signature->byteLen);
        }
    }

    if (status == SFZCRYPTO_SUCCESS){
        rv = true;
    }

    sb_sw_release_ssh_memory();

    return rv;
}

/* end of file sb_sw_rsa_sign.c */
