#include "main.h"
/**
 * get_endianness - checks for endianness.
 * Return: 1 if "big endian" else 0 if "small endian"..
 */
int get_endianness(void)
{
	int digit = 1;
	char *ptr = (char *) &digit;

	return (*ptr == 1);
}
