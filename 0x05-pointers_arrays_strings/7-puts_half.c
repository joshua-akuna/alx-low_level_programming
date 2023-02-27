#include "main.h"
#include <string.h>

/**
 * puts_half - prints the second half of a string.
 * @str: a char pointer pointing to a string.
 */

void puts_half(char *str)
{
	unsigned int i, len, temp;

	len = strlen(str);

	for (i = len/2; i < len; i++)
	{
		temp = str[i] - '0';
		_putchar(temp + '0');
	}
	_putchar('\n');
}
