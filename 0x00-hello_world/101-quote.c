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
	char str1[] = "and that piece of art is useful\"";
	char str2[] = "- Dora Korapar, 2015-10-19\n";

	fprintf(stderr, "%s %s", str1, str2);
	return (1);
}
