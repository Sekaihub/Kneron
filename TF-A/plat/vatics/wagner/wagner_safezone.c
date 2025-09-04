#include <common/debug.h>
#include <drivers/delay_timer.h>
#include <lib/libc/endian.h>
#include <wagner_buf.h>
#include <wagner_log.h>
#include "wagner_private.h"

#include "sbhybrid_internal.h"
#include <safezone.h>
#include <eip130_token_publicdata.h>
#include <eip130_token_asset.h>
#include <eip130_token_otp.h>

//#define SAFEZONE_DEBUG
#define SBSIM_MAX_SG SZ_64
static SBIF_SGVector_t SG_In[1 + SBSIM_MAX_SG];
static unsigned int __maybe_unused PollCount = 1;
static SB_StorageArea_t __maybe_unused StorageArea;
SBHYBRID_Context_t contex;
bl_header_info_t bl_header_info;
static bool	got_header_info;

uint8_t sbpk[SBPK_SIZE] __aligned(4) = {
/* the Qx value */
0xdf, 0xb7, 0x10, 0x20,
0x35, 0x9b, 0x14, 0xc6,
0xe0, 0xa9, 0x43, 0x66,
0xf5, 0xfc, 0x29, 0x21,
0xa9, 0xd9, 0x41, 0x58,
0x1d, 0xc6, 0x7c, 0xac,
0x05, 0xba, 0x1d, 0x23,
0xcc, 0x39, 0x01, 0xbc,

/* the Qy value */
0xbd, 0x46, 0xe7, 0xdd,
0x3d, 0xaf, 0x61, 0x3c,
0x2b, 0x61, 0x50, 0xc4,
0x15, 0xec, 0x84, 0x1b,
0xf1, 0x3a, 0x86, 0x59,
0xc0, 0xe0, 0x96, 0xd6,
0x0e, 0x28, 0xb4, 0x64,
0x7e, 0xd2, 0xd2, 0x80
};

uint8_t sbph[SBPK_HASH_SIZE] __aligned(4) = {
0x8c, 0xd8, 0xca, 0x29,
0x58, 0x9b, 0x67, 0x89,
0x4c, 0x8a, 0xfa, 0xe5,
0xaa, 0x7f, 0xb4, 0x08,
0xd4, 0xaf, 0xdd, 0xaf,
0x71, 0xac, 0x03, 0xda,
0x31, 0x7e, 0x1d, 0x64,
0xf8, 0x73, 0xaa, 0xe8,
};
uint8_t *secure_boot_public_key = sbpk;
uint8_t *secure_boot_public_key_hash = sbph;

