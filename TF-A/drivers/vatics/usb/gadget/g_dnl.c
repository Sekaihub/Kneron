// SPDX-License-Identifier: GPL-2.0+
/*
 * g_dnl.c -- USB Downloader Gadget
 *
 * Copyright (C) 2012 Samsung Electronics
 * Lukasz Majewski  <l.majewski@samsung.com>
 */

#include <common/debug.h>
#include <assert.h>
#include <wagner_buf.h>
#include <drivers/vatics/usb/g_dnl.h>

/*
 * One needs to define the following:
 * CONFIG_USB_GADGET_VENDOR_NUM
 * CONFIG_USB_GADGET_PRODUCT_NUM
 * CONFIG_USB_GADGET_MANUFACTURER
 * at e.g. ./configs/<board>_defconfig
 */

/**
 *  image_size - final fastboot image size
 **/
static u32 image_size;


#define STRING_MANUFACTURER 25
#define STRING_PRODUCT 2
/* Index of String Descriptor describing this configuration */
#define STRING_USBDOWN 2
/* Index of String serial */
#define STRING_SERIAL  3
#define MAX_STRING_SERIAL	256
/* Number of supported configurations */
#define CONFIGURATION_NUMBER 1

#define DRIVER_VERSION		"usb_dnl 2.0"
#define DWC3_CONTROLLER_NUMBER	0x23	//from uboot: gadget_chips.h
#define debug DBGUSB

#define CONFIG_USB_GADGET_VENDOR_NUM	0x3231
#define CONFIG_USB_GADGET_PRODUCT_NUM	0x0730
static const char product[] = "Download gadget";
static const char g_dnl_serial[] = "00000";
static const char manufacturer[] = "VATICS";

static struct usb_device_descriptor device_desc = {
	.bLength = sizeof device_desc,
	.bDescriptorType = USB_DT_DEVICE,

	.bcdUSB = __constant_cpu_to_le16(0x0200),
	.bDeviceClass = USB_CLASS_PER_INTERFACE,
	.bDeviceSubClass = 0, /*0x02:CDC-modem , 0x00:CDC-serial*/

	.idVendor = __constant_cpu_to_le16(CONFIG_USB_GADGET_VENDOR_NUM),
	.idProduct = __constant_cpu_to_le16(CONFIG_USB_GADGET_PRODUCT_NUM),
	/* .iProduct = DYNAMIC */
	/* .iSerialNumber = DYNAMIC */
	.bNumConfigurations = 1,
};

/*
 * static strings, in UTF-8
 * IDs for those strings are assigned dynamically at g_dnl_bind()
 */
static struct usb_string g_dnl_string_defs[] = {
	{.s = manufacturer},
	{.s = product},
	{.s = g_dnl_serial},
	{ }		/* end of list */
};

static struct usb_gadget_strings g_dnl_string_tab = {
	.language = 0x0409, /* en-us */
	.strings = g_dnl_string_defs,
};

static struct usb_gadget_strings *g_dnl_composite_strings[] = {
	&g_dnl_string_tab,
	NULL,
};

void g_dnl_set_product(const char *s)
{
	if (s)
		g_dnl_string_defs[1].s = s;
	else
		g_dnl_string_defs[1].s = product;
}

static int g_dnl_unbind(struct usb_composite_dev *cdev)
{
	struct usb_gadget *gadget = cdev->gadget;

	debug("%s: calling usb_gadget_disconnect for "
			"controller '%s'\n", __func__, gadget->name);
	usb_gadget_disconnect(gadget);

	return 0;
}

/*
static inline struct g_dnl_bind_callback *g_dnl_bind_callback_first(void)
{
	return ll_entry_start(struct g_dnl_bind_callback,
				g_dnl_bind_callbacks);
}

static inline struct g_dnl_bind_callback *g_dnl_bind_callback_end(void)
{
	return ll_entry_end(struct g_dnl_bind_callback,
				g_dnl_bind_callbacks);
}
*/

