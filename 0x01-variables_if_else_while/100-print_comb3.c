#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Desription: 'prints all possible combinations of two digits'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	int unit, tens;

	for (tens = 48; tens < 57; tens++)
	{
		for (unit = tens + 1; unit <= 57; unit++)
		{
			putchar(tens);
			putchar(unit);

			if (tens == 57 - 1 && unit == 57)
				break;

			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
