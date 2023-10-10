#include "search_algos.h"

void print_array(int *array, int start, int end);

/**
 * binary_search - searches for a value in a sorted array of integers
 *	using the Binary search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in the @array.
 * @value: is the value to search for.
 * Return: the index of the array where @value is located
 *	else -1 if @value is not present in @array.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left_index, right_index, mid_index;

	if (array == NULL)
		return (-1);
	left_index = 0;
	right_index = size - 1;

	while (left_index <= right_index)
	{
		print_array(array, left_index, right_index);
		mid_index = (left_index + right_index) / 2;

		if (array[mid_index] > value)
			right_index = mid_index - 1;
		else if (array[mid_index] < value)
			left_index = mid_index + 1;
		else
			return (mid_index);
	}

	return (-1);
}

/**
 * print_array - prints the contents of @array from the @start to @end index
 * @array: the array whose content to print
 * @start: index to start printing
 * @end: index to end printing
 */
void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i && i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
