#include "lists.h"
/**
 * free_list - frees a list_t list.
 * @head: the linked list whose elements will be freed.
 * Return: nothing.
 */
void free_list(list_t *head)
{
	if (!head)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
	head = NULL;
}
