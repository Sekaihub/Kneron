// SPDX-License-Identifier: GPL-2.0
/**
 * udc-core.c - Core UDC Framework
 *
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com
 *
 * Author: Felipe Balbi <balbi@ti.com>
 *
 * Taken from Linux Kernel v3.19-rc1 (drivers/usb/gadget/udc-core.c) and ported
 * to uboot.
 *
 * commit 02e8c96627 : usb: gadget: udc: core: prepend udc_attach_driver with
 *		       usb_
 */

#include <assert.h>
#include <errno.h>
#include <string.h>

#include <linux/dma-mapping.h>
#include <linux/compat.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>

#include <drivers/vatics/usb/gadget/udc.h>

#include <wagner_buf.h>

#define	EISNAM		120	/* Is a named type file */

DEFINE_MUTEX(udc_lock);

/* ------------------------------------------------------------------------- */

int usb_gadget_map_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in)
{
	if (req->length == 0)
		return 0;

	//req->dma = (unsigned long) req->buf;

	req->dma = dma_map_single(req->buf, req->length,
				  is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);

	return 0;
}

void usb_gadget_unmap_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in)
{
	if (req->length == 0)
		return;

	dma_unmap_single(req->dma, req->length,
			 is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
}

/* ------------------------------------------------------------------------- */

/**
 * usb_gadget_giveback_request - give the request back to the gadget layer
 * Context: in_interrupt()
 *
 * This is called by device controller drivers in order to return the
 * completed request back to the gadget layer.
 */
void usb_gadget_giveback_request(struct usb_ep *ep,
		struct usb_request *req)
{
	req->complete(ep, req);
}

/* ------------------------------------------------------------------------- */

void usb_gadget_set_state(struct usb_gadget *gadget,
		enum usb_device_state state)
{
	gadget->state = state;
}

/* ------------------------------------------------------------------------- */

/**
 * usb_gadget_udc_reset - notifies the udc core that bus reset occurs
 * @gadget: The gadget which bus reset occurs
 * @driver: The gadget driver we want to notify
 *
 * If the udc driver has bus reset handler, it needs to call this when the bus
 * reset occurs, it notifies the gadget driver that the bus reset occurs as
 * well as updates gadget state.
 */
void usb_gadget_udc_reset(struct usb_gadget *gadget,
		struct usb_gadget_driver *driver)
{
	driver->reset(gadget);
	usb_gadget_set_state(gadget, USB_STATE_DEFAULT);
}

/**
 * usb_gadget_udc_start - tells usb device controller to start up
 * @udc: The UDC to be started
 *
 * This call is issued by the UDC Class driver when it's about
 * to register a gadget driver to the device controller, before
 * calling gadget driver's bind() method.
 *
 * It allows the controller to be powered off until strictly
 * necessary to have it powered on.
 *
 * Returns zero on success, else negative errno.
 */
static inline int usb_gadget_udc_start(struct usb_udc *udc)
{
	return udc->gadget->ops->udc_start(udc->gadget, udc->driver);
}

/**
 * usb_gadget_udc_stop - tells usb device controller we don't need it anymore
 * @gadget: The device we want to stop activity
 * @driver: The driver to unbind from @gadget
 *
 * This call is issued by the UDC Class driver after calling
 * gadget driver's unbind() method.
 *
 * The details are implementation specific, but it can go as
 * far as powering off UDC completely and disable its data
 * line pullups.
 */
static inline void usb_gadget_udc_stop(struct usb_udc *udc)
{
	udc->gadget->ops->udc_stop(udc->gadget);
}

/**
 * usb_add_gadget_udc_release - adds a new gadget to the udc class driver list
 * @parent: the parent device to this udc. Usually the controller driver's
 * device.
 * @gadget: the gadget to be added to the list.
 * @release: a gadget release function.
 *
 * Returns zero on success, negative errno otherwise.
 */
int usb_add_gadget_udc_release(struct usb_gadget *gadget)
{
	struct usb_udc		*udc;

#ifdef IMAGE_BL2
	udc = &overlaid_bufferp->usb_buf.udc;
#else
	udc = &overlaid_buffer.usb_buf.udc;
#endif
	memset(udc, 0, sizeof(*udc));

	udc->gadget = gadget;

	mutex_lock(&udc_lock);

	usb_gadget_set_state(gadget, USB_STATE_NOTATTACHED);

	mutex_unlock(&udc_lock);

	return 0;
}

/**
 * usb_add_gadget_udc - adds a new gadget to the udc class driver list
 * @parent: the parent device to this udc. Usually the controller
 * driver's device.
 * @gadget: the gadget to be added to the list
 *
 * Returns zero on success, negative errno otherwise.
 */
int usb_add_gadget_udc(struct usb_gadget *gadget)
{
	return usb_add_gadget_udc_release(gadget);
}

static void usb_gadget_remove_driver(struct usb_udc *udc)
{
	DBGUSB("unregistering UDC driver [%s]\n",
			udc->driver->function);

	usb_gadget_disconnect(udc->gadget);
	udc->driver->disconnect(udc->gadget);
	udc->driver->unbind(udc->gadget);
	usb_gadget_udc_stop(udc);

	udc->driver = NULL;
}

/**
 * usb_del_gadget_udc - deletes @udc from udc_list
 * @gadget: the gadget to be removed.
 *
 * This, will call usb_gadget_unregister_driver() if
 * the @udc is still busy.
 */
void usb_del_gadget_udc(struct usb_gadget *gadget)
{
	struct usb_udc		*udc;

#ifdef IMAGE_BL2
	udc = &overlaid_bufferp->usb_buf.udc;
#else
	udc = &overlaid_buffer.usb_buf.udc;
#endif

	if (udc->gadget == gadget) {
		DBGUSB("unregistering gadget\n");
		if (udc->driver)
			usb_gadget_remove_driver(udc);
	} else{
		WARN("gadget not registered.\n");
	}
}

/* ------------------------------------------------------------------------- */

static int udc_bind_to_driver(struct usb_udc *udc, struct usb_gadget_driver *driver)
{
	int ret;

	DBGUSB("registering UDC driver [%s]\n",
			driver->function);

	udc->driver = driver;

	// DWC3 doesn't need it
	//usb_gadget_udc_set_speed(udc, driver->speed);

	ret = driver->bind(udc->gadget);
	if (ret)
		goto err1;
	ret = usb_gadget_udc_start(udc);
	if (ret) {
		driver->unbind(udc->gadget);
		goto err1;
	}
#ifndef IMAGE_BL2
	usb_gadget_connect(udc->gadget);
#endif

	return 0;
err1:
	if (ret != -EISNAM)
		WARN("failed to start %s: %d\n",
			udc->driver->function, ret);
	udc->driver = NULL;
	return ret;
}

int usb_gadget_probe_driver(struct usb_gadget_driver *driver)
{
	struct usb_udc		*udc;
	int			ret;

	assert(driver && driver->bind && driver->setup);

	/* udc already init in usb_add_gadget_udc() */
#ifdef IMAGE_BL2
	udc = &overlaid_bufferp->usb_buf.udc;
#else
	udc = &overlaid_buffer.usb_buf.udc;
#endif

	ret = udc_bind_to_driver(udc, driver);

	return ret;
}

int usb_gadget_register_driver(struct usb_gadget_driver *driver)
{
	return usb_gadget_probe_driver(driver);
}

int usb_gadget_unregister_driver(struct usb_gadget_driver *driver)
{
	struct usb_udc		*udc;
	int			ret = -ENODEV;

	if (!driver || !driver->unbind)
		return -EINVAL;
#ifdef IMAGE_BL2
	udc = &overlaid_bufferp->usb_buf.udc;
#else
	udc = &overlaid_buffer.usb_buf.udc;
#endif

	mutex_lock(&udc_lock);
	if (udc->driver == driver) {
		usb_gadget_remove_driver(udc);
		usb_gadget_set_state(udc->gadget,
				USB_STATE_NOTATTACHED);
		ret = 0;
	}

	mutex_unlock(&udc_lock);
	return ret;
}
