/**
 * File: minsha_init.c
 *
 * Description : Hash Initialization APIs
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
#include "sb_sw_hash.h"

#if !defined(SB_SW_HASH_SHA224) && !defined(SB_SW_HASH_SHA256) && !defined(SB_SW_HASH_SHA384) && !defined(SB_SW_HASH_SHA512)
#error "None of SB_SW_HASH_SHA224, SB_SW_HASH_SHA256, SB_SW_HASH_SHA384 or SB_SW_HASH_SHA512 is defined."
#endif /* SB_SW_HASH_* */

#ifdef SB_SW_HASH_SHA224
static const uint32_t sha224_init[8] =
{
    0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
    0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4
};
#endif

#ifdef SB_SW_HASH_SHA256
static const uint32_t sha256_init[8] =
{
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};
#endif

void
SB_SW_HASH_Init(
    SB_SW_HASH_Context_t *const ctx_p,
    uint32_t HashType)
{
#if defined(SB_SW_HASH_SHA224) || defined(SB_SW_HASH_SHA256)
    uint32_t i;
#endif

    switch (HashType)
    {
#ifdef SB_SW_HASH_SHA256
    case 256:
        ctx_p->type = 256;
        ctx_p->blocksize = 64;

        for (i = 0; i < 8; i++)
        {
            ctx_p->state[i] = sha256_init[i];
        }
        break;
#endif

#ifdef SB_SW_HASH_SHA224
    case 224:
        ctx_p->type = 224;
        ctx_p->blocksize = 64;

        for (i = 0; i < 8; i++)
        {
            ctx_p->state[i] = sha224_init[i];
        }
        break;
#endif

#ifdef SB_SW_HASH_SHA512
    case 512:
        ctx_p->type = 512;
        ctx_p->blocksize = 128;

        SB_SW_HASH_SHA512_LoadDefaultDigest(ctx_p->state);
        break;
#endif

#ifdef SB_SW_HASH_SHA384
    case 384:
        ctx_p->type = 384;
        ctx_p->blocksize = 128;

        SB_SW_HASH_SHA384_LoadDefaultDigest(ctx_p->state);
        break;
#endif

    default:
        ctx_p->type = 0;
    }

    ctx_p->bitcount = 0;                /* Reset the bit counter */
}
