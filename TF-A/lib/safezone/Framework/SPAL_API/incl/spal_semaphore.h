/* spal_semaphore.h
 *
 * Description: Semaphore APIs
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

#ifndef INCLUDE_GUARD_SPAL_SEMAPHORE_H_
#define INCLUDE_GUARD_SPAL_SEMAPHORE_H_

#include "public_defs.h"
#include "spal_result.h"

#include "cfg_spal.h"

struct SPAL_Semaphore
{
    union
    {
#ifdef SPAL_CFG_SEMAPHORE_ALIGN_TYPE
        SPAL_CFG_SEMAPHORE_ALIGN_TYPE Alignment;
#endif
        uint8_t Size[SPAL_CFG_SEMAPHORE_SIZE];
    } Union;
};

typedef struct SPAL_Semaphore SPAL_Semaphore_t;


SPAL_Result_t
SPAL_Semaphore_Init(
    SPAL_Semaphore_t * const Semaphore_p,
    const unsigned int InitialCount);


void
SPAL_Semaphore_Wait(
    SPAL_Semaphore_t * const Semaphore_p);


SPAL_Result_t
SPAL_Semaphore_TryWait(
    SPAL_Semaphore_t * const Semaphore_p);


SPAL_Result_t
SPAL_Semaphore_TimedWait(
    SPAL_Semaphore_t * const Semaphore_p,
    const unsigned int TimeoutMilliSeconds);


void
SPAL_Semaphore_Post(
    SPAL_Semaphore_t * const Semaphore_p);


void
SPAL_Semaphore_Destroy(
    SPAL_Semaphore_t * const Semaphore_p);

#endif /* Include guard */

/* end of file spal_semaphore.h */
