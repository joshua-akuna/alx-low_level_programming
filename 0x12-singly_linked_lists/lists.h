#ifndef _LISTS_H_
#define _LISTS_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct list_s - singly linked list node.
 * @str: string - (malloc'ed string)
 * @len: length of the string.
 * @next: a pointer that points to the next node.
 *
 * Description: singly linked list node structure.
 */
struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
};
typedef struct list_s list_t;

int _putchar(char c);
size_t _str_len(char *str);

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void before_main() __attribute__((constructor));

#endif
