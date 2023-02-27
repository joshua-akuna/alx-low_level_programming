#include "main.h"
#include <string.h>

/**
 * puts_half - prints the second half of a string.
 * @str: a char pointer pointing to a string.
 */

void puts_half(char *str)
{
	unsigned int i, len, half_len, temp;

	len = strlen(str);
	half_len = len / 2;
	if (len % 2 == 1)
		half_len++;

	for (i = half_len; i < len; i++)
	{
		temp = str[i] - '0';
		_putchar(temp + '0');
	}
	_putchar('\n');
}
