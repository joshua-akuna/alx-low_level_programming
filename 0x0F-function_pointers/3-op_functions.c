#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - calculates the sum of 2 integers.
 * @a: first integer argument.
 * @b: second integer argument.
 *
 * Return: sum of a and b.
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - calculates the difference between 2 integers.
 * @a: first integer argument.
 * @b: second integer argument.
 *
 * Return: difference of a and b.
 */

int op_sub(int a, int b)
{
	return (a - b);

}
/**
 * op_mul - calculates the product of 2 integers.
 * @a: first integer argument.
 * @b: second integer argument.
 *
 * Return: product of the a and b.
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - calculates the division of a by b..
 * @a: first integer argument.
 * @b: second integer argument.
 *
 * Return: results of the division of a by b..
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - calculates the modulus of a by b..
 * @a: first integer argument.
 * @b: second integer argument.
 *
 * Return: the modulus of a by b.
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
