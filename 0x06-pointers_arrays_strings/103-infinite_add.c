/**
 * infinite_add - sum`s two integers stored as strings
 * @n1: first integer string parameter to add
 * @n2: second integer string parameter to add
 * @r: array to store the sum of n1, n2
 * @size_r: size of char array r
 *
 * Return: 0 (if size of r is insufficient) else r,
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int ten = 0, index = 0, i;
	char *_n1 = n1, *_n2 = n2;

	while (*_n1 != 0)
		_n1++;
	while (*_n2 != 0)
		_n2++;
	size_r--;
	r[size_r] = 0;
	_n1--;
	_n2--;
	while (_n2 != n2 - 1 && _n1 != n1 - 1)
	{
		r[index] = *_n2 - '0' + *_n1 + ten;
		ten = 0;
		if (r[index] > '9')
		{
			ten++;
			r[index] -= 10;
		}
		index++;
		_n2--;
		_n1--;
		if (size_r == index && (_n1 != n1 - 1 || _n2 != n2 - 1 || ten == 1))
			return (0);
	}
	while (_n1 != n1 - 1)
	{
		r[index] = *_n1 + ten;
		ten = 0;
		if (r[index] > '9')
		{
			ten = 1;
			r[index] -= 10;
		}
		_n1--;
		index++;
		if (size_r == index && (_n1 != n1 - 1 ||  ten == 1))
			return (0);
	}
	while (_n2 != n2 - 1)
	{
		r[index] = *_n2 + ten;
		ten = 0;
		if (r[index] > '9')
		{
			ten = 1;
			r[index] -= 10;
		}
		_n2--;
		index++;
		if (size_r == index && (_n2 != n2 - 1 || ten == 1))
			return (0);
	}
	if (ten == 1)
	{
		r[index] = '1';
		r[index + 1] = 0;
	}
	else
	{
		r[index--] = 0;
	}
	i = 0;
	while (i <= index)
	{
		ten = r[index];
		r[index] = r[i];
		r[i] = ten;
		index--;
		i++;
	}
	return (r);
}
