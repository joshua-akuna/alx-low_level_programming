#include "main.h"
/**
 * set_bit - set the bit of a number at a given index to 1.
 * @n: a pointer to an unsigned long integer.
 * @index: index of the bit in the integer to switch to 1.
 * Return: 1 if operation was successful, else -1..
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n |= (1 << index);
	return (1);
}
