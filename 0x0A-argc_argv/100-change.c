#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make
 * a change for an amount of money "argv".
 * @argc: and int argument for the size of the string array "argv";
 * @argv: a string array argument.
 * Return: 1 if number of arguments is not exactly 1,
 * else 0 if program executed successfully.
 */
int main(int argc, char *argv[])
{
	int coins[] = {25, 10, 5, 2, 1};
	int amount, cents = 0, i, len = 5;

	if (argc != 2)
	{
		printf("%s\n", "Error");
		return (1);
	}

	amount = atoi(*(argv + 1));
	if (amount < 0)
	{
		printf("%d\n", 0);
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			while (amount >= coins[i])
			{
				amount -= coins[i];
				cents++;
			}
		}
		printf("%d\n", cents);
	}

	return (0);
}
