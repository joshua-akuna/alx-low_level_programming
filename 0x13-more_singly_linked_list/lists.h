#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list.
 * @n: an integer.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int _putchar(int);
size_t print_listint(const listint_t *h);

#endif /* _LISTS_H_ */
