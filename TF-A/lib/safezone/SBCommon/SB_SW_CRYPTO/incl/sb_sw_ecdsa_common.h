/* sb_sw_ecdsa_common.h
 *
 * Description: Secure Boot ECDSA Interface.
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

#ifndef INCLUDE_GUARD_SB_SW_ECDSA_COMMON_H
#define INCLUDE_GUARD_SB_SW_ECDSA_COMMON_H

#include "endian_utils.h"

typedef struct SB_SW_ECDSA_Verify_Workspace_
{
    char unused; /* Workspace not currently used.
                    Single member included because
                    memberless structs are not allowed in ISO C. */
} SB_SW_ECDSA_Verify_Workspace_t;


#ifndef SB_CF_BIGENDIAN
static inline void
memcpyrev(void *dest,
          const void *src,
          size_t bytes)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    size_t i;

    for (i = 0; i < bytes; i++)
    {
        d[bytes - i - 1] = s[i];
    }
}
#endif

#endif /* INCLUDE_GUARD_SB_SW_ECDSA_COMMON_H */

/* end of file sb_sw_ecdsa_common.h */
