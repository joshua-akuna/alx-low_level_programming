#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted list of integers.
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: A pointer
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL, *node = NULL;

	if (list == NULL)
		return (NULL);

	node = list;

	while (node->next && node->n < value)
	{
		prev = node;
		node = node->express;
		if (node == NULL)
		{
			for (node = prev; node->next; node = node->next)
				;
			break;
		}

		printf("Value checked at index [%lu] = [%d]\n",
				node->index, node->n);
	}


	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);

	while (prev && prev->index <= node->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
