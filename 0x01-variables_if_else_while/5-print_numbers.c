#include <stdio.h>

/**
 * main - The programs entry point.
 *
 * Description: 'The program prints all single digits of base 10
 * from 0 followed by a new line'.
 *
 * Return: Always 0.(if successful).
 */

int main(void)
{
	/*Declaring an int for a and z ASCII code*/
	int start = 0;
	int end = 10;

	while (start < end)
	{
		printf("%d", start);
		start++;
	}
	putchar('\n');
	return (0);
}
