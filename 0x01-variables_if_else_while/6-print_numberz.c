#include <stdio.h>

/**
 * main - The programs entry point.
 *
 * Description: 'The program prints all single digits of base 10
 * from 0 followed by a new line using putchar function only'.
 *
 * Return: Always 0.(if successful).
 */

int main(void)
{
	/*Declaring an int for a and z ASCII code*/
	int start = 48;
	int end = 57;

	while (start <= end)
	{
		putchar(start);
		start++;
	}
	putchar('\n');
	return (0);
}
