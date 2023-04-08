#include "main.h"
/**
 * get_bit - returns the value of a bit at a specified index.
 * @n: an integer whose bit to return at a specified index.
 * @index: the index whose bit will be returned.
 * Return: a bit, 0 or 1.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n & (1 << index)) >> index);
}
