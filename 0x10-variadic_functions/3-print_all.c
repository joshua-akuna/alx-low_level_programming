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
	printf("%i", va_arg(args, int));
}

/**
 * print_char - prints an character.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_char(va_list args)
{

	printf("%c", va_arg(args, int));
}

/**
 * print_double - prints an double.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_double(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_str - prints an string.
 * @args: a va_list type argument.
 * Return: nothing.
 */
void print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		printf("%s", "(nil)");
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
	int i, j;
	char *sep;
	fmt fmts[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_double},
		{'s', print_str},
		{'\0', NULL},
	};

	sep = "";
	i = 0;

	va_start(args, format);
	while (format != NULL || format[i])
	{
		j = 0;
		while (fmts[j].val)
		{
			if (format[i] == fmts[j].val)
			{
				printf("%s", sep);
				fmts[j].f(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(args);

	putchar('\n');
}
