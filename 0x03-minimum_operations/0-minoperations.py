#!/usr/bin/python3
"""How many operations"""


def minOperations(n):
    """how many opiration"""
    if type(n) is not int or n <= 1:
        return 0
    add = 0
    num = 2
    while n > 1:
        if n % num == 0:
            add = add + num
            n = n / num
        else:
            num = num + 1
    return add

