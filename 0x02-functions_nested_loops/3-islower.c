#include "main.h"

/**
 * _islower - the functions determines if c parameter is a
 * lowercase alphabet or not.
 * @c: an int argument to be checked.
 * Return: returns (0) if its a lowercase alphabet, else return (1)
 */
int _islower(int c)
{
	int a, z;

	a = 'a';
	z = 'z';

	if (c >= a && c <= z)
		return (1);
	return (0);
}
