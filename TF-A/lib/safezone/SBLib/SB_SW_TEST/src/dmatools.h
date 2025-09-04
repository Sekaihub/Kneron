/**
 *  File: dmatools.h
 *
 *  Description : DMA related functions
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

#ifdef SB_ALLOCATOR_DMARESOURCE
#include "dmares_mgmt.h"    // DMAResource_Init
#include "dmares_buf.h"     // DMAResource_Alloc

static int DMAResourceInit = 0;
static int DMAHandleCount = 0;
static DMAResource_Handle_t DMAHandles[3];

static void FreeDMAResources(void)
{
    while (DMAHandleCount > 0)
    {
        DMAResource_Release(DMAHandles[--DMAHandleCount]);
        c_memset(DMAHandles[DMAHandleCount], 0, sizeof DMAHandles[DMAHandleCount]);
    }

    if (DMAResourceInit)
    {
        DMAResource_UnInit();
    }
    DMAResourceInit = 0;
}

static void DMAResourcesInit(void)
{
    if (DMAResourceInit == 0)
    {
        if (!DMAResource_Init())
        {
            fail("Failed to initialize DMAResource");
        }
    }
    DMAResourceInit = 1;
}

static void ConvertVectorToDMAResource(SBIF_SGVector_t *vec)
{
    DMAResource_Properties_t Props = { 0, 0, 0, 0 };
    DMAResource_AddrPair_t AddrPair;
    int res;

    Props.Size = vec->DataLen;
    Props.Alignment = 4;

    DMAResourcesInit();

    res = DMAResource_Alloc(Props, &AddrPair, &DMAHandles[DMAHandleCount]);
    fail_if (res != 0, "Failed to allocate DMA buffer");

    /* Copy input data. */
    c_memcpy(AddrPair.Address.Native_p, vec->Data_p, vec->DataLen);

    /* Set vec to new DMA-able address. */
    vec->Data_p = AddrPair.Address.Native_p;

    /* Increment handle count. */
    DMAHandleCount++;
}

#else
static void FreeDMAResources(void)
{
    /* Not used because DMA resources are not enabled. */
}

static void ConvertVectorToDMAResource(SBIF_SGVector_t *vec)
{
    /* Not used because DMA resources are not enabled. */
    (void)vec;
}
#endif

/* Equivalent of ConvertVectorToDMAResource with input expressed as
   memory area. */
static void ConvertAreaToDMAResource(void **Area_pp, size_t sz)
{
    SBIF_SGVector_t vec;
    vec.Data_p = *Area_pp;
    vec.DataLen = (uint32_t)sz;
    ConvertVectorToDMAResource(&vec);
    *Area_pp = vec.Data_p;
}

/* end of file dmatools.h */
