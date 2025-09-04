/* sb_sw_rsa_common.h
 *
 * Description: Secure Boot RSA Common Interface.
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

#ifndef INCLUDE_GUARD_SB_SW_RSA_COMMON_H
#define INCLUDE_GUARD_SB_SW_RSA_COMMON_H

#include "implementation_defs.h"
#include "c_lib.h"
#include "sb_sw_hash.h"
#ifdef VERIFY_ONLY
#include "sbif.h"
#define RSA_BYTES SBIF_RSA_BYTES
#else
#define RSA_BYTES 512
#endif

#ifndef RSA_DIGEST_BYTES
#define RSA_DIGEST_BYTES 32
#endif

/*----------------------------------------------------------------------------
 * SfzCryptoStatus
 */
typedef enum
{
    SFZCRYPTO_SUCCESS = 0,             /* Success. */
    SFZCRYPTO_UNSUPPORTED,             /* Not supported. */
    SFZCRYPTO_BAD_ARGUMENT,            /* wrong use; not depending on configuration. */
    SFZCRYPTO_FEATURE_NOT_AVAILABLE,   /* Current implementation does not have this feature. */
    SFZCRYPTO_NOT_INITIALISED,         /* sfzcrypto has not been initialized yet. */
    SFZCRYPTO_ALREADY_INITIALIZED,     /* sfzcrypto has already been initialized. */
    SFZCRYPTO_INVALID_PARAMETER,       /* Invalid parameter. */
    SFZCRYPTO_INVALID_KEYSIZE,         /* Invalid key size. */
    SFZCRYPTO_INVALID_LENGTH,          /* Invalid length. */
    SFZCRYPTO_INVALID_ALGORITHM,       /* If invalid algorithm code is used. */
    SFZCRYPTO_INVALID_MODE,            /* If invalid mode code is used. */
    SFZCRYPTO_INVALID_CMD,             /* If the command was invalid. */
    SFZCRYPTO_UNWRAP_ERROR,            /* Unwrap error. */
    SFZCRYPTO_VERIFY_FAILED,           /* If (signature) verification failed. */
    SFZCRYPTO_SIG_GEN_FAILED,          /* If signature generation failed. */
    SFZCRYPTO_INVALID_SIGNATURE,       /* If signature was invalid. */
    SFZCRYPTO_SIGNATURE_CHECK_FAILED,  /* Signature check failed. */
    SFZCRYPTO_DATA_TOO_SHORT,          /* Data too short. */
    SFZCRYPTO_BUFFER_TOO_SMALL,        /* Buffer supplied is too small for intended use. */
    SFZCRYPTO_NO_MEMORY,               /* No memory. */
    SFZCRYPTO_OPERATION_FAILED,        /* Operation failed. */
    SFZCRYPTO_INTERNAL_ERROR           /* Internal error. */
}
SfzCryptoStatus;

typedef enum
{
    SFZRSA_ALGO_PKCS = 1,
    SFZRSA_ALGO_PSS,
}
SfzRsaAlgo;


#define SFZCRYPTO_ALGO_HASH_SHA256 3 /* enum value from safezone */
// size in bytes used for tag and padding in PKCS #1 padding operation
#define SFZCRYPTO_PKCS1_FIX_PAD              11
// value of tag used in PKCS #1 padding when done for sign/verification
#define SFZCRYPTO_PKCS1_SIGN_VERIFY_TAG      1


#define CALSOFTIMP_BIGINT_TO_CL(bigvarname, p_sfzbigint, extra_spaceb) \
    do {                                                               \
        ASSERT(extra_spaceb == 0);                                     \
        ssh_mprz_init(&bigvarname);                                    \
        ssh_mprz_set_buf(&bigvarname,                                  \
                           (p_sfzbigint)->data,                        \
                           (p_sfzbigint)->byteLen);                    \
    } while(0)

#define CALSOFTIMP_NEW_CL(bigvarname, size) \
    do { ssh_mprz_init(&bigvarname); } while(0)

