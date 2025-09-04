/**
 *  File: ssh-glue.c
 *
 *  Description : Glues sshcrypto and sshmath to SecureBoot:
 *                replaces memory management with primitive memory management
 *                over static buffer.
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
#include "sshincludes.h"
#include "sshmp.h"
#include "sshrand.h"
#include <stdlib.h>
#include "sb_sw_rsa_common.h"

/* Ensure sizes of types correspond actual types. */
COMPILE_GLOBAL_ASSERT(sizeof(int) == SIZEOF_INT);
COMPILE_GLOBAL_ASSERT(sizeof(long) == SIZEOF_LONG);
COMPILE_GLOBAL_ASSERT(sizeof(long long) == SIZEOF_LONG_LONG);

/* Glue functions. */

/* Replace ssh_rand with random generation that gets random material
   from TRNG if available. */
#ifndef ssh_rand_REMOVE
SshUInt32 ssh_rand(void)
{
    SfzCryptoStatus status;

    uint32_t ui = 0;

    status = sfzcrypto_rand_data(NULL,
                                 sizeof(uint32_t),
                                 (uint8_t *)&ui);

    if (status != SFZCRYPTO_SUCCESS)
    {
        /* Random number generation failed: panic. */
        PANIC("Random number generation failed.");
    }

    return ui;
}
#endif /* ssh_rand_REMOVE */

/* Replace ssh_mprz_rand with random generation that gets random material
   from TRNG if available. */
#ifndef ssh_mprz_rand_REMOVE
void
ssh_mprz_rand(
        SshMPInteger op,
        unsigned int bits)
{
    uint32_t rand_words = ((bits + SSH_WORD_BITS - 1) / 8) / sizeof(SshWord);
    if (ssh_mprz_realloc(op, rand_words))
    {
        /* Reallocation succeeded, op contains enough space for the
           new integer. */

        /* Note: ssh_mprz_rand may only by called if sfzcrypto_sw_lock is
           held. */
        SfzCryptoStatus status;

        /* Fill op with randomness. */
        status = sfzcrypto_sw_gen_rand_data(
                           rand_words * sizeof(SshWord),
                           (uint8_t *) op->v,
                           SFZCRYPTO_QUALITY_SYMM_KEY_BITS(bits));

        if (status == SFZCRYPTO_SUCCESS)
        {
            op->n = rand_words;
            /* Retain bits number of the lowest order bits. */
            ssh_mprz_mod_2exp(op, op, bits);
        }
        else
        {
            /* Indicate rng failure with nan.
               There is no nan for this situation, so pick one of the others.
               Division by zero used. */
            ssh_mprz_makenan(op, SSH_MP_NAN_EDIVZERO);
        }
    }
    else
    {
        /* reallocation already marked op as nan/nomem. */
    }
}
#endif /*ssh_mprz_rand_REMOVE */

#ifdef SSH_MEMORY_ACCOUNTING
volatile unsigned long ssh_malloc_count;
volatile unsigned long ssh_free_count;
#endif

uint8_t ssh_mem[SSH_MEM_SIZE] = {0xba};
ShhMemInfo_t ssh_mem_info[SSH_MEM_MAX_REQ];
uint32_t ssh_mem_used = 0;
uint32_t ssh_mem_index = 0;

void sb_sw_release_ssh_memory(void)
{
    ssh_mem_used = 0;
    ssh_mem_index = 0;
}

/* Use primitive memory management. */
#ifndef ssh_malloc_REMOVE
void *ssh_malloc(const size_t Size)
{
    void *ptr;

    if (Size <= (SSH_MEM_SIZE - ssh_mem_used))
    {
        if ((ssh_mem_index + 1) >= SSH_MEM_MAX_REQ)
        {
            ptr = NULL;
            ssh_fatal("ssh_malloc: Too many requests for allocation. Increase SSH_MEM_MAX_REQ\n");
        }
        else
        {
            unsigned long temp0 = (unsigned long)&ssh_mem[ssh_mem_used];
            unsigned long temp1 = (temp0 + 3) & (~(unsigned long)3);
            ptr = (void*)temp1;
            ssh_mem_used += (uint32_t)Size + (uint32_t)(temp1 - temp0);
            ssh_mem_info[ssh_mem_index].address = (unsigned long)ptr;
            ssh_mem_info[ssh_mem_index].size = (uint32_t)Size;
            ssh_mem_info[ssh_mem_index].index = ssh_mem_index;
            ssh_mem_index++;
        }
    }
    else
    {
        ptr = NULL;
        ssh_fatal("ssh_malloc: Not enough static memory for new allocation. Increase SSH_MEM_SIZE\n");
    }
    return ptr;
}
#endif /* ssh_malloc_REMOVE */

#ifndef ssh_calloc_REMOVE
void *ssh_calloc(const size_t MemberCount, const size_t MemberSize)
{
    /* Adjust to differences between ssh_calloc and SPAL_Memory_Calloc.
       ssh_calloc always allocates something: */

    void *ptr = NULL;

#ifdef SSH_MEMORY_FAIL_IDX
#ifdef SSH_MEMORY_ACCOUNTING
    if (ssh_malloc_count == SSH_MEMORY_FAIL_IDX) ptr = NULL; else
#endif
#endif

    if (MemberCount == 0 || MemberSize == 0)
    {
        ptr = malloc(1);
    }
    else
    {
        ptr = calloc(MemberCount, MemberSize);
    }

#ifdef SSH_MEMORY_ACCOUNTING
        if (ptr) ssh_malloc_count++;
#endif
    return ptr;
}
#endif /* ssh_calloc_REMOVE */

#ifndef ssh_xmalloc_REMOVE
void *ssh_xmalloc(const size_t size)
{
  void *ptr = NULL;

  if ((ptr = ssh_malloc(size)) == NULL)
    ssh_fatal("ssh_xmalloc: Can not allocate %zd bytes of memory.", size);
  return ptr;
}
#endif /* ssh_xmalloc_REMOVE */

#ifndef ssh_free_REMOVE
void ssh_free(void *MemoryArea)
{
    /* Free only if it is last block */
    if (ssh_mem_info[ssh_mem_index - 1].address == (unsigned long)MemoryArea)
    {
        ssh_mem_used -= ssh_mem_info[ssh_mem_index - 1].size;
        ssh_mem_index--;
    }
}
#endif /* ssh_free_REMOVE */

#ifndef ssh_xfree_REMOVE
void ssh_xfree(void *MemoryArea)
{
    ssh_free(MemoryArea);
}
#endif /* ssh_xfree_REMOVE */


/* end of file ssh-glue.c */
