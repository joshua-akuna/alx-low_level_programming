#include <stddef.h>
/**
 * _strpbrk - locate the first occurence in the string 's' of
 * any bytes in the string "accept"
 * @s: string to scan
 * @accept: string to find matching charater.
 * Return: a pointer to the first occurence found or "NULL" is no
 * matching character was found.
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0, j, foundMatch;

	while (s[i] != 0)
	{
		foundMatch = 0;
		j = 0;
		while (accept[j] != 0)
		{
			if (accept[j] == s[i])
			{
				foundMatch = 1;
				break;
			}
			j++;
		}
		if (foundMatch)
			return (s + i);
		i++;
	}

	return (NULL);
}
