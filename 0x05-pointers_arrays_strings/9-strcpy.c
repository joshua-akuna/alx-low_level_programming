#include <string.h>

/**
 * _strcpy - copies the string pointed to by 'src',
 * including the terminating null character byte ('\0')
 * to the buffer pointed to by 'dest'.
 *
 * @dest: the array to which the contents of the 'src'
 * array is to be copied.
 *
 * @src: a char pointer pointing to a string.
 *
 * Return: the dest pointer.
 */

char * _strcpy(char *dest, char *src)
{
	size_t i;
	unsigned int n;

	n = strlen(src);
	
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	
	for (; i < n; i++)
		dest[i] = '\0';

	return dest;
}
