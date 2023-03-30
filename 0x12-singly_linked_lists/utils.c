#include "lists.h"
/**
 * _putchar - prints a single character.
 *
 * @c: the character to be printed.
 *
 * Return: number of characters printed.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _str_len - determines the length of a string.
 * @str: a string argument.
 * Return: length of the string.
 */
size_t _str_len(char *str)
{
	size_t len = 0;

	if (!str || !str[0])
		return (len);

	while (str[len])
		len++;

	return (len);
}
