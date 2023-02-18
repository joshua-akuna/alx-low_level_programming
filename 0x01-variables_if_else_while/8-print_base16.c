#include <stdio.h>

/**
 * main - The entry point for the program
 *
 * Description: 'Printsall the numbers of base16 in lower case
 * followed by a new line using the putchar function only.'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	/*Declare int variables for the ASCII codes of all hex numbers*/
	int _0 = 48;
	int _9 = 57;
	int a = 97;
	int f = 102;

	while (_0 <= _9)
	{
		putchar(_0);
		_0++;
	}

	while (a <= f)
	{
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
