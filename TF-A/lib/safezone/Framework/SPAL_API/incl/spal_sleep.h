/* spal_sleep.h
 *
 * Description: Sleep APIs
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

#ifndef INCLUDE_GUARD_SPAL_SLEEP_H
#define INCLUDE_GUARD_SPAL_SLEEP_H

/*----------------------------------------------------------------------------
 * SPAL_SleepMS
 *
 * This function blocks the caller for the specified number of milliseconds.
 * The typical implementation will sleep the execution context, allowing other
 * execution contexts to be scheduled. This function must be called from a
 * schedulable execution context.
 *
 * Milliseconds
 *     During in milliseconds to sleep before returning.
 */
void
SPAL_SleepMS(
    unsigned int Milliseconds);


#endif /* Include guard */

/* end of file spal_sleep.h */
