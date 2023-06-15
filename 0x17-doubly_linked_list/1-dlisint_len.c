#include "lists.h"

/**
 * dlistint_len - determines the number of nodes in a
 *	doubly linked list.
 *
 * @h: a node to the doubly linked list.
 *
 * Return: the size of the doubly linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	if (h == NULL)
		return (0);
	return (1 + dlistint_len(h->next));
}
