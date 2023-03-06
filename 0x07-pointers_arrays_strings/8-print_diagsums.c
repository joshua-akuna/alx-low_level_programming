#include <stdio.h>

/**
 * print_diagsums - prints the sum of the diagonals of a
 * square matrix of integers.
 * @a: square matrix.
 * @size: size of each sides of the square matrix.
 */

void print_diagsums(int *a, int size)
{
	int i = 0, sum_1 = 0, sum_2 = 0;
	int *ptr = a;

	for (i = 0; i < (size * size); i += size + 1)
	{
		sum_1 += *(ptr + i);
	}

	for (i = size - 1; i < size * size - 1; i += size - 1)
	{
		sum_2 += *(ptr + i);
	}

	printf("%d, %d\n", sum_1, sum_2);
}
