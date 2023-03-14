#include <stdlib.h>
/**
 * word_count - returns the number of words in a string.
 * @str: a pointer to a string argument.
 * Return: integer
 */
int word_count(char *str)
{
	char *ptr = str;

	if (*ptr == '\0')
		return (0);

	if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0'))
		return (1 + word_count(ptr + 1));
	return (word_count(ptr + 1));
}

/**
 * word_len - returns the size of a string argument.
 * @str: a pointer to a string.
 * Return: an integer.
 */
int word_len(char *str)
{
	if (*str == '\0' || *str == ' ')
		return (0);
	return (1 + word_len(str + 1));
}

/**
 * str_len - returns the size of a string argument.
 * @str: a pointer to a string.
 * Return: an integer.
 */

int str_len(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + str_len(str + 1));
}


/**
 * strtow - splits a string into words.
 * @str: a pointer to a string to split;
 * Return: NULL if str == NULL || str == "" || malloc fails
 * else an array of the substrings with the last element beint NULL.
 */

char **strtow(char *str)
{
	char **words;
	char *ptr = str;
	unsigned int size, count, len;
	unsigned int i, j = 0, k;

	if (str == NULL || word_count(ptr) == 0)
		return (NULL);

	count = word_count(ptr);
	size = sizeof(char *) * (count + 1);

	words = malloc(size);

	if (!words)
		return (NULL);
	len = str_len(str);

	for (i = 0; i < count; i++)
	{
		for ( ; j < len; j++)
		{
			if (ptr[j] == ' ')
				continue;

			size = word_len(ptr + j);
			words[i] = malloc(size + 1);

			for (k = 0; k < size; k++)
				words[i][k] = str[j + k];

			words[i][k] = '\0';
			j += k;
			break;
		}
	}
	words[i] = NULL;

	return (words);
}
