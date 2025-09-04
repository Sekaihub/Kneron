#
# Copyright (c) 2023, VATICS INC. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

BL2_AT_EL3	:=	0
BL1_ENABLE_MMU	:=	0
BL2_ENABLE_MMU	:=	1
WAGNER_A35	:=	0
TRUSTED_BOARD_BOOT	:=	1
INIT_UNUSED_NS_EL2	:=	1
ENABLE_WATCHDOG		:=	1
$(eval $(call add_define_val,WAGNER_A35,${WAGNER_A35}))
$(eval $(call add_define_val,ENABLE_WATCHDOG,${ENABLE_WATCHDOG}))

ifneq (${WAGNER_A35},1)
# Cortex-A55 must be compiled with HW_ASSISTED_COHERENCY enabled
$(eval $(call add_define_val,WAGNER_A55,${WAGNER_A55}))
HW_ASSISTED_COHERENCY	:=	1
ERRATA_A55_1530923	:=	1
# Wagner Cortex-A55 cores support Armv8.2 extensions
ARM_ARCH_MAJOR := 8
ARM_ARCH_MINOR := 2
endif

######################################
# For SOC Release BL1(ROM), Select 1
# Set ROM_RELEASE = 1 for SOC final release
######################################
ROM_RELEASE	:=	0

####################
## For FPGA Select 1
WAGNER_FPGA	:=	0

####################
# Below for BL1(ROM) Development
ROM_IN_DRAM	:=	1
FORCE_STOP	:=	0

#######################
## Below for ALL Debug
# LOG_MARKER_ERROR    /* 10 */
# LOG_MARKER_NOTICE   /* 20 */
# LOG_MARKER_WARNING  /* 30 */
# LOG_MARKER_INFO     /* 40 */
# LOG_MARKER_VERBOSE  /* 50 */
# To compile with highest log level (VERBOSE) set value to 50
ifneq (${DEBUG}, 0)
LOG_LEVEL		:=	50
endif
ENABLE_UART_PIN		:=	1
DEBUG_USB		:=	0
DEBUG_MMU_TABLES	:=	0

################################
### Override for ROM Release ###
################################
ifeq (${ROM_RELEASE},1)
override WAGNER_FPGA		:=	0
override ROM_IN_DRAM		:=	0
override FORCE_STOP		:=	0
override LOG_LEVEL		:=	0
override ENABLE_UART_PIN	:=	0
override ENABLE_ASSERTIONS	:=      0
override DEBUG_USB		:=	0
override ENABLE_WATCHDOG	:=	1
endif

$(eval $(call add_define_val,WAGNER_FPGA,${WAGNER_FPGA}))
$(eval $(call add_define_val,ROM_IN_DRAM,${ROM_IN_DRAM}))
$(eval $(call add_define_val,BL1_ENABLE_MMU,${BL1_ENABLE_MMU}))
$(eval $(call add_define_val,BL2_ENABLE_MMU,${BL2_ENABLE_MMU}))
$(eval $(call add_define_val,ENABLE_UART_PIN,${ENABLE_UART_PIN}))
$(eval $(call add_define_val,DEBUG_USB,${DEBUG_USB}))
$(eval $(call add_define_val,DEBUG_MMU_TABLES,${DEBUG_MMU_TABLES}))
$(eval $(call add_define_val,FORCE_STOP,${FORCE_STOP}))

CRASH_CONSOLE_BASE		:=	UART_0
COLD_BOOT_SINGLE_CPU		:=	0
PROGRAMMABLE_RESET_ADDRESS	:=	0
ENABLE_SVE_FOR_NS		:=	0

# Process flags
$(eval $(call add_define,CRASH_CONSOLE_BASE))

# Checkpatch: Base commit to perform code check on
BASE_COMMIT			:= origin/wagner
CHECKPATCH			:= plat/vatics/wagner/scripts/checkpatch.pl

# Add the build options to pack Trusted OS Extra1 and Trusted OS Extra2 images
# in the FIP if the platform requires.
ifneq ($(BL32_EXTRA1),)
$(eval $(call TOOL_ADD_IMG,bl32_extra1,--tos-fw-extra1))
endif
ifneq ($(BL32_EXTRA2),)
$(eval $(call TOOL_ADD_IMG,bl32_extra2,--tos-fw-extra2))
endif

include lib/xlat_tables_v2/xlat_tables.mk

USE_COHERENT_MEM	:=	0

PLAT_INCLUDES		:=	-Iplat/vatics/wagner/include	\
				-Iinclude/plat/arm/common/aarch64

PLAT_BL_COMMON_SOURCES	:=	drivers/ti/uart/aarch64/16550_console.S \
				drivers/delay_timer/delay_timer.c	\
				drivers/delay_timer/generic_delay_timer.c \
				drivers/vatics/watchdog/wdt.c \
				drivers/vatics/qspi/dw_qspi.c \
				drivers/vatics/pdma/pdma.c \
				drivers/mtd/spi-mem/spi_mem.c \
				drivers/mtd/nor/spi_nor.c \
				drivers/mtd/nand/spi_nand.c \
				plat/vatics/wagner/aarch64/wagner_common.c \
				plat/vatics/wagner/wagner_tzc.c	\
				plat/vatics/wagner/wagner_spi.c

