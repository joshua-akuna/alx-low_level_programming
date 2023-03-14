#include <stdlib.h>
/**
 * create_row - creates a 1-D array of size "width".
 * @width: an int argument.
 * Return: a pointer to the int array or NULL if malloc fails.
 */
int *create_row(int width)
{
	int *row, i;

	row = malloc(sizeof(width) * width);

	if (row == NULL)
		return (NULL);

	for (i = 0; i < width; i++)
		row[i] = 0;

	return (row);
}

/**
 * alloc_grid - creates a 2-D array of integers of size "width*height"
 * @width: number of columns of each row of the array in integer.
 * @height: number of rows of the array in integer.
 * Return: 0 if width of height is less than or equals 0
 * else NULL if malloc fails else pointer to the 2-D array.
 */

int **alloc_grid(int width, int height)
{
	int **grid = NULL;
	int i;

	if (width <= 0 || height <= 0)
		return (0);

	grid = malloc(sizeof(*grid) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		*(grid + i) = create_row(width);

		if (*(grid + i) == NULL)
		{
			free(grid);
			return (NULL);
		}
	}

	return (grid);
}
