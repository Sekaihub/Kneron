/* sbhybrid_eip28_rsa_verify.c
 *
 * Secure Boot RSA-Verify acceleration using EIP-28.
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

#ifndef __MODULE__
#define __MODULE__ "sbhybrid_eip28_rsa_verify.c"
#endif

#include "sbhybrid_internal.h"

#ifdef SBHYBRID_WITH_EIP28
#include "c_lib.h"
#include "eip28.h"

#if !defined(SUPPORT_RSA_PKCS) && !defined(SUPPORT_RSA_PSS)
#error "Either SUPPORT_RSA_PKCS or SUPPORT_RSA_PSS must be defined!"
#endif

// encoded message length
#ifdef SUPPORT_RSA_PKCS
// digest info for sha256 = 19 bytes
#define SBHYBRID_RSA_EM_BYTES  (RSA_DIGEST_BYTES+19)
#define SBHYBRID_RSA_EM_WORDS  (((SBHYBRID_RSA_EM_BYTES*8)+31)/32)
#define SBHYBRID_RSA_CMP_WORD_SIZE  SBHYBRID_RSA_EM_WORDS
#define SBHYBRID_RSA_EM_TAIL_SZ 3
#else
// PSS uses the unhashed msg, which we must hash before doing anything
// so EM size is SBIF_RSA_BYTES, and the compare word size is the digest size
#define SBHYBRID_RSA_EM_BYTES  SBIF_RSA_BYTES
#define SBHYBRID_RSA_EM_WORDS  (((SBHYBRID_RSA_EM_BYTES*8)+31)/32)
#define SBHYBRID_RSA_CMP_WORD_SIZE  (RSA_DIGEST_BYTES/4)
#define SBHYBRID_RSA_EM_TAIL_SZ 2
#endif

// word offsets, must be evenly aligned with at least two empty words inbetween
#define SBHYBRID_EIP28_E_OFFSET       0  // public key exponent offset
#define SBHYBRID_EIP28_N_OFFSET       SBHYBRID_EIP28_E_OFFSET + 4 // public key modulus offset
#define SBHYBRID_EIP28_S_OFFSET       SBHYBRID_EIP28_N_OFFSET + SBIF_RSA_WORDS + 2 // signature offset
#define SBHYBRID_EIP28_M_OFFSET       SBHYBRID_EIP28_S_OFFSET + SBIF_RSA_WORDS + 2 // result of modexp operation
#define SBHYBRID_EIP28_EM1_OFFSET     SBHYBRID_EIP28_M_OFFSET + SBHYBRID_RSA_EM_WORDS + SBHYBRID_RSA_EM_TAIL_SZ // encoded message 1
#define SBHYBRID_EIP28_EM2_OFFSET     SBHYBRID_EIP28_EM1_OFFSET + SBHYBRID_RSA_CMP_WORD_SIZE + SBHYBRID_RSA_EM_TAIL_SZ // encoded message 2

/*----------------------------------------------------------------------------
 * SBHYBRID_EIP28_Write_OctetString
 *
 * Write octet string formatted big integer to given WordOffset in PKA RAM.
 */
static inline void
SBHYBRID_EIP28_Write_OctetString(EIP28_IOArea_t * const IOArea_p,
                                 const uint32_t WordOffset,
                                 const uint32_t FillWords,
                                 const uint8_t * const Bytes_p,
                                 const uint32_t ByteCount)
{
    EIP28_BigUInt_t BigUInt;
    EIP28_Status_t EIP28_Status;

    L_TRACE(LF_SBHYBRID,
            "Writing octet string to PKARAM, "
            "WordOffset = %u, FillWords = %u, "
            "Bytes_p %p, ByteCount %u",
            WordOffset,
            (unsigned int)FillWords,
            Bytes_p,
            (unsigned int)ByteCount);

    PRECONDITION(FillWords >= (ByteCount >> 2));

    BigUInt.StoreAsMSB = true;
    BigUInt.Bytes_p = (uint8_t *)discard_const(Bytes_p);
    BigUInt.ByteCount = ByteCount;

    EIP28_Status = EIP28_Memory_PutBigUInt_CALLATOMIC(IOArea_p,
                                                      (EIP28_WordOffset_t)WordOffset,
                                                      FillWords,
                                                      &BigUInt,
                                                      NULL/* LastWordUsed_p: */);

    ASSERT(EIP28_Status == EIP28_STATUS_OK);
}

