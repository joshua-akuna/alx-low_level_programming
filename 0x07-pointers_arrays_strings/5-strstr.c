#include <stddef.h>
#include <stdio.h>

/**
 * _strstr - finds the first occurrence of the substring "needle" in
 * the string "haystack".
 * @haystack: the string to scan for the "needle" substring.
 * @needle: to substring whose index is to be identified.
 * Return: a pointer to the beginning of the identified substring,
 * or "NULL" if the sustring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j, hasFoundMatch;

	while (haystack[i] != 0)
	{
		hasFoundMatch = 1;
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] != 0)
			{
				if (needle[j] != haystack[i + j])
				{
					hasFoundMatch = 0;
					break;
				}

				if (needle[j] == 0)
					return (haystack + i);
				j++;
			}

			if (hasFoundMatch)
			{
				return (haystack + i);
			}
		}

		i++;
	}

	return (NULL);
}
