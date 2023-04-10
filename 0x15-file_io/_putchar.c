#include "main.h"
/**
 * _putchar - prints a single character.
 * @c: a character.
 * Return: number of characters printed.
 */
int _putchar(int c)
{
	return (write(1, c, 1));
}
