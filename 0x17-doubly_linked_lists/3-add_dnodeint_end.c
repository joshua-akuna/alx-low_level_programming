#include "lists.h"

/**
 * add_dnodeint_end - add a new end at the end of a
 *	dlistint_t doubly linked list.
 * @head: a pointer to the dlistint_t doubly linked list.
 * @n: item to be stored in the new node.
 * Return: a pointer to the new node added to the linked list.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *tail = NULL;

	if (head == NULL)
		return (new_node);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		dprintf(2, "Can't malloc\n");
		return (new_node);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head)
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
	else
		*head = new_node;
	return (new_node);
}
