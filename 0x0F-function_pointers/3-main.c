#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - calculates a mathematical operation.
 * @argc: number of string elements in the argv array.
 * @argv: an array of strings.
 *
 * Return: 0 if executed successfully.
 */

int main(int argc, char *argv[])
{
	int a, b;
	int (*func_ptr)(int, int) = NULL;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	func_ptr = get_op_func(argv[2]);

	if (!func_ptr)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", func_ptr(a, b));
	return (0);
}
