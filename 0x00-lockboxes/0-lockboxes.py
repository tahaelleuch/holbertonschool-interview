#!/usr/bin/python3
"""Trying to open boxes"""


def canUnlockAll(boxes):
    """unlock boxes"""

    if len(boxes) == 0:
        return False
    if not isinstance(boxes, list):
        return False

    keys = [0]
    for index, box in enumerate(boxes):
        for key in box:
            if key < (len(boxes)) and key != index:
                keys.append(key)
    keys = list(dict.fromkeys(keys))
    return len(keys) == len(boxes)
