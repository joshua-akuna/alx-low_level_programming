#include "lists.h"

/**
 * print_dlistint - prints the content of a doubly
 *	linked list.
 *
 * @h: a node of the doubly linked list.
 *
 * Return: the size of the doubly linked list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	if (h == NULL)
		return (0);
	printf("%i\n", h->n);
	return (1 + print_dlistint(h->next));
}
