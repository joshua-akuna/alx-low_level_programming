#include "main.h"
int expon(int base, int exp);
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a string of bits.
 * Return: the converted number else 0 if the input is NULL
 * or contains a non bit.
 */
unsigned int binary_to_uint(const char *b)
{
	long int len = 0, res = 0, pos, i;

	if (b == NULL || *b == '\0')
		return (0);

	while (b[len])
		len++;

	for (i = 0; i < len; i++)
	{
		pos = len - i - 1;
		if (b[pos] != '0' && b[pos] != '1')
			return (0);
		res += (b[pos] - '0') * expon(2, i);

	}
	return (res);
}
/**
 * expon - calculates the base exponential exp.
 * @base: a number base system.
 * @exp: an integer.
 * Return: base exponential exp.
 */
int expon(int base, int exp)
{
	long int res = 1, i;

	if (exp < 0)
	{
		for (i = 0; i > exp; i--)
			res /= base;
	}
	else if (exp > 0)
	{
		for (i = 0; i < exp; i++)
			res *= base;
	}
	return (res);
}
