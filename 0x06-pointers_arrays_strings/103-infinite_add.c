#include <stdio.h>
/**
 * infinite_add- adds 2 nummbers.
 * @n1: pointer to a string of digits.
 * @n2: pointer to a string of digits.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size to store the result.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char *num1 = n1, *num2 = n2;
	int init = 0, final = 0, ten = 0, temp;

	while (*num1)
		num1++;
	while (*num2)
		num2++;
	num1--;
	num2--;
	r[--size_r] = 0;

	while ((num1) != n1 - 1 && (num2) != n2 - 1)
	{
		r[init] = *num1 - '0' + *num2 + ten;
		ten = 0;

		if (r[init] > '9')
		{
			r[init] -= 10;
			ten++;
		}
		num1--;
		num2--;
		init++;
		if (init == size_r && (ten == 1 || num1 != n1 - 1 || num2 != n2 - 1))
			return (0);
	}

	while (num1 != n1 - 1)
	{
		r[init] = *num1 + ten;
		ten = 0;

		if (r[init] > '9')
		{
			r[init] -= 10;
			ten++;
		}
		num1--;
		init++;

		if (init == size_r && (ten == 1 || num1 != n1 - 1))
			return (0);
	}

	while (num2 != n2 - 1)
	{
		r[init] = *num2 + ten;
		ten = 0;
		if (r[init] > '9')
		{
			r[init] -= 10;
			ten++;
		}
		num2--;
		init++;

		if (init == size_r && (ten == 1 || num2 != n2 - 1))
			return (0);
	}

	if (ten == 1)
	{
		r[init] = '1';
		r[init + 1] = 0;
	}
	else
	{
		r[init--] = 0;
	}

	while (init != final)
	{
		temp = r[init];
		r[init] = r[final];
		r[final] = temp;
		init--;
		final++;
	}
	return (r);
}
