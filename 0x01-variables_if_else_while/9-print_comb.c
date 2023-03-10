#include <stdio.h>

/**
 * main - The entry point for the program
 *
 * Description: 'Prints all possible combinations of single-digit numbers'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	/*Declare int variables for the ASCII codes of all hex numbers*/
	int _0 = 48;
	int _9 = 57;

	while (_0 <= _9)
	{
		putchar(_0);
		if (_0 == _9)
			break;
		putchar(',');
		putchar(' ');
		_0++;
	}

	putchar('\n');

	return (0);
}
