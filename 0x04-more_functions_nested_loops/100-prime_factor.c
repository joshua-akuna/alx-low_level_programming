#include <stdio.h>

/**
 * main - determine the largest prime factor of a specified number.
 * Return: always 0.
 */

int main(void)
{
	long int num = 612852475143;
	int pf = 2;
	int largest = 0;

	while (num > 1)
	{
		if (num % pf == 0)
		{
			largest = pf > largest ? pf : largest;
			num /= pf;
			continue;
		}
		pf++;
	}
	printf("%d\n", largest);

	return (0);
}
