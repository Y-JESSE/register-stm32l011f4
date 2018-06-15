#ifndef __JESSE_INIT_H__
#define __JESSE_INIT_H__

#include <stdarg.h>
#include "stm32l0xx.h"

typedef int (*_fn_init)(void);
#define SECTION(x)			 						__attribute__((section(x)))


#define _INIT_EXPORT(fn, level)			const _fn_init __init_##fn SECTION(".jesse_fn."level) = fn

#define JESSE_INIT_BOARD(fn)					_INIT_EXPORT(fn, "1")
#define JESSE_INIT_DEVICE(fn)					_INIT_EXPORT(fn, "2")
#define JESSE_INIT_COMPONENT(fn)			_INIT_EXPORT(fn, "3")

#endif /* __JESSE_INIT_H__ */
