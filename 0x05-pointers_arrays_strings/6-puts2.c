#include "main.h"
#include <string.h>

/**
 * puts2 - prints every even character of a string.
 * @str: a char pointer pointing to a string.
 */

void puts2(char *str)
{
	unsigned int temp, i, len;

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		temp = str[i] - '0';
		if (temp % 2 == 0)
			_putchar(temp + '0');
	}
	_putchar('\n');
}
