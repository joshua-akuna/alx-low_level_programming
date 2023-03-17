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
	void *new_blk = 0;
	unsigned int i;
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

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_blk = malloc(new_size);

	if (!new_blk)
		return (NULL);
	from = ptr;
	to = new_blk;

	for (i = 0; i < new_size && i < old_size; i++)
	{
		to[i] = from[i];
	}

	free(ptr);
	return (new_blk);
}
