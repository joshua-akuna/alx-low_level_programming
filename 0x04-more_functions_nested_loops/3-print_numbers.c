#include "main.h"

/**
 * print_numbers - print the digits 0 through 9
 */

void print_numbers(void)
{
	int num1;

	num1 = '0';
	while (num1 <= '9')
		_putchar(num1++);
	_putchar('\n');
}
