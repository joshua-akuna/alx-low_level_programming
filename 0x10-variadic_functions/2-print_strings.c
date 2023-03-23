#include <stdio.h>
#include <stdarg.h>
/**
 * print_strings - prints a list of strings seperated
 * by a seperator.
 * @separator: a string printed between the string arguments..
 * @n: number of variable int arguments.
 * @...: list of variable int arguments.
 * Return: nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (separator && i && i < n)
			printf("%s", separator);
		str = va_arg(args, char *);
		str = str? str : "nil";

		printf("%s", str);
	}

	va_end(args);
	putchar('\n');
}
