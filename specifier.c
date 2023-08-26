#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void print_int(int n)
{
	char buffer[20];

	char *p = buffer + 19;

	*p = '\0';

	int abs_n = abs(n);

	while (abs_n > 0 && p > buffer)
	{
		p--;

		*p = '0' + (abs_n % 10);

		abs_n /= 10;
	}

	if (n < 0)
	{
		p--;
		*p = '-';
	}

	puts(p);
}
