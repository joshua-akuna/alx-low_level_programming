#include "lists.h"
/**
 * sum_listint - calculates the sum of all n attribute
 * of each node in the linked list.
 * @head: a listint_t singly linked list.
 * Return: sum of all n attributes of each node of the
 * linked list. If list is empty, return 0;
 */
int sum_listint(listint_t *head)
{
	/* create a local variable to store the current sum */
	int accum = 0;
	/* return 0 is the list is NULL */
	if (!head)
		return (0);

	/* update the value of the accum variable for each node */
	do {
		accum += head->n;
		head = head->next;
	} while (head);
	/* return the result */
	return (accum);
}
