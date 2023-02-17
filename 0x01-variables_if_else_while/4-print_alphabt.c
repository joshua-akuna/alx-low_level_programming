#include <stdio.h>

/**
 * main - The programs entry point.
 *
 * Description: 'The program prints the alphabet in lower case
 * except letters q and e'.
 *
 * Return: Always 0.(if successful).
 */

int main(void)
{
	/*Declaring an int for a and z ASCII code*/
	int a = 97;
	int z = 122;
	int e = 101;
	int q = 113;

	while (a <= z)
	{
		if (a != e && a != q)
			putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
