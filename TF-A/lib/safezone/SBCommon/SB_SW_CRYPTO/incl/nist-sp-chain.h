/* nist-sp-chain.h
 *
 * Description: File backed chaining of NIST-SP-800-90 random number generators.
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
#include "nist-sp-800-90.h"

#ifndef INCLUDE_GUARD_NIST_SP_CHAIN_H
#define INCLUDE_GUARD_NIST_SP_CHAIN_H

typedef struct RngChainRec
{
    SshDrbgState state_main;
    SshDrbgState state_child;
    bool read_state;
    bool entropy_slow;
    union
    {
        uint32_t alloc_status;
        SshDrbgStateEstimateStruct structure;
    } state_main_storage;
    union
    {
        uint32_t alloc_status;
        SshDrbgStateEstimateStruct structure;
    } state_child_storage;
} RngChainStruct;

typedef RngChainStruct *RngChain;

RngChain
sfz_random_nist_chain_init(RngChain preallocated,
                           bool nonblock);

void
sfz_random_nist_chain_uninit(RngChain RngChain_p);

bool
sfz_random_nist_chain_seed(RngChain RngChain_p,
                           void *seed_p,
                           rngsize_t seed_size);

bool
sfz_random_nist_chain_generate(RngChain random_state,
                               void *target_p,
                               rngsize_t target_size,
                               unsigned int quality_bits);

#endif /* INCLUDE_GUARD_NIST_SP_CHAIN_H */

/* end of file nist-sp-chain.h */
