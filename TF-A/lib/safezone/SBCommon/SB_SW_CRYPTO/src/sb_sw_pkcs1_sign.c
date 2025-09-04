/* sb_sw_pkcs1_sign.c
 *
 * Description: This file contains support routines for RSA procedures
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
 * Function name:   sb_sw_pkcs1_pad_prepare                                  *
 *****************************************************************************/
/* Fails if p_output_buffer is of insufficient length. */

static bool
sb_sw_pkcs1_pad_prepare(size_t input_buffer_len,
                        uint8_t tag_number,
                        uint8_t * output_buffer_p,
                        size_t output_buffer_len)
{
    uint32_t padding_length = 0;
    bool status = true;

    /* argument validation */
    if (NULL == output_buffer_p)
    {
        status = false;
    }

    if (true == status)
    {
        padding_length = (uint32_t)(output_buffer_len - input_buffer_len);
        if (output_buffer_len < input_buffer_len ||
            padding_length < SFZCRYPTO_PKCS1_FIX_PAD)
        {
            status = false;
        }
    }

    if (true == status)
    {
        if (1 == tag_number)
        {
            /* Block type 1 (used with signatures). */
            c_memset(output_buffer_p + 2, 0xff, padding_length - 3);
            /* Write tag number (block type). */
            output_buffer_p[0] = 0x0;
            output_buffer_p[1] = tag_number;
        }
        else
        {
            status = false;
        }
    }

    if (true == status)
    {
        /* The final padding byte is always zero. */
        output_buffer_p[padding_length - 1] = 0x0;
    }
    return status;
}

/*!***************************************************************************
 * Function name:   sb_sw_pkcs1_wrap_and_pad                                 *
 *****************************************************************************/
static bool
sb_sw_pkcs1_wrap_and_pad(const uint8_t * encoded_oid_p,
                         size_t encoded_oid_len,
                         const uint8_t * digest_p,
                         size_t digest_len,
                         uint8_t tag_number,
                         uint8_t * output_buffer_p,
                         size_t output_buffer_len)
{
    uint32_t padding_length, input_buffer_len;
    bool status = true;

    input_buffer_len = (uint32_t)(encoded_oid_len + digest_len);
    padding_length = (uint32_t)(output_buffer_len - input_buffer_len);

    /* argument validation */
    if ((NULL == output_buffer_p) || (NULL == encoded_oid_p))
    {
        status = false;
    }

    if (true == status)
    {
        if (!sb_sw_pkcs1_pad_prepare(input_buffer_len,
                                     tag_number,
                                     output_buffer_p,
                                     output_buffer_len))
        {
            status = false;
        }
    }

    if (true == status)
    {
        c_memcpy(output_buffer_p + padding_length,
                 encoded_oid_p,
                 encoded_oid_len);

        c_memcpy(output_buffer_p + padding_length + encoded_oid_len,
                digest_p,
                digest_len);
    }

    return status;
}


/*!***************************************************************************
 * Function name:   sb_sw_pkcs1_sign                                         *
 *****************************************************************************/
SfzCryptoStatus
sb_sw_pkcs1_sign(uint16_t hash_algo,
                 uint8_t * digest_p,
                 uint32_t digest_len,
                 size_t max_output_msg_len,
                 uint8_t * output_msg_p,
                 size_t * const output_msg_len_p)
{
    const uint8_t * encoded_oid_p;
    size_t encoded_oid_len;
    bool rv;
    SfzCryptoStatus status = SFZCRYPTO_OPERATION_FAILED;

    if ((encoded_oid_p = sb_sw_hash_encoded_asn1_oid(hash_algo)) == NULL)
    {
        status = SFZCRYPTO_INTERNAL_ERROR;
        goto FUNC_RETURN;
    }

    if ((encoded_oid_len = sb_sw_hash_encoded_asn1_oid_len(hash_algo)) == 0)
    {
        status = SFZCRYPTO_INTERNAL_ERROR;
        goto FUNC_RETURN;
    }

    rv = sb_sw_pkcs1_wrap_and_pad(encoded_oid_p,
                                  encoded_oid_len,
                                  digest_p,
                                  digest_len,
                                  SFZCRYPTO_PKCS1_SIGN_VERIFY_TAG,
                                  output_msg_p,
                                  max_output_msg_len);

    if (rv)
    {
        *output_msg_len_p = max_output_msg_len;
        status = SFZCRYPTO_SUCCESS;
    }

FUNC_RETURN:
    return status;
}


/* end of file sb_sw_pkcs1_sign.c */
