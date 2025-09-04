// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2003
 * Gerry Hamel, geh@ti.com, Texas Instruments
 *
 * Based on
 * linux/drivers/usbd/usbd.c.c - USB Device Core Layer
 *
 * Copyright (c) 2000, 2001, 2002 Lineo
 * Copyright (c) 2001 Hewlett Packard
 *
 * By:
 *	Stuart Lynne <sl@lineo.com>,
 *	Tom Rushworth <tbr@lineo.com>,
 *	Bruce Balden <balden@lineo.com>
 */

#include <drivers/vatics/usb/usbdevice.h>
#include <linux/types.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <wagner_buf.h>

#define MAX_INTERFACES 2

int maxstrings = 20;

/* Global variables ************************************************************************** */

struct usb_string_descriptor **usb_strings;

int usb_devices;

extern struct usb_function_driver ep0_driver;

int registered_functions;
int registered_devices;

static char *usbd_device_events[] = {
	"DEVICE_UNKNOWN",
	"DEVICE_INIT",
	"DEVICE_CREATE",
	"DEVICE_HUB_CONFIGURED",
	"DEVICE_RESET",
	"DEVICE_ADDRESS_ASSIGNED",
	"DEVICE_CONFIGURED",
	"DEVICE_SET_INTERFACE",
	"DEVICE_SET_FEATURE",
	"DEVICE_CLEAR_FEATURE",
	"DEVICE_DE_CONFIGURED",
	"DEVICE_BUS_INACTIVE",
	"DEVICE_BUS_ACTIVITY",
	"DEVICE_POWER_INTERRUPTION",
	"DEVICE_HUB_RESET",
	"DEVICE_DESTROY",
	"DEVICE_FUNCTION_PRIVATE",
};

/* Descriptor support functions ************************************************************** */


/**
 * usbd_get_string - find and return a string descriptor
 * @index: string index to return
 *
 * Find an indexed string and return a pointer to a it.
 */
struct usb_string_descriptor *usbd_get_string (__u8 index)
{
	if (index >= maxstrings) {
		return NULL;
	}
	return usb_strings[index];
}


/* Access to device descriptor functions ***************************************************** */


/* *
 * usbd_device_configuration_instance - find a configuration instance for this device
 * @device:
 * @configuration: index to configuration, 0 - N-1
 *
 * Get specifed device configuration. Index should be bConfigurationValue-1.
 */
static struct usb_configuration_instance *usbd_device_configuration_instance (struct usb_device_instance *device,
		unsigned int port, unsigned int configuration)
{
	if (configuration >= device->configurations)
		return NULL;

	return device->configuration_instance_array + configuration;
}


/* *
 * usbd_device_interface_instance
 * @device:
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 *
 * Return the specified interface descriptor for the specified device.
 */
struct usb_interface_instance *usbd_device_interface_instance (struct usb_device_instance *device, int port, int configuration, int interface)
{
	struct usb_configuration_instance *configuration_instance;

	if ((configuration_instance = usbd_device_configuration_instance (device, port, configuration)) == NULL) {
		return NULL;
	}
	if (interface >= configuration_instance->interfaces) {
		return NULL;
	}
	return configuration_instance->interface_instance_array + interface;
}

/* *
 * usbd_device_alternate_descriptor_list
 * @device:
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 * @alternate: alternate setting
 *
 * Return the specified alternate descriptor for the specified device.
 */
struct usb_alternate_instance *usbd_device_alternate_instance (struct usb_device_instance *device, int port, int configuration, int interface, int alternate)
{
	struct usb_interface_instance *interface_instance;

	if ((interface_instance = usbd_device_interface_instance (device, port, configuration, interface)) == NULL) {
		return NULL;
	}

	if (alternate >= interface_instance->alternates) {
		return NULL;
	}

	return interface_instance->alternates_instance_array + alternate;
}


/* *
 * usbd_device_device_descriptor
 * @device: which device
 * @configuration: index to configuration, 0 - N-1
 * @port: which port
 *
 * Return the specified configuration descriptor for the specified device.
 */
struct usb_device_descriptor *usbd_device_device_descriptor (struct usb_device_instance *device, int port)
{
	return (device->device_descriptor);
}

/**
 * usbd_device_configuration_descriptor
 * @device: which device
 * @port: which port
 * @configuration: index to configuration, 0 - N-1
 *
 * Return the specified configuration descriptor for the specified device.
 */
