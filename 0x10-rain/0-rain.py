#!/usr/bin/python3
"""rain"""


def rain(walls):
    """
    get how much rain can hold the walls
    """
    sum_rain = 0
    for wall in walls[1:-1]:
        sum_rain = sum_rain + wall
    return sum_rain
