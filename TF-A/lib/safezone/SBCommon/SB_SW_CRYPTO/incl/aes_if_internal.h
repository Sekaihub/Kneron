/**
 *  File: aes_if_internal.h
 *
 *  Description: Definition of context structure for aes_if.c.
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

#ifndef INCLUDE_GUARD_AES_IF_INTERNAL_H
#define INCLUDE_GUARD_AES_IF_INTERNAL_H

#include "public_defs.h"
#include "aes_if.h"
#include "cfg_sbif.h"

/* Define struct AES_IF_Ctx, used internally. */
struct AES_IF_Ctx
{
    uint8_t Key[SBIF_CFG_CONFIDENTIALITY_BITS / 8];
    AES_IF_ResultCode_t Result;
    uint32_t IV[4];
};

#endif /* INCLUDE_GUARD_AES_IF_INTERNAL_H */

/* end of file aes_if_internal.h */
