#include "search_algos.h"

size_t min_value(int num1, int num2);
int recursive_binary_search(int *array, size_t low, size_t high, int value);
void print_array(int *array, size_t low, size_t high);

/**
 * exponential_search - searches for a value in a sorted array of
 *	integers using the Exponential search
 * @array: a pointer to the first element of the @array to search in
 * @size: number of elements in @array
 * @value: value to search for
 * Return: the first index where value is located
 *	else -1 if array is NULL or value is not present in @array
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, upper_bound;

	if (array == NULL || size == 0)
		return (-1);
	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	upper_bound = array[bound - 1] == value ? bound : bound - 1;
	printf("Value found between indexes [%ld] and [%ld]\n",
			bound / 2, upper_bound);
	return (recursive_binary_search(array, bound / 2,
			min_value(upper_bound, size - 1), value));
}

/**
 * min_value - returns the minimum of 2 number arguments.
 * @num1: the first int argument.
 * @num2: the second int argument.
 * Return: the minimum argument.
 */
size_t min_value(int num1, int num2)
{
	return (num1 > num2 ? num2 : num1);
}

/**
 * recursive_binary_search - resursively searches for a value in a
 *	sorted array of integers using the binary search algorithm.
 * @array: a pointer to the first element of the array to search in
 * @low: the first index in @array to start search.
 * @high: the last index in @array to stop search.
 * @value: the value to search for.
 * Return: the index in @array where @value is located
 *	else return -1 if @value is not found in @array
 */
int recursive_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (high >= low)
	{
		print_array(array, low, high);
		mid = low + (high - low) / 2;

		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			return (recursive_binary_search(array, low, mid - 1, value));
		if (array[mid] < value)
			return (recursive_binary_search(array, mid + 1, high, value));
	}
	return (-1);
}

/**
 * print_array - prints the contents of @array
 * @array: the array whose contents to print
 * @low: index in @array to start printing from
 * @high: index in @array to stop printing
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i = low;

	(void)array;
	printf("Searching in array: ");
	while (i <= high)
	{
		if (i != low)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}
