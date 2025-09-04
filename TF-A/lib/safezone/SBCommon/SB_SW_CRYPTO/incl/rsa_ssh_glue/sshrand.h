/**
 *  File: sshrand.h
 *
 *  Description : Definition of replacement ssh_rand() for sshcrypto and
 *                sshmath.
 *                Random is implemented via CAL API: sfzcrypto_rand_data().
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

#ifndef SSHRAND_H
#define SSHRAND_H

/* Supplement for sshrand.h. */

#include "sshincludes.h"

/**  Obtain a pseudo-random number uniformly selected from [0,2^32). It
     is guaranteed that the sequence of numbers produced has a high
     period, and passes most empirical statistical randomness tests.

     This operation updates the global state irreversibly. */
SshUInt32 ssh_rand(void);

#endif /* SSHRAND_H */

/* end of file sshrand.h */
