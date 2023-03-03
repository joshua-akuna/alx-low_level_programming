/**
 * move_pointer- moves the pointer to the last index of the string.
 * @str: a string parameter.
 * Return: Always str;
 */
char *move_pointer(char *str)
{
	while (*str != 0)
		str++;
	str--;

	return (str);
}

/**
 * handle_overflow- handles the last digit.
 * @overflow: the number of tens carried over.
 * @index: an integer parameter.
 * @str: pointer to the string of digits
 */
void handle_overflow(char *str, int overflow, int index)
{
	if (overflow == 1)
	{
		str[index] = '1';
		str[index + 1] = 0;
	}
	else
	{
		str[index--] = 0;
	}
}

/**
 * reverse_string - reverses a string.
 * @n: an integer parameter.
 * @str: a string parameter.
 */
void reverse_string(char *str, int n)
{
	int index = n, i = 0, temp;

	while (index >= i)
	{
		temp = str[index];
		str[index] = str[i];
		str[i] = temp;
		index--;
		i++;
	}
}

/**
 * check_overflow- checks if a summation is greater than 10;
 * @res: the result buffer.
 * @str: the string to add.
 * @overflow: the number of tens carried over.
 * @index: an integer parameter.
 * Return: 1, if sum is greater than 10 else 0.
 */
int check_overflow(char *res, char *str, int overflow, int index)
{
	res[index] = *str + overflow;
	overflow = 0;
	if (res[index] > '9')
	{
		overflow = 1;
		res[index] -= 10;
	}

	return (overflow);
}

/**
 * infinite_add - adds 2 nummbers.
 * @n1: pointer to a string of digits.
 * @n2: pointer to a string of digits.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size to store the result.
 * Return: Always r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, index = 0;
	char *_n1 = n1, *_n2 = n2;

	_n1 = move_pointer(_n1);
	_n2 = move_pointer(_n2);
	r[--size_r] = 0;
	while (_n2 != n2 - 1 && _n1 != n1 - 1)
	{
		r[index] = *_n2 - '0' + *_n1 + overflow;
		overflow = 0;
		if (r[index] > '9')
		{
			overflow++;
			r[index] -= 10;
		}
		index++;
		_n2--;
		_n1--;
		if (size_r == index && (_n1 != n1 - 1 || _n2 != n2 - 1 || overflow == 1))
			return (0);
	}
	while (_n1 != n1 - 1)
	{
		overflow = check_overflow(r, _n1, overflow, index);
		_n1--;
		index++;
		if (size_r == index && (_n1 != n1 - 1 || overflow == 1))
			return (0);
	}
	while (_n2 != n2 - 1)
	{
		overflow = check_overflow(r, _n2, overflow, index);
		_n2--;
		index++;
		if (size_r == index && (_n2 != n2 - 1 || overflow == 1))
			return (0);
	}
	handle_overflow(r, overflow, index);
	reverse_string(r, index);
	return (r);
}
