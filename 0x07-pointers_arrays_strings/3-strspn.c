#include <stdio.h>
/**
 * _strspn - returns the size of bytes in the initial segment of 's'
 * which consist only of bytes from "accept".
 * @s: a pointer to a string.
 * @accept: a pointer to a substring.
 * Return: Always an int.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j, isNotFound;

	while (*(s + i) !=  0)
	{
		isNotFound = 1;
		j = 0;
		while (accept[j] != 0)
		{
			if (s[i] == accept[j])
			{
				isNotFound = 0;
				break;
			}
			j++;
		}
		if (isNotFound)
			break;
		i++;
	}

	return (i);
}
