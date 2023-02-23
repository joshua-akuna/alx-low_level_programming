#include "main.h"

/**
 * print_diagonal - draws a diagonal on the terminal.
 * @n: an integer parameter.
 */

void print_diagonal(int n)
{
	int count_y, count_x;

	if (n > 0)
	{
		for (count_y = 0; count_y < n; count_y++)
		{
			for (count_x = 0; count_x <= count_y; count_x++)
			{
				if (count_x != count_y)
				{
					_putchar(' ');
					continue;
				}
				_putchar('\\');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
