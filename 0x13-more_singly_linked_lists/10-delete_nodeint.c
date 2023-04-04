#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list.
 * @head: a pointers to the singly linked list.
 * @index: index whose node is to be deleted.
 * Return: 1 if node was deleted, else -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node_at_index;
	listint_t *node_before_index;
	unsigned int i;

	if (!head || !(*head))
		return (-1);

	if (index == 0)
	{
		node_at_index = *head;
		*head = (*head)->next;
	}
	else
	{
		node_before_index = *head;
		while (node_before_index && i < index - 1)
		{
			i++;
			node_before_index = node_before_index->next;
		}
		node_at_index = node_before_index->next;

		/* checks if the nodes of interest are valid */
		if (node_before_index == NULL || node_at_index == NULL)
			return (-1);

		/*
		 * assign the node next to the one to be deleted as
		 * the next to the node before the one to be deleted.
		 */
		node_before_index->next = node_at_index->next;
	}
	/* delete the node at index index */
	free(node_at_index);
	node_at_index = NULL;

	return (1);
}
