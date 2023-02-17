#include <stdio.h>

/**
 * main - The program's entry point.
 *
 * Description: 'prints a string to the standard error'
 *
 * Return: Returns 0 (if successful)
 */

int main(void)
{
	char *str = "and that piece of art is usefull\""
		"- Dora Korpar, 2015-10-19";
	fprintf(stderr, str);
	return (1);
}
