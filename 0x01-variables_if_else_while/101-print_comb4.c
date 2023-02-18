#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Desription: 'Prints all possible combinations of three digits'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	int unit, tens, hundreds;
	int end = 57;

	for (hundreds = 48; hundreds < end - 1; hundreds++)
	{
		for (tens = hundreds + 1; tens < end; tens++)
		{
			for (unit = tens + 1; unit <= end; unit++)
			{
				putchar(hundreds);
				putchar(tens);
				putchar(unit);

				if (hundreds == end - 2 && tens == end - 1 && unit == end)
					continue;

				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
