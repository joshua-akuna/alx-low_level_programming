#include "main.h"

/**
 * print_line - prints '_', 'n' times.
 * @n: an integer parameter.
 */

void print_line(int n)
{
	int count;

	if (n > 0)
	{
		for (count = 0; count < n; count++)
			_putchar('_');
	}
	_putchar('\n');
}
