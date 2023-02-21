#include "main.h"

/**
 * print_sign - print '+' for positive integers,
 * '-' for negative integers and 0 for 0.
 * @n: an int parameter.
 * Return: return (1) if the argument 'n' is positive,
 * return (0) if the argument is 0 or return (-1) if argument is negative.
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar(0);
		return (0);
	}
}
