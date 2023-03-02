#include "main.h"

/**
 * print_number - prints an int parameter.
 * @n: and int parameter.
 */

void print_number(int n)
{
	unsigned int temp;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	temp = n;
	temp /= 10;

	if (temp)
	{
		print_number(temp);
	}
	_putchar((n % 10) + '0');
}
