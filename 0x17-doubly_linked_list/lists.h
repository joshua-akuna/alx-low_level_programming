#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listnode_s - a struct for a node in a
 *	doubly linked list.
 *
 * @n: an int stored in a doubly linked list.
 *
 * @next: a pointer to the next node of the doubly linked list.
 *
 * @prev: a pointer to the previous node of the doubly linked list.
 */
typedef struct listnode_s
{
	int n;
	struct listnode_s *next;
	struct listnode_s *prev;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);
#endif /* _LISTS_H_ */
