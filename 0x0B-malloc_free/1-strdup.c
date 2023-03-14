#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string argument.
 * @str: a pointer to a string argument.
 * Return: NULL if str is NULL or if pointer fails
 * else pointer to the _string.
 */

char *_strdup(char *str)
{
	char *_string;
	unsigned int index = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;

	_string = malloc(sizeof(char) * len);

	if (_string == NULL)
		return (NULL);

	for (index = 0; index < len; index++)
		*(_string + index) = *(str + index);

	*(_string + index) = '\0';

	return (_string);
}
