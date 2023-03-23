#include <stdarg.h>
#include <stdio.h>
/**
 * sum_them_all - sum up all the arguments of the variable arguments.
 * @n: the number of variable arguments.
 * @...: variable arguments.
 *
 * Return: sum of the variable arguments.
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list args;

	if (n <= 0)
		return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	va_end(args);

	return (sum);
}
