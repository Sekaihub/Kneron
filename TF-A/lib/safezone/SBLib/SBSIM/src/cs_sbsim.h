/* cs_sbsim.h
 *
 * Configuration Switches for the SBSim Application
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

// the following switch asks SBSim to allocate the image memory provided to
// SB_Image_DecryptAndVerify() from the DMA Resource API of Driver
// Framework. This is required for the Crypto Module DMA buffers.
// The Driver Framework _implementation_ can be customized for your solution
// without having to touch the Secure Boot Libary.
// Details can be found in the Driver Framework Porting Guide
#define SBSIM_ALLOCATOR_DMARESOURCE

// This switch selects between calling
//   SB_Image_DecryptAndVerify and
//   SB_Image_Verify
// SB_CM only supports the first
#define SBSIM_WITH_DECRYPT

// this switch select between a single buffer (in-place) and using two buffers
// in case of decryption, in-place overwrites the original image.
// This switch is meaningful only when SBSIM_WITH_DECRYPT is set
#define SBSIM_NOT_INPLACE

/* end of file cs_sbsim.h */
