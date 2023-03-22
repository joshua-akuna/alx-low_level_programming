/**
 * int_index - searches for an integer.
 * @array: an array of integers.
 * @size: number of elements in the array.
 * @cmp: a pointer to a callback function used to compare values.
 *
 * Return: -1 if size is less than or equals 0 or no element matches,
 * else return the index of the first occurence of the element in the
 * array.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || size <= 0 || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]))
			return (i);

	return (-1);
}
