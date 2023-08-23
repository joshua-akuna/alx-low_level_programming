#!/usr/bin/python3
"""
the module defines the island_perimeter function
"""


def island_perimeter(grid):
    """
    The function returns the perimeter of the island described in grid.
        0 represents a water zone
        1 represents a land zone
        a cell is a square od side length 1
        grid cells are connected horizontally/vertically (not diagonally)
        grid is rectangle, width and height don't exceed 100
    Grid is completely surrounded by water, and there's one island.
    The island doesn't have lakes (water inside that isn't connected
        to the water around the island).
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
