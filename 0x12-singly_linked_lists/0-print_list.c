#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 * @h: a linked list of list_t type nodes.
 * Return: number of nodes.
 */
size_t print_list(const list_t *h)
{
	list_t *head;
	size_t num_of_nodes = 0;
	char *str;

	if (!h)
		return (num_of_nodes);

	head = (list_t *)h;

	while (head)
	{
		str = head->str ? head->str : "(nil)";
		while (*str)
		{
			_putchar(*str);
			str++;
		}
		_putchar('\n');
		num_of_nodes++;
		head = head->next;
	}
	return (num_of_nodes);
}