const char cfgA_token[] __aligned(4) = {
0x00, 0x00, 0x00, 0xcf, 0x46, 0x57, 0x77, 0x02,
0x00, 0x00, 0x00, 0x03, 0xbf, 0x05, 0x7f, 0xb9,
0xbb, 0xad, 0x44, 0xc5, 0x1a, 0x40, 0x68, 0xb4,
0x93, 0x47, 0xf8, 0x8d, 0x8e, 0x94, 0x96, 0x9f,
0x9d, 0xea, 0x39, 0xc1, 0xae, 0x41, 0x0d, 0xd1,
0x62, 0x4e, 0x6e, 0xf4, 0x38, 0x76, 0xad, 0x02,
0x7e, 0x64, 0xe4, 0x3e, 0xff, 0x6f, 0xec, 0xe2,
0xa8, 0xec, 0x50, 0x5c, 0xad, 0x8c, 0x97, 0x49,
0xec, 0x50, 0x64, 0xd8, 0x29, 0x02, 0x5a, 0xb7,
0x70, 0xe4, 0xa2, 0x62, 0xac, 0xc1, 0xbd, 0xef,
0xf4, 0x07, 0x08, 0x45, 0x7d, 0x3f, 0x4b, 0x3b,
0xc1, 0xd1, 0xdc, 0xda, 0xa5, 0x5a, 0xe9, 0xaf,
0x21, 0x58, 0xc0, 0x90, 0xd7, 0xf6, 0x08, 0x23,
0x27, 0xbf, 0x6c, 0x1e, 0xf5, 0x47, 0x6a, 0x4a,
0xa9, 0xb6, 0xe9, 0x67, 0x61, 0xe1, 0x94, 0xd1,
0x16, 0x78, 0x9d, 0xdd, 0x3f, 0x64, 0x1a, 0x9f,
0xb4, 0x05, 0x72, 0x22, 0xf1, 0x22, 0xb5, 0x85,
0xc6, 0xe3, 0xc0, 0xd4, 0x3b, 0x39, 0xae, 0xbf,
0x00, 0x7a, 0x99, 0xc8, 0x58, 0x3b, 0xab, 0x19,
0xcc, 0x11, 0x3f, 0x4f, 0xa9, 0x8f, 0x84, 0x19,
0xdb, 0xa7, 0x07, 0xab, 0xb5, 0xb9, 0xcb, 0xf6,
0xd1, 0xca, 0x12, 0x5c, 0xc9, 0x73, 0xc9, 0x59,
0x62, 0x42, 0x0d, 0xd3, 0x97, 0xd9, 0xc7, 0x6d,
0x1c, 0x96, 0xb0, 0x08, 0x0f, 0x70, 0xb2, 0x2e,
0x72, 0x5c, 0x68, 0x86, 0x80, 0x7e, 0x01, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const char cfgB_token[] __aligned(4) = {
0x00, 0x00, 0x00, 0xcf, 0x46, 0x57, 0x77, 0x02,
0x00, 0x00, 0x00, 0x03, 0xec, 0x15, 0x5e, 0x49,
0x64, 0x95, 0x23, 0x37, 0xb0, 0x85, 0x9a, 0x56,
0xee, 0x89, 0x73, 0x61, 0x00, 0xf1, 0xeb, 0x58,
0x95, 0x37, 0x23, 0xc9, 0xcf, 0x0c, 0x4f, 0x87,
0xe8, 0x00, 0xdf, 0x6c, 0xc3, 0x88, 0x00, 0xcd,
0x11, 0x1c, 0xfb, 0x34, 0x1a, 0xe8, 0xdf, 0x95,
0x23, 0x90, 0x01, 0x12, 0xd2, 0x79, 0x99, 0x83,
0x57, 0x59, 0x20, 0x1c, 0x84, 0x5c, 0xcc, 0x3e,
0x50, 0xa6, 0xd3, 0x66, 0xd6, 0x44, 0x4d, 0xd9,
0x54, 0x87, 0x1e, 0xbc, 0x8e, 0x82, 0xa9, 0x0a,
0xda, 0xd7, 0x10, 0x19, 0xbe, 0xb3, 0xf3, 0x1d,
0x90, 0x03, 0x3f, 0xb4, 0x8d, 0xac, 0x40, 0x3e,
0xc1, 0xa1, 0x7f, 0x29, 0xff, 0xd6, 0xd1, 0x64,
0xf2, 0xb6, 0x17, 0x74, 0x61, 0xe1, 0x94, 0xd1,
0x16, 0x78, 0x9d, 0xdd, 0x3f, 0x64, 0x1a, 0x9f,
0xb4, 0x05, 0x72, 0x22, 0xf1, 0x22, 0xb5, 0x85,
0xc6, 0xe3, 0xc0, 0xd4, 0x3b, 0x39, 0xae, 0xbf,
0x00, 0x7a, 0x99, 0xc8, 0x58, 0x3b, 0xab, 0x19,
0xcc, 0x11, 0x3f, 0x4f, 0xa9, 0x8f, 0x84, 0x19,
0xdb, 0xa7, 0x07, 0xab, 0xb5, 0xb9, 0xcb, 0xf6,
0xd1, 0xca, 0x12, 0x5c, 0xc9, 0x73, 0xc9, 0x59,
0x62, 0x42, 0x0d, 0xd3, 0xb5, 0x79, 0xff, 0x47,
0xbd, 0x3b, 0x91, 0x14, 0x41, 0x38, 0xb7, 0xac,
0xcd, 0x25, 0x35, 0x8d, 0x00, 0x7e, 0x01, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
char *curret_cfgToken = (char *)cfgA_token;

bool
SB_Poll(void *PollParam_p)
{
	unsigned int * const PollCount_p = PollParam_p;

	*PollCount_p = *PollCount_p + 1;
#if 0
	VERBOSE("%s, delay 10ms\n", __func__);
	mdelay(10);
#ifndef __CC_ARM
	/* If poll delay has been configured, cause a small delay. */
	if (sbsim_configuration.fPolldelay) {
		nanosleep(&sbsim_configuration.polldelay, NULL);
	}
#endif
#endif

	return true;
}

uint32_t
SB_ReadData(void *PollParam_p,
		uint32_t *Data_p,
		uint32_t DataLen)
{
	/* Check Poll parameter has been provided (ignore by this function). */
	if (PollParam_p == NULL) {
		return 0;
	}

	/* Check Data_p is not NULL address (API misuse.) */
	if (Data_p == NULL) {
		return 0;
	}

	/*  If read block size has been set and the
	 *  DataLen is more than read block size, then return read block size.
	 */
#if 0
	if ((sbsim_configuration.readblock != 0) &&
			(sbsim_configuration.readblock < (int)DataLen)) {
		return (uint32_t)sbsim_configuration.readblock;
	}
#endif

	/* Else: All data requested available for reading. */
	VERBOSE("%s, addr:%p len:%d\n", __func__, Data_p, DataLen);
	return DataLen;
}

static void Print_OctetString(const char * const Description_p,
		const void * const Data_p,
		const unsigned int DataLen)
{
#ifdef SAFEZONE_DEBUG
	const uint8_t *Byte_p = Data_p;
	int Column = 16;
	unsigned int PrintedLen;

	printf("%s:", Description_p);

	for (PrintedLen = 0; PrintedLen < DataLen; PrintedLen++) {
		if (Column++ == 16) {
			printf("\n");
			Column = 1;
		}

		//VERBOSE("%.2x ", (int)*Byte_p);
		printf("0x%x ", (int)*Byte_p);
		Byte_p++;
	}

	printf("\n");
#endif
}

static void Print_PublicKey(const char * const Description_p,
		const SBIF_PublicKey_t * const PublicKey_p)
{
	VERBOSE("%s:\n", Description_p);
#ifdef SBIF_ECDSA
	Print_OctetString("Qx", PublicKey_p->Qx, sizeof(PublicKey_p->Qx));
	Print_OctetString("Qy", PublicKey_p->Qy, sizeof(PublicKey_p->Qy));
#else
	Print_OctetString("pubkeyExp", PublicKey_p->pubkeyExp,
					sizeof(PublicKey_p->pubkeyExp));
	Print_OctetString("modulus", PublicKey_p->modulus,
					sizeof(PublicKey_p->modulus));
#endif
}

static void Print_Signature(const char * const Description_p,
		const SBIF_Signature_t * const Signature_p)
{
	printf("%s:\n", Description_p);
#ifdef SBIF_ECDSA
	Print_OctetString("r", &Signature_p->r, sizeof(Signature_p->r));
	Print_OctetString("s", &Signature_p->s, sizeof(Signature_p->s));
#else
	Print_OctetString("signature", &Signature_p->signature,
					sizeof(Signature_p->signature));
#endif
}

static void __maybe_unused
Print_ImageInfo(const SBIF_Header_t * const Header_p)
{
	uint32_t TypeWord;
	uint32_t Type;
	uint32_t PubKeyType;
	uint8_t TypeChar[4];
	uint32_t header_image_len;

	TypeWord = be32toh(Header_p->Type);
	TypeChar[3] = (uint8_t)(TypeWord);
	TypeChar[2] = (uint8_t)(TypeWord >>  8);
	TypeChar[1] = (uint8_t)(TypeWord >> 16);
	TypeChar[0] = (uint8_t)(TypeWord >> 24);

	VERBOSE("Image header:\n");
	if ((TypeChar[0] >= 'A') && (TypeChar[0] <= 'Z') &&
			(TypeChar[1] >= 'A') && (TypeChar[1] <= 'Z') &&
			(TypeChar[2] >= 'a') && (TypeChar[2] <= 'z')) {
		VERBOSE("Type:\t%c%c%c\n",
				TypeChar[0], TypeChar[1], TypeChar[2]);
	} else {
		VERBOSE("Type:\tUnknown (corrupt header)\n");
	}
	VERBOSE("Version: %d\n", TypeChar[3]);
	PubKeyType = be32toh(Header_p->PubKeyType) & 0xffffff;
	if (PubKeyType == SBIF_PUBKEY_TYPE_ROM)	{
		VERBOSE("Public key in ROM\n");
	} else if (PubKeyType == SBIF_PUBKEY_TYPE_OTP) {
		VERBOSE("Public key in OTP\n");
	} else if (PubKeyType == SBIF_PUBKEY_TYPE_IMAGE) {
		VERBOSE("Public key in image header\n");
	} else {
		VERBOSE("Unknown public key type\n");
	}
#ifdef SBIF_ECDSA
	Print_OctetString("r",
		Header_p->Signature.r, sizeof(Header_p->Signature.r));
	Print_OctetString("s",
		Header_p->Signature.s, sizeof(Header_p->Signature.r));
#else
	Print_OctetString("signature",
		Header_p->Signature.signature,
		sizeof(Header_p->Signature.signature));
#endif
	Print_OctetString("key",
		Header_p->EncryptionKey, sizeof(Header_p->EncryptionKey));
	Print_OctetString("iv",
		Header_p->EncryptionIV, sizeof(Header_p->EncryptionIV));

	header_image_len = be32toh(Header_p->ImageLen);
	VERBOSE("len:\t%u\n", (unsigned int)header_image_len);

	Type = SBIF_TYPE_TYPE(TypeWord);
	if ((Type == SBIF_IMAGE_BLTp) ||
			(Type == SBIF_IMAGE_BLTw) ||
			(Type == SBIF_IMAGE_BLTe)) {
		SBIF_Certificate_t *Certs_p;
		uint32_t CertCount;
		uint32_t CertIndex;

		Certs_p = (void *)
			((SBIF_Header_t *)discard_const(Header_p) + 1);

		CertCount = be32toh(Header_p->CertificateCount);
		VERBOSE("cert count: %u\n", (unsigned int)CertCount);

		for (CertIndex = 0; CertIndex < CertCount; CertIndex++) {
			if (CertIndex == 4 && CertIndex < CertCount) {
				VERBOSE("%u more certificates\n",
				(unsigned int)(CertCount - CertIndex + 1));
				break;
			}

			VERBOSE("cert %u\n", (unsigned int)CertIndex);
			Print_PublicKey("public key",
					&Certs_p[CertIndex].PublicKey);
			Print_Signature("signature",
					&Certs_p[CertIndex].Signature);
		}
	}

	if (SBIF_Attribute_Check(&Header_p->ImageAttributes)) {
		uint32_t Value32 = 0;

		VERBOSE("Image attributes are valid\n");

		/* check for the rollback attribute */
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_ROLLBACK_ID,
					&Value32)) {
			VERBOSE("  RollbackID: 0x%08x\n",
					(unsigned int)Value32);
		} else {
			VERBOSE("  RollbackID: [not found]\n");
		}
	} else {
		VERBOSE("Image attributes check failed\n");
	}
}

