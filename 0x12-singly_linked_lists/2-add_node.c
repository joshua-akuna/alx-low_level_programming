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
	list_t *new_node = NULL;
	size_t len = 0;

	if (str && head)
	{
		new_node = malloc(sizeof(list_t));
		
		if (!new_node)
			return (NULL);

		while (str[len])
			len++;
		
		new_node->str = strdup((char *)str);
		new_node->len = len;
		new_node->next = *head;
		*head = new_node;
	}

	return (new_node);
}
