#include "main.h"
/**
 * flip-bits - calculates the number of bits to flip
 *	to get from one number to another.
 * @n: first integer argument.
 * @m: second integer argument.
 * Return: the numbers of bits to flip to get from
 *	param n to param m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int diff, count = 0;

	diff = n ^ m;
	while (diff > 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
