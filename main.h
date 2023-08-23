#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);

/**
 * struct spec - A structure that maps a conversion specifier to a function
 * @c: The conversion specifier
 * @f: The function pointer that prints the argument according to the specifier
 */
typedef struct spec
{
	char c;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
#endif
