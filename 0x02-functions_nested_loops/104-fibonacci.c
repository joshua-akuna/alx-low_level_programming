#include <stdio.h>

/**
 * main - entry point.
 *
 * Return: return 0 always.
 */

int main(void)
{
	unsigned long fib = 0, cur = 1, prev = 0, count;
	unsigned long fib1_div1, fib1_div2, fib2_div1, fib2_div2;
	unsigned long div1, div2, divisor = 10000000000;

	for (count = 0; count < 92; count++)
	{
		fib = cur + prev;
		printf("%lu, ", fib);
		
		prev = cur;
		cur = fib;
	}
	fib1_div1 = cur / divisor;
	fib2_div1 = prev / divisor;
	fib1_div2 = cur % divisor;
	fib2_div2 = prev % divisor;

	for (count = 93; count < 99; count++)
	{
		div1 = fib1_div1 + fib2_div1;
		div2 = fib1_div2 + fib2_div2;

		if (div2 > 9999999999)
		{
			div1 += 1;
			div2 %= 10000000000;
		}
		printf("%lu%lu", div1, div2);

		if (count != 97)
			printf(", ");

		fib1_div1 = fib2_div1;
		fib1_div2 = fib2_div2;
		fib2_div1 = div1;
		fib2_div2 = div2;
	}
	putchar('\n');
	return (0);
}
