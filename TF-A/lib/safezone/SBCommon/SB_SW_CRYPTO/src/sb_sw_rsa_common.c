/* sb_sw_rsa_common.c
 *
 * Description: RSA common calculations
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

#include "endian_utils.h"
#include "c_lib.h"
#include "sb_sw_rsa_common.h"
#include "sshincludes.h"
#include "sshmp.h"

/* Map NaN type to SfzCryptoStatus.
   If the operand is not NaN, SFZCRYPTO_SUCCESS is returned. */
#ifndef ssh_mprz_nan_status_REMOVE
static SfzCryptoStatus ssh_mprz_nan_status(SshMPInteger op)
{
    if (!ssh_mprz_isnan(op)) return SFZCRYPTO_SUCCESS;

    /* Check for memory allocation failure. */
    if (op == NULL || op->nankind & SSH_MP_NAN_ENOMEM)
    {
        return SFZCRYPTO_NO_MEMORY;
    }

    /* Other kind of NaNs have no equivalent in SFzCryptoStatus,
       just return failure. */
    return SFZCRYPTO_OPERATION_FAILED;
}
#endif /* ssh_mprz_nan_status_REMOVE */

#define CALSOFTIMP_TRANSLATE_NAN(sshvarname)                            \
     ssh_mprz_nan_status(&sshvarname)


SfzCryptoStatus
sb_sw_big_exp_act4(SfzCryptoBigInt * const base_p,
                   BIG_INT_EXP * const exp_p,
                   SfzCryptoBigInt * const modulus_p,
                   SfzCryptoBigInt * const result_p)
{
    SfzCryptoStatus status;
    SshMPIntegerStruct base, e, m, res;

    CALSOFTIMP_BIGINT_TO_CL(base, base_p, 0);
    CALSOFTIMP_BIGINT_TO_CL(e, exp_p, 0);
    CALSOFTIMP_BIGINT_TO_CL(m, modulus_p, 0);
    /* Get storage for result. bigPow internally uses few extra bytes. */
    CALSOFTIMP_NEW_CL(res, modulus_p->byteLen + 4);

    ssh_mprz_powm(&res, &base, &e, &m);

    if ((status = CALSOFTIMP_TRANSLATE_NAN(res)) == SFZCRYPTO_SUCCESS)
    {
        CALSOFTIMP_CL_TO_BIGINT_N(result_p, res, modulus_p->byteLen);
    }

    CALSOFTIMP_BIGINT_FREE(base);
    CALSOFTIMP_BIGINT_FREE(e);
    CALSOFTIMP_BIGINT_FREE(m);
    CALSOFTIMP_BIGINT_FREE(res);

    return status;
}

#ifdef SUPPORT_RSA_PSS
SfzCryptoStatus
sb_sw_hash_data_256(SB_SW_HASH_Context_t * const p_hash_ctx,
                    uint8_t * p_in,
                    uint8_t * p_out,
                    uint32_t length)
{
    uint32_t temp[RSA_DIGEST_BYTES / sizeof(uint32_t)];

    if ((p_hash_ctx == NULL) || (p_in == NULL) || (p_out == NULL))
    {
        return SFZCRYPTO_INVALID_PARAMETER;
    }

    SB_SW_HASH_Init(p_hash_ctx, 256);
    SB_SW_HASH_FinalUpdate(p_hash_ctx, p_in, length, temp);
    reverse_memcpy(p_out, temp, RSA_DIGEST_BYTES);

    return SFZCRYPTO_SUCCESS;
}

SfzCryptoStatus
sb_sw_rsa_mgf1(uint32_t hash_algo,
               uint8_t * seed_p,
               size_t seed_len,
               uint8_t * mask_p,
               size_t mask_len)
{
    size_t i;
    uint32_t steps;
    uint8_t digest[RSA_DIGEST_BYTES];
    size_t digest_len;
    SB_SW_HASH_Context_t hash_ctx;
    SfzCryptoStatus status = SFZCRYPTO_OPERATION_FAILED;
    uint8_t tmp_buf[40];

    (void)hash_algo;

    /* argument validation */
    if (mask_p == NULL)
    {
        status = SFZCRYPTO_DATA_TOO_SHORT;
        goto FUNC_RETURN;
    }

    c_memset(digest, 0x00, sizeof(digest));

    digest_len = RSA_DIGEST_BYTES;

    for (i = 0, steps = 0; i < mask_len; i += digest_len, steps++)
    {
        union
        {
            uint8_t counter[SFZCRYPTO_PSS_CTR_SIZE];
            SshUInt32 v32;
        } u;
        size_t  avail;

        BE32_WRITE(&u.v32, steps);

        c_memset(&hash_ctx, 0x00, sizeof(SB_SW_HASH_Context_t));
        c_memset(tmp_buf, 0x00, sizeof(tmp_buf));

        c_memcpy(tmp_buf, seed_p, seed_len);
        c_memcpy(tmp_buf + seed_len, u.counter, SFZCRYPTO_PSS_CTR_SIZE);

        status = sb_sw_hash_data_256(&hash_ctx,
                                     tmp_buf,
                                     digest,
                                     (uint32_t)(seed_len + SFZCRYPTO_PSS_CTR_SIZE));

        if (SFZCRYPTO_SUCCESS != status)
        {
            goto FUNC_RETURN;
        }

        /* Now copy the digest to the mask. */
        avail = mask_len - i;
        if (avail >= digest_len)
        {
            c_memcpy(mask_p + i, digest, digest_len);
        }
        else
        {
            c_memcpy(mask_p + i, digest, avail);
        }
    }

FUNC_RETURN:
    return status;
}
#endif /* SUPPORT_RSA_PSS */

/* end of file sb_sw_rsa_common.c */
