#include "main.h"

/**
 * print_times_table - prints the "param n" times table starting at 0.
 *
 * @n: an integer parameter
 */

void print_times_table(int n)
{
	int row, mul, res;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		_putchar('0');

		for (mul = 1; mul <= n; mul++)
		{
			_putchar(',');
			_putchar(' ');

			res = row * mul;

			if (res >= 100)
			{
				_putchar((res / 100) + '0');
				_putchar(((res / 10) % 10) + '0');
			}
			else
			{
				_putchar(' ');

				if (res >= 10)
					_putchar(((res / 10) % 10) + '0');
				else
					_putchar(' ');
			}

			_putchar((res % 10) + '0');
		}
		_putchar('\n');
	}
}