struct usb_configuration_descriptor *usbd_device_configuration_descriptor (struct
									   usb_device_instance
									   *device, int port, int configuration)
{
	struct usb_configuration_instance *configuration_instance;
	if (!(configuration_instance = usbd_device_configuration_instance (device, port, configuration))) {
		return NULL;
	}
	return (configuration_instance->configuration_descriptor);
}


/**
 * usbd_device_interface_descriptor
 * @device: which device
 * @port: which port
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 * @alternate: alternate setting
 *
 * Return the specified interface descriptor for the specified device.
 */
struct usb_interface_descriptor *usbd_device_interface_descriptor (struct usb_device_instance
								   *device, int port, int configuration, int interface, int alternate)
{
	struct usb_interface_instance *interface_instance;
	if (!(interface_instance = usbd_device_interface_instance (device, port, configuration, interface))) {
		return NULL;
	}
	if ((alternate < 0) || (alternate >= interface_instance->alternates)) {
		return NULL;
	}
	return (interface_instance->alternates_instance_array[alternate].interface_descriptor);
}

/**
 * usbd_device_endpoint_descriptor_index
 * @device: which device
 * @port: which port
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 * @alternate: index setting
 * @index: which index
 *
 * Return the specified endpoint descriptor for the specified device.
 */
struct usb_endpoint_descriptor *usbd_device_endpoint_descriptor_index (struct usb_device_instance
								       *device, int port, int configuration, int interface, int alternate, int index)
{
	struct usb_alternate_instance *alternate_instance;

	if (!(alternate_instance = usbd_device_alternate_instance (device, port, configuration, interface, alternate))) {
		return NULL;
	}
	if (index >= alternate_instance->endpoints) {
		return NULL;
	}
	return *(alternate_instance->endpoints_descriptor_array + index);
}


/**
 * usbd_device_endpoint_transfersize
 * @device: which device
 * @port: which port
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 * @index: which index
 *
 * Return the specified endpoint transfer size;
 */
int usbd_device_endpoint_transfersize (struct usb_device_instance *device, int port, int configuration, int interface, int alternate, int index)
{
	struct usb_alternate_instance *alternate_instance;

	if (!(alternate_instance = usbd_device_alternate_instance (device, port, configuration, interface, alternate))) {
		return 0;
	}
	if (index >= alternate_instance->endpoints) {
		return 0;
	}
	return *(alternate_instance->endpoint_transfersize_array + index);
}


/**
 * usbd_device_endpoint_descriptor
 * @device: which device
 * @port: which port
 * @configuration: index to configuration, 0 - N-1
 * @interface: index to interface
 * @alternate: alternate setting
 * @endpoint: which endpoint
 *
 * Return the specified endpoint descriptor for the specified device.
 */
struct usb_endpoint_descriptor *usbd_device_endpoint_descriptor (struct usb_device_instance *device, int port, int configuration, int interface, int alternate, int endpoint)
{
	struct usb_endpoint_descriptor *endpoint_descriptor;
	int i;

	for (i = 0; !(endpoint_descriptor = usbd_device_endpoint_descriptor_index (device, port, configuration, interface, alternate, i)); i++) {
		if (endpoint_descriptor->bEndpointAddress == endpoint) {
			return endpoint_descriptor;
		}
	}
	return NULL;
}

/**
 * usbd_endpoint_halted
 * @device: point to struct usb_device_instance
 * @endpoint: endpoint to check
 *
 * Return non-zero if endpoint is halted.
 */
int usbd_endpoint_halted (struct usb_device_instance *device, int endpoint)
{
	return (device->status == USB_STATUS_HALT);
}


/* URB linked list functions ***************************************************** */

/*
 * Initialize an urb_link to be a single element list.
 * If the urb_link is being used as a distinguished list head
 * the list is empty when the head is the only link in the list.
 */
void urb_link_init (urb_link * ul)
{
	if (ul) {
		ul->prev = ul->next = ul;
	}
}

/*
 * Detach an urb_link from a list, and set it
 * up as a single element list, so no dangling
 * pointers can be followed, and so it can be
 * joined to another list if so desired.
 */
void urb_detach (struct urb *urb)
{
	if (urb) {
		urb_link *ul = &urb->link;
		ul->next->prev = ul->prev;
		ul->prev->next = ul->next;
		urb_link_init (ul);
	}
}

