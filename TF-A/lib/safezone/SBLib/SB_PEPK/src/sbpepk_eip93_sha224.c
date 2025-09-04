/* sbpepk_eip93_sha224.c
 *
 * Description: Include appropriate file from SB_HYBRID.
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

/* Request SB_HYBRID's "personality" SB_PEPK. */
#ifndef SB_PEPK
#define SB_PEPK
#endif /* !defined SB_PEPK */

/* The functionality is actually implemented in SB_HYBRID. */
#include "sbhybrid_eip93_sha224.c"

/* end of file sbpepk_eip93_sha224.c */
