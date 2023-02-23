#include "main.h"
#include <stdio.h>

/**
 * print_number - prints a number with _putchar only.
 * @n: an integer parameter.
 */

void print_number(int n)
{
	int div = 1;
	int temp;
	int digit;

	if (n < 0)
	{
		_putchar('-');
		n *= ((n > 1) - (n < 1));
	}

	temp = n;

	while (temp > 9)
	{
		temp /= 10;
		div *= 10;
	}

	while (div > 9)
	{
		digit = (n / div) % 10;
		_putchar(digit + '0');
		div /= 10;
	}

	digit = n % 10;
	_putchar(digit + '0');
	_putchar('\n');
}
