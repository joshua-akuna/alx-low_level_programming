#include "main.h"

/**
 * more_numbers - prints 0 through 14 ten times.
 */

void more_numbers(void)
{
	int count = 0, num, digit;

	while (count < 10)
	{
		for (num = 0; num <= 14; num++)
		{
			if (num > 9)
			{
				digit = (num / 10) % 10;
				_putchar(digit + '0');
			}
			digit = num % 10;
			_putchar(digit + '0');
		}
		_putchar('\n');
		count++;
	}
}