int eip130_headerSize(SBIF_Header_t *Header_p)
{
	return SBIF_GET_HEADER_SIZE(Header_p, sizeof(SBIF_Header_t));
}

void set_got_header_info(uint32_t val)
{
	got_header_info = val;
}

void eip130_headerInfo(SBIF_Header_t *Header_p)
{
	uint32_t	image_type;

	if (got_header_info)
		return;

	set_got_header_info(1);
	if (SBIF_Attribute_Check(&Header_p->ImageAttributes)) {
#if defined(IMAGE_BL1)
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_SPI,
					&bl_header_info.spi_attr)) {
			VERBOSE("spi_attr:0x%x\n", bl_header_info.spi_attr);
		}
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_SCRTU_FW,
					&bl_header_info.scrtu_fw_offset)) {
			VERBOSE("scrtu fw_off:0x%x\n",
					bl_header_info.scrtu_fw_offset);
		}
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_DDR_FW,
					&bl_header_info.ddr_fw_offset)) {
			VERBOSE("ddr fw_off:0x%x\n",
					bl_header_info.ddr_fw_offset);
		}
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_TOTAL_SZIE,
					&bl_header_info.total_size)) {
			VERBOSE("total_size:0x%x\n",
					bl_header_info.total_size);
		}
#elif defined(IMAGE_BL2)
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_SPI_BL33_ADDR,
					&bl_header_info.spi_bl33_addr)) {
			VERBOSE("spi_bl33_addr:0x%x\n",
					bl_header_info.spi_bl33_addr);
		}
		if (SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
					SBIF_ATTRIBUTE_SPI_BL33_SIZE,
					&bl_header_info.spi_bl33_size)) {
			VERBOSE("spi_bl33_size:0x%x\n",
					bl_header_info.spi_bl33_size);
		}
