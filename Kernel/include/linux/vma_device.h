/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __VMA_DEVICE_H
#define __VMA_DEVICE_H

extern struct device *vma_register_device(int devno, void *drvdata, const char *fmt, ...);
extern void vma_unregister_device(int devno);

#endif /* __VMA_DEVICE_H */
