#include <stdio.h>

/**
 * main - The entry point for the program
 *
 * Description: 'Prints the alphabet in lower case and then upper case'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	/*Declare int variables for a, z, A, Z ASCII codes*/
	int a = 97;
	int z = 122;
	int A = 65;
	int Z = 90;

	while (a <= z)
	{
		putchar(a);
		a++;
	}

	while (A <= Z)
	{
		putchar(A);
		A++;
	}
	putchar('\n');
	return (0);
}
