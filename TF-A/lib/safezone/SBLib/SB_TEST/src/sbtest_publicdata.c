/* sbtest_publicdata.c
 *
 * Description: Secure Boot Public Data Test Tool.
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

#include "implementation_defs.h"
#include "sb_publicdata.h"

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
#include "dmares_mgmt.h"    // Init
#include "dmares_buf.h"     // Alloc
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum resource size this example application can handle. */
#define MAX_PUBLICDATA_SIZE 512

int main(int argc, char *argv[])
{
    int i;
    SB_Result_t Result;
#ifdef SBSIM_ALLOCATOR_DMARESOURCE
    DMAResource_Handle_t DMAHandleOutput;
    uint8_t * BufferOutput_p = NULL;
#else
    static uint8_t BufferOutput[MAX_PUBLICDATA_SIZE];
    uint8_t * const BufferOutput_p = BufferOutput;
#endif
    int rangeStart;

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
    if (!DMAResource_Init())
    {
        fprintf(stderr, "ERROR: Failed to initialize DMAResouce\n");
        return 1;
    }

    // Allocate the DMA-safe buffer for reading the Public Data
    {
        DMAResource_Properties_t Props = { 0, 0, 0, 0 };
        DMAResource_AddrPair_t AddrPair;
        int res;

        Props.Size = MAX_PUBLICDATA_SIZE;
        Props.Alignment = 4;

        res = DMAResource_Alloc(Props, &AddrPair, &DMAHandleOutput);
        if (res != 0)
        {
            fprintf(stderr, "ERROR: Failed to allocate DMA buffer (%d)\n",
                    res);
            return 1;
        }

        // Use allocated buffer instead of StorageArea
        BufferOutput_p = AddrPair.Address.Native_p;
    }
#endif /* SBSIM_ALLOCATOR_DMARESOURCE */

    rangeStart = 1;
    for(i = 1; i < 127; i++)
    {
        uint32_t Length;

        Result = SB_PublicData_Read((uint32_t)i, NULL, &Length);
        if (Result != SB_ERROR_ARGUMENTS)
        {
            int AssetLength = (int)Length;

            if (rangeStart < (i - 1))
            {
                printf("(Unused AssetNumber range: %d...%d)\n", rangeStart, i - 1);
            }

            Result = SB_PublicData_Read((uint32_t)i, BufferOutput_p, &Length);
            if (Result == SB_SUCCESS)
            {
                int j = 0;
                printf("AssetNumber %d: PublicData:", i);
                while(j < (int)Length)
                {
                    printf(" %02x", BufferOutput_p[j]);
                    j++;
                }
                printf("\n");
            }
            else
            {
                printf("AssetNumber %d: PrivateData / Monotonic Counter (Length %d)\n",
                       i, AssetLength);
            }

            rangeStart = i + 1;
        }
    }

    /* Print remaining unused identifiers, if any. */
    if (rangeStart < (i - 1))
    {
        printf("(Unused AssetNumber range: %d...%d)\n", rangeStart, (i - 1));
    }

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
    DMAResource_Release(DMAHandleOutput);

    DMAResource_UnInit();
#endif

    PARAMETER_NOT_USED(argc);
    PARAMETER_NOT_USED(argv);

    return 0;
}

/* end of file sbtest_publicdata.c */
