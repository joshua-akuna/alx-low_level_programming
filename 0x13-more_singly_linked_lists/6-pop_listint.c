#include "lists.h"
/**
 * pop_listint - deletes the head node of a listint_t singly
 * linked list.
 * @head: pointer to a singly linked list.
 * Return: the value of the n attribute of the head node.
 */
int pop_listint(listint_t **head)
{
	/*
	 * create an int and a pointer to store the current head
	 * and its attribute n
	 */
	int value = 0;
	listint_t *popped_node = NULL;
	/* returns NULL if the pointer to the list is NULL */
	if (!head)
		return (0);
	/*
	 * assign the pointer of the current head to the pointer of the
	 * popped_head and assign the next node in the list as
	 * the new head
	 */
	popped_node = *head;
	*head = (*head)->next;
	/* gets the value of the n attribute of the popped node */
	value = popped_node->n;
	/* free the popped node and assign it a value of NULL */
	free(popped_node);
	popped_node = NULL;
	/* return value */
	return (value);
}
