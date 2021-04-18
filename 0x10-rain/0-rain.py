#!/usr/bin/python3
"""rain"""


def rain(walls):
    """
    get how much rain can hold the walls
    """
    water = 0
    for i in range(1, len(walls) - 1):
        first = walls[i]
        for j in range(i):
            first = max(first, walls[j])
        sec = walls[i]

        for j in range(i + 1, len(walls)):
            sec = max(sec, walls[j])

        water = water + (min(first, sec) - walls[i])

    return water
