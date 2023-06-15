#include "lists.h"

/**
 *  * delete_dnodeint_at_index - delete dlistint node at index
 *   *
 *    * @head: head of list
 *     * @index: index of node
 *      *
 *       * Return: new node address, or NULL if index not accessible or malloc fail
 *        */
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
