#!/usr/bin/python3
"""making changes"""


def makeChange(coins, total):
    """makechange function"""

    if total <= 0:
        return 0

    coins.sort()
    reversed_coin = coins[::-1]

    number = 0
    for c in reversed_coin:
        number += total // c
        total = total % c

    if total != 0:
        return -1

    return number
