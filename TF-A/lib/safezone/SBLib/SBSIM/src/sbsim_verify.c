/* sbsim_verify.c
 *
 * Description: Secure Boot Simulator verification tool.
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

#ifndef __MODULE__
#define __MODULE__ "sbsim_verify.c"
#endif

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif /* _POSIX_C_SOURCE */

#include "cf_sblib.h"                   /* Configuration toggles */
#include "sb_common.h"                  /* verify [and decrypt] API */
#include "sb_setfipsmode.h"             /* set FIPS mode API */
#include "sbif.h"                       /* header fields and consts */
#include "sbif_attributes.h"            /* header attribute processing API */

#include "endian_utils.h"
#include "c_lib.h"

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
#include "dmares_mgmt.h"                /* Init */
#include "dmares_buf.h"                 /* Alloc */
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef SBSIM_TIME_INFO
#include <sys/time.h>

#define GetTimeSample(a) gettimeofday(a, NULL);

static unsigned long
GetTimeDiff(const struct timeval * T1)
{
    struct timeval T2;
    unsigned long Diff;
    long D;

    gettimeofday(&T2, NULL);

    /* Calculate the usec difference */
    D = T2.tv_usec - T1->tv_usec;
    if (D < 0)
    {
        D += 1000000;
    }
    Diff = (unsigned long)D;

    /* Calculate the sec difference */
    D = T2.tv_sec - T1->tv_sec;
    if (D < 0)
    {
        D += -1;
    }
    Diff += ((unsigned long)D) * 1000000;

    return Diff;
}
#endif

#ifndef SBSIM_MAX_IMAGE_SIZE
/* support 16MB images */
#define SBSIM_MAX_IMAGE_SIZE (16 * 1024 * 1024 + 1024)
#endif

/* Configuration values loaded from command line options. */
struct
{
#ifndef __CC_ARM
    struct timespec polldelay;
    bool fPolldelay;
#endif
    int readblock;
} sbsim_configuration;

#define SBSIM_MAX_SG 64
static SBIF_SGVector_t SG_In[1 + SBSIM_MAX_SG];
//static SBIF_SGVector_t SG_Out[1 + SBSIM_MAX_SG];

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
static DMAResource_Handle_t DMAHandleInput[1 + SBSIM_MAX_SG];
#endif


static void
Print_OctetString(const char * const Description_p,
                  const void * const Data_p,
                  const unsigned int DataLen)
{
    const uint8_t * Byte_p = Data_p;
    int Column = 16;
    unsigned int PrintedLen;

    printf("%s:", Description_p);

    for (PrintedLen = 0; PrintedLen < DataLen; PrintedLen++)
    {
        if (Column++ == 16)
        {
            printf("\n\t");
            Column = 1;
        }

        printf("%.2x ", (int)*Byte_p);
        Byte_p++;
    }

    printf("\n");
}


static void
Print_PublicKey(const char * const Description_p,
                const SBIF_PublicKey_t * const PublicKey_p)
{
    printf("%s:\n", Description_p);
#ifdef SBIF_ECDSA
    Print_OctetString("Qx", PublicKey_p->Qx, sizeof(PublicKey_p->Qx));
    Print_OctetString("Qy", PublicKey_p->Qy, sizeof(PublicKey_p->Qy));
#else
    Print_OctetString("pubkeyExp", PublicKey_p->pubkeyExp, sizeof(PublicKey_p->pubkeyExp));
    Print_OctetString("modulus", PublicKey_p->modulus, sizeof(PublicKey_p->modulus));
#endif
}

static void
Print_Signature(const char * const Description_p,
                const SBIF_Signature_t * const Signature_p)
{
    printf("%s:\n", Description_p);
#ifdef SBIF_ECDSA
    Print_OctetString("r", &Signature_p->r, sizeof(Signature_p->r));
    Print_OctetString("s", &Signature_p->s, sizeof(Signature_p->s));
#else
    Print_OctetString("signature", &Signature_p->signature, sizeof(Signature_p->signature));
#endif
}


