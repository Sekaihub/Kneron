/**
 *  File: sshincludes.h
 *
 *  Description : Environment (basic data types, basic utility functions)
 *                for compiling sshcrypto and sshmath.
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

/* Glue for using sshmath.h [subset of ful QuickSec sshincludes.h]. */

#ifndef SSHINCLUDES_H
#define SSHINCLUDES_H

#include "implementation_defs.h"
#include "c_lib.h"

/* sshcrypto stripping */
/* sshcipher stripping */
/* ssharcfour */
#define ssh_arcfour_ctxsize_REMOVE
#define ssh_arcfour_free_REMOVE

/* sshdes */
#define ssh_des_init_is_weak_key_REMOVE
#define ssh_des_ctxsize_REMOVE
#define ssh_des_init_with_key_check_REMOVE
#define ssh_des_cfb_REMOVE
#define ssh_des_ofb_REMOVE
#define ssh_des3_ctxsize_REMOVE
#define ssh_des3_init_with_key_check_REMOVE
#define ssh_des3_cfb_REMOVE
#define ssh_des3_ofb_REMOVE

/* sshrijndael */
#define ssh_aes_init_fb_REMOVE
#define ssh_rijndael_init_fb_REMOVE
#define ssh_rijndael_ctxsize_REMOVE
#define ssh_rijndael_ofb_REMOVE
#define ssh_rijndael_ctr_REMOVE
#define ssh_rijndael_cfb_REMOVE
#define ssh_rijndael_cbc_mac_REMOVE

/* sshhash stripping */
/* sshmd5 */
#define ssh_md5_asn1_compare_REMOVE
#define ssh_md5_asn1_generate_REMOVE
#define ssh_md5_ctxsize_REMOVE
#define ssh_md5_uninit_REMOVE
#define ssh_md5_of_buffer_REMOVE

/* sshsha */
#define ssh_sha_asn1_compare_REMOVE
#define ssh_sha_asn1_generate_REMOVE
#define ssh_sha_ctxsize_REMOVE
#define ssh_sha_uninit_REMOVE
#define ssh_sha_of_buffer_REMOVE
#define ssh_sha_96_final_REMOVE
#define ssh_sha_96_of_buffer_REMOVE
#define ssh_sha_80_final_REMOVE
#define ssh_sha_80_of_buffer_REMOVE
#define ssh_sha_transform_REMOVE
#define ssh_sha_permuted_transform_REMOVE

/* sshsha256 */
#define ssh_sha256_asn1_compare_REMOVE
#define ssh_sha256_asn1_generate_REMOVE
#define ssh_sha224_asn1_compare_REMOVE
#define ssh_sha224_asn1_generate_REMOVE
#define ssh_sha256_of_buffer_REMOVE
#define ssh_sha224_final_REMOVE
#define ssh_sha256_128_final_REMOVE
#define ssh_sha256_128_of_buffer_REMOVE
#define ssh_sha256_96_final_REMOVE
#define ssh_sha256_96_of_buffer_REMOVE
#define ssh_sha256_80_final_REMOVE
#define ssh_sha256_80_of_buffer_REMOVE

/* sshrandom stripping */
/* devrandom */
#define ssh_random_devrandom_uninit_REMOVE

/* sshglue stripping */
/* ssh-glue */
#define ssh_xmalloc_REMOVE
#define ssh_xfree_REMOVE

/* sshmath stripping */
/* sshmp-ecp */
#define ssh_ecp_copy_curve_REMOVE
#define ssh_ecp_compare_curves_REMOVE
#define ssh_ecp_set_point_REMOVE
#define ssh_ecp_set_point_from_octet_str_REMOVE
#define ssh_ecp_negate_point_REMOVE
#define ssh_ecp_compare_points_REMOVE
#define ssh_ecp_negate_projective_point_REMOVE
#define ssh_ecp_projective_add2_REMOVE
#define ssh_ecp_projective_generic_add_REMOVE
#define ssh_ecp_is_supersingular_REMOVE
#define ssh_ecp_mov_condition_REMOVE

/* sshmp-intmod */
#define ssh_mprzm_init_primeideal_REMOVE
#define ssh_mprz_set_mprzm_ideal_REMOVE
#define ssh_mprzm_get_ideal_REMOVE
#define ssh_mprzm_cmp_REMOVE
#define ssh_mprzm_mul_2exp_REMOVE
#define ssh_mprzm_pow_REMOVE
#define ssh_mprzm_pow_gg_REMOVE
#define ssh_mprzm_pow_ui_exp_REMOVE
#define ssh_mprzm_pow_precomp_init_REMOVE
#define ssh_mprzm_pow_precomp_clear_REMOVE
#define ssh_mprzm_pow_precomp_REMOVE
#define ssh_mprzm_pow_precomp_get_ideal_REMOVE
#define ssh_mprzm_dump_REMOVE