#endif
	}
	image_type = Load_BE32(&Header_p->Type);
	image_type = SBIF_TYPE_TYPE(image_type);
	bl_header_info.bl_image_size = be32toh(Header_p->ImageLen);

	//Check Valid Header
	if ((image_type == SBIF_IMAGE_BLTp) ||
			(image_type == SBIF_IMAGE_BLTw) ||
			(image_type == SBIF_IMAGE_BLTe)) {
		bl_header_info.bl_offset =
			SBIF_GET_HEADER_SIZE(Header_p, sizeof(SBIF_Header_t));
	} else {
		//For Non-secure unknown header
		bl_header_info.spi_attr = 0;
		bl_header_info.ddr_fw_offset = 0;
		bl_header_info.bl_offset = 0;
		bl_header_info.bl_image_size = SZ_128K;
	}


	VERBOSE("image_offset:0x%x\n", bl_header_info.bl_offset);
	VERBOSE("image_size:0x%x\n", bl_header_info.bl_image_size);
}

int publicData_assetSearch(Device_Handle_t Device_EIP130,
		uint32_t assetNum,
		Eip130TokenAssetId_t *assetID,
		uint32_t *len)
{
	Eip130Token_Command_t t_cmd;
	Eip130Token_Result_t t_res;
	int ret;

	Eip130Token_Command_AssetSearch(&t_cmd, assetNum);
	Eip130Token_Command_Identity(&t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
	// Eip130Token_Command_SetTokenID(&t_cmd, 0x5000, false);
	Eip130Token_Command_SetTokenID(&t_cmd, assetNum, false);
	SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
			&t_cmd, &t_res,
			SBLIB_CFG_XM_MAILBOXNR);
	ret = Eip130Token_Result_Code(&t_res);
	if (ret)
		return ret;
	Eip130Token_Result_AssetSearch(&t_res, assetID, len);
	return ret;
}

