#include <stdio.h>

/**
 * main - entry point.
 * Return: always 0.
 */

int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 3 == 0 && num % 5 == 0)
		{
			printf("Fizz Buzz ");
			continue;
		}

		if (num % 3 == 0)
		{
			printf("Fizz ");
			continue;
		}
		
		if (num % 5 == 0)
		{
			printf("Buzz ");
			continue;
		}

		printf("%d ", num);
	}

	return (0);
}
