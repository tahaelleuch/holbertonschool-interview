#!/usr/bin/python3
"""reads stdin line by line and computes metrics"""

import sys

try:
    i = 0
    code_dict = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    fileSize = 0
    for line in sys.stdin:
        token = line.split()
        if len(token) >= 2:
            if token[-2] in code_dict.keys():
                code_dict[token[-2]] += 1
            fileSize += int(token[-1])
            i += 1
            if not i % 10:
                print("File size: {:d}".format(fileSize))
                for key in sorted(code_dict.keys()):
                    if code_dict[key] != 0:
                        print("{}: {:d}".format(key, code_dict[key]))
    print("File size: {:d}".format(fileSize))
    for key in sorted(code_dict.keys()):
        if code_dict[key] != 0:
            print("{}: {:d}".format(key, code_dict[key]))
except KeyboardInterrupt:
    print("File size: {:d}".format(fileSize))
    for key in sorted(code_dict.keys()):
        if code_dict[key] != 0:
            print("{}: {:d}".format(key, code_dict[key]))
    raise
