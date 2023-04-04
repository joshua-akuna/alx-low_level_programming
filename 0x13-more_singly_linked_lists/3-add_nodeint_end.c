#include "lists.h"
/**
 * add_nodeint_end - adds a node to the end of a linked list.
 * @head: pointer to a linked list.
 * @n: an integer.
 * Return: a pointer to the newly created node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/*
	 * initialize 2 pointers for the newly created node
	 * and last nodes of the singly linked list.
	 */
	listint_t *new_node = NULL;
	listint_t *last_node = NULL;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	/* returns NULL if malloc fails */
	if (!new_node)
		return (NULL);
	/* initialize the attributes of the new node */
	new_node->n = n;
	new_node->next = NULL;
	/*
	 * if the list is empty or NULL, as the new node as the head
	 * of the singly linked list, else find its last node and
	 * attach it as the next attribbute of the last node.
	 */
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;

		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}

	return (new_node);
}
