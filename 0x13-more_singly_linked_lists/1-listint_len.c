#include "lists.h"
/**
 * listint_len - ruturns the number of nodes in linked list.
 * @h: a pointer to a singly linked list.
 * Return: number of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	/* returns the value of 0 if the node is NULL */
	if (!h)
		return (0);
	/* returns the sum of 1 and the return value of the next function */
	return (1 + (listint_len(h->next)));
}
