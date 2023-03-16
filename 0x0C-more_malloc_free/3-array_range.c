#include <stdlib.h>
#include <stdio.h>
/**
 * array_range - returns an array contining the values of the range from "min" to "max", both inclusive.
 * @min: an integer argument.
 * @max: an integer argument.
 * Return: "NULL" if malloc fails or min is greater than max else return a pointer to the dynamically created array of integers.
 */

int *array_range(int min, int max)
{
	int *range;
	int size, i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	range = malloc(size * sizeof(*range));

	if (!range)
		return (NULL);

	for (i = 0; i < size; i++)
		range[i] = min++;

	return (range);
}
