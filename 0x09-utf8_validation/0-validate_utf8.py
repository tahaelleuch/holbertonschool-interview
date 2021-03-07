#!/usr/bin/python3
"""utf8 validation"""

def validUTF8(data):
    """utf8 validation"""
    nbr_b = 0
    srt_num = 1 << 7
    end_num = 1 << 6
    for number in data:
        num = 1 << 7
        if nbr_b == 0:
            while num & number:
                nbr_b += 1
                num = num >> 1
            if nbr_b == 0:
                continue
            if nbr_b == 1 or nbr_b > 4:
                return False
        else:
            if not (number & srt_num and not (number & end_num)):
                return False
        nbr_b -= 1
    return nbr_b == 0