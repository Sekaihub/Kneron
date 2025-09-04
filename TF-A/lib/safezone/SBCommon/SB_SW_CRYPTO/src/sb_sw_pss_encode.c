/* sb_sw_pss_encode.c
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
#include "p11mep.h"

/*!***************************************************************************
 * Function name:   sb_sw_pss_encode                                           *
 *****************************************************************************/
SfzCryptoStatus
sb_sw_pss_encode(uint8_t hash_algo,
                 size_t salt_len,
                 size_t maximal_bit_length,
                 uint8_t * msg_digest_p,
                 size_t msg_digest_len,
                 uint8_t * emsg_p,
                 size_t emsg_len)
{
    uint8_t digest[RSA_DIGEST_BYTES];
    uint8_t salt_p[RSA_DIGEST_BYTES];
    uint8_t db_p[RSA_BYTES];
    uint8_t mask;
    /* 8 for zero pad */
    uint8_t tmp[8 + RSA_DIGEST_BYTES + RSA_DIGEST_BYTES];
    size_t db_len;
    uint32_t bits;
    uint32_t i;
    size_t digest_len = msg_digest_len;
    SB_SW_HASH_Context_t hash_ctx;
    SfzCryptoStatus status = SFZCRYPTO_OPERATION_FAILED;

    if (msg_digest_len != RSA_DIGEST_BYTES)
    {
        goto FUNC_RETURN;
    }

    if ((maximal_bit_length + 7) / 8 != emsg_len)
    {
        goto FUNC_RETURN;
    }

    if (maximal_bit_length < ((8 * msg_digest_len) + (8 * salt_len) + 9))
    {
        goto FUNC_RETURN;
    }

    /* Generate a random salt. */
    status = (SfzCryptoStatus)P11MEP_GenerateRandom(salt_p, salt_len);

    if (SFZCRYPTO_SUCCESS != status)
    {
        goto FUNC_RETURN;
    }

    c_memset(digest, 0, RSA_DIGEST_BYTES);
    c_memset(tmp, 0, sizeof(tmp));

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

    db_len = emsg_len - digest_len - 1;

    c_memset(db_p, 0, db_len);

    db_p[db_len - salt_len - 1] = 0x01;
    c_memcpy(db_p + db_len - salt_len, salt_p, salt_len);

    status = sb_sw_rsa_mgf1(hash_algo,
                            digest,
                            digest_len,
                            emsg_p,
                            db_len);

    if (SFZCRYPTO_SUCCESS != status)
    {
        goto FUNC_RETURN;
    }

    for (i = 0; i < db_len; i++)
    {
        emsg_p[i] ^= db_p[i];
    }

    c_memset(db_p, 0, db_len);

    bits = (uint32_t)((8 * emsg_len) - maximal_bit_length);

    mask = 0xff;
    while (bits)
    {
        mask >>= 1;
        bits--;
    }
    emsg_p[0] &= mask;

    c_memcpy(emsg_p + db_len, digest, digest_len);
    emsg_p[emsg_len - 1] = 0xbc;

    // Forget salt and tmp
    c_memset(salt_p, 0, salt_len);
    c_memset(tmp, 0, sizeof(tmp));

FUNC_RETURN:
    return status;
}


/* end of file sb_sw_pss_encode.c */
