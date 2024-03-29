#include "lists.h"
/**
 * insert_nodeint_at_index - insert a new node at a given index.
 * @head: a pointer to a singly linked list of type listint_t.
 * @idx: index of the list where the new node should be inserted.
 * idx starts at 0.
 * @n: an int for the n attribute of the new node.
 * Return: pointer to the inserted node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = NULL;
	listint_t *prev_node = NULL;
	unsigned int index = 0;

	if (head == NULL)
		return (NULL);

	/* creates a new node */
	new_node = malloc(sizeof(listint_t));
	/* returns NULL if malloc fails */
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/* finds the node at idx - 1 */
	prev_node = *head;
	while (prev_node != NULL && index < idx - 1)
	{
		index++;
		prev_node = prev_node->next;
	}
	/* checks if the node before the node at position idx is valid */
	if (prev_node == NULL)
		return (NULL);
	/* assign the next node to prev_node as the next to the new_node.*/
	new_node->next = prev_node->next;
	/* assign the new_node as next to the current_node */
	prev_node->next = new_node;
	return (new_node);
}