static void process_token(Device_Handle_t Device_EIP130,
			Eip130Token_Command_t *t_cmd,
			Eip130TokenAssetId_t assetID,
			Eip130Token_Result_t *t_res)
{
	Eip130Token_Command_Identity(t_cmd, SBLIB_CFG_XM_TOKEN_IDENTITY);
	Eip130Token_Command_SetTokenID(t_cmd, assetID, false);
	SBHYBRID_EIP130_Common_ProcessToken(Device_EIP130,
			t_cmd, t_res,
			SBLIB_CFG_XM_MAILBOXNR);

}

int publicData_update(Device_Handle_t Device_EIP130,
		uint8_t *dest,
		Eip130TokenAssetId_t assetID,
		uint32_t len)
{
	Eip130Token_Command_t t_cmd;
	Eip130Token_Result_t t_res;
	int ret;

	Eip130Token_Command_PublicData_Read(&t_cmd, assetID,
			(Eip130TokenDmaAddress_t)dest, len);
	process_token(Device_EIP130, &t_cmd, assetID, &t_res);
	ret = Eip130Token_Result_Code(&t_res);
	if (ret) {
		VERBOSE("read pubdata fail, t_res.W[0]:0x%x\n", t_res.W[0]);
		return ret;
	}
	return ret;
}

