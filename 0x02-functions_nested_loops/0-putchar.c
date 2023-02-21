#include "main.h"

/**
 * main - the entry point of the program.
 * Description: 'calls the custom function _putchar to print the string
 * "_putchar"'
 * Return: return (0) always if success.
 */

int main(void)
{
	char *ptr = "_putchar";

	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	_putchar('\n');
	return (0);
}
