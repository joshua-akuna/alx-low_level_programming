#include "dog.h"
#include <stdio.h>
/**
 * print_dog - prints the attributes of a variable of type struct dog.
 * @d: a variable of type struct dog.
 */

void print_dog(struct dog *d)
{
	char *name;
	float age;
	char *owner;

	if (!d)
		return;

	name = d->name? d->name : "nil";
	age = d->age? d->age : 0;
	owner = d->owner? d->owner : "nil";

	printf("Name: %s\nAge: %f\nOwner: %s\n", name, age, owner);
}
