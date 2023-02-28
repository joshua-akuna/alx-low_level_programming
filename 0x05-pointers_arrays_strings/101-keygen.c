#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main- generates random valid passwords for the program 101-crackme.
 * Return: always 0.
 */

int main(void)
{
	char pwd[84];
	int i = 0, sum = 0;
	int num1, num2;

	srand(time(0));

	while (sum < 2772)
	{
		pwd[i] = 33 + rand() % 94;
		sum += pwd[i++];
	}

	pwd[i] = '\0';

	if (sum != 2772)
	{
		num1 = (sum - 2772) / 2;
		num2 = (sum - 2772) / 2;

		if ((sum - 2772) % 2 != 0)
			num1++;

		for (i = 0; pwd[i]; i++)
		{
			if (pwd[i] >= (33 + num1))
			{
				pwd[i] -= num1;
				break;
			}
		}


		for (i = 0; pwd[i]; i++)
		{
			if (pwd[i] >= (33 + num2))
			{
				pwd[i] -= num2;
				break;
			}
		}
	}

	printf("%s\n", pwd);

	return (0);
}
