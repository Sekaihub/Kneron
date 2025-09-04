#
# SPDX-License-Identifier: BSD-3-Clause
#
DEBUG_DRAM	:=	0
DRAM_BUSCLK	:=	1400
HIGH_PERFORMANCE := 0
DDR_DQ_SWAP	:=	0


ifeq (${HIGH_PERFORMANCE},1)
DRAM_BUSCLK	:=	1520
endif

$(eval $(call add_define_val,DEBUG_DRAM,${DEBUG_DRAM}))
$(eval $(call add_define_val,HIGH_PERFORMANCE,${HIGH_PERFORMANCE}))
$(eval $(call add_define_val,DRAM_BUSCLK,${DRAM_BUSCLK}))
$(eval $(call add_define_val,DDR_DQ_SWAP,${DDR_DQ_SWAP}))

LPDDR4_SOURCE           :=     	drivers/vatics/dmac/dmac.c \
				drivers/vatics/ddr/sim_print.S \
				drivers/vatics/ddr/ddrc_init.c \
				drivers/vatics/ddr/lpddr4_init.c \
				drivers/vatics/ddr/lpddr4_func.c \
				drivers/vatics/ddr/memtester.c \
				drivers/vatics/ddr/tests.c \


ifeq (${DDR_DQ_SWAP},1)
  ifeq (${DRAM_BUSCLK},1520)
		LPDDR4_SOURCE += drivers/vatics/ddr/dwc_ddrphy_phyinit_out_lpddr4_train1d_non-EVM_HIGH_PERFORMANCE.c

	else
		LPDDR4_SOURCE += drivers/vatics/ddr/dwc_ddrphy_phyinit_out_lpddr4_train1d_non-EVM.c
	endif
else
  ifeq (${DRAM_BUSCLK},1520)
  LPDDR4_SOURCE += drivers/vatics/ddr/dwc_ddrphy_phyinit_out_lpddr4_train1d_EVM_HIGH_PERFORMANCE.c

  else ifeq (${DRAM_BUSCLK},1200)
  LPDDR4_SOURCE += drivers/vatics/ddr/dwc_ddrphy_phyinit_out_lpddr4_train1d_EVM1200.c

  else
  LPDDR4_SOURCE += drivers/vatics/ddr/dwc_ddrphy_phyinit_out_lpddr4_train1d_EVM.c
  endif
endif
