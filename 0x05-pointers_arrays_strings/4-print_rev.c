#include "main.h"
#include <string.h>

/**
 * print_rev- prints a string in reverse.
 * @s: a char pointer to a string.
 */

void print_rev(char *s)
{
	int len, i;

	len = strlen(s);

	for (i = 0; i < len; i++)
	{
		_putchar(s[len - 1 - i]);
	}
	_putchar('\n');
}
