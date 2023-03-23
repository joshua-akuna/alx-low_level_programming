#include <stdio.h>
#include <stdarg.h>
/**
 * print_numbers - prints a list of numbers seperated
 * by a seperator.
 * @separator: a string printed between the numbers.
 * @n: number of variable int arguments.
 * @...: list of variable int arguments.
 * Return: nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (separator && i && i < n)
			printf("%s", separator);

		printf("%d", va_arg(args, int));

		if (i == n - 1)
			printf("\n");
	}

	va_end(args);
}