ifneq (${ENABLE_STACK_PROTECTOR},0)
PLAT_BL_COMMON_SOURCES	+=	plat/vatics/wagner/wagner_stack_protector.c
endif

ifneq (${TRUSTED_BOARD_BOOT},0)
AUTH_SOURCES            :=      plat/vatics/wagner/wagner_crypto.c

BL1_SOURCES             +=      bl1/tbbr/tbbr_img_desc.c		\
				${AUTH_SOURCES}

BL2_SOURCES             +=      ${AUTH_SOURCES}
endif

# GIC-600 configuration
GICV3_SUPPORT_GIC600	:=	1

# Include GICv3 driver files
include drivers/arm/gic/v3/gicv3.mk

# Include USB driver files
include drivers/vatics/usb/usb.mk

BL2_USB_EARLY_TZC	:=	1
$(eval $(call add_define_val,BL2_USB_EARLY_TZC,${BL2_USB_EARLY_TZC}))

# Include Safezone files
include plat/vatics/wagner/wagner_safezone.mk

# Include clock driver files
include drivers/vatics/clk/clk.mk

# Include DDR driver files
include drivers/vatics/ddr/ddr.mk

WAGNER_SDHCI_SOURCE     :=      plat/vatics/wagner/wagner_sdhci.c \
				drivers/mmc/mmc.c \
				drivers/mmc/sdhci.c \
				drivers/mmc/sdhci-adma.c
FS_FAT_SOURCE           :=      fs/fat.c

WAGNER_GIC_SOURCES	:=	${GICV3_SOURCES}			\
				plat/common/plat_gicv3.c		\
				plat/vatics/wagner/wagner_gicv3.c

BL1_SOURCES		+=	plat/vatics/wagner/aarch64/wagner_helpers.S \
				plat/vatics/wagner/wagner_bl1_setup.c \
				plat/vatics/wagner/wagner_bl_common.c \
				plat/vatics/wagner/wagner_usb_boot.c \
				plat/vatics/wagner/wagner_log.c \
				plat/vatics/wagner/wagner_pmu_api.S \
				plat/vatics/wagner/wagner_bl1_fwu.c \
				lib/locks/exclusive/${ARCH}/spinlock.S	\
				${LEIPZIG_USB_SOURCES} \
				${WAGNER_SDHCI_SOURCE} \
				${FS_FAT_SOURCE}       \
				${LPDDR4_SOURCE}       \
				${SAFEZONE_SOURCES}

ifeq ($(BL1_ENABLE_MMU),1)
BL1_SOURCES		+=	${XLAT_TABLES_LIB_SRCS}
endif


BL2_SOURCES		+=	common/desc_image_load.c		\
				drivers/arm/pl061/pl061_gpio.c		\
				drivers/gpio/gpio.c			\
				${XLAT_TABLES_LIB_SRCS}			\
				plat/vatics/wagner/aarch64/wagner_helpers.S \
				plat/vatics/wagner/wagner_bl2_mem_params_desc.c \
				plat/vatics/wagner/wagner_pmu_api.S \
				plat/vatics/wagner/wagner_bl2_setup.c \
				plat/vatics/wagner/wagner_bl_common.c \
				plat/vatics/wagner/wagner_usb_boot.c \
				plat/vatics/wagner/wagner_log.c \
				${LEIPZIG_USB_SOURCES} \
				${WAGNER_SDHCI_SOURCE} \
				${FS_FAT_SOURCE}       \
				${CLOCK_SOURCE}       \
				${LPDDR4_SOURCE}       \
				${SAFEZONE_SOURCES}

ifeq (${SPD},opteed)
BL2_SOURCES		+=	lib/optee/optee_utils.c
endif

BL31_SOURCES		+=	drivers/arm/cci/cci.c			\
				drivers/arm/pl061/pl061_gpio.c		\
				drivers/gpio/gpio.c			\
				${XLAT_TABLES_LIB_SRCS}			\
				plat/common/plat_psci_common.c  	\
				plat/vatics/wagner/aarch64/wagner_helpers.S \
				plat/vatics/wagner/wagner_bl31_setup.c 	\
				plat/vatics/wagner/wagner_bl_common.c 	\
				plat/vatics/wagner/wagner_pm.c		\
				plat/vatics/wagner/wagner_topology.c 	\
				plat/vatics/wagner/wagner_pmu_api.S 	\
				plat/vatics/wagner/wagner_sip_svc.c	\
				${WAGNER_GIC_SOURCES}                   \
				${SAFEZONE_SOURCES}

ifeq (${WAGNER_A35},1)
BL1_SOURCES		+=	lib/cpus/aarch64/cortex_a35.S
BL31_SOURCES		+=	lib/cpus/aarch64/cortex_a35.S
else
BL1_SOURCES		+=	lib/cpus/aarch64/cortex_a55.S
BL31_SOURCES		+=	lib/cpus/aarch64/cortex_a55.S
endif

FIP_ALIGN			:=	512
