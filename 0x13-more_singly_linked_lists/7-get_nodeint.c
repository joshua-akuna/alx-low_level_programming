#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of a linked list.
 * @head: a singly linked list.
 * @index: index of the node to return.
 * Return: node at the index of the singly linked list if found
 * else NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* initialize a local variable for the index startind at 0 */
	unsigned int i;

	i = 0;
	/* returns NULL if linked list is NULL */
	if (head == NULL)
		return (NULL);
	/*
	 * loops through each node of the list and return the node at
	 * i equals index.
	 */
	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	/* returns NULL if node at the specified index is not found */
	return (NULL);
}
