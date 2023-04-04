#include "lists.h"

void add_node(listint_t **head, listint_t *node);
/**
 * reverse_listint - reserves a listint_t singly linked list.
 * @head: pointer to the singly linked list.
 * Return: the first point to the first_node of the reversed_list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *reverse_list;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (*head);
	reverse_list = NULL;
	while (*head != NULL)
	{
		temp = (*head)->next;
		add_node(&reverse_list, *head);
		*head = temp;
	}
	*head = reverse_list;
	return (reverse_list);
}

/**
 * add_node - adds a node to the beginning of a list.
 * @head: a pointer to a singly linked list where the
 * node is to be added.
 * @node: node to add to the list.
 * Return: nothing.
 */
void add_node(listint_t **head, listint_t *node)
{
	node->next = *head;
	*head = node;
}
