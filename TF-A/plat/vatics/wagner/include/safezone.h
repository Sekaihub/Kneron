#ifndef SAFEZONE_H
#define SAFEZONE_H
#include <platform_def.h>
#include <lib/mmio.h>
#include <sysctrl.h>

#include <cf_sblib.h>                   /* Configuration toggles */
#include <sb_common.h>                  /* verify [and decrypt] API */
#include <sb_setfipsmode.h>             /* set FIPS mode API */
#include <sbif.h>                       /* header fields and consts */
#include <sbif_attributes.h>            /* header attribute processing API */

#include "sbhybrid_internal.h"
#include "../wagner_private.h"

#define SBPK_SIZE		64
#define SBPK_HASH_SIZE		32
#define SECURE_BOOT_PUBKEY_NUM	0x1
#define SECURE_BOOT_PUBHASH_NUM	0x2

#define MONOCNT_BL2_NUM		10
#define MONOCNT_BL31_NUM	11
#define MONOCNT_BL32_NUM	12
#define MONOCNT_BL33_NUM	13
#define MONOCNT_NS_BL1U_NUM	14

int eip130_initfw(uintptr_t gpfw_base, uint32_t fips_disable);
int eip130_verifyImage(unsigned int image_id,
				uintptr_t image_buf, uintptr_t dest);
int eip130_verifyImage_with_key(unsigned int image_id, uintptr_t image_buf,
					uintptr_t dest,
					const uint8_t *_PublicKey_p,
					const uint8_t *_Hash_p);
int eip130_headerSize(SBIF_Header_t *Header_p);

void eip130_headerInfo(SBIF_Header_t *Header_p);
void eip130_force_unlink(void);
void set_got_header_info(uint32_t val);
#endif
