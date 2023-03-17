#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: the old memory block.
 * @old_size: size of the old memory block.
 * @new_size: size of the new memory block
 * Return: a generic pointer.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_blk;
	unsigned int i, size;
	char *from, *to;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (new_size <= 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}

	if (old_size > new_size)
		size = new_size;
	else
		size = old_size;
	new_blk = malloc(size);
	if (!new_blk)
		return (NULL);
	from = ptr;
	to = new_blk;
	for (i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
	free(ptr);
	return (new_blk);
}
