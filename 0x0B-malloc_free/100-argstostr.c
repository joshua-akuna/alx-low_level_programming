#include <stdlib.h>
#include <stdio.h>
/**
 * _str_len - determines the length of a string.
 * @s: pointer to a string.
 * Return: size of string.
 */
int _str_len(char *s)
{
	int len = 0;

	if (*s == '\0')
		return (0);

	while (*(s + len))
		len++;

	return (len + 1);
}

/**
 * argstostr - contatenates all the strings in an input array argument.
 * @ac: count of strings in "av".
 * @av: an array of strings.
 * Return: a pointer to a string.
 */

char *argstostr(int ac, char **av)
{
	int i, len = 0;
	char *str, *sub_str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		len += _str_len(*(av + i));

	str = malloc(sizeof(char) * len);

	if (str == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		sub_str = *(av + i);

		while (*sub_str != '\0')
		{
			*(str + len) = *sub_str;
			sub_str++;
			len++;
		}

		if (i != ac - 1)
			*(str + len++) = '\n';
	}

	printf("%s\n", str);

	return (NULL);
}
