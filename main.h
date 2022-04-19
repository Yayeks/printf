#ifndef _MAIN_
#define _MAIN_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
 * struct op - flag / function object
 * @c: flag
 * @f: function
 */
typedef struct op
{
	char *c;
	int (*f)(va_list);
} op_t;

#endif
