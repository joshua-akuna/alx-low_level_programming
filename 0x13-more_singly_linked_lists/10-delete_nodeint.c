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
	listint_t *prev_node;
	listint_t *node;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
	}
	else
	{
		prev_node = *head;
		while (prev_node && i < index - 1)
		{
			i++;
			prev_node = prev_node->next;
		}

		/* checks if the nodes of interest are valid */
		if (prev_node == NULL || prev_node->next == NULL)
			return (-1);

		/*
		 * assign the node next to the one to be deleted as
		 * the next to the node before the one to be deleted.
		 */
		node = prev_node->next;
		prev_node->next = prev_node->next->next;
	}
	/* delete the node at index index */
	free(node);

	return (1);
}
