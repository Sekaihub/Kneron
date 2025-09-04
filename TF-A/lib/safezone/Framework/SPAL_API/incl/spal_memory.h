/* spal_memory.h
 *
 * Description: Memory management routines
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

#ifndef INCLUDE_GUARD_SPAL_MEMORY_H_
#define INCLUDE_GUARD_SPAL_MEMORY_H_

#include "public_defs.h"

void *
SPAL_Memory_Alloc(
    const size_t Size);


void
SPAL_Memory_Free(
    void * const Memory_p);


void *
SPAL_Memory_Calloc(
    const size_t MemberCount,
    const size_t MemberSize);


void *
SPAL_Memory_ReAlloc(
    void * const Mem_p,
    size_t NewSize);

#endif /* Include guard */

/* end of file spal_memory.h */
