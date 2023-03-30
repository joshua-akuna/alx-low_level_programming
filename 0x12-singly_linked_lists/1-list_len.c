#include "lists.h"
/**
 * list_len - calculates the number of nodes in the singly linked list.
 * @h: a pointer to the linked list.
 * Return: number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	list_t *head = NULL;
	size_t num_of_nodes = 0;

	if (!h)
		return (num_of_nodes);

	head = (list_t *) h;

	while (head)
	{
		num_of_nodes++;
		head = head->next;
	}

	return (num_of_nodes);
}
