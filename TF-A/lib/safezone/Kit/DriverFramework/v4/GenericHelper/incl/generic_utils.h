/* generic_utils.h
 *
 * Description: generic helper functions.
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

#ifndef INCLUDE_GUARD_GENERIC_UTILS_H
#define INCLUDE_GUARD_GENERIC_UTILS_H

#include "implementation_defs.h"

/* Discard const qualifier from pointer */
static inline void *
discard_const(const void * Ptr_p)
{
    union
    {
        const void * c_p;
        void * n_p;
    } Conversion;

    Conversion.c_p = Ptr_p;
    return Conversion.n_p;
}

static inline void *
reverse_memcpy(void * Dest_p,
               const void * Src_p,
               size_t Size)
{
    char * dp = Dest_p;
    const char * sp = Src_p;

    sp += (Size - 1);
    while (Size--)
    {
        *dp++ = *sp--;
    }
    return Dest_p;
}

typedef union Ptr {
   uint8_t * u8;
   uint16_t * u16;
   uint32_t * u32;
   uint64_t * u64;
   unsigned long * ul;
   int8_t * s8;
   int16_t * s16;
   int32_t * s32;
   int64_t * s64;
   long * sl;
} ptr_t;


#endif /* INCLUDE_GUARD_GENERIC_UTILS_H */

/* end of file generic_utils.h */
