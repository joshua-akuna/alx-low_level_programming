#include <stdlib.h>
/**
 * malloc_checked - allocates memory using a malloc.
 * @b: an integer.
 * Return: pointer to the dynamically allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = NULL;

	ptr = malloc(b);
	if (ptr == NULL)
		exit (98);
	return (ptr);
}
