/**
 * infinite_add- adds 2 nummbers.
 * @n1: pointer to a string of digits.
 * @n2: pointer to a string of digits.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size to store the result.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, index, ten = 0, temp = 0;
	char *num1 = n1, *num2 = n2;

	while (*num1 != 0)
		num1++;
	while (*num2 != 0)
		num2++;
	num1--;
	num2--;
	size_r--;
	r[size_r] = 0;

	while (num1 != n1 - 1 && num2 != n2 - 1)
	{
		r[i] = *num1 - '0' + *num2 + ten;
		ten = 0;

		if (r[i] > '9')
		{
			r[i] -= 10;
			ten++;
		}
		num1--;
		num2--;
		i++;
		if (i == size_r && (ten == 1 || num1 != n1 - 1 || num2 != n2 - 1))
			return (0);
	}

	while (num1 != n1 - 1)
	{
		r[i] = *num1 + ten;
		ten = 0;

		if (r[i] > '9')
		{
			r[i] -= 10;
			ten++;
		}
		num1--;
		i++;

		if (i == size_r && (ten == 1 || num1 != n1 - 1))
			return (0);
	}

	while (num2 != n2 - 1)
	{
		r[i] = *num2 + ten;
		ten = 0;
		if (r[i] > '9')
		{
			r[i] -= 10;
			ten++;
		}
		num2--;
		i++;

		if (i == size_r && (ten == 1 || num2 != n2 - 1))
			return (0);
	}

	if (ten == 1)
	{
		r[i] = '1';
		r[i + 1] = 0;
	}
	else
	{
		r[i--] = 0;
	}

	index = 0;
	while (i >= index)
	{
		temp = r[i];
		r[i] = r[index];
		r[index] = temp;
		i--;
		index++;
	}
	return (r);
}
