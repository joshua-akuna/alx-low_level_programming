#include "lists.h"

/**
 * find_listint_loop - finds a loop in a listint_t linked list
 * and returns the pointer to the node where the loop starts.
 *
 * @head: head of the listint_t singly linked list.
 *
 * Return: pointer to the node where the loop starts if it
 * exists, else NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_node = NULL;
	listint_t *fast_node = NULL;

	slow_node = head;
	fast_node = head;

	while (fast_node != NULL && fast_node->next != NULL)
	{
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;

		if (slow_node == fast_node)
		{
			fast_node = head;
			while (slow_node != fast_node)
			{
				slow_node = slow_node->next;
				fast_node = fast_node->next;
			}
			return (fast_node);
		}
	}
	return (NULL);
}
