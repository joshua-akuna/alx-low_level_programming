#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from input 'n'to 98.
 *
 * @n: the integer from which counting begins.
 *
 * Return: has no return statement.
 */

void print_to_98(int n)
{
	if (n < 98)
	{
		while (n < 98)
			printf("%d, ", n++);
	}
	else
	{
		while (n > 98)
			printf("%d, ", n--);
	}
	printf("%d\n", n);
}
