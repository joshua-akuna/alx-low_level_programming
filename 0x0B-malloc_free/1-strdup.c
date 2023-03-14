#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string argument.
 * @str: a pointer to a string argument.
 * Return: NULL if str is NULL or if pointer fails
 * else pointer to the _string.
 */

char *_strdup(char *str)
{
	char *_string = NULL;
	unsigned int index = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len) != '\0')
		len++;

	_string = malloc(len + 1);

	if (_string == NULL)
		return (NULL);

	for (index = 0; *(str + index) != '\0'; index++)
		*(_string + index) = *(str + index);

	*(_string + index) = '\0';

	return (_string);
}
