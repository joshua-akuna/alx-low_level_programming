#include <stdio.h>

/**
 * main - entry point.
 *
 * Return: return 0 always.
 */

int main(void)
{
	long int fib, cur, prev, count;
	long int fib1, fib2, div;

	fib = 0;
	cur = 1;
	prev = 0;
	div = 10000000000;

	for (count = 0; count < 98; count++)
	{
		fib = cur + prev;

		if (fib < 0)
		{
			fib1 = (fib / div) * ((fib > 1) - (fib < 1));
			fib2 = (fib % div) * ((fib > 1) - (fib < 1));
			printf("%ld%ld", fib1, fib2);
		}
		else
		{
			printf("%ld", fib);
		}

		if (count == 97)
			break;

		printf(", ");

		prev = cur;
		cur = fib;
	}

	putchar('\n');

	return (0);
}
