#
# SPDX-License-Identifier: BSD-3-Clause
#

$(eval $(call add_define,CONFIG_USB_DWC3_GADGET))

LEIPZIG_USB_SOURCES	 += \
					drivers/vatics/usb/dwc3/dwc3_core.c \
					drivers/vatics/usb/dwc3/dwc3_gadget.c \
					drivers/vatics/usb/dwc3/dwc3_ep0.c \
					drivers/vatics/usb/gadget/config.c \
					drivers/vatics/usb/gadget/usbstring.c \
					drivers/vatics/usb/gadget/core.c \
					drivers/vatics/usb/gadget/udc/udc-core.c \
					drivers/vatics/usb/gadget/composite.c \
					drivers/vatics/usb/gadget/f_fastboot.c \
					drivers/vatics/usb/gadget/fb_getvar.c \
					drivers/vatics/usb/gadget/fb_command.c \
					drivers/vatics/usb/gadget/fb_common.c \
					drivers/vatics/usb/gadget/g_dnl.c

