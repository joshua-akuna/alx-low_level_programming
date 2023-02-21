#include "main.h"

/**
 * _abs - computes the absolute value of an int.
 * @n: an int parameter
 * Return: return (abs(n)), the absolute value of parameter n.
 */

int _abs(int n)
{
	int res;

	res = n * ((n > 0) - (n < 0));

	return (res);
}
