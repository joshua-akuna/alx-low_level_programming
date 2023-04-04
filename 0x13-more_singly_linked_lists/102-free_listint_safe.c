#include "lists.h"

listint_t *get_loop_start_node(listint_t *head);
void detach_loop(listint_t *head);
/**
 * free_listint_safe - frees the node of a singly linked
 * list with without loop.
 * @h: a pointer to the linked list.
 * Return: size of the list freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *loop_start_node = NULL;
	listint_t *temp = NULL;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (count);

	loop_start_node = get_loop_start_node(*h);
	while (loop_start_node)
	{
		detach_loop(*h);
		loop_start_node = get_loop_start_node(*h);
	}
	while (*h != NULL)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		count++;
	}
	h = NULL;
	return (count);
}
/**
 * get_loop_start_node - determines the start node of a loop
 * in a listint_t singly linked list.
 * @head: a listint_t singly linked list.
 * Return: pointer to the node which starts the loop.
 */
listint_t *get_loop_start_node(listint_t *head)
{
	listint_t *slow_node = head;
	listint_t *fast_node = head;
	listint_t *loop_start_node = head;

	while (fast_node != NULL && fast_node->next != NULL)
	{
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;

		if (fast_node == slow_node)
		{
			while (loop_start_node != slow_node)
			{
				loop_start_node = loop_start_node->next;
				slow_node = slow_node->next;
			}
			return (loop_start_node);
		}
	}
	return (NULL);
}
/**
 * detach_loop - detaches a loop in a listint_t singly linked
 * list if it exists.
 * @head: a listint_t singly linked list.
 * Return: nothing.
 */
void detach_loop(listint_t *head)
{
	listint_t *slow_node = head;
	listint_t *fast_node = head;
	listint_t *loop_start_node = head;
	listint_t *last_node = NULL;

	while (fast_node != NULL && fast_node->next != NULL)
	{
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;

		if (fast_node == slow_node)
			break;
	}

	if (fast_node == NULL || fast_node->next == NULL)
		return;

	while (loop_start_node != slow_node)
	{
		slow_node = slow_node->next;
		loop_start_node = loop_start_node->next;
	}
	last_node = slow_node;
	while (last_node->next != slow_node)
		last_node = last_node->next;

	last_node->next = NULL;
}
