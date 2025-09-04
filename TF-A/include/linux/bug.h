#ifndef _LINUX_BUG_H
#define _LINUX_BUG_H

#include <common/debug.h>
#include <linux/compiler.h>
#include <linux/err.h>

#define BUG() do { \
	ERROR("%s()!\n", __func__); \
	panic(); \
} while (0)

#define BUG_ON(condition) do { if (unlikely(condition)) BUG(); } while (0)

#define WARN_ON(condition) ({						\
	int __ret_warn_on = !!(condition);				\
	if (unlikely(__ret_warn_on))					\
		WARN("WARNING at %s:%d/%s()!\n", __FILE__, __LINE__, __func__); \
	unlikely(__ret_warn_on);					\
})

#define WARN_ON_ONCE(condition)	({				\
	static bool __warned;					\
	int __ret_warn_once = !!(condition);			\
								\
	if (unlikely(__ret_warn_once && !__warned)) {		\
		__warned = true;				\
		WARN_ON(1);					\
	}							\
	unlikely(__ret_warn_once);				\
})

#define WARN_ONCE(condition, format...) ({          \
	static bool __warned;     \
	int __ret_warn_once = !!(condition);            \
								\
	if (unlikely(__ret_warn_once && !__warned)) {       \
		__warned = true;                \
		WARN(format);                \
	}                           \
	unlikely(__ret_warn_once);              \
})

#endif	/* _LINUX_BUG_H */