/* sshmp-powm */
#define ssh_mprz_powm_gg_REMOVE
#define ssh_mprz_powm_ui_exp_REMOVE
#define ssh_mprz_powm_precomp_init_REMOVE
#define ssh_mprz_powm_precomp_create_REMOVE
#define ssh_mprz_powm_precomp_clear_REMOVE
#define ssh_mprz_powm_precomp_destroy_REMOVE
#define ssh_mprz_powm_with_precomp_REMOVE

/* sshmp-montgomery */
#define ssh_mpmzm_mul_2exp_REMOVE
#define ssh_mpmzm_pow_ui_REMOVE
#define ssh_mpmzm_pow_gg_REMOVE
#define ssh_mpmzm_pow_state_alloc_REMOVE
#define ssh_mpmzm_pow_state_init_REMOVE
#define ssh_mpmzm_pow_state_iterate_REMOVE
#define ssh_mpmzm_pow_state_set_result_REMOVE
#define ssh_mpmzm_pow_state_free_REMOVE


/* ssh stripping for RSA PKCS */
#define ssh_rand_REMOVE
#define ssh_mprz_miller_rabin_REMOVE
#define ssh_mprz_is_probable_prime_REMOVE
#define ssh_mprz_rand_REMOVE
#define ssh_calloc_REMOVE
#define ssh_xmalloc_REMOVE
#define ssh_xfree_REMOVE
#define ssh_mprz_div_REMOVE
#define ssh_mprz_gcd_REMOVE
#define ssh_mprz_gcdext_REMOVE
#define ssh_mprz_invert_REMOVE
#define ssh_mpmzm_invert_REMOVE
#define ssh_mprzm_invert_REMOVE
#define ssh_mpmzm_div_2exp_REMOVE
#define ssh_mprzm_div_2exp_REMOVE
#define ssh_mpmzm_mul_ui_REMOVE
#define ssh_mprzm_mul_ui_REMOVE
#define ssh_mprzm_pow_ui_g_REMOVE
#define ssh_mprz_powm_ui_g_REMOVE
#define ssh_mpmzm_sub_REMOVE
#define ssh_mpmzm_add_REMOVE
#define ssh_mpmzm_cmp_ui_REMOVE
#define ssh_mpmzm_cmp_REMOVE
#define ssh_mprz_set_mpmzm_ideal_REMOVE
#define ssh_mprz_powm_gg_REMOVE
#define ssh_mprzm_square_REMOVE
#define ssh_mprzm_mul_REMOVE
#define ssh_mprzm_sub_REMOVE
#define ssh_mprzm_add_REMOVE
#define ssh_mprzm_cmp_ui_REMOVE
#define ssh_mprz_set_mprzm_REMOVE
#define ssh_mprzm_set_ui_REMOVE
#define ssh_mprzm_set_mprz_REMOVE
#define ssh_mprzm_set_REMOVE
#define ssh_mprzm_clear_REMOVE
#define ssh_mprzm_init_inherit_REMOVE
#define ssh_mprzm_init_REMOVE
#define ssh_mprzm_clear_ideal_REMOVE
#define ssh_mprzm_init_ideal_REMOVE
#define ssh_mprzm_nanresult2_REMOVE
#define ssh_mprzm_nanresult1_REMOVE
#define ssh_mprzm_checknan_REMOVE
#define ssh_mprzm_makenan_REMOVE
#define ssh_mprzm_isnan_REMOVE
#define ssh_mpmk_2adic_neg_REMOVE
#define ssh_mpk_gcd_REMOVE
#define ssh_mpk_mod_ui_REMOVE
#define ssh_mpk_div_REMOVE
#define ssh_mpk_mul_ui_REMOVE
#define ssh_mpk_sub_ui_REMOVE
#define ssh_mpk_add_ui_REMOVE
#define ssh_mpk_count_trailing_zeros_REMOVE
#define OMIT_SSH_MPRZ_DIV
#define OMIT_SSH_MPRZ_GCD
#define OMIT_SSH_MPRZ_GCDEXT
#define OMIT_SSH_MPRZ_DIVREM
#define OMIT_SSH_MPRZ_MOD_UI
#define OMIT_SSH_MPRZ_DECODE_UINT32_STR_NOALLOC
#define OMIT_SSH_MPRZ_ENCODE_UINT32_STR
#define OMIT_SSH_MPRZ_DECODE_RENDERED
#define OMIT_SSH_MPRZ_ENCODE_RENDERED
#define OMIT_SSH_MPRZ_SET_BUF_LSB_FIRST
#define OMIT_SSH_MPRZ_GET_BUF_LSB_FIRST
#define OMIT_SSH_BUF_TO_MP
#define OMIT_SSH_MPRZ_TO_BUF
#define OMIT_SSH_MPRZ_SET_BIT
#define OMIT_SSH_MPRZ_DIV_UI
#define OMIT_SSH_MPRZ_MUL_UI
#define OMIT_SSH_MPRZ_MOD
#define OMIT_SSH_MPRZ_SQUARE
#define OMIT_SSH_MPRZ_MUL
#define OMIT_SSH_MPRZ_SUB_UI
#define OMIT_SSH_MPRZ_ADD_UI
#define OMIT_SSH_MPRZ_SUB
#define OMIT_SSH_MPRZ_ADD
#define OMIT_SSH_MPRZ_CMP
#define OMIT_SSH_MPRZ_MOD_2EXP
#define OMIT_SSH_MPRZ_DIV_2EXP
#define OMIT_SSH_MPRZ_MUL_2EXP
#define OMIT_SSH_MPRZ_SIGNUM
#define OMIT_SSH_MPRZ_ABS
#define OMIT_SSH_MPRZ_INIT_SET_UI
#define OMIT_SSH_MPRZ_INIT_SET
#define OMIT_SSH_MPRZ_GET_WORD
#define OMIT_SSH_MPRZ_CLEAR_EXTRA
#define OMIT_SSH_MPRZ_FREE
#define OMIT_SSH_MPRZ_MALLOC
#define OMIT_SSH_MPRZ_NANRESULT2


