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
		for (col = 0; col < 10; col++)
		{
			res = row * col;
			_putchar('0' + res);

			if (col == 9)
				break;

			_putchar(',');
			_putchar(' ');
		}
		_putchar('\n');
	}
}
