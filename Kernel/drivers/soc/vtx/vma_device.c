// SPDX-License-Identifier: GPL-2.0-only

#include <linux/module.h>
#include <linux/device.h>
#include <linux/err.h>

static struct class *vma_class;

struct device *vma_register_device(int devno, void *drvdata, const char *fmt, ...)
{
	va_list vargs;
	struct device *dev;
	char buf[32];

	va_start(vargs, fmt);
	vsnprintf(buf, sizeof(buf), fmt, vargs);
	dev = device_create_with_groups(vma_class, NULL, devno, drvdata, NULL, buf);
	va_end(vargs);

	return dev;
}
EXPORT_SYMBOL_GPL(vma_register_device);

void vma_unregister_device(int devno)
{
	device_destroy(vma_class, devno);
}
EXPORT_SYMBOL_GPL(vma_unregister_device);

static int __init vma_class_init(void)
{
	vma_class = class_create(THIS_MODULE, "vma");
	if (IS_ERR(vma_class)) {
		pr_warn("Unable to create vma class; errno = %ld\n", PTR_ERR(vma_class));
		return PTR_ERR(vma_class);
	}
	return 0;
}

static void __exit vma_class_exit(void)
{
	class_destroy(vma_class);
}

subsys_initcall(vma_class_init);
module_exit(vma_class_exit);
MODULE_LICENSE("GPL");