/*
 * Return the first urb_link in a list with a distinguished
 * head "hd", or NULL if the list is empty.  This will also
 * work as a predicate, returning NULL if empty, and non-NULL
 * otherwise.
 */
urb_link *first_urb_link (urb_link * hd)
{
	urb_link *nx;
	if (NULL != hd && NULL != (nx = hd->next) && nx != hd) {
		/* There is at least one element in the list */
		/* (besides the distinguished head). */
		return (nx);
	}
	/* The list is empty */
	return (NULL);
}

/*
 * Return the first urb in a list with a distinguished
 * head "hd", or NULL if the list is empty.
 */
struct urb *first_urb (urb_link * hd)
{
	urb_link *nx;
	if (NULL == (nx = first_urb_link (hd))) {
		/* The list is empty */
		return (NULL);
	}
	return (p2surround (struct urb, link, nx));
}

/*
 * Detach and return the first urb in a list with a distinguished
 * head "hd", or NULL if the list is empty.
 *
 */
struct urb *first_urb_detached (urb_link * hd)
{
	struct urb *urb;
	if ((urb = first_urb (hd))) {
		urb_detach (urb);
	}
	return urb;
}


/*
 * Append an urb_link (or a whole list of
 * urb_links) to the tail of another list
 * of urb_links.
 */
void urb_append (urb_link * hd, struct urb *urb)
{
	if (hd && urb) {
		urb_link *new = &urb->link;

		/* This allows the new urb to be a list of urbs, */
		/* with new pointing at the first, but the link */
		/* must be initialized. */
		/* Order is important here... */
		urb_link *pul = hd->prev;
		new->prev->next = hd;
		hd->prev = new->prev;
		new->prev = pul;
		pul->next = new;
	}
}

/* Event signaling functions ***************************************************** */

/**
 * usbd_device_event - called to respond to various usb events
 * @device: pointer to struct device
 * @event: event to respond to
 *
 * Used by a Bus driver to indicate an event.
 */
void usbd_device_event_irq (struct usb_device_instance *device, usb_device_event_t event, int data)
{
#if (DEBUG_USB == 1)
	usb_device_state_t state;
#endif

	if (!device || !device->bus) {
		ERROR("(%p,%d) NULL device or device->bus", device, event);
		return;
	}

#if (DEBUG_USB == 1)
	state = device->device_state;
#endif

	INFO("%s", usbd_device_events[event]);

	switch (event) {
	case DEVICE_UNKNOWN:
		break;
	case DEVICE_INIT:
		device->device_state = STATE_INIT;
		break;

	case DEVICE_CREATE:
		device->device_state = STATE_ATTACHED;
		break;

	case DEVICE_HUB_CONFIGURED:
		device->device_state = STATE_POWERED;
		break;

	case DEVICE_RESET:
		device->device_state = STATE_DEFAULT;
		device->address = 0;
		break;

	case DEVICE_ADDRESS_ASSIGNED:
		device->device_state = STATE_ADDRESSED;
		break;

	case DEVICE_CONFIGURED:
		device->device_state = STATE_CONFIGURED;
		break;

	case DEVICE_DE_CONFIGURED:
		device->device_state = STATE_ADDRESSED;
		break;

	case DEVICE_BUS_INACTIVE:
		if (device->status != USBD_CLOSING) {
			device->status = USBD_SUSPENDED;
		}
		break;
	case DEVICE_BUS_ACTIVITY:
		if (device->status != USBD_CLOSING) {
			device->status = USBD_OK;
		}
		break;

	case DEVICE_SET_INTERFACE:
		break;
	case DEVICE_SET_FEATURE:
		break;
	case DEVICE_CLEAR_FEATURE:
		break;

	case DEVICE_POWER_INTERRUPTION:
		device->device_state = STATE_POWERED;
		break;
	case DEVICE_HUB_RESET:
		device->device_state = STATE_ATTACHED;
		break;
	case DEVICE_DESTROY:
		device->device_state = STATE_UNKNOWN;
		break;

	case DEVICE_FUNCTION_PRIVATE:
		break;

	default:
		DBGUSB("event %d - not handled\n", event);
		break;
	}
	DBGUSB("%s event: %d oldstate: %d newstate: %d ",
		device->name, event, state, device->device_state);
	DBGUSB("status: %d address: %d\n", device->status, device->address);

	/* tell the bus interface driver */
	if( device->event ) {
		/* DBGUSB("calling device->event\n"); */
		device->event(device, event, data);
	}
}
