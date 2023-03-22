#include <stddef.h>
/**
 * array_iterator - prints each number in an int array by passing
 * each element to the action callback function.
 * @array: an int array argument.
 * @size: size of the int array.
 * @action: a pointer to a callback function that prints an integer,
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || size <= 0 || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
