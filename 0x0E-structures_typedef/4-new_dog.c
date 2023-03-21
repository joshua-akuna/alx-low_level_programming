#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_copy - dynamically allocate a space for the string argument.
 * @str: a parameter of type string.
 * Return: pointer to the dynamically allocated space.
 */
char *malloc_copy(char *str)
{
	int i = 0, len = 0;
	char *ptr;

	while (*(str + i++))
		len++;
	ptr = malloc(len + 1);

	if (!ptr)
		return (0);

	for (i = 0; i < len; i++)
		ptr[i] = str[i];
	ptr[i] = 0;

	return (ptr);
}

/**
 * new_dog - creates a variable of type dog_t.
 * @name: a variable of type string.
 * @age: a variable of type float;
 * @owner: a variable of type string.
 * Return: a ptr to a dynamically allocated memory block for a
 * new instance of a type dog_t variable else false if function fails.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog_ptr;
	char *_name;
	char *_owner;

	if (!name || !owner)
		return (0);

	dog_ptr = malloc(sizeof(dog_t));
	if (!dog_ptr)
		return (0);

	_name = malloc_copy(name);
	if (!_name)
	{
		free(dog_ptr);
		return (0);
	}

	_owner = malloc_copy(owner);
	if (!_owner)
	{
		free(_name);
		free(dog_ptr);
		return (0);
	}

	dog_ptr->name = _name;
	dog_ptr->age = age;
	dog_ptr->owner = _owner;

	return (dog_ptr);
}
