#include <stdlib.h>
/**
 * _calloc - allocate memory for an array of nmemb elements of "size"
 * bytes each and returns a pointer to the allocated memory.
 * @nmemb: size of array.
 * @size: size of each element in the array.
 * Return: pointer to a dynamically allocated memory space.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	int _size, i = 0;

	if (nmemb == 0)
		return (NULL);

	_size = nmemb * size + 1;
	ptr = malloc(_size);

	if (!ptr)
		return (NULL);

	for (i = 0; i < _size - 1; i++)
		ptr[i] = 0;
	ptr[i] = '\0';

	return (ptr);
}
