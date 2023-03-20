#include "dog.h"
/**
 * init_dog - initializes a variable of type struct dog.
 * @d: a variable of type struct dog to be initialized.
 * @name: a variable of type string.
 * @age: a variable of type float.
 * @owner: a variable of type string.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
