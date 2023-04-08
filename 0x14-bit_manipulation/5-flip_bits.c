#include "main.h"
/**
 * flip_bits - determines the number of bits you need to flip
 * to get from number n to number m.
 * @m: an unsigned int.
 * @n: an unsigned int.
 * Return: the number of bits flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_of_bits_flipped = 0;
	unsigned long int diff_btw_nums;

	diff_btw_nums = n ^ m;

	while (diff_btw_nums)
	{
		num_of_bits_flipped += (diff_btw_nums & 1);
		diff_btw_nums >>= 1;
	}

	return (num_of_bits_flipped);
}
