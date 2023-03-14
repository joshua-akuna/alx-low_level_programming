#include <stdlib.h>
/**
 * fill_row - creates a 1-D array of size "width".
 * @row: a 1-D array
 * @width: an int argument for size of the array.
 */
void fill_row(int *row, int width)
{
	int i;

	for (i = 0; i < width; i++)
		*(row + i) = 0;
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

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		*(grid + i) = malloc(sizeof(int) * width);
		if (*(grid + i) == NULL)
		{
			for ( ; i >= 0; i--)
				free(*(grid + i));
			free(grid);
			return (NULL);
		}
		fill_row(*(grid + i), width);
	}

	return (grid);
}
