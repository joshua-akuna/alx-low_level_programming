#include "search_algos.h"
#include <math.h>

size_t min_value(int num1, int num2);

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
	size_t end_step, start_step;

	if (array == NULL)
		return (-1);

	start_step = 0;
	end_step = sqrt(size);

	printf("Value checked array[%ld] = [%d]\n", start_step, array[start_step]);
	while (array[min_value(end_step, size) - 1] < value)
	{
		start_step = end_step;
		end_step += sqrt(size);

		/* if (start_step >= size) return (-1); */
		printf("Value checked array[%ld] = [%d]\n", start_step, array[start_step]);
		if (array[end_step] >= value || end_step >= size)
			break;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", start_step, end_step);

	while (array[start_step] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", start_step, array[start_step]);
		start_step++;
		/* if (start_step == min_value(end_step, size)) return (-1); */
		if (start_step == min_value(end_step, size))
			break;
	}

	if (array[start_step] == value)
	{
		printf("Value checked array[%ld] = [%d]\n", start_step, array[start_step]);
		return (start_step);
	}

	return (-1);
}

/**
 * min_value - calculates the minimum of 2 numbers
 * @num1: the first number
 * @num2: the second number
 * Return: the minimum of @num1 and @num2
 */
size_t min_value(int num1, int num2)
{
	return (num1 > num2 ? num2 : num1);
}
