/**
 * _atoi - converts a string to an integer.
 * @s: a char pointer to a string.
 * Return: an int value of 's'.
 */

int _atoi(char *s)
{
	unsigned int res, index, sign, end_of_ints;

	res = 0;
	index = 0;
	end_of_ints = 0;
	sign = 1;

	while (s[index])
	{
		if (s[index] == 45)
			sign *= -1;

		while(s[index] >= '0' && s[index] <= '9')
		{
			end_of_ints = 1;
			res = res * 10 + s[index] - '0';
			index++;
		}

		if(end_of_ints)
			break;
		index++;
	}

	return (res * sign);
}
