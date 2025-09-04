# SPDX-License-Identifier: GPL-2.0

# LEIPZIG platform

######################################################
## Platform Driver
######################################################
snd-soc-vtx-platform-objs := vtx-pcm.o vtx-i2s.o

obj-$(CONFIG_SND_SOC_VTX) += snd-soc-vtx-platform.o

######################################################
## Internal Built-In Codec Driver
######################################################
snd-soc-vtx-codec-internal-inno-objs := innosilicon.o

obj-$(CONFIG_SND_SOC_VTX_CODEC_INTERNAL_INNO) += snd-soc-vtx-codec-internal-inno.o

######################################################
## Machine Driver
######################################################
snd-soc-vtx-machine-evm-objs := leipzig-evm.o
snd-soc-vtx-machine-evm-ssm2603-objs := leipzig-evm-ssm2603.o
#snd-soc-vtx-machine-evm-inno-ssm2603-objs := leipzig-evm-ssm2603.o

obj-$(CONFIG_SND_SOC_VTX_MACH_INTERNAL_INNO) += snd-soc-vtx-machine-evm.o
obj-$(CONFIG_SND_SOC_VTX_MACH_SSM2603) += snd-soc-vtx-machine-evm-ssm2603.o
#obj-$(CONFIG_SND_SOC_VTX_MACH_INTERNAL_SSM2603) += snd-soc-vtx-machine-evm-inno-ssm2603.o


