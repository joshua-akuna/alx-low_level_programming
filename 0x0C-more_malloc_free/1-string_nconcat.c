#include <stdlib.h>
#include <stdio.h>
/**
 * string_nconcat - retruns a pointer to a newly allocated space
 * in memory which contains s1, followed by the first n bytes of
 * s2 and null terminted.
 * @s1: a pointer to a string.
 * @s2: a pointer to a string.
 * @n: numbers of bytes of "s2" to concatenate to "s1".
 * Return: a pointer to a new dynamically allocated memory with
 * n bytes of s2 concatenated to s1.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i = 0, j = 0, size = 0, size2 = 0;

	if (!s1)
		s1 = "";

	if (!s2)
		s2 = "";

	while (*(s1 + i++))
		size++;

	i = 0;

	while (*(s2 + i++))
		size2++;

	if (n > size2++)
		n = size2;

	size += n + 1;

	str = malloc(size * sizeof(*s1));

	if (!str)
		return (NULL);

	for (i = 0; s1[i];)
		str[j++] = s1[i++];

	for (i = 0; i < n && s2[i];)
		str[j++] = s2[i++];

	str[j] = '\0';

	return (str);
}
