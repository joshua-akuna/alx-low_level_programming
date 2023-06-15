#include "lists.h"

/**
 * sum_dlistint - sums up the n property of the nodes
 *	of the doubly linked list.
 * @head: a pointer to the node of the doubly linked list.
 * Return: the accumulation of the n property of each node.
 */
int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);
	return (head->n + sum_dlistint(head->next));
}
