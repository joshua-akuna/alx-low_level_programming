#include "lists.h"
listint_t *find_loop_start_node(listint_t *head);
/**
 * print_listint_safe - prints the n attribute of each
 * node of the linkedlist which may have a loop.
 * @head: the linkedlist.
 * Return: number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t len = 0;
	listint_t *cur_node = NULL;
	listint_t *loop_start_node = NULL;
	int loop_count = 0;

	if (head == NULL)
		exit(98);
	cur_node = (listint_t *)head;
	loop_start_node = find_loop_start_node(cur_node);

	while (cur_node != NULL)
	{
		if (loop_start_node != NULL && cur_node == loop_start_node)
			loop_count++;
		if (loop_count == LOOP_END)
			break;

		printf("[%p] %i\n", (void *)cur_node, cur_node->n);
		cur_node = cur_node->next;
		len++;
	}
	if (loop_start_node)
		printf("-> [%p] %i\n", (void *)cur_node, cur_node->n);
	return (len);
}
/**
 * find_loop_start_node - finds the node where the loop starts
 * in the singly linked list.
 * @head: a singly linked list.
 * Return: a node that starts the loop if it exist else NULL
 */
listint_t *find_loop_start_node(listint_t *head)
{
	/*
	 * initialize 2 pointers for the starting node, slow and
	 * fast moving pointer in the list.
	 */
	listint_t *slow_node = head;
	listint_t *fast_node = head;
	listint_t *start_node = head;
	/* loops through the list until a last node is reached */
	while (fast_node != NULL && fast_node->next != NULL)
	{
		/*
		 * for each iteration, move the slow_node 1 step
		 * forward and the fast_node 2 steps forward.
		 */
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;

		/*
		 * checks if the fast and slow nodes
		 * points to the same address.
		 */
		if (slow_node == fast_node)
		{
			while (start_node != slow_node)
			{
				start_node = start_node->next;
				slow_node = slow_node->next;
			}
			return (start_node);
		}
	}
	/* returns NULL if there's no loop in the list */
	return (NULL);
}
