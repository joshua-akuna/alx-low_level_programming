#ifndef _DOG_H_
#define _DOG_H_

/**
 * struct dog - a struct defining a dog.
 * @name: a string attribute.
 * @age: a float attributre.
 * @owner: a string attribute.
 *
 * Description: This is a struct that defines a dog
 * with three attributes name, age and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
