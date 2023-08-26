#!/usr/bin/python3
"""Defines an island perimeter measuring function."""

def island_perimeter(grid):
    """
        Return the perimiter of an island.

        Grid represents water by 0 and l and by 1.
        Args:
            grid: List of list of integers representing an island.
        Returns:
            Perimeter of island defined in grid.
    """
    size = 0
    grid_edges = 0
    grid_width = len(grid[0])
    grid_height = len(grid)

    for x in range(grid_height):
        for y in range(grid_width):
            if grid[x][y] == 1:
                size += 1
                if (y > 0 and grid[x][y - 1] == 1):
                    grid_edges += 1
                if (x > 0 and grid[x - 1][y] == 1):
                    grid_edges += 1
    return size * 4 - grid_edges * 2
