#include "lists.h"
/**
 * free_listint2 - frees a listint_t singly linked list.
 * @head: pointer to a singly linked list.
 * Return: nothing.
 */
void free_listint2(listint_t **head)
{
	/* created a temporary pointer for the next node */
	listint_t *next_node = NULL;

	/* returns NULL if pointer to the linkedlist is NULL */
	if (head == NULL)
		return;

	/* loops through the list and frees each node */
	while (*head)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}
	/* sets the pointer to the linked list to NULL */
	head = NULL;
}