static inline void
SBHYBRID_EIP28_Get_BigInt(EIP28_IOArea_t * const IOArea_p,
                          uint8_t * Bytes_p,
                          const uint32_t ExpectedByteCount,
                          const uint32_t WordOffset,
                          const uint32_t WordCount)
{
    EIP28_Status_t EIP28_Status;
    EIP28_BigUInt_t BigUInt;
    BigUInt.StoreAsMSB = true;
    BigUInt.Bytes_p = Bytes_p; // PKA engine write directly to reserved memory
    EIP28_Status = EIP28_Memory_GetBigUInt_ZeroPad_CALLATOMIC(IOArea_p, WordOffset, WordCount,
                                                              &BigUInt, ExpectedByteCount);
    ASSERT(EIP28_Status == EIP28_STATUS_OK);
}

void
SBHYBRID_EIP28_RSAVerify_Init(SBHYBRID_EIP28_Context_t * const Verify_p,
                              const SBIF_PublicKey_t * const PublicKey_p,
                              const SBIF_Signature_t * const Signature_p)
{
    EIP28_IOArea_t * const IOArea_p = &Verify_p->EIP28_IOArea;

    L_TRACE(LF_SBHYBRID,
            "EIP28 RSA Verify init, IOArea_p = %p, Verify_p = %p, "
            "PublicKey_p = %p, Signature_p = %p.",
            (void *)IOArea_p,
            (void *)Verify_p,
            (void *)PublicKey_p,
            (void *)Signature_p);

    /* load public key modulus */
    L_TRACE(LF_SBHYBRID, "Write public key modulus value.");
    SBHYBRID_EIP28_Write_OctetString(IOArea_p, SBHYBRID_EIP28_N_OFFSET, SBIF_RSA_WORDS,
                                     PublicKey_p->modulus, SBIF_RSA_BYTES);

    /* load public key exponent */
    L_TRACE(LF_SBHYBRID, "Write public key exponent value.");
    SBHYBRID_EIP28_Write_OctetString(IOArea_p, SBHYBRID_EIP28_E_OFFSET, 1,
                                     PublicKey_p->pubkeyExp, 4);

    /* Load signature */
    L_TRACE(LF_SBHYBRID, "Write signature value.");
    SBHYBRID_EIP28_Write_OctetString(IOArea_p, SBHYBRID_EIP28_S_OFFSET, SBIF_RSA_WORDS,
                                     Signature_p->signature, SBIF_RSA_BYTES);

    Verify_p->Value_e_p = NULL;
    Verify_p->Step = 0;
}


#ifdef SUPPORT_RSA_PKCS

void
SBHYBRID_EIP28_RSA_PKCS_1_5_ENCODE(EIP28_IOArea_t * const IOArea_p,
                                   const uint8_t * digest_p,
                                   const uint8_t * EM_p)
{
    static const uint8_t digestinfo_sha256[] =
    {
        0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
        0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
        0x00, 0x04, 0x20
    };
    uint32_t oid_len = sizeof(digestinfo_sha256);
    uint8_t tmp[SBHYBRID_RSA_EM_BYTES];

    /* PKCS encode is nothing more than digestinfo + msg digest */
    c_memset(tmp, 0, SBHYBRID_RSA_EM_BYTES);
    c_memcpy(tmp, digestinfo_sha256, oid_len);
    c_memcpy(tmp+oid_len, digest_p, RSA_DIGEST_BYTES);
    //  Write encoded message to offset EM1 (= result of modexp operation)
    SBHYBRID_EIP28_Write_OctetString(IOArea_p,
                                     SBHYBRID_EIP28_EM1_OFFSET, SBHYBRID_RSA_EM_WORDS,
                                     EM_p, SBHYBRID_RSA_EM_BYTES);
    // Write PKCS encoded digest to offset EM2
    SBHYBRID_EIP28_Write_OctetString(IOArea_p,
                                     SBHYBRID_EIP28_EM2_OFFSET, SBHYBRID_RSA_EM_WORDS,
                                     tmp, SBHYBRID_RSA_EM_BYTES);

}
#else

