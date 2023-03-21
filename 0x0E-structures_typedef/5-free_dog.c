#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - frees a struct variable of type dog_t;
 * @d: s struct variable of type dog_t;
 */
void free_dog(dog_t *d)
{
	if (!d)
		return;

	if (d->name)
		free(d->name);
	if (d->owner)
		free(d->owner);
	free(d);
}
