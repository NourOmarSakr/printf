#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	char c;
	char *s;
	int d;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s != '\0')
					{
						_putchar(*s);
						s++;
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					count += _print_int(d);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}
