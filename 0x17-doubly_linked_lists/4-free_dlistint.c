#include "lists.h"

/**
 * free_dlistint - frees up the dynamic memory of the
 *	nodes of a doubly linked list.
 * @head: a pointer to a node of a doubly linked list.
 * Return: Nothing.
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	free_dlistint(head->next);
	free(head);
}
