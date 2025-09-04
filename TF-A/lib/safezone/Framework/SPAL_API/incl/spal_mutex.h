/* spal_mutex.h
 *
 * Description: Mutex APIs
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

#ifndef INCLUDE_GUARD_SPAL_MUTEX_H_
#define INCLUDE_GUARD_SPAL_MUTEX_H_

#include "public_defs.h"
#include "spal_result.h"

#include "cfg_spal.h"

struct SPAL_Mutex
{
    union
    {
#ifdef SPAL_CFG_MUTEX_ALIGN_TYPE
        SPAL_CFG_MUTEX_ALIGN_TYPE Alignment;
#endif
        uint8_t Size[SPAL_CFG_MUTEX_SIZE];
    } Union;
};

typedef struct SPAL_Mutex SPAL_Mutex_t;

SPAL_Result_t
SPAL_Mutex_Init(
    SPAL_Mutex_t * const Mutex_p);

void
SPAL_Mutex_Lock(
    SPAL_Mutex_t * const Mutex_p);

void
SPAL_Mutex_UnLock(
    SPAL_Mutex_t * const Mutex_p);

void
SPAL_Mutex_Destroy(
    SPAL_Mutex_t * const Mutex_p);

bool
SPAL_Mutex_IsLocked(
    SPAL_Mutex_t * const Mutex_p);

SPAL_Result_t
SPAL_Mutex_TryLock(
    SPAL_Mutex_t * const Mutex_p);

#endif /* Include guard */

/* end of file spal_mutex.h */
