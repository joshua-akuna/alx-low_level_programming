#include "lists.h"
/**
 * listint_len - ruturns the number of nodes in linked list.
 * @h: a pointer to a singly linked list.
 * Return: number of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);
	return (1 + (listint_len(h->next)));
}
