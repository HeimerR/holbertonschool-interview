#!/usr/bin/python3
""" Island Perimeter """


def add_border(grid):
    """ add horizontal zero padding """
    last_idx = len(grid[0]) + 1
    for row in grid:
        row.insert(0, 0)
        row.insert(last_idx, 0)


def rot(grid):
    """ transpose matrix """
    grid_t = [[row[i] for row in grid] for i in range(len(grid[0]))]
    return grid_t


def count_per(grid):
    """ count the perimeter for vertical match """
    count = 0
    for row in grid:
        for i in range(len(row)):
            if row[i] == 1 and row[i-1] == 0:
                count += 1
            if row[i] == 0 and row[i-1] == 1:
                count += 1
    return count


def island_perimeter(grid):
    """  returns the perimeter of the island described in grid
         grid is rectangular, with its width and height not exceeding 100
    """
    add_border(grid)
    perimeter = count_per(grid)
    grid_t = rot(grid)
    add_border(grid_t)
    perimeter += count_per(grid_t)
    return perimeter
