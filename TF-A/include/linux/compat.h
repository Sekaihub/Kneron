#ifndef _LINUX_COMPAT_H_
#define _LINUX_COMPAT_H_

typedef int irqreturn_t;

#define IRQ_NONE 0
#define IRQ_HANDLED 1
#define IRQ_WAKE_THREAD 2

#define uboot_spin_lock_init(lock) do {} while (0)
#define uboot_spin_lock(lock) do {} while (0)
#define uboot_spin_unlock(lock) do {} while (0)
#define spin_lock_irqsave(lock, flags) do { } while (0)
#define spin_unlock_irqrestore(lock, flags) do { flags = 0; } while (0)

#define DEFINE_MUTEX(...)
#define mutex_init(...)
#define mutex_lock(...)
#define mutex_unlock(...)


#endif
