/* cfg_spal.h
 *
 * Description: SPAL configuration constants.
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

#ifndef INCLUDE_GUARD_CFG_SPAL_H
#define INCLUDE_GUARD_CFG_SPAL_H

/* These are configuration constants for SPAL.
   The values have been tested with 32-bit and 64-bit Linux environments.
   Depending on target OS values may have to be adjusted. */

#if defined(__x86_64__)
/* For 64-bit environments: use wider pthread type. */
#define SPAL_CFG_THREAD_TYPE long int
#endif

#if defined(__x86_64__)
/* For 64 bit environments: try doubling the storage size. */
#define SPAL_CFG_MUTEX_SIZE 56
#define SPAL_CFG_MUTEX_ALIGN_TYPE long int
#else
#ifdef WIN32
/* This value is needed by the Win32 build */
#define SPAL_CFG_MUTEX_SIZE 36
#else
/* These value are large enough for encountered 32-bit linux variants. */
#define SPAL_CFG_MUTEX_SIZE 28
#endif
#define SPAL_CFG_MUTEX_ALIGN_TYPE long int
#endif


#if defined(__x86_64__)
/* For 64 bit environments: try doubling the storage size. */
#define SPAL_CFG_SEMAPHORE_SIZE       40
#define SPAL_CFG_SEMAPHORE_ALIGN_TYPE void *
#else
/* These value are large enough for encountered 32-bit linux variants. */
#define SPAL_CFG_SEMAPHORE_SIZE       20
#define SPAL_CFG_SEMAPHORE_ALIGN_TYPE void *
#endif

#endif /* INCLUDE_GUARD_CFG_SPAL_H */

/* end of file cfg_spal.h */