int eip130_monoCnt(unsigned int image_id)
{
	Device_Handle_t Device_EIP130;
	Eip130Token_Command_t t_cmd;
	Eip130Token_Result_t t_res;
	Eip130TokenAssetId_t assetID;
	int ret = 0;
	uint32_t len;
	uint64_t monocnt = 0;
	unsigned int assetNum = 0;

		switch (image_id) {
#if defined(IMAGE_BL1)
		case BL2_IMAGE_ID:
			assetNum = MONOCNT_BL2_NUM;
			break;
		case NS_BL1U_IMAGE_ID:
			assetNum = MONOCNT_NS_BL1U_NUM;
			break;
#else
		case BL31_IMAGE_ID:
			assetNum = MONOCNT_BL31_NUM;
			break;
		case BL32_IMAGE_ID:
			assetNum = MONOCNT_BL32_NUM;
			break;
		case BL33_IMAGE_ID:
			assetNum = MONOCNT_BL33_NUM;
			break;
#endif
		default:
			return 0;
		}


	SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
	ret = publicData_assetSearch(Device_EIP130,
					assetNum, &assetID, &len);
	if (ret != 0) {
		VERBOSE("no assetNum:%d, OTP_Rollback = 0\n", assetNum);
		return monocnt;
	}
	Eip130Token_Command_OTPMonotonicCounter_Read(&t_cmd, assetID,
				(Eip130TokenDmaAddress_t)&monocnt, len);
	process_token(Device_EIP130, &t_cmd, assetID, &t_res);
	ret = Eip130Token_Result_Code(&t_res);
	if (ret) {
		VERBOSE("%s fail, t_res.W[0]:0x%x\n", __func__, t_res.W[0]);
		return ret;
	}
	SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);

	ret = __builtin_popcountl(monocnt);
	VERBOSE("monocnt value=0x%lx,  OTP_Rollback:%d\n", monocnt, ret);

	return ret;
}

int rollbackId_verify(unsigned int image_id, SBIF_Header_t *Header_p)
{
	int otp_id = eip130_monoCnt(image_id);
	uint32_t header_id = 0;

	if (!otp_id)
		return 0;

	SBIF_Attribute_Fetch(&Header_p->ImageAttributes,
				SBIF_ATTRIBUTE_ROLLBACK_ID,
				&header_id);
	VERBOSE("OTP_Rollback:%d Image_Rollback:%d\n", otp_id, header_id);

	return header_id < otp_id ? -1 : 0;
}

void update_otp_publicKey(void)
{
	Device_Handle_t Device_EIP130;
	int ret = 0;
	Eip130TokenAssetId_t keyId, hashId;
	uint32_t keyLen, hashLen;

	SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
	ret = publicData_assetSearch(Device_EIP130,
			SECURE_BOOT_PUBKEY_NUM, &keyId, &keyLen);
	if (ret != 0 ||	keyLen != sizeof(sbpk)) {
		wagner_bootstep(WAGNER_STEP_BL1_EIP130NOPUBKEY);
		VERBOSE("fail to find available assetNum:%d\n",
						SECURE_BOOT_PUBKEY_NUM);
		return;
	}
	VERBOSE("eip130 assetNum:%d, len:%d\n",
			SECURE_BOOT_PUBKEY_NUM, keyLen);

	ret = publicData_assetSearch(Device_EIP130,
			SECURE_BOOT_PUBHASH_NUM, &hashId, &hashLen);
	if (ret != 0 || hashLen != sizeof(sbph)) {
		wagner_bootstep(WAGNER_STEP_BL1_EIP130NOPUBHASH);
		VERBOSE("fail to find available assetNum:%d\n",
						SECURE_BOOT_PUBHASH_NUM);
		return;
	}
	VERBOSE("eip130 assetNum:%d, len:%d\n",
			SECURE_BOOT_PUBHASH_NUM, hashLen);

	/* update otp key into array */
	publicData_update(Device_EIP130, secure_boot_public_key,
			keyId, keyLen);
	publicData_update(Device_EIP130, secure_boot_public_key_hash,
			hashId, hashLen);
	SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);
#ifdef SAFEZONE_DEBUG
	VERBOSE("\nsecure_boot_public_key:");
	for (int i = 0 ; i < sizeof(sbpk) ; i++) {
		if (i % 8 == 0)
			printf("\n");
		printf("0x%x ", secure_boot_public_key[i]);
	}

	VERBOSE("\nsecure_boot_public_key_hash:");
	for (int i = 0 ; i < sizeof(sbph) ; i++) {
		if (i % 8 == 0)
			printf("\n");
		printf("0x%x ", secure_boot_public_key_hash[i]);
	}