SB_Result_t
SBHYBRID_EIP28_RSA_PSS_MGF1(SBHYBRID_SymmContext_t * const HashContext_p,
                            uint8_t * seed_p,
                            size_t seed_len,
                            uint8_t * mask_p,
                            size_t mask_len)
{
    SB_Result_t status = SB_SUCCESS;
    uint8_t digest[RSA_DIGEST_BYTES];
    uint8_t tmp_buf[40];
    uint32_t counter = 0;
    size_t i;

    c_memset(digest, 0, RSA_DIGEST_BYTES);

    for (i = 0; i < mask_len; i += RSA_DIGEST_BYTES)
    {
        size_t  avail;
        union
        {
            uint8_t counter[4];
            uint32_t v32;
        } C;
        // Convert counter to an octet string C of length 4 octets
        BE32_WRITE(&C.v32, counter);
        // concatenate seed_p and C
        c_memset(tmp_buf, 0, sizeof(tmp_buf));
        c_memcpy(tmp_buf, seed_p, seed_len);
        c_memcpy(tmp_buf + seed_len, C.counter, 4);
        // hash(seed+C)
        status = SBHYBRID_SHA2XX_Init(HashContext_p);
        if (status != SB_SUCCESS)
        {
            goto FUNC_RETURN;
        }
        status = SBHYBRID_SHA2XX_AddBlock(HashContext_p, tmp_buf, (uint32_t)(seed_len)+4, true);
        if (status != SB_SUCCESS)
        {
            goto FUNC_RETURN;
        }
        status = SBHYBRID_SHA2XX_RunFsm(HashContext_p);
        if (status != SB_SUCCESS)
        {
            goto FUNC_RETURN;
        }

        SBHYBRID_SHA2XX_GetDigest(HashContext_p, digest);

        /* Concatenate the result of hash to mask */
        avail = mask_len - i;
        if (avail >= RSA_DIGEST_BYTES)
        {
            c_memcpy(mask_p + i, digest, RSA_DIGEST_BYTES);
        }
        else
        {
            c_memcpy(mask_p + i, digest, avail);
        }
        counter++;
    }

FUNC_RETURN:
    return status;
}

