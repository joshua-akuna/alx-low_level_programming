#include "lists.h"

/**
 *
 */
size_t print_dlistint(const dlistint_t *h)
{
	if (h == NULL)
		return 0;
	printf("%i\n", h->n);
	return (1 + print_dlistint(h->next));
}
