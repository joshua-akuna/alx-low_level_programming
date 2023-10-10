#include "search_algos.h"

int recursive_binary_search(int *array, size_t low, size_t high, int value);

/**
 * advanced_binary - searches for the first occurence of a value
 *	in a sorted array of integers using the binary sort algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in @array
 * @value: the value to search for
 *
 * Return: the index of the first occurence of @value in @array
 *	else -1 if array is NULL or @value is not present in @array
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}

/**
 * recursive_binary_search - recursively searches for the first occurence
 *	of a value in a sorted array of integers using the binary
 *	sort algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @low: the index in @array to start search
 * @high: the index in @array to stop search
 * @value: the value to search for
 *
 * Return: the index of the first occurence of @value in @array
 *	else -1 if array is NULL or @value is not present in @array
 */
int recursive_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (low > high)
		return (-1);

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i != low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");

	mid = low + (high - low) / 2;
	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (recursive_binary_search(array, low, mid, value));
	}

	if (array[mid] >= value)
		return (recursive_binary_search(array, low, mid, value));
	else
		return (recursive_binary_search(array, mid + 1, high, value));
}
