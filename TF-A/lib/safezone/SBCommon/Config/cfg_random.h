/* cfg_random.h
 *
 * Description: Configuration for SW random functionality
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

#ifndef INCLUDE_GUARD_CFG_RANDOM_H
#define INCLUDE_GUARD_CFG_RANDOM_H

/* Device for acquiring entropy or take the random numbers from.
 * This device may be blocking.
 */
#ifndef CFG_RANDOM_ENTROPY_DEVICE
#define CFG_RANDOM_ENTROPY_DEVICE  "/dev/random"
#endif

/* Device for acquiring entropy or take the random numbers from.
 * This device shall be non-blocking.
 * (If there is no non-blocking randomness device in the system,
 * do not define a file here)
 */
#ifndef CFG_RANDOM_NONBLOCKING_ENTROPY_DEVICE
#define CFG_RANDOM_NONBLOCKING_ENTROPY_DEVICE  "/dev/urandom"
#endif

/* Requested level of randomness quality (the only one supported)
 */
#define CFG_RANDOM_QUALITY 128

/* File for storing randomness state.
 * When available, this file is used instead of CFG_RANDOM_ENTROPY_DEVICE.
 */
#define CFG_RANDOM_STATE_FILENAME ".nist_drbg_statefile.bin"

/* Use Unix/posix function calls to ensure state file access is save.
 * umask is used to protect the file (only readable for the user),
 * flock prevents simultaneous access by multiple processes and
 * fsync ensures changes are written to disc in case of unexpected
 * power down or other failure.
 */
//#define CFG_RANDOM_STATE_FILE_UNIX

#endif /* INCLUDE_GUARD_CFG_RANDOM_H */

/* end of file cfg_random.h*/
