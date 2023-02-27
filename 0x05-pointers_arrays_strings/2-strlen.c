#include <string.h>

/**
 * _strlen - returns the length of a string.
 * @s: pointer to a string.
 * Return: length of the string.
 */

int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}
