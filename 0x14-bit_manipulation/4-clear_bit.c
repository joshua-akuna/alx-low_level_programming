#include "main.h"
/**
 * clear_bit - set the value of a bit at a given index to 0.
 * @n: a pointer to an unsigned long int whose bit at
 * an index will be set to 0.
 * @index: the unsigned int.
 * Return: 1 if operation is successful, else -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n &= (~(1 << index));
	return (1);
}
