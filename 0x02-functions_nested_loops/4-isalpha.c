#include "main.h"

/**
 * _isalpha - checks if the argument is an alphabet.
 * @c: an int parameter.
 * Return: returns (1) if param c is an alphabet else 0.
 */

int _isalpha(int c)
{
	int a, z, A, Z;

	a = 'a';
	z = 'z';
	A = 'A';
	Z = 'Z';

	if ((c >= a && c <= z) || (c >= A && c <= Z))
		return (1);
	return (0);
}
