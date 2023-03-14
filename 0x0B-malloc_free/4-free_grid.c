#include <stdlib.h>
/**
 * free_grid - frees the dynamically allocated memory of a 2-D grid.
 * @grid: pointer to a 2-D grid.
 * @height: number of rows in the 2-D grid.
 * Return: Nothing.
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(*(grid + i));

	free(grid);

}
