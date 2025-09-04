/* sbpk_sw_aes_if.c
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

/* Request SB_HYBRID's "personality" SB_PK. */
#ifndef SB_PK
#define SB_PK
#endif /* !defined SB_PK */

/* The functionality is actually implemented in SB_HYBRID. */
#include "sbhybrid_sw_aes_if.c"

/* end of file sbpk_sw_aes_if.c */