static void
Print_ImageInfo(const SBIF_Header_t * const Header_p)
{
    uint32_t TypeWord;
    uint32_t Type;
    uint32_t PubKeyType;
    uint8_t TypeChar[3];
    uint32_t header_image_len;

    TypeWord = Load_BE32(&Header_p->Type);
    TypeChar[2] = (uint8_t)(TypeWord >>  8);
    TypeChar[1] = (uint8_t)(TypeWord >> 16);
    TypeChar[0] = (uint8_t)(TypeWord >> 24);

    printf("Image header:\n");
    if ((TypeChar[0] >= 'A') && (TypeChar[0] <= 'Z') &&
        (TypeChar[1] >= 'A') && (TypeChar[1] <= 'Z') &&
        (TypeChar[2] >= 'a') && (TypeChar[2] <= 'z'))
    {
        printf("Type:\t%c%c%c\n", TypeChar[0], TypeChar[1], TypeChar[2]);
    }
    else
    {
        printf("Type:\tUnknown (corrupt header)\n");
    }
    printf("Version: %d\n", (int)SBIF_TYPE_VERSION(TypeWord));

    PubKeyType = Load_BE32(&Header_p->PubKeyType) & 0xffffff;
    if (PubKeyType == SBIF_PUBKEY_TYPE_ROM)
    {
        printf("Public key in ROM\n");
    }
    else if (PubKeyType == SBIF_PUBKEY_TYPE_OTP)
    {
        printf("Public key in OTP\n");
    }
    else if (PubKeyType == SBIF_PUBKEY_TYPE_IMAGE)
    {
        printf("Public key in image header\n");
    }
    else
    {
        printf("Unknow public key type\n");
    }

#ifdef SBIF_ECDSA
    Print_OctetString("r", Header_p->Signature.r, sizeof(Header_p->Signature.r));
    Print_OctetString("s", Header_p->Signature.s, sizeof(Header_p->Signature.r));
#else
    Print_OctetString("signature", Header_p->Signature.signature, sizeof(Header_p->Signature.signature));
#endif
    Print_OctetString("key", Header_p->EncryptionKey, sizeof(Header_p->EncryptionKey));
    Print_OctetString("iv", Header_p->EncryptionIV, sizeof(Header_p->EncryptionIV));

    header_image_len = Load_BE32(&Header_p->ImageLen);
    printf("len:\t%u\n", (unsigned int)header_image_len);

    Type = SBIF_TYPE_TYPE(TypeWord);
    if ((Type == SBIF_IMAGE_BLTp) ||
        (Type == SBIF_IMAGE_BLTw) ||
        (Type == SBIF_IMAGE_BLTe))
    {
        SBIF_Certificate_t * Certs_p;
        uint32_t CertCount;
        uint32_t CertIndex;

        Certs_p = (void *)((SBIF_Header_t *)discard_const(Header_p) + 1);

        CertCount = Load_BE32(&Header_p->CertificateCount);
        printf("cert count: %u\n", (unsigned int)CertCount);

        for (CertIndex = 0; CertIndex < CertCount; CertIndex++)
        {
            if (CertIndex == 4 && CertIndex < CertCount)
            {
                printf("%u more certificates\n", (unsigned int)(CertCount - CertIndex + 1));
                break;
            }

            printf("cert %u\n", (unsigned int)CertIndex);
            Print_PublicKey("public key", &Certs_p[CertIndex].PublicKey);
            Print_Signature("signature", &Certs_p[CertIndex].Signature);
        }
    }

    if (SBIF_Attribute_Check(&Header_p->ImageAttributes))
    {
        uint32_t Value32 = 0;

        printf("Image attributes are valid\n");

        /* check for the rollback attribute */
        if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
                                 SBIF_ATTRIBUTE_ROLLBACK_ID,
                                 &Value32))
        {
            printf("  RollbackID: 0x%08x\n", (unsigned int)Value32);
        }
        else
        {
            printf("  RollbackID: [not found]\n");
        }
    }
    else
    {
        printf("Image attributes check failed\n");
    }
}

