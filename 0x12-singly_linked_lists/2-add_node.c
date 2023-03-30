#include "lists.h"
/**
 * add_node - adds a new node at the beginning of the
 * singly linked list.
 * @head: a double pointer to the first node of
 * the linked list.
 * @str: a string
 * Return: a pointer to the first node of the linked list.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t len = 0;

	if (!str || !head)
		return (NULL);

	new_node = malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup((char *)str);

	while (*str)
	{
		len++;
		str++;
	}

	if (len <= 0)
		return (NULL);

	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
