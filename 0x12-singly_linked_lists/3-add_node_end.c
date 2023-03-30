#include "lists.h"

/**
 * add_node_end - adds a new node at the end of the linked list.
 * @head: a pointer to a singly linked list.
 * @str: a string.
 * Return: address to the new node or NULL if unsuccessful.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	size_t len = 0;
	list_t *last_node = NULL;

	if (str && head)
	{
		new_node = malloc(sizeof(list_t));
		if (!new_node)
			return (NULL);

		while (str[len])
			len++;

		new_node->str = strdup(str);
		new_node->len = len;
		new_node->next = NULL;

		if (!*head)
			*head = new_node;
		else
		{
			last_node = *head;
			while (last_node->next != NULL)
				last_node = last_node->next;
			last_node->next = new_node;
		}
	}
	return (new_node);
}
