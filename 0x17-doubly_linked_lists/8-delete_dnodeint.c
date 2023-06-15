#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at the specified
 *	index in the doubly linked list.
 * @head: a pointer to a doubly linked list
 * @index: the index of the node in the doubly linked list to delete.
 * Return: 1 if successful else -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node = *head, *node_to_delete;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(node);
		return (1);
	}
	while (node->next != NULL && index-- > 1)
		node = node->next;

	if (index > 1 || node->next == NULL)
		return (-1);

	node_to_delete = node->next;
	node->next = node_to_delete->next;
	if (node->next != NULL)
		node->next->prev = node;
	free(node_to_delete);
	return (1);
}
