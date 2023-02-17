#include <stdio.h>

/**
 * main - The programs entry point.
 *
 * Description: 'The program prints the alphabet in lower case'.
 *
 * Return: Always 0.(if successful).
 */

int main(void)
{
	/*Declaring an int for a and z ASCII code*/
	int start;
	int end;

	start = 97;
	end = 122;

	while (start <= end)
	{
		putchar(start);
		start++;
	}
	putchar('\n');
	return (0);
}
