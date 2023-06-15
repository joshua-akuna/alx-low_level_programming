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
	dlistint_t *prev, *next;
	unsigned int len = 0;

	if (h == NULL)
		return (NULL);
	/* attaches the new_node as the head if idx is 0 */
	if (idx == 0 || *h == NULL)
		return (add_dnodeint(h, n));
	/* else find the node at which the new node will be inserted */
	next = *h;
	while (next != NULL)
	{
		len++;
		if (len - 1 == idx)
			break;
		next = next->next;
	}
	/* if the node at idx is not NULL, break the link and insert new node */
	if (next)
	{
		/* creates a new node */
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
		{
			dprintf(2, "Can't malloc\n");
			return (NULL);
		}
		new_node->n = n;
		/* attaches the new node to the linked list */
		/* at the specified index idx */
		prev = next->prev;
		prev->next = new_node;
		new_node->prev = prev;
		next->prev = new_node;
		new_node->next = next;

		return (new_node);
	}
	else if (next == NULL && len == idx)
		return (add_dnodeint_end(h, n));
	return (NULL);
}
