#include <stdio.h>

/**
 * main - entry point.
 *
 * Return: return 0 always.
 */

int main(void)
{
	long int fib, cur, prev, count;

	fib = 0;
	cur = 1;
	prev = 0;

	for (count = 50; count > 0; count--)
	{
		fib = cur + prev;
		prev = cur;
		cur = fib;

		printf("%ld", fib);

		if (count == 1)
			break;

		printf(", ");
	}
	putchar('\n');

	return (0);
}