#endif
}
int eip130_verifyImage_with_key(unsigned int image_id, uintptr_t image_buf,
				uintptr_t dest,
				const uint8_t *_PublicKey_p,
				const uint8_t *_Hash_p)
{
	SBIF_SGVector_t DataVectorsOutput[1];
	unsigned int HeaderLen =
		SBIF_GET_HEADER_SIZE(image_buf, sizeof(SBIF_Header_t));
	unsigned int DataLen;
	__maybe_unused unsigned int FragSizeLast = 0;
	SBIF_Header_t *Header_p = NULL;
	uint32_t PubKeyType;
	const uint8_t *PublicKey_p = (const uint8_t *)_PublicKey_p;
	const uint8_t *Hash_p =	(const uint8_t *)_Hash_p;
	int Result = -1;

	//        DataLen = (unsigned int)ImageSize - HeaderLen;
	Header_p = (SBIF_Header_t *)image_buf;
	DataLen = be32toh(Header_p->ImageLen);
	FragSizeLast = DataLen;

	PubKeyType = be32toh(Header_p->PubKeyType) & 0xffffff;
	if (PubKeyType == SBIF_PUBKEY_TYPE_IMAGE)
		PublicKey_p = NULL;
	else
		Hash_p = NULL;

	if (rollbackId_verify(image_id, Header_p)) {
		VERBOSE("Rollback id verify fail\n");
		wagner_err(WAGNER_ERR_ROLLBACK);
		return SB_ERROR_IMAGE_VERSION;
	}
	SG_In[0].Data_p = (uint32_t *)image_buf;
	SG_In[0].DataLen = HeaderLen;
	SG_In[1].Data_p = (uint32_t *)(image_buf + HeaderLen);
	SG_In[1].DataLen = DataLen;
	VERBOSE("SG_In[0] address:%p SG_In[1] address:%p\n", SG_In[0].Data_p,
			SG_In[1].Data_p);

	VERBOSE("SG_In[0] len:%d SG_In[1] len:%d\n", SG_In[0].DataLen,
			SG_In[1].DataLen);

	VERBOSE("ECDSA_WORDS:%d\n", SBIF_ECDSA_WORDS);
	VERBOSE("HeaderLen:%d DataLen:%d\n", HeaderLen, DataLen);
#ifdef SAFEZONE_DEBUG
	Print_ImageInfo(Header_p);
	/* always use the public key from the image header */
	Print_PublicKey("Public key from the image header",
					&Header_p->PublicKey);
#endif
	DataVectorsOutput[0].Data_p = (void *)dest;
	DataVectorsOutput[0].DataLen = SG_In[1].DataLen;

	Result = SB_Image_DecryptAndVerify(&StorageArea,
			&PollCount,
			(const SBIF_PublicKey_t *)PublicKey_p, // PublicKey_p
			Hash_p,// Hash_p
			Header_p,
			&SG_In[1],
			DataVectorsOutput,
			1);   // FragCount


	VERBOSE("Verify Result:%d\n", Result);
	return Result;

}

int eip130_verifyImage(unsigned int image_id,
			   uintptr_t image_buf, uintptr_t dest)
{
	return eip130_verifyImage_with_key(image_id, image_buf, dest,
			secure_boot_public_key, secure_boot_public_key_hash);
}

void eip130_force_unlink(void)
{
	Device_Handle_t Device_EIP130;

	SBHYBRID_EIP130_Common_Initialize_HW(&Device_EIP130);
	SBHYBRID_EIP130_Common_Uninitialize_HW(Device_EIP130);
}

int eip130_initfw(uintptr_t gpfw_base, uint32_t fips_disable)
{
	int ret = 0;

	VERBOSE("%s +++\n", __func__);
	if (!fips_disable)
		curret_cfgToken = (char *)cfgA_token;
	else
		curret_cfgToken = (char *)cfgB_token;

	// from external, separate token and data
	if (gpfw_base != VPL_SCRTU_EIP130_GPFW_BASE) {

		curret_cfgToken = (char *)gpfw_base;
		gpfw_base = gpfw_base + 256;
		VERBOSE("external token:0x%p gpfw:0x%lx\n",
						curret_cfgToken,
						gpfw_base);
	}
	ret = SBHYBRID_Initialize_FW(&contex, (void *)gpfw_base, 98304/4);
	if (ret != 0)
		VERBOSE("eip130 GPFW verify fail\n");
#if defined(IMAGE_BL1)
	else
		update_otp_publicKey();
#endif

	VERBOSE("ret:%d\n", ret);
	return ret;
}

