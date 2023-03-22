#include "calc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * get_op_func - selects the correct function to
 * perform the operation asked by the user.
 * @s: the operator argument used to select the operation to perform.
 * Return: resturns a pointer to te function that correspons to the
 * operator given as a paramter.
 */

int (*get_op_func(char *s))(int a, int b)
{
	int i;

	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	i = 0;

	while (ops[i].op)
	{
		if (strcmp(ops[i].op, s) == 0)
		{
			printf("%s = {%s}\n", ops[i].op, s);
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
