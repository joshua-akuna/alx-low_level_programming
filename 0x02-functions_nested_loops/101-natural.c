#include <stdio.h>

/**
 * main - the entry point of the program.
 *
 * Return: return 0 always
 */

int main(void)
{
	int count, sum;

	sum = 0;

	for (count = 0; count < 1024; count++)
	{
		if (count % 3 == 0 || count % 5 == 0)
		{
			sum += count;
		}
	}

	printf("%d\n", sum);

	return (0);
}
