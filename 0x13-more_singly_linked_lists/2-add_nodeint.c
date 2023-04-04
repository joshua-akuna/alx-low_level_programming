#include "lists.h"
/**
 * add_nodeint - adds a node to the beginning of the listint_t list argument.
 * @head: a pointer to the singly linkedlist.
 * @n: value of the n attribute of the new node to be created.
 * Return: new node if possible, else NULL;
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* create and initialize a pointer to a listint_t structure */
	listint_t *new_node = NULL;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	/* returns NULL if malloc fails */
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* link the pointer to the current head as next node to the new_node */
	new_node->next = *head;
	/* assign the address stored in the new_node pointer to the *head node.*/
	*head = new_node;

	return (new_node);
}
