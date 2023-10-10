#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 * Return: the first index where value is located in the @array
 *	else -1 if @array is NULL or value is not found in the @array
 */

int jump_search(int *array, size_t size, int value)
{
	size_t prev, step, index;

	if (array == NULL)
		return (-1);

	prev = 0;
	step = sqrt(size);

	printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	while (array[prev] < value)
	{
		prev = step;
		step += sqrt(size);

		if (prev >= size)
			break;
		if (array[prev] < value)
			printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	}
	index = prev - (step - prev);
	printf("Value found between indexes [%ld] and [%ld]\n", index, prev);

	while (index <= prev && index < size)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		if (array[index] == value)
			return (index);
		index++;
	}

	return (-1);
}
