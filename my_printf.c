#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;

			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;

				case 's':
					count += puts(va_arg(args, char *));
					break;

				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					print_int(va_arg(args, int));
					count += strlen(p);
					break;

				default:
					puts("Invalid format specifier");
					return (-1);
			}
		}

		format++;
	}

	va_end(args);
	return (count);
}
