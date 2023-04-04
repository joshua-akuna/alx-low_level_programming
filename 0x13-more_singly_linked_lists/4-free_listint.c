#include "lists.h"
/**
 * free_listint - frees a listint_t singly linked list.
 * @head: pointer to a singly linked list.
 * Return: nothing.
 */
void free_listint(listint_t *head)
{
	/* the recursive function base case */
	if (!head)
		return;
	/* passes the next node to the recursive function */
	free_listint(head->next);
	/* frees the nodes when the base case is satisfied */
	free(head);
}
