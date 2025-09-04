#
# Copyright (c) 2023, VATICS INC. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#


SAFEZONE_SOURCES        :=      lib/safezone/SBLib/SB_SM/src/sbsm_api_decrypt.c \
				lib/safezone/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
			        lib/safezone/SBLib/SB_SM/src/sbsm_eip130_asset.c \
				lib/safezone/SBLib/SB_SM/src/sbsm_eip130_common.c \
			        lib/safezone/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
			        lib/safezone/SBLib/SB_SM/src/sbsm_eip130_hash.c \
			        lib/safezone/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
			        lib/safezone/SBLib/SB_SM/src/sbsm_hw_init.c \
			        lib/safezone/SBCommon/SBIF/src/sbif_attributes.c \
			        lib/safezone/Kit/EIP130/TokenHelper/src/eip130_token_common.c \
			        lib/safezone/Kit/EIP130/MailboxControl/src/eip130.c \
			        lib/safezone/Framework/CLIB/src/c_lib.c \
			        lib/safezone/Integration/DriverFramework_v4_bare/src/hwpal_device_bare.c \
			        lib/safezone/Integration/DriverFramework_v4_bare/src/hwpal_dmares_bare.c \
			        lib/safezone/SBLib/SB_HYBRID/src/sbhybrid_fw_init.c \

SAFEZONE_SOURCES         +=     plat/vatics/wagner/wagner_safezone.c

SAFEZONE_FLAGS += -DSB_CF_LITTLEENDIAN
SAFEZONE_FLAGS += -DSBCM_CF_IMAGE_TYPE_W_SBCR_KEY
SAFEZONE_FLAGS += -DCFG_IMPLDEFS_NO_DEBUG

SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/Config/ECC256
SAFEZONE_FLAGS += -Ilib/safezone/Config
SAFEZONE_FLAGS += -Ilib/safezone/SBLib/Config
SAFEZONE_FLAGS += -Ilib/safezone/SBLib/SB_API/incl
SAFEZONE_FLAGS += -Ilib/safezone/SBLib/SB_HYBRID/src
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/SBIF_API/incl
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/SBIF_TOOLS/incl
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/SB_SW_CRYPTO/incl
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/SB_AES_API/incl
SAFEZONE_FLAGS += -Ilib/safezone/Integration/DMARes_Record_bare/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/DriverFramework/v4_safezone/Basic_Defs/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/DriverFramework/v4_safezone/CLib_Abstraction/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/DriverFramework/v4/Device_API/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/DriverFramework/v4/DMAResource_API/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/DriverFramework/v4/GenericHelper/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/EIP130/MailboxControl/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/EIP130/MailboxControl/src
SAFEZONE_FLAGS += -Ilib/safezone/Kit/EIP130/TokenHelper/incl
SAFEZONE_FLAGS += -Ilib/safezone/Kit/EIP130/TokenHelper/src
SAFEZONE_FLAGS += -Ilib/safezone/Framework/PUBDEFS/incl
SAFEZONE_FLAGS += -Ilib/safezone/Framework/IMPLDEFS/incl
SAFEZONE_FLAGS += -Ilib/safezone/Framework/CLIB/incl

# missing in document???
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/SB_SW_CRYPTO/incl/micro-ecc
SAFEZONE_FLAGS += -Ilib/safezone/SBCommon/Config
SAFEZONE_FLAGS += -Iinclude/linux


CFLAGS                  +=      ${SAFEZONE_FLAGS}

