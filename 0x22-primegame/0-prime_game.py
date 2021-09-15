#!/usr/bin/python3
"""prime game"""


def isWinner(x, nums):
    """is winner"""
    one = 0
    two = 0
    if nums and x > 0:
        for i in nums:
            if (i > 0):
                if (i % 2 == 0):
                    one += 1
                else:
                    two += 1
        if one >= two:
            return "Maria"
        else:
            return "Ben"
    else:
        return None
