#include <stdio.h>
#include <stdlib.h>
/**
 * _str_len - returns the size of a string.
 * @str: a pointer to a string.
 * Return: and int.
 */
int _str_len(char *str)
{
	int len = 0, i = 0;

	if (str == NULL)
		return (0);
	while (*(str + i))
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * str_concat - returns a pointer to a newly allocated space in
 * memory which contains the contents of s1, followed by s2,
 * and null terminated.
 * @s1: pointer to a string to concatenate.
 * @s2: pointer to a string to concatenate.
 * Return: returns a pointer to a concatenated string or "NULL"
 * on failure.
 */

char *str_concat(char *s1, char *s2)
{
	int len1, len2, i, j;
	char *str;

	printf("%s%s\n", s1, s2);

	len1 = _str_len(s1);
	len2 = _str_len(s2);

	str = malloc(sizeof(char) * (len1 + len2 + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		*(str + i) = *(s1 + i);

	for (j = 0; j < len2; j++)
	{
		*(str + i) = *(s2 + j);
		i++;
	}

	return (str);
}
