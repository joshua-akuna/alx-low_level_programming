#include <stdio.h>

/**
 * _strcat - concatenates two strings.
 * @dest: char pointer to a string.
 * @src: char pointer to a string.
 * Return: dest always.
 */

char *_strcat(char *dest, char *src)
{
	unsigned int len, i;

	len = 0;

	for (i = 0; dest[i] != '\0'; i++)
		len++;

	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];

	return (dest);
}
