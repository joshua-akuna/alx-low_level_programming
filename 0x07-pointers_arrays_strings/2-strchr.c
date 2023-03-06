#include <stddef.h>
/**
 * _strchr - returns a pointer to the first occurence of the character 'c'
 * in the string 's', or NULL if the character is not foound.
 * @s: pointer to a string to be scanned.
 * @c: character to scan for
 * Return: a pointer to the first occurrence of the character 'c'
 * or "NULL" if 'c' is not found.
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (s[i] != 0)
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	
	if (s[i] == c)
		return (s + i);

	return (NULL);
}
