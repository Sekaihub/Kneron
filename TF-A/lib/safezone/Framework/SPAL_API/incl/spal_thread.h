/* spal_thread.h
 *
 * Description: Thread APIs
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

#ifndef INCLUDE_GUARD_SPAL_THREAD_H
#define INCLUDE_GUARD_SPAL_THREAD_H

#include "public_defs.h"
#include "spal_result.h"

#include "cfg_spal.h"


#ifdef SPAL_CFG_THREAD_TYPE
typedef SPAL_CFG_THREAD_TYPE SPAL_Thread_t;
#else
typedef uint32_t SPAL_Thread_t;
#endif

SPAL_Thread_t
SPAL_Thread_Self(
    void);


SPAL_Result_t
SPAL_Thread_Create(
    SPAL_Thread_t * const Thread_p,
    const void * const Reserved_p,
    void * (*StartFunction_p)(void * const Param_p),
    void * const ThreadParam_p);


SPAL_Result_t
SPAL_Thread_Detach(
    const SPAL_Thread_t Thread);


SPAL_Result_t
SPAL_Thread_Join(
    const SPAL_Thread_t Thread,
    void ** const Status_p);


void
SPAL_Thread_Exit(
    void * const Status);

#endif /* Include guard */

/* end of file spal_thread.h */
