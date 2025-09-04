/* sb_sw_rsa_verify.c
 *
 * Description: RSA verification related calculations
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

#include "sb_sw_rsa_verify.h"
#include "sbif.h"

#ifdef SUPPORT_RSA_PKCS
/*!***************************************************************************
 * Function name:   sb_sw_pkcs1_unpad                                  *
 *****************************************************************************/
static bool
sb_sw_pkcs1_unpad(const uint8_t * input_buffer_p,
                  size_t input_buffer_len,
                  uint32_t tag_number,
                  uint8_t * output_buffer_p,
                  size_t output_buffer_len,
                  int32_t * ret_len_p)
{
    uint32_t i;
    bool status = true;

    /* argument validation */
    if ((NULL == input_buffer_p) || (NULL == output_buffer_p))
    {
        status = false;
    }

    if (status)
    {
        /* Check for valid block. */
        if (input_buffer_p[0] != 0 || input_buffer_p[1] != tag_number)
        {
            status = false;
        }
    }

    if (status)
    {
        /* Block type 1 (used with signatures). */
        if (1 == tag_number)
        {
            for (i = 2; i < input_buffer_len; i++)
            {
                if (input_buffer_p[i] != 0xff)
                {
                    break;
                }
            }

            /* Check there is enough padding and the output buffer is
               big enough. */
            if (i < 10 || input_buffer_p[i] != 0x0 ||
                output_buffer_len < input_buffer_len - i - 1)
            {
                status = false;
            }

            if (true == status)
            {
                /* Step over the final 0 padding byte. */
                i++;

                /* Copy. */
                c_memmove(output_buffer_p,
                          input_buffer_p + i,
                          input_buffer_len - i);
                *ret_len_p = (int32_t)(input_buffer_len - i);
            }
        }
    }

    return status;
}

/*!***************************************************************************
 * Function name:   sb_sw_pkcs1_verify                                   *
 *****************************************************************************/
static SfzCryptoStatus
sb_sw_pkcs1_verify(uint16_t hash_algo,
                   uint8_t * digest_p,
                   uint32_t digest_len,
                   const uint8_t * decrypted_signature_p,
                   size_t decrypted_signature_len)
{
    uint8_t ber_buf_p[RSA_BYTES];
    const uint8_t * encoded_oid_p;
    int32_t ret_len;
    size_t encoded_oid_len;
    size_t max_output_msg_len;
    bool rv;
    SfzCryptoStatus status = SFZCRYPTO_OPERATION_FAILED;

    /* argument validation */
    if (decrypted_signature_p == NULL)
    {
        goto FUNC_RETURN;
    }

    max_output_msg_len = decrypted_signature_len;

    /* Decode the message. */
    rv = sb_sw_pkcs1_unpad(decrypted_signature_p,
                           decrypted_signature_len,
                           SFZCRYPTO_PKCS1_SIGN_VERIFY_TAG,
                           ber_buf_p,
                           max_output_msg_len, &ret_len);

    if (!rv)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    encoded_oid_p = sb_sw_hash_encoded_asn1_oid(hash_algo);
    encoded_oid_len = sb_sw_hash_encoded_asn1_oid_len(hash_algo);

    if ((NULL == encoded_oid_p) || (0 == encoded_oid_len) ||
        ((uint32_t)ret_len < encoded_oid_len + digest_len))
    {
        status = SFZCRYPTO_INTERNAL_ERROR;
        goto FUNC_RETURN;
    }

    if (((uint32_t)ret_len != encoded_oid_len + digest_len))
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    /* Compare. */
    if (c_memcmp(ber_buf_p + encoded_oid_len, digest_p, digest_len) == 0 &&
        c_memcmp(ber_buf_p, encoded_oid_p, encoded_oid_len) == 0)
    {
        status = SFZCRYPTO_SUCCESS;
    }
    else
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
    }

FUNC_RETURN:
    return status;
}
#endif /* SUPPORT_RSA_PKCS */

#ifdef SUPPORT_RSA_PSS
/*!***************************************************************************
 * Function name:   sb_sw_rsa_pss_decode                                     *
 *****************************************************************************/