static void
Program_Exit(const int Value)
{
    printf("Result: FAIL\n");
    exit(Value);
}


static SB_StorageArea_t StorageArea;

static unsigned int PollCount = 0;


int main(int argc, char * argv[])
{
    SBIF_PublicKey_t PublicKey;
    const SBIF_PublicKey_t * PublicKey_p = NULL;
    SBIF_Header_t * Header_p = NULL;
    size_t ImageSize;                   /* as read from file */
    unsigned int HeaderLen;
    unsigned int DataLen;
    SB_Result_t Result;
    uint8_t * AllocatedInputBuffer_p = NULL;
    const uint8_t * Hash_p = NULL;
#ifdef SBIF_ECDSA
    uint8_t HashBuf[SBIF_ECDSA_BYTES];
#else
    uint8_t HashBuf[32];
#endif
#ifndef SBLIB_CF_REMOVE_SETFIPSMODE
    bool fFipsMode = false;
#endif
    unsigned int FragCount = 1;
    unsigned int FragSize = 0;
    unsigned int FragSizeLast = 0;
#ifdef SBSIM_TIME_INFO
    struct timeval T1;
#endif

    /* Macro: Remove handled command line option from argc/argv. */
#define OPTION_HANDLED  do { argv[1] = argv[0]; argc--; argv++; } while (0)

    /* Handle options until no option found */
    while (1)
    {
        if ((argc > 1) && (c_strcmp(argv[1], "--") == 0))
        {
            OPTION_HANDLED;
            break;                      /* No more options. */
        }
#ifndef __CC_ARM
        else if ((argc > 1) &&
                 (c_strncmp(argv[1], "--polldelay=", 12) == 0))
        {
            /* Store parsed option and remove it from the command line. */
            double polldelay = atof(argv[1] + 12);
            if (polldelay < 0.0)
            {
                polldelay = 0.0;
            }
            sbsim_configuration.polldelay.tv_sec  = (time_t)polldelay;
            sbsim_configuration.polldelay.tv_nsec = (time_t)((polldelay - (double)((time_t)polldelay)) * 1000000000U);
            sbsim_configuration.fPolldelay = true;
            OPTION_HANDLED;
        }
#endif
        else if ((argc > 1) &&
                 (c_strncmp(argv[1], "--readblock=", 12) == 0))
        {
            int readblock = atoi(argv[1] + 12);
            if (readblock > SBSIM_MAX_IMAGE_SIZE)
            {
                readblock = 0;
            }
            else if (readblock > 0)
            {
                /* Make readblock multiple of nearest blocksize. */
                readblock += SB_READ_DATA_BLOCKSIZE / 2;
                readblock /= SB_READ_DATA_BLOCKSIZE;
                if (readblock == 0)
                {
                    readblock = 1;
                }
                readblock *= SB_READ_DATA_BLOCKSIZE;
            }
            sbsim_configuration.readblock = readblock;
            OPTION_HANDLED;
        }
        else if ((argc > 1) &&
                 ((c_strcmp(argv[1], "-1") == 0) ||
                  (c_strcmp(argv[1], "1") == 0)))
        {
            OPTION_HANDLED;
        }
        else if ((argc > 1) &&
                 ((c_strcmp(argv[1], "-2") == 0) ||
                  (c_strcmp(argv[1], "2") == 0)))
        {
            fprintf(stderr, "SBSIM ERROR: Two buffers mode not supported.\n");
            Program_Exit(1);
        }
#ifndef SBLIB_CF_REMOVE_SETFIPSMODE
        else if ((argc > 1) &&
                 (c_strcmp(argv[1], "--fips") == 0))
        {
            fFipsMode = true;
            OPTION_HANDLED;
        }
#endif
        else if ((argc > 1) &&
                 (c_strncmp(argv[1], "--deckeyfile=", 13) == 0))
        {
            fprintf(stderr, "SBSIM ERROR: Decryption key not supported.\n");
            Program_Exit(1);
        }
        else if ((argc > 1) &&
                 (c_strncmp(argv[1], "--unwrapkeyfile=", 16) == 0))
        {
            fprintf(stderr, "SBSIM ERROR: Unwrapping key not supported.\n");
            Program_Exit(1);
        }
        else
        {
            break;                      /* No match: options handled. */
        }
    }

    if ((argc < 3) || (argc > 6))
    {
        char curve0[8];
        char curve1[12];
        uint32_t temp0 = 0;
        uint32_t temp1 = 0;
        char *cfg = NULL;
        char *cert = NULL;

        if (c_strstr(argv[0], "RSA") != NULL)
        {
            temp0 = 7;
            temp1 = 10;
            if (c_strstr(argv[0], "pkcs") != NULL)
            {
                temp1 += 1;
            }
        }
        else if (c_strstr(argv[0], "cfgP") != NULL)
        {
            temp0 = 4;
            temp1 = 4;
        }
        else
        {
            fprintf(stderr, "Unknown configuration: %s\n", argv[0]);
            Program_Exit(1);
        }
        cfg = c_strstr(argv[0], "_cfg");
        if (cfg == NULL)
        {
            fprintf(stderr, "Unknown configuration: %s\n", argv[0]);
            Program_Exit(1);
        }
        c_strncpy(curve0, &cfg[4], temp0);
        c_strncpy(curve1, &cfg[4], temp1);
        curve0[temp0] = '\0';
        curve1[temp1] = '\0';
        cert = c_strstr(&cfg[temp1 + 4], "c");
        temp0 = (uint32_t)atoi(&cert[1]);

        fprintf(stderr,
                "description:\n"
                "\tCurve: %s\n"
                "\tProtection: Integrity Protection only (no SBCR use)\n"
                "\tSupported certificates: up to %d\n"
                "\tVariant: %s\n\n",
                curve0, temp0, &cert[2]);

        fprintf(stderr,
                "usage:\n"
                "\t%s <options> <%s public key file> <%s signed image file> [<output file> [<fragcount>]]\n\n"
                "The available options are:\n"
#ifndef __CC_ARM
                "    --polldelay=seconds      wait specified delay during polling HW crypto operations\n"
#endif
                "    --readblock=bytes    set the size of block to process at once\n",
                argv[0], curve0, curve1);

#ifndef SBLIB_CF_REMOVE_SETFIPSMODE
        if (c_strcmp(&cert[2], "sm") == 0)
        {
            fprintf(stderr,
                    "    --fips                   switch to FIPS mode before calling SB_Image_Verify()\n");
        }
#endif

        Program_Exit(1);
    }

#ifndef SBLIB_CF_REMOVE_SETFIPSMODE
    if (fFipsMode)
    {
        /* Enable FIPS mode before calling SB_Image_Verify() */
        if (SB_SetFipsMode(SBLIB_CFG_XM_TOKEN_IDENTITY, 1, 2, 3, 4) != SB_SUCCESS)
        {
            fprintf(stderr, "SBSIM ERROR: Could not set FIPS Mode\n");
            Program_Exit(1);
        }
    }
#endif

    /* load the image */
    {
        FILE * ImageFile;
        size_t ReadSize = 0;

        ImageFile = fopen(argv[2], "rb");
        if (!ImageFile)
        {
            fprintf(stderr,
                    "SBSIM ERROR: Could not open image file %s\n",
                    argv[2]);
            Program_Exit(1);
        }

        fseek(ImageFile, 0L, SEEK_END);
        ImageSize = (size_t)ftell(ImageFile);
        fseek(ImageFile, 0L, SEEK_SET);

        /* allocate the input buffer */
        AllocatedInputBuffer_p = malloc(ImageSize);
        if (!AllocatedInputBuffer_p)
        {
            fprintf(stderr, "SBSIM ERROR: Memory allocation (input)\n");
            Program_Exit(2);
        }

        ReadSize = fread(AllocatedInputBuffer_p, 1, ImageSize, ImageFile);
        if (ferror(ImageFile))
        {
            fprintf(stderr,
                    "SBSIM ERROR: Could not read image file %s\n",
                    argv[2]);
            Program_Exit(1);
        }

        if (ImageSize != ReadSize)
        {
            fprintf(stderr,
                    "SBSIM ERROR: Error while reading image file %s\n",
                    argv[2]);
            Program_Exit(1);
        }

        if (ImageSize < sizeof(SBIF_Header_t))
        {
            fprintf(stderr,
                    "SBSIM ERROR: Header bigger than image file %s\n",
                    argv[2]);
            Program_Exit(1);
        }

        fclose(ImageFile);
    }

    HeaderLen = SBIF_GET_HEADER_SIZE(AllocatedInputBuffer_p, ImageSize);
    DataLen = (unsigned int)ImageSize - HeaderLen;

    // Check for overflows in image size calculation
    if ((HeaderLen == 0) ||
        (HeaderLen > ImageSize) ||
        (DataLen > ImageSize) ||
        ((DataLen + HeaderLen) > ImageSize))
    {
        fprintf(stderr, "SBSIM ERROR: Invalid image header\n");
        Program_Exit(1);
    }

    if (DataLen >= SBSIM_MAX_IMAGE_SIZE)
    {
        fprintf(stderr, "SBSIM ERROR: Payload data exceeds max size\n");
        Program_Exit(1);
    }

    if (argc == 5)
    {
        int temp = atoi(argv[4]);
        if (temp < 1 || temp > SBSIM_MAX_SG)
        {
            fprintf(stderr,
                    "SBSIM ERROR: Invalid FragCount: %d (min=1; max=%u)\n",
                    temp, SBSIM_MAX_SG);
            Program_Exit(1);
        }

        FragCount = (unsigned int)temp;
    }

    if (FragCount == 1)
    {
        FragSize = 0;
        FragSizeLast = DataLen;
    }
    else
    {
        // divide up the image into FragCount pieces
        FragSize = DataLen / FragCount;

#if ((SBIF_ECDSA_BYTES == 48) || (SBIF_ECDSA_BYTES == 66))
        // round up to nearest 128-byte aligned
        if (FragSize & 127)
        {
            FragSize = FragSize + 128 - (FragSize & 127);
        }
#else
        // round up to nearest 64-byte aligned
        if (FragSize & 63)
        {
            FragSize = FragSize + 64 - (FragSize & 63);
        }
#endif

        FragCount = DataLen / FragSize;
        if (FragSize * FragCount < DataLen)
        {
            FragCount++;                // partial last fragment
            FragSizeLast = DataLen - (FragCount - 1) * FragSize;
        }
        else
        {
            FragSizeLast = FragSize;
        }
    }

    printf("SBSIM: ImageSize=%u; HeaderLen=%u; DataLen=%u; FragSize=%u; FragSizeLast=%u; FragCount=%u; %u+%u*%u+%u=%u\n",
           (unsigned int)ImageSize, HeaderLen, DataLen,
           FragSize, FragSizeLast, FragCount,
           HeaderLen, FragCount - 1, FragSize, FragSizeLast,
           HeaderLen + (FragCount - 1) * FragSize + FragSizeLast);

#ifndef SBSIM_ALLOCATOR_DMARESOURCE
    {
        ptr_t Buf_p;
        Buf_p.u8 = AllocatedInputBuffer_p;
        unsigned int lp;

        SG_In[0].Data_p = Buf_p.u32;
        SG_In[0].DataLen = HeaderLen;
        Buf_p.u8 += HeaderLen;

        for (lp = 1; lp < FragCount; lp++)
        {
            SG_In[lp].Data_p = Buf_p.u32;
            SG_In[lp].DataLen = FragSize;
            Buf_p.u8 += FragSize;
        }

        SG_In[FragCount].Data_p = Buf_p.u32;
        SG_In[FragCount].DataLen = DataLen - (FragCount - 1) * FragSize;
    }

#else
    if (!DMAResource_Init())
    {
        fprintf(stderr, "SBSIM ERROR: DMAResource initialization failed\n");
        Program_Exit(1);
    }

    /* Allocate the DMA buffers */
    {
        uint8_t * Copy_p = AllocatedInputBuffer_p;
        DMAResource_Properties_t Props = { 0, 0, 0, 0 };
        DMAResource_AddrPair_t AddrPair;
        unsigned int lp;
        int res;

        Props.Alignment = 4;

        // first fragment is for the entire header + certificates
        {
            Props.Size = HeaderLen;

            res = DMAResource_Alloc(Props, &AddrPair, DMAHandleInput + 0);
            if (res != 0)
            {
                fprintf(stderr,
                        "SBSIM ERROR: DMAResource allocation failed (%d)\n",
                        res);
                Program_Exit(2);
            }

            c_memcpy(AddrPair.Address.Native_p, Copy_p, Props.Size);
            Copy_p += Props.Size;

            SG_In[0].Data_p = (uint32_t *)AddrPair.Address.Native_p;
            SG_In[0].DataLen = Props.Size;
        }

        // allocate the fragments
        Props.Size = FragSize;
        for (lp = 1; lp <= FragCount; lp++)
        {
            if (lp == FragCount)
            {
                Props.Size = FragSizeLast;
            }

            res = DMAResource_Alloc(Props, &AddrPair, DMAHandleInput + lp);
            if (res != 0)
            {
                fprintf(stderr,
                        "SBSIM ERROR: DMAResource allocation failed (%u, %d)\n",
                        lp, res);
                Program_Exit(2);
            }

            // copy part of the image into this input buffer
            c_memcpy(AddrPair.Address.Native_p, Copy_p, Props.Size);
            Copy_p += Props.Size;

            SG_In[lp].Data_p = (uint32_t *)AddrPair.Address.Native_p;
            SG_In[lp].DataLen = Props.Size;
        }

        // we no longer need the buffer the file was read into
        free(AllocatedInputBuffer_p);
        AllocatedInputBuffer_p = NULL;
    }
#endif /* SBSIM_ALLOCATOR_DMARESOURCE */

    Header_p = (SBIF_Header_t *)SG_In[0].Data_p;
    Print_ImageInfo(Header_p);

    /* load the public key */
    if ((Load_BE32(&Header_p->PubKeyType) & 0xffffff) == SBIF_PUBKEY_TYPE_IMAGE)
    {
        FILE * HashFile;
        size_t Length;

        /* public key is stored in the image header,
           hence it shall not be provided */
        PublicKey_p = NULL;

        HashFile = fopen(argv[1], "rb");
        if (HashFile == NULL)
        {
            fprintf(stderr,
                    "SBSIM ERROR: Could not open hash file %s\n",
                    argv[1]);
            Program_Exit(1);
        }

        fseek(HashFile, 0L, SEEK_END);
        Length = (size_t)ftell(HashFile);
        fseek(HashFile, 0L, SEEK_SET);
#if SBIF_ECDSA_BYTES == 66
        Length += 2;
#endif
        if (Length != sizeof(HashBuf))
        {
            fprintf(stderr,
                    "SBSIM ERROR: Inappropriate size of hash file %s\n",
                    argv[1]);
            Program_Exit(1);
        }

        Length = fread(&HashBuf, 1, sizeof(HashBuf), HashFile);
        fclose(HashFile);
#if SBIF_ECDSA_BYTES == 66
        HashBuf[64] = 0;
        HashBuf[65] = 0;
        Length += 2;
#endif
        if (Length != sizeof(HashBuf))
        {
            fprintf(stderr,
                    "SBSIM ERROR: Could not read hash file %s\n",
                    argv[1]);
            Program_Exit(1);
        }

        Hash_p = HashBuf;
    }
    else
    {
        FILE * PublicKeyFile;
        size_t Length;

        PublicKeyFile = fopen(argv[1], "rb");
        if (PublicKeyFile == NULL)
        {
            fprintf(stderr,
                    "SBSIM ERROR: Could not open public key file %s\n",
                    argv[1]);
            Program_Exit(1);
        }

        Length = fread(&PublicKey, 1, sizeof(PublicKey), PublicKeyFile);
        fclose(PublicKeyFile);
        if (Length != sizeof(PublicKey))
        {
            fprintf(stderr,
                    "SBSIM ERROR: Inappropriate size of public key file %s\n",
                    argv[1]);
            Program_Exit(1);
        }

        /* public key is not stored in the image header,
           hence it shall be provided */
        PublicKey_p = &PublicKey;
    }
    if (PublicKey_p != NULL)
    {
        Print_PublicKey("Public key input", &PublicKey);
    }
    else
    {
        Print_PublicKey("Public key from the image header", &Header_p->PublicKey);
    }

    // do the secure boot [decrypt+]verify
    c_memset(&StorageArea, 0x55, sizeof(StorageArea));

#ifdef SBSIM_TIME_INFO
    GetTimeSample(&T1);
#endif

    Result = SB_Image_Verify(&StorageArea,
                             /*PollParam_p:*/&PollCount,
                             PublicKey_p,
                             Hash_p,
                             Header_p,
                             SG_In + 1,
                             FragCount);

#ifdef SBSIM_TIME_INFO
    printf("SB image 'Verify' took %u us\n", (unsigned int)GetTimeDiff(&T1));
#endif

    printf("SB_Poll() was called %u times.\n", PollCount);

    if (Result == SB_SUCCESS)
    {
        printf("Result: PASS\n");

        if (argc >= 4)
        {
            FILE * Outf_p = fopen(argv[3], "wb");
            printf("Writing verified image to %s... ", argv[3]);
            if (Outf_p)
            {
                unsigned int lp;

                fflush(stdout);

                // skip the header part
                for (lp = 1; lp <= FragCount; lp++)
                {
                    if (0 == fwrite(SG_In[lp].Data_p,
                                    SG_In[lp].DataLen, 1,
                                    Outf_p))
                    {
                        break;              // from the for
                    }
                }
                if (lp > FragCount)
                {
                    printf("Done\n");
                }
                else
                {
                    printf("Failed\n");
                }

                fclose(Outf_p);
            }
            else
            {
                printf("Could not open file\n");
            }
        }
    }
    else
    {
        printf("Result: FAIL\n");
    }
    fflush(stdout);

    if (AllocatedInputBuffer_p)
    {
        free(AllocatedInputBuffer_p);
    }

#ifdef SBSIM_ALLOCATOR_DMARESOURCE
    {
        unsigned int lp;
        for (lp = 0; lp <= FragCount; lp++)
        {
            DMAResource_Release(DMAHandleInput[lp]);
        }
    }

    DMAResource_UnInit();
#endif

    return (int)Result;
}

/* Simple implementation of SB_Poll. */
bool
SB_Poll(void * PollParam_p)
{
    unsigned int * const PollCount_p = PollParam_p;

    *PollCount_p = *PollCount_p + 1;

#ifndef __CC_ARM
    /* If poll delay has been configured, cause a small delay. */
    if (sbsim_configuration.fPolldelay)
    {
        nanosleep(&sbsim_configuration.polldelay, NULL);
    }
#endif

    return true;
}

/* Simple implementation of SB_ReadData. */
uint32_t
SB_ReadData(void * PollParam_p,
            uint32_t * Data_p,
            uint32_t DataLen)
{
    /* Check Poll parameter has been provided (ignore by this function). */
    if (PollParam_p == NULL)
    {
        return 0;
    }

    /* Check Data_p is not NULL address (API misuse.) */
    if (Data_p == NULL)
    {
        return 0;
    }

    /* If read block size has been set and the
       DataLen is more than read block size, then return read block size. */
    if ((sbsim_configuration.readblock != 0) &&
        (sbsim_configuration.readblock < (int)DataLen))
    {
        return (uint32_t)sbsim_configuration.readblock;
    }

    /* Else: All data requested available for reading. */
    return DataLen;
}

/* end of file sbsim_verify.c */
