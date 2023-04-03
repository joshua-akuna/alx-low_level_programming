#include "lists.h"
/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: a pointer to a singly linked list.
 * Return: number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);
	printf("%i\n", h->n);
	return (1 + (print_listint(h->next)));
}
