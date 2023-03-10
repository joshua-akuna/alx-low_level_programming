#include <stdio.h>
#include <stdlib.h>

int isNotAPositiveInt(char *s);

/**
 * main - prints the product of the index 1 and 2 elements in "argv".
 * @argc: int argument for the size of the array "argv".
 * @argv: a string array.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, num, sum;

	if (argc == 1)
	{
		printf("%d\n", 0);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (isNotAPositiveInt(*(argv + i)))
			{
				printf("%s\n", "Error");
				return (1);
			}

			num = atoi(*(argv + i));
			sum += num;
		}
		printf("%d\n", sum);
	}
	return (0);
}

/**
 * isNotAPositiveInt - determines if the argument is a positive integer.
 * @s: a string argument.
 * Return: 1 if input is not a positive int else 0.
 */
int isNotAPositiveInt(char *s)
{
	if (*s == '\0')
		return (0);

	if ((*s < '0' || *s > '9'))
		return (1);

	return (isNotAPositiveInt(s + 1));
}
