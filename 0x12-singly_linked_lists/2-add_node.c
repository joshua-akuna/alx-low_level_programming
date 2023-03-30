#include "lists.h"
/**
 * add_node - adds a new node at the beginning of the
 * singly linked list.
 * @head: a double pointer to the first node of
 * the linked list.
 * @char: a string
 * Return: a pointer to the first node of the linked list.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup((char *)str);
	new_node->len = _str_len((char *)str);
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