#if defined(SSHMATH_ASSEMBLER_SUBROUTINES) && defined(__GNUC__)
/* GCC has "intrinsic" operations that often perform well for
   small memory operations. */
#define memset __builtin_memset
#define memcpy __builtin_memcpy
#define memcmp __builtin_memcmp
#define memmove __builtin_memmove
#define strncpy __builtin_strncpy
#else
/* Use c_lib for memory operations. */
#define memset c_memset
#define memcpy c_memcpy
#define memcmp c_memcmp
#define memmove c_memmove
#define strncpy c_strncpy
#endif

/* Define memory management API. */
#ifndef SSH_MEM_SIZE
#define SSH_MEM_SIZE 200000
#endif
#ifndef SSH_MEM_MAX_REQ
#define SSH_MEM_MAX_REQ 200
#endif

typedef struct {
    unsigned long address;
    uint32_t size;
    uint32_t index;
} ShhMemInfo_t;

extern uint8_t ssh_mem[SSH_MEM_SIZE];
extern ShhMemInfo_t ssh_mem_info[SSH_MEM_MAX_REQ];
extern uint32_t ssh_mem_used;
extern uint32_t ssh_mem_index;

void *ssh_malloc(const size_t Size);
void *ssh_calloc(const size_t MemberCount, const size_t MemberSize);
void *ssh_xmalloc(const size_t Size);
void ssh_free(void *MemoryArea);
void ssh_xfree(void *MemoryArea);

/* Debugging and assertations.
   SSH_DEBUG is currently omitted, assertions map to
   implementation_defs.h provided assertions.
   SSH_HEAVY_ASSERT is also omitted. */
#define SSH_DEBUG(level, format) do {} while(0)
#define SSH_HEAVY_ASSERT(condition) ((void) 0)
#define SSH_ASSERT ASSERT
#define SSH_VERIFY ASSERT
#define ssh_fatal PANIC

/* Distribution: These parts of the mathematics library are included. */
#define SSHDIST_MATH
#define SSHDIST_MATH_INTMOD
#define SSHDIST_MATH_ARITHMETIC
#define SSHDIST_MATH_SIEVE
#define SSHDIST_MATH_MONTGOMERY
#define SSHDIST_MATH_POWM
#define SSHDIST_MATH_NAF
#define SSHDIST_MATH_ECP

/* Distribution: These parts of the crypto library are included. */
#define SSHDIST_CRYPT_ZEROIZE
#define SSHDIST_CRYPTO_HASH
#define SSHDIST_CRYPTO_CIPHER
#define SSHDIST_CRYPTO_RANDOM

/* Ask code to assume small instruction chache, to minimize footprint. */
#define SSH_INSN_CACHE_SIZE 8

/* Omitted functions. */
#define OMIT_SSH_MPRZ_GET_STR
#define OMIT_SSH_MPRZ_SET_STR
#define OMIT_SSH_MPRZ_ENCODE_SSH2STYLE
#define OMIT_SSH_MPRZ_DECODE_SSH2STYLE
#define OMIT_SSH_MPRZ_RAND

/* Data types */
typedef bool Boolean;
typedef uint16_t SshUInt16;
typedef uint32_t SshUInt32;
typedef uint64_t SshUInt64;
typedef int32_t SshInt32;
typedef int64_t SshInt64;
typedef SshInt64 SshTime;

#define TRUE true
#define FALSE false
#define SSH_MP_INTEGER_BIT_SIZE_STATIC 0
#define NULL_FNPTR ((void (*)())0)

#include "sshmp-types.h"

#endif /* SSHINCLUDES_H */

/* end of file sshincludes.h */
