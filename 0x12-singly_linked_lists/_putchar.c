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