static SfzCryptoStatus
sb_sw_rsa_pss_decode(uint8_t hash_algo,
                     size_t salt_len,
                     size_t maximal_bit_length,
                     uint8_t * msg_digest_p,
                     size_t msg_digest_len,
                     uint8_t * emsg_p,
                     size_t emsg_len)
{
    uint8_t digest[RSA_DIGEST_BYTES];
    uint8_t db_p [RSA_BYTES];
    uint8_t *salt_p = NULL;
    uint8_t tmp[8 + RSA_DIGEST_BYTES + RSA_DIGEST_BYTES];
    uint8_t mask;
    uint32_t i;
    uint32_t bits;
    size_t db_len;
    size_t digest_len = msg_digest_len;
    SB_SW_HASH_Context_t hash_ctx;
    SfzCryptoStatus status = SFZCRYPTO_SUCCESS;

    /* argument validation */
    if (NULL == emsg_p)
    {
        status = SFZCRYPTO_DATA_TOO_SHORT;
        goto FUNC_RETURN;
    }

    if (maximal_bit_length < (8 * digest_len) + (8 * salt_len) + 9)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    if (emsg_p[emsg_len - 1] != 0xbc)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    if ((maximal_bit_length + 7) / 8 != emsg_len)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    c_memset(digest, 0, RSA_DIGEST_BYTES);
    c_memset(tmp, 0, sizeof(tmp));

    bits = (uint32_t)((8 * emsg_len) - maximal_bit_length);
    mask = (uint8_t)(0xff << (8 - bits));

    if (emsg_p[0] & mask)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    db_len = emsg_len - digest_len - 1;

    status = sb_sw_rsa_mgf1(hash_algo,
                            emsg_p + emsg_len - digest_len - 1,
                            digest_len,
                            db_p,
                            db_len);

    if (SFZCRYPTO_SUCCESS != status)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    /* XOR. */
    for (i = 0; i < db_len; i++)
    {
        db_p[i] ^= emsg_p[i];
    }

    mask = 0xff;
    while (bits)
    {
        mask >>= 1;
        bits--;
    }

    db_p[0] &= mask;

    for (i = 0; i < emsg_len - digest_len - salt_len - 2; i++)
    {
        if (db_p[i] != 0x0)
        {
            status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
            goto FUNC_RETURN;
        }
    }

    if (db_p[i] != 0x1)
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
        goto FUNC_RETURN;
    }

    salt_p = db_p + (db_len - salt_len);

    c_memcpy(tmp + 8, msg_digest_p, msg_digest_len);
    c_memcpy(tmp + 8 + msg_digest_len, salt_p, salt_len);

    c_memset(&hash_ctx, 0x00, sizeof(SB_SW_HASH_Context_t));

    status = sb_sw_hash_data_256(&hash_ctx,
                                 tmp,
                                 digest,
                                 (uint32_t)(8 + msg_digest_len + salt_len));

    if (SFZCRYPTO_SUCCESS != status)
    {
        goto FUNC_RETURN;
    }

    /* Compare the hash digests */
    if (c_memcmp(digest, emsg_p + emsg_len - digest_len - 1, digest_len))
    {
        status = SFZCRYPTO_SIGNATURE_CHECK_FAILED;
    }

FUNC_RETURN:
    return status;
}
#endif /* SUPPORT_RSA_PSS */

bool
SB_SW_RSA_Verify(uint8_t Digest[RSA_DIGEST_BYTES],
                 SfzCryptoBigInt * Signature_p,
                 BIG_INT_EXP * PubkeyExp_p,
                 SfzCryptoBigInt * Modulus_p,
                 uint8_t AlgoType)
{
    SfzCryptoStatus status;
    bool ret = false;
    SfzCryptoBigInt big_plaintext;

    c_memset(big_plaintext.data, 0, Modulus_p->byteLen);
    big_plaintext.byteLen = Modulus_p->byteLen;

    status = sb_sw_big_exp_act4(Signature_p,
                                PubkeyExp_p,
                                Modulus_p,
                                &big_plaintext);

    if (SFZCRYPTO_SUCCESS == status)
    {
#ifdef SUPPORT_RSA_PKCS
        if (SFZRSA_ALGO_PKCS == AlgoType)
        {
            status = sb_sw_pkcs1_verify(SFZCRYPTO_ALGO_HASH_SHA256,
                                        Digest,
                                        RSA_DIGEST_BYTES, /*digest len */
                                        big_plaintext.data,
                                        big_plaintext.byteLen);
        }
        else
#endif

#ifdef SUPPORT_RSA_PSS
        if (SFZRSA_ALGO_PSS == AlgoType)
        {
            uint32_t salt_len = RSA_DIGEST_BYTES;
            uint32_t maximal_bit_length = Modulus_p->byteLen * 8;
            uint32_t sig_len = Signature_p->byteLen;

            status = sb_sw_rsa_pss_decode(SFZCRYPTO_ALGO_HASH_SHA256,
                                          salt_len,
                                          maximal_bit_length - 1,
                                          Digest,
                                          RSA_DIGEST_BYTES,
                                          big_plaintext.data,
                                          sig_len);
        }
        else
#endif
        {
            status = SFZCRYPTO_INVALID_ALGORITHM;
        }
    }

    if (SFZCRYPTO_SUCCESS == status)
    {
        ret = true;
    }

    sb_sw_release_ssh_memory();

    return ret;
}

/* end of file sb_sw_rsa_verify.c */