static int g_dnl_do_config(struct usb_configuration *c)
{
	const __maybe_unused char *s = c->cdev->driver->name;
	struct g_dnl_bind_callback *callback = &usb_dnl_bind_callback;

	debug("%s: configuration: 0x%p composite dev: 0x%p\n",
	      __func__, c, c->cdev);

	assert(!strcmp(s, callback->usb_function_name));

	return callback->fptr(c);
}

static int g_dnl_config_register(struct usb_composite_dev *cdev)
{
	struct usb_configuration *config;
	const char *name = "usb_dnload";

#ifdef IMAGE_BL2
	config = &overlaid_bufferp->usb_buf.g_dnl_config;
#else
	config = &overlaid_buffer.usb_buf.g_dnl_config;
#endif

	memset(config, 0, sizeof(*config));

	config->label = name;
	config->bmAttributes = USB_CONFIG_ATT_ONE;
#ifdef IS_SELFPOWERED
	config->bmAttributes |= USB_CONFIG_ATT_SELFPOWER;
#endif
	config->bConfigurationValue = CONFIGURATION_NUMBER;
	config->iConfiguration = STRING_USBDOWN;
	config->bind = g_dnl_do_config;

	return usb_add_config(cdev, config);
}

static bool g_dnl_detach_request;

bool g_dnl_detach(void)
{
	return g_dnl_detach_request;
}

void g_dnl_trigger_detach(void)
{
	g_dnl_detach_request = true;
}

void g_dnl_clear_detach(void)
{
	image_size = 0;
	g_dnl_detach_request = false;
}

void g_dnl_set_imagesize(uint32_t size)
{
	image_size = size;
}

uint32_t g_dnl_get_imagesize(void)
{
	return image_size;
}

static inline int g_dnl_get_bcd_device_number(struct usb_composite_dev *cdev)
{
	return (DWC3_CONTROLLER_NUMBER + 0x200);
}


static int g_dnl_bind(struct usb_composite_dev *cdev)
{
	__maybe_unused struct usb_gadget *gadget = cdev->gadget;
	int id, ret;
	int gcnum;

	debug("%s: gadget: 0x%p cdev: 0x%p\n", __func__, gadget, cdev);

	id = usb_string_id(cdev);

	if (id < 0)
		return id;

	g_dnl_string_defs[0].id = id;
	device_desc.iManufacturer = id;

	id = usb_string_id(cdev);

	if (id < 0)
		return id;

	g_dnl_string_defs[1].id = id;
	device_desc.iProduct = id;

	//g_dnl_bind_fixup(&device_desc, cdev->driver->name);

	if (strlen(g_dnl_serial)) {
		id = usb_string_id(cdev);

		if (id < 0)
			return id;

		g_dnl_string_defs[2].id = id;
		device_desc.iSerialNumber = id;
	}

	ret = g_dnl_config_register(cdev);
	if (ret)
		goto error;

	gcnum = g_dnl_get_bcd_device_number(cdev);
	device_desc.bcdDevice = cpu_to_le16(gcnum);

	debug("%s: calling usb_gadget_connect for "
			"controller '%s'\n", __func__, gadget->name);
#ifndef IMAGE_BL2
	usb_gadget_connect(gadget);
#endif

	return 0;

 error:
	g_dnl_unbind(cdev);
	return -ENOMEM;
}

static struct usb_composite_driver g_dnl_driver = {
	.name = NULL,
	.dev = &device_desc,
	.strings = g_dnl_composite_strings,
	.max_speed = USB_SPEED_SUPER,

	.bind = g_dnl_bind,
	.unbind = g_dnl_unbind,
};

/*
 * NOTICE:
 * Registering via USB function name won't be necessary after rewriting
 * g_dnl to support multiple USB functions.
 */
int g_dnl_register(const char *name)
{
	int ret;

	debug("%s: g_dnl_driver.name = %s\n", __func__, name);
	g_dnl_driver.name = name;

	ret = usb_composite_register(&g_dnl_driver);
	if (ret) {
		WARN("%s: failed!, error: %d\n", __func__, ret);
		return ret;
	}
	return 0;
}

void g_dnl_unregister(void)
{
	usb_composite_unregister(&g_dnl_driver);
}
