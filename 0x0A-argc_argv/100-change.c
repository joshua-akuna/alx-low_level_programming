#include <stdio.h>
#include <stdlib.h>

int minNumOfCents(int amount);

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
	long int amount, cents;

	if (argc != 2)
	{
		printf("%s\n", "Error");
		return (1);
	}

	if (argc < 0)
		return (0);

	amount = atoi(*(argv + 1));
	if (amount < 0)
	{
		printf("%d\n", 0);
	}
	else
	{
		printf("%ld\n", minNumOfCents(amount));
	}

	return (0);
}

/**
 * minNumOfCents - calculate the minimum number of coins to make change
 * for an amount of money.
 * @amount: an int argument.
 * Return: minimum number of coins.
 */

int minNumOfCents(int amount)
{
	int coins[] = {25, 10, 5, 2, 1};
	long int len = 5, i, res;

	if (amount == 0)
		return (0);

	for (i = 0; i < len; i++)
	{
		if (amount >= coins[i])
		{
			res = (1 + minNumOfCents(amount - coins[i]));
			break;
		}
	}

	return (res);
}
