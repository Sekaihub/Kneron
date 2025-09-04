#
# SPDX-License-Identifier: BSD-3-Clause
#

DEBUG_CLK	:=	0

$(eval $(call add_define_val,DEBUG_DRAM,${DEBUG_CLK}))

CLOCK_SOURCE           :=     	drivers/vatics/clk/kl730_clk.c \
