#include "search_algos.h"

/**
 * linear_search - searches a value in an array of integers using
 *	Linear search algorithm.
 * @array: a pointer to the first element of the array to search
 * @size: the number of elements in the array argument
 * @value: the value to search for in the array
 * Return: the index of the value in the array if found
 *	If value is not present in the array, return -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	(void)value;
	if (array == NULL)
		return (-1);
	while (i < size)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}

	return (-1);
}
