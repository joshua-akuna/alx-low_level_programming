#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - a custom method that prints the alphabet in lowercase.
 * Return: return (0) always if successful.
 */

void print_alphabet(void)
{
	char start, end;

	start = 'a', end = 'z';

	while (start <= end)
	{
		_putchar(start);
		start++;
	}
	_putchar('\n');
}
