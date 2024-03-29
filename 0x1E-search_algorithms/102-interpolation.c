#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 *	using the Interpolation search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 * Return: the first index in @array where @value is located
 *	else -1 if @array is NULL or @value is not present in the @array
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low, pos, high;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	pos = low + (((double)(high - low) / (array[high] - array[low]))
			* (value - array[low]));
	if (pos >= size)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	while ((array[low] != array[high]) && (value >= array[low]
				&& (value <= array[high])))
	{
		pos = low + (((double)(high - low) / (array[high] - array[low]))
				* (value - array[low]));
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low = pos + 1;
		else if (array[pos] > value)
			high = pos - 1;
		else
			return (pos);
	}
	return (-1);
}
