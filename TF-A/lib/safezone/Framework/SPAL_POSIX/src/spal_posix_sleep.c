/* spal_posix_sleep.c
 *
 * Description: POSIX specific implementation of SPAL Sleep API
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

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L /* Request IEEE 1003.1-2004 support. */
#endif /* _POSIX_C_SOURCE */

#include "spal_thread.h"
#include "spal_sleep.h"
#include "implementation_defs.h"

#ifdef __CC_ARM
// Use stubbed implemtation - no semaphore implementation available

void
SPAL_SleepMS(unsigned int Milliseconds)
{
    IDENTIFIER_NOT_USED(Milliseconds);
}

#else

#include <semaphore.h>
#include <time.h>
#include <errno.h>

/*----------------------------------------------------------------------------
 * SPAL_SleepMS
 */
void
SPAL_SleepMS(unsigned int Milliseconds)
{
    struct timespec WaitTime;
    sem_t Sem;
    int rval;

    // create a private semaphore that we can wait on until the timeout
    rval = sem_init(&Sem, /*pshared:*/0, /*Initial:*/0); // blocks forever
    ASSERT(rval == 0);

    rval = clock_gettime(CLOCK_REALTIME, &WaitTime);
    ASSERT(rval == 0);

#define THOUSAND 1000
#define MILLION  1000000
#define BILLION  1000000000
    WaitTime.tv_sec += (time_t)(Milliseconds / THOUSAND);
    WaitTime.tv_nsec += (long)((Milliseconds % THOUSAND) * MILLION);
    if (WaitTime.tv_nsec >= BILLION)
    {
        WaitTime.tv_sec += 1;
        WaitTime.tv_nsec -= BILLION;
    }
#undef BILLION
#undef MILLION
#undef THOUSAND

    // wait can be interrupted by certain (debug) signals
    do
    {
        rval = sem_timedwait(&Sem, &WaitTime);
    } while (rval != 0 && errno == EINTR);

    sem_destroy(&Sem);
}

#endif


/* end of file spal_posix_sleep.c */
