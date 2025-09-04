/* dmares_record.h
 *
 * DMAResource Record Definition.
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
    DMARES_DOMAIN_UNKNOWN = 0,
    DMARES_DOMAIN_HOST,
    DMARES_DOMAIN_HOST_UNALIGNED,
    DMARES_DOMAIN_BUS,
    DMARES_DOMAIN_INTERHOST,
    DMARES_DOMAIN_EIP13xDMA,
    DMARES_DOMAIN_ALTERNATIVE,
};

#ifdef CFG_ENABLE_TARGET_VTBAL
#define DMARES_DOMAIN_EIP93DMA DMARES_DOMAIN_BUS
#endif

// Maximum number of address/domain pairs stored per DMA resource.
#define DMARES_ADDRPAIRS_CAPACITY 3

typedef struct
{
    // signature used to validate handles
    uint32_t Magic;

    // DMA resource properties: Size, Alignment, Bank & fCached
    DMAResource_Properties_t Props;

    // Storage for upto N address/domain pairs.
    DMAResource_AddrPair_t AddrPairs[DMARES_ADDRPAIRS_CAPACITY];

    // if true, 32-bit words are swapped when transferred to/from
    // the DMA resource
    bool fSwapEndianess;

    // this implementation supports the following allocator references:
    // 'A' -> this DMA resource has been obtained through DMAResource_Alloc
    // 'R' -> this DMA resource has been obtained through DMAResource_Register
    // 'T' -> this DMA resource has been obtained through DMAResource_Attach
    char AllocatorRef;

    // maximum data amount that can be stored in bytes, e.g. allocated size
    unsigned int BufferSize;

} DMAResource_Record_t;

#define DMARES_RECORD_MAGIC 0xde42b5e7

#endif

/* end of file dmares_record.h */