#define CALSOFTIMP_BIGINT_FREE(bigvarname) ssh_mprz_clear(&bigvarname)

#define CALSOFTIMP_CL_TO_BIGINT_N(p_sfzbigint, sshvarname, length)      \
    do {                                                                \
        (p_sfzbigint)->byteLen = (length);                              \
        ssh_mprz_get_buf((p_sfzbigint)->data,                           \
                           (p_sfzbigint)->byteLen,                      \
                           &sshvarname);                                \
    } while(0)


/* Big number structure. */
typedef struct
{
    uint8_t  data[RSA_BYTES + 4];       /* Data part. */
    uint32_t byteLen;                   /* Data length in bytes. */
} SfzCryptoBigInt;

/* Big number structure for public exponent. */
typedef struct
{
    uint8_t  data[4];                   /* Data part. */
    uint32_t byteLen;                   /* Data length in bytes. */
} SfzCryptoBigIntPubExp;

#ifdef VERIFY_ONLY
#define BIG_INT_EXP SfzCryptoBigIntPubExp
#else
#define BIG_INT_EXP SfzCryptoBigInt
#endif

void sb_sw_release_ssh_memory(void);

SfzCryptoStatus
sb_sw_big_exp_act4(SfzCryptoBigInt * const bas_p,
                   BIG_INT_EXP * const ex_p,
                   SfzCryptoBigInt * const modulu_p,
                   SfzCryptoBigInt * const resul_p);

#ifdef SUPPORT_RSA_PKCS

/*!***************************************************************************
 * Function name:   sb_sw_hash_asn1_encoded_oid                              *
 *****************************************************************************/
static const uint8_t *
sb_sw_hash_asn1_encoded_oid(uint32_t algorithm,
                            size_t * const len_p)
{
    const uint8_t *str_p = NULL;

    if (SFZCRYPTO_ALGO_HASH_SHA256 == algorithm)
    {
        static const uint8_t digestinfo_sha256[] = {
            0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
            0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
            0x00, 0x04, 0x20
        };
        if (len_p)
        {
            *len_p = 19;
        }
        str_p = (const uint8_t *)digestinfo_sha256;
    }
    else
    {
        if (0 != len_p)
        {
            *len_p = 0;
        }
        str_p = NULL;
    }

    return str_p;
}


/*!***************************************************************************
 * Function name:   sb_sw_hash_encoded_asn1_oid                              *
 *****************************************************************************/

static inline const uint8_t *
sb_sw_hash_encoded_asn1_oid(uint32_t algorithm)
{
    return sb_sw_hash_asn1_encoded_oid(algorithm, NULL);
}

/*!***************************************************************************
 * Function name:   sb_sw_hash_encoded_asn1_oid_len                          *
 *****************************************************************************/
static inline size_t
sb_sw_hash_encoded_asn1_oid_len(uint32_t algorithm)
{
    size_t len = 0;
    sb_sw_hash_asn1_encoded_oid(algorithm, &len);
    return len;
}
#endif /* SUPPORT_RSA_PKCS */

#ifdef SUPPORT_RSA_PSS

// counter size in bytes utilized in PSS operation
#define SFZCRYPTO_PSS_CTR_SIZE  4U

SfzCryptoStatus
sb_sw_hash_data_256(SB_SW_HASH_Context_t * const p_hash_ctx,
                    uint8_t * p_in,
                    uint8_t * p_out,
                    uint32_t length);

SfzCryptoStatus
sb_sw_rsa_mgf1(uint32_t hash_algo,
               uint8_t * seed_p,
               size_t seed_len,
               uint8_t * mask_p,
               size_t mask_len);
#endif /* SUPPORT_RSA_PSS */

#if ((!defined(SUPPORT_RSA_PKCS)) && (!defined(SUPPORT_RSA_PSS)))
#error "SUPPORT_RSA_PKCS or SUPPORT_RSA_PSS must be defined"
#endif

#endif /* INCLUDE_GUARD_SB_SW_RSA_COMMON_H */

/* end of file sb_sw_rsa_common.h */