SB_Result_t
SBHYBRID_EIP28_RSA_PSS_ENCODE(EIP28_IOArea_t * const IOArea_p,
                              SBHYBRID_SymmContext_t * const HashContext_p,
                              uint8_t * digest_p, // M
                              uint8_t * EM_p) // EM
{
    SB_Result_t status = SB_SUCCESS;
    uint8_t digest[RSA_DIGEST_BYTES];
    uint8_t dbMask_p[SBHYBRID_RSA_EM_BYTES];
    uint8_t tmp[8 + RSA_DIGEST_BYTES + RSA_DIGEST_BYTES];
    uint32_t bits = (uint32_t)((8 * SBHYBRID_RSA_EM_BYTES) - (SBIF_RSA_BITS-1));
    uint8_t mask = (uint8_t)(0xff << (8 - bits));
    size_t db_len = SBHYBRID_RSA_EM_BYTES - RSA_DIGEST_BYTES - 1;
    uint8_t *salt_p = NULL;
    uint32_t i;

    /* If the rightmost octet of EM does not have hexadecimal value
       0xbc, output "inconsistent" and stop. */
    if (*(EM_p+SBHYBRID_RSA_EM_BYTES-1) != 0xbc)
    {
        L_TRACE(LF_SBHYBRID,
                "EIP28 RSA PSS, rightmost octet of EM does not have hexadecimal value 0xbc (=%x)",
                *(EM_p+SBHYBRID_RSA_EM_BYTES-1));
        status = SB_ERROR_VERIFICATION;
        goto FUNC_RETURN;
    }
    // H = EM_p size of RSA_DIGEST_BYTES
    SBHYBRID_EIP28_Write_OctetString(IOArea_p,
                                     SBHYBRID_EIP28_EM1_OFFSET, SBHYBRID_RSA_CMP_WORD_SIZE,
                                     EM_p+db_len, RSA_DIGEST_BYTES);

    c_memset(tmp, 0, sizeof(tmp));
    c_memset(dbMask_p, 0, sizeof(dbMask_p));
    /* 6 If the leftmost 8*emLen - emBits bits of the leftmost octet in
       maskedDB are not all equal to zero, output "inconsistent" and
       stop.*/
    if (EM_p[0] & mask)
    {
        L_TRACE(LF_SBHYBRID,
               "EIP28 RSA PSS - leftmost octet of MaskedDB is not 0");
        status = SB_ERROR_VERIFICATION;
        goto FUNC_RETURN;
    }

    /* 7 Let dbMask = MGF(H, emLen - hLen - 1) */
    status = SBHYBRID_EIP28_RSA_PSS_MGF1(HashContext_p,
                                         (EM_p + db_len),
                                         RSA_DIGEST_BYTES,
                                         dbMask_p,
                                         db_len);

    if (status != SB_SUCCESS)
    {
        L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - MGF Failed!");
        status = SB_ERROR_VERIFICATION;
        goto FUNC_RETURN;
    }

    /* 8 Let DB = maskedDB XOR dbMask. */
    for (i = 0; i < db_len; i++)
    {
        dbMask_p[i] ^= EM_p[i];
    }

    /* 9 Set the leftmost 8emLen - emBits bits of the
       leftmost octet in DB to zero. */
    mask = 0xff;
    while (bits)
    {
        mask >>= 1;
        bits--;
    }
    dbMask_p[0] &= mask;

    /* 10 If the emLen - hLen - sLen - 2 leftmost octets of DB are not
           zero or if the octet at position emLen - hLen - sLen - 1 (the
           leftmost position is "position 1") does not have hexadecimal
           value 0x01, output "inconsistent" and stop.*/
    for (i = 0; i < SBHYBRID_RSA_EM_BYTES - RSA_DIGEST_BYTES - RSA_DIGEST_BYTES - 2; i++)
    {
        if (dbMask_p[i] != 0x0)
        {
            L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - leftmost octets of DB are not zero!");
            status = SB_ERROR_VERIFICATION;
            goto FUNC_RETURN;
        }
    }

    if (dbMask_p[i] != 0x1)
    {
        L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - Leftmost octet of dbMask is not 0x01!");
        status = SB_ERROR_VERIFICATION;
        goto FUNC_RETURN;
    }
    /* 11 Let salt be the last sLen octets of DB */
    salt_p = dbMask_p + (db_len - RSA_DIGEST_BYTES);

    /* 12 Let M' = (0x)00 00 00 00 00 00 00 00 || mHash || salt */
    /* mHash = digest_p */
    c_memcpy(tmp + 8, digest_p, RSA_DIGEST_BYTES);
    c_memcpy(tmp + 8 + RSA_DIGEST_BYTES, salt_p, RSA_DIGEST_BYTES);

    /* 13 Let H' = Hash(M'), an octet string of length hLen. */
    c_memset(digest, 0, RSA_DIGEST_BYTES);
    status = SBHYBRID_SHA2XX_Init(HashContext_p);
    if (status != SB_SUCCESS)
    {
        L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - Failed to initialize hash");
        goto FUNC_RETURN;
    }
    status = SBHYBRID_SHA2XX_AddBlock(HashContext_p,
                                      tmp,
                                      (uint32_t)(8 + RSA_DIGEST_BYTES + RSA_DIGEST_BYTES),
                                      true);
    if (status != SB_SUCCESS)
    {
        L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - Failed to add block to hash");
        goto FUNC_RETURN;
    }
    status = SBHYBRID_SHA2XX_RunFsm(HashContext_p);
    if (status != SB_SUCCESS)
    {
        L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS - Final hash failed");
        goto FUNC_RETURN;
    }
    SBHYBRID_SHA2XX_GetDigest(HashContext_p, digest);
    // final hash result of = H'
    // write H' to EM2 offset
    SBHYBRID_EIP28_Write_OctetString(IOArea_p,
                                     SBHYBRID_EIP28_EM2_OFFSET, SBHYBRID_RSA_CMP_WORD_SIZE,
                                     digest, RSA_DIGEST_BYTES);

FUNC_RETURN:
    return status;
}

#endif /* SUPPORT_RSA_PKCS */

