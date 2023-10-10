#include "search_algos.h"

listint_t *find_node_at_index(listint_t *list, size_t index);

/**
 * jump_list - searches for a value in a sorted list of integers
 *	using the Jump search algorithm
 * @list: a pointer to the head of the list to search in
 * @size: the number of nodes in the list
 * @value: the value to search for
 *
 * Return: a pointer to the first node where value is loacated
 *	else NULL if value is not present in head or head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t prev, step, index;
	listint_t *node = NULL;

	if (list == NULL)
		return (NULL);

	prev = 0;
	step = sqrt(size);
	node = find_node_at_index(list, prev);
	if (node == NULL)
		return (NULL);

	while (node->n < value)
	{
		prev = step;
		step += sqrt(size);

		if (prev >= size)
			break;

		node = find_node_at_index(list, prev);
		if (node == NULL)
			return (NULL);

		printf("Value checked at index [%ld] = [%d]\n",
				node->index, node->n);
	}
	index = prev - (step - prev);
	printf("Value found between indexez [%ld] and [%ld]\n",
			index, prev);

	while (index <= prev && index < size)
	{
		node = find_node_at_index(list, index);
		if (node == NULL)
			return (NULL);

		printf("Value checked at index [%ld] = [%d]\n",
				node->index, node->n);
		if (node->n == value)
			return (node);
		index++;
	}
	return (NULL);
}

/**
 * find_node_at_index - finds the node whose value of its index property
 *	equals the index argument
 * @list: the list to search in
 * @index: the index node to search for
 *
 * Return: the node whose value of index property equals the index argument
 */
listint_t *find_node_at_index(listint_t *list, size_t index)
{
	listint_t *node = list;

	while (node && node->index < index)
		node = node->next;
	return (node->index == index ? node : NULL);
}
