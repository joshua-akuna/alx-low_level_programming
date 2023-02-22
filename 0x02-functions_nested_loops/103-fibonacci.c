#include <stdio.h>

/**
 * main - entry point.
 *
 * Return: return 0 always.
 */

int main(void)
{
	long int fib, cur, prev, even_sum;

	fib = 0;
	cur = 1;
	prev = 0;

	while (fib < 4000000)
	{
		fib = cur + prev;

		if (fib > 4000000)
			break;

		if (fib % 2 == 0)
			even_sum += fib;

		prev = cur;
		cur = fib;
	}
	
	printf("%ld\n", even_sum);

	return (0);
}
