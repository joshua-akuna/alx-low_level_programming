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
	dlistint_t *node = *h, *new_node = NULL;
	unsigned int index = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (node != NULL)
	{
		if (idx == index)
		{
			/* creates a new node */
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			/* attaches the new node to the linked list */
			new_node->prev = node->prev;
			node->prev->next = new_node;
			node->prev = new_node;
			new_node->next = node;
			/* returns the newly created node */
			return (new_node);
		}
		else if (idx == index + 1 && node->next == NULL)
			return (add_dnodeint_end(h, n));
		/* move to the next node */
		index++;
		node = node->next;
	}
	return (NULL);
}
