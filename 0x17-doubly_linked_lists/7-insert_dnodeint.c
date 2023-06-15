#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a specified
 *	index in a doubly linked list.
 * @h: a pointer to a doubly linked list of type dlistint_t.
 * @idx: the specified index where the new node will be inserted
 *	in the doubly linked list.
 * @n: an int value to be stored in the doubly linked list.
 * Return: a pointer to the new node of type dlistint_t.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *prev = *h;

	if (h == NULL)
		return (NULL);
	/* creates a new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		if (prev != NULL)
			prev->prev = new_node;
		new_node->next = prev;
		*h = new_node;
		return (*h);
	}

	if (prev == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (prev->next != NULL && idx-- > 1)
		prev = prev->next;
	if (idx > 1)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = prev->next;
	new_node->prev = prev;
	prev->next = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	return (new_node);
}
