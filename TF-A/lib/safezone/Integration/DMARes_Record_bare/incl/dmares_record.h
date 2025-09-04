/* dmares_record.h
 *
 * DMAResource Record Definition for use with the 'barebones' Driver Framework
 * implementation.
 *
 * The document "Driver Framework Porting Guide" contains the detailed
 * specification of this API.
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

#ifndef INCLUDE_GUARD_DMARES_RECORD_H
#define INCLUDE_GUARD_DMARES_RECORD_H

/*----------------------------------------------------------------------------
 * AddrTrans_Domain_t
 *
 * This is a list of domains that can be supported by the implementation. The
 * exact meaning can be different for different EIP devices and different
 * environments.
 */
enum
{
    DMARES_DOMAIN_HOST = 0,
    DMARES_DOMAIN_UNIFIED,
    DMARES_DOMAIN_EIP13xDMA,
    DMARES_DOMAIN_EIP93DMA
};

// this implementation does not support a DMAResource Record
typedef void DMAResource_Record_t;

#endif

/* end of file dmares_record.h */
