#include "main.h"

/**
 * get_endianness - checks for endianness.
 * Return: 0 if big endian else 1 if little endian.
 */
int get_endianness(void)
{
	int n = 1;

	return ((*(char *)&n == 1) ? 1 : 0);
}