SB_Result_t
SBHYBRID_EIP28_RSAVerify(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    const uint32_t curstep)
{
    EIP28_IOArea_t * const IOArea_p = &Verify_p->EIP28_IOArea;
    EIP28_Status_t EIP28_Status = EIP28_STATUS_OK;
    SB_Result_t res = SBHYBRID_PENDING;
    uint8_t EM_p[SBIF_RSA_BYTES];

    switch (curstep)
    {
    case 0:
        // do nothing (wait) - digest calculation has not been completed yet.
        break;
    case 1:
            // Decrypt signature -> convert to RSAVP1 format
            // M = message result, e = exponent, n = modulus, s = signature
            EIP28_Status = EIP28_StartOp_ModExp_CupAmodB_CALLATOMIC(IOArea_p,
                                                                    SBHYBRID_EIP28_E_OFFSET,
                                                                    SBHYBRID_EIP28_N_OFFSET,
                                                                    SBHYBRID_EIP28_S_OFFSET,
                                                                    1, //exponent is always 1 word
                                                                    SBIF_RSA_WORDS,
                                                                    4,
                                                                    SBHYBRID_EIP28_M_OFFSET);
            ASSERT(EIP28_Status == EIP28_STATUS_OK);
        break;
    case 2:
        ASSERT(Verify_p->Value_e_p != NULL);
        // get Encoded Message (EM)
        SBHYBRID_EIP28_Get_BigInt(IOArea_p, EM_p, SBHYBRID_RSA_EM_BYTES,
                                  SBHYBRID_EIP28_M_OFFSET, SBHYBRID_RSA_EM_WORDS);
#ifdef SUPPORT_RSA_PKCS
        // apply PKCS_1_5 encoding operation on digest and write EM's to PKA
        SBHYBRID_EIP28_RSA_PKCS_1_5_ENCODE(IOArea_p, Verify_p->Value_e_p, EM_p);
#else
        // apply PSS encoding on EM and digest and write EM's to PKA
        res = SBHYBRID_EIP28_RSA_PSS_ENCODE(IOArea_p,
                                            Verify_p->HashEngineContext_p,
                                            Verify_p->Value_e_p,
                                            EM_p);
        if (res != SB_SUCCESS)
        {
            L_TRACE(LF_SBHYBRID, "EIP28 RSA PSS encoding failed.");
        }
        else
        {
            // otherwise FSM will not continue
            res = SBHYBRID_PENDING;
        }
#endif
        break;
    case 3:
        L_TRACE(LF_SBHYBRID,
                "EIP28 RSA PKCS Compare EM1 %u, EM2 %u, "
                "lengths %u.",
                SBHYBRID_EIP28_EM1_OFFSET, SBHYBRID_EIP28_EM2_OFFSET, SBHYBRID_RSA_CMP_WORD_SIZE);

        EIP28_Status = EIP28_StartOp_Compare_AcmpB_CALLATOMIC(IOArea_p,
                                                              SBHYBRID_EIP28_EM1_OFFSET,
                                                              SBHYBRID_EIP28_EM2_OFFSET,
                                                              SBHYBRID_RSA_CMP_WORD_SIZE);
        ASSERT(EIP28_Status == EIP28_STATUS_OK);
        break;
    case 4:
        /* EM1 and EM2 */
        {
            EIP28_CompareResult_t CompareResult;

            EIP28_ReadResult_Compare(IOArea_p, &CompareResult);

            if (CompareResult != EIP28_COMPARERESULT_A_EQUALS_B)
            {
                L_DEBUG(LF_SBHYBRID, "Verification failed: EM1 and EM2 not equal");

                res = SB_ERROR_VERIFICATION;
            }
            else
            {
                L_TRACE(LF_SBHYBRID, "Verification successful.");
                res = SB_SUCCESS;
            }
        }
        break;
    default:
        L_DEBUG(LF_SBHYBRID,
                "RSA Verification Proceeded to invalid step %u",
                (unsigned int)curstep);
        res = SB_ERROR_VERIFICATION;
        break;
    }
    return res;
}

SB_Result_t
SBHYBRID_EIP28_RSAVerify_RunFsm(
    SBHYBRID_EIP28_Context_t * const Verify_p)
{
    EIP28_IOArea_t * const IOArea_p = &Verify_p->EIP28_IOArea;
    SB_Result_t res = SBHYBRID_PENDING;
    uint32_t     next_step = 0;
    bool IsReady;

    EIP28_CheckIfDone(IOArea_p, &IsReady);
    if (IsReady)
    {
        next_step = Verify_p->Step + 1;

        // in step 2 we can only proceed when the digest is available
        if (next_step == 2 && Verify_p->Value_e_p == NULL)
        {
            next_step = 0;
        }
        else
        {
            Verify_p->Step++;
            L_TRACE(LF_SBHYBRID, "FSM step %u", next_step);
        }
    }

    res = SBHYBRID_EIP28_RSAVerify(Verify_p, next_step);

    if (next_step != 0)
    {
        /*
          This function is called in polling manner so print traces
          log only when EIP28 is ready and we can do something.
        */

        if (res == SB_SUCCESS)
        {
            L_TRACE(LF_SBHYBRID, "Success.");
        }
        else if (res == SBHYBRID_PENDING)
        {
            L_TRACE(LF_SBHYBRID, "Pending.");
        }
        else
        {
            L_TRACE(LF_SBHYBRID, "ERROR %d.", res);
        }
    }

    return res;
}

void
SBHYBRID_EIP28_RSAVerify_SetDigest(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    uint8_t * Digest_p)
{
    Verify_p->Value_e_p = Digest_p;
}

#else
extern const char * sbhybrid_empty_file; /* C forbids empty source files. */
#endif /* SBHYBRID_WITH_EIP28 */

/* end of file sbhybrid_eip28_rsa-verify.c */
