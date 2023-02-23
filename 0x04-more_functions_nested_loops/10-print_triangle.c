#include "main.h"

/**
 * print_triangle - prints a right-hand triangle of '#'.
 * @size: height/width of the triangle.
 */

void print_triangle(int size)
{
	int row, col;

	if (size < 1)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (size - col - 1 <= row)
			{
				_putchar('#');
				continue;
			}
			_putchar(' ');
		}

		_putchar('\n');
	}
}
