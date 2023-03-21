#include "dog.h"
/**
 * new_dog - creates a variable of type dog_t.
 * @name: a variable of type string.
 * @age: a variable of type float;
 * @owner: a variable of type string.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	char *_name;
	char *_owner;
	dog_t my_dog;
	dog_t *dog_ptr;

	_name = name? name : "";
	_owner = owner? owner : "";

	my_dog.name = _name;
	my_dog.age = age;
	my_dog.owner = _owner;

	dog_ptr = &my_dog;

	if (!dog_ptr)
		return 0;

	return (dog_ptr);
}
