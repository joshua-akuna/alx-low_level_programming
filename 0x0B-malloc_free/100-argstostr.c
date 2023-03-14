#include <stdlib.h>
#include <stdio.h>

/**
 * word_len - returns the length of a string.
 * @str: a char pointer to a string.
 * Return: an integer.
 */
int word_len(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + word_len(str + 1));
}

/**
 * argstostr - contatenates all the strings in an input array argument.
 * @ac: count of strings in "av".
 * @av: an array of strings.
 * Return: a pointer to a string.
 */

char *argstostr(int ac, char **av)
{
	int i, j, len = 0, sub_len = 0;
	char *str, *sub_str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		len += word_len(*(av + i)) + 1;
	len++;

	str = malloc(sizeof(char) * len);

	if (str == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		sub_str = *(av + i);
		sub_len = word_len(sub_str);

		for (j = 0; j < sub_len; j++)
		{
			str[len++] = sub_str[j];
		}

		str[len++] = '\n';
	}
	str[len++] = '\0';

	return (str);
}
