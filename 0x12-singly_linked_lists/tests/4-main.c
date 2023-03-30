#include "../lists.h"
/**
 * main - test code for 4-free_list.c file.
 * Return: Always 0.
 */
int main(void)
{
	list_t *head;

	head = NULL;
	add_node_end(&head, "Bob");
	add_node_end(&head, "&");
	add_node_end(&head, "Kris");
	add_node_end(&head, "love");
	add_node_end(&head, "asm");

	print_list(head);
	free_list(head);
	head = NULL;

	return (0);
}
