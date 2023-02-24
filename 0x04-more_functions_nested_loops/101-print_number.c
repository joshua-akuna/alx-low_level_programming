#include "main.h"

/**
 * print_number - prints a number with _putchar only.
 * @n: an integer parameter.
 */

void print_number(int n)
{
	unsigned int temp;

	if (n < 0)
	{
		_putchar('-');
		n *= ((n > 1) - (n < 1));
	}

	temp = n;
	temp /= 10;

	if (temp != 0)
		print_number(temp);

	_putchar((n % 10) + '0');

}
