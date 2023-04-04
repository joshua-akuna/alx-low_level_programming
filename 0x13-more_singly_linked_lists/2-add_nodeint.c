#include "lists.h"
/**
 * add_nodeint - adds a listint_t struct at the beginning of
 * the singly linked list.
 * @head: a pointer to the singly linked list.
 * @n: an integer.
 * Return: address of the newly created element or NULL
 * if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = NULL;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
