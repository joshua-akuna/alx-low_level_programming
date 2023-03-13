#include <stdlib.h>
/**
 * create_array- creates an array of chars an
 * initializes it with a specific char.
 * @size: size of the array.
 * @c : a character to initialize the array.
 * Return: Null if size equals 0 or if pointer fails
 * else pointer to the array.
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(c) * size);

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		*(array + index) = c;

	return (array);
}
