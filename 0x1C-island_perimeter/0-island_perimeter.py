#!/usr/bin/python3
"""island perimeter module"""


def island_perimeter(grid):
    """island perimeter"""

    result = 0
    x = len(grid)
    y = len(grid[0])

    for i in range(x):
        for j in range(y):
            if(grid[i][j] == 1):
                if(i == 0 or grid[i-1][j] == 0):
                    result = result + 1
                if(i == x-1 or grid[i+1][j] == 0):
                    result = result + 1
                if(j == 0 or grid[i][j-1] == 0):
                    result = result + 1
                if(j == y-1 or grid[i][j+1] == 0):
                    result = result + 1

    return result
