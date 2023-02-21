#include "main.h"

/**
 * print_alphabet_x10 - print the alphabet 10 times in lowercase
 * Return: return (0) always if successfully executed
 */

void print_alphabet_x10(void)
{
	int start, stop;
	int i;

	start = 0, stop = 10;

	while (start < stop)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		start++;
		_putchar('\n');
	}
}
