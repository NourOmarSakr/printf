#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - prints an integer
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int print_int(int n)
{
	unsigned int m;
	int count = 0;

	if (n < 0)
	{
		m = -n;
		_putchar('-');
		count++;
	}
	else
	{
		m = n;
	}

	if (m / 10 != 0)
	{
		count += print_int(m / 10);
	}

	_putchar((m % 10) + '0');
	count++;

	return (count);
}
