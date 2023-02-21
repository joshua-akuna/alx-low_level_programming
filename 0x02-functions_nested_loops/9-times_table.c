#include "main.h"

/**
 * times_table - prints the 9 time table, starting at 0.
 * Return: has no return statement.
 */

void times_table(void)
{
	int row, col, res;

	for (row = 0; row < 10; row++)
	{
		_putchar('0');

		for (col = 0; col < 10; col++)
		{
			_putchar(',');
			_putchar(' ');

			res = row * col;

			if (res <= 9)
				_putchar(' ');
			else
				_putchar((res / 10) + '0');

			_putchar((res / 10) + '0');
		}

		_putchar('\n');
	}
}
