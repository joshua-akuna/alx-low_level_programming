#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "variadic_functions.h"

/**
 * print_int - prints an integer.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_int(va_list args)
{
	int num = va_arg(args, int);

	printf("%d", num);
}

/**
 * print_char - prints an character.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_char(va_list args)
{
	int c = va_arg(args, int);

	printf("%c", c);
}

/**
 * print_double - prints an double.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_double(va_list args)
{
	double num = va_arg(args, double);

	printf("%f", num);
}

/**
 * print_str - prints an string.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
	{
		printf("nil");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - the function prints anything.
 * @format: a string that defines the format of the element to print.
 * @...: an iterable of elements to print.
 * Return: nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i, j, len;
	fmt fmts[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_double},
		{'s', print_str},
		{'\0', NULL}
	};

	if (!format)
		return;

	va_start(args, format);
	len = strlen(format);

	i = 0;
	while (format[i])
	{
		j = 0;
		while (fmts[j].val)
		{
			if (format[i] == fmts[j].val)
			{
				if (i && i < len)
					printf(", ");
				fmts[j].f(args);
				break;
			}
			j++;
		}
		i++;
	}
	putchar('\n');

	va_end(args);
}
