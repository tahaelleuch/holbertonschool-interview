#!/usr/bin/python3
"""rotate matrix"""


def rotate_2d_matrix(matrix):
    """rotate it"""
    new_matrix = []
    n = len(matrix)
    new_matrix = list(map(list, matrix))

    for i in range(n):
        for j in range(n):
            matrix[i][j] = new_matrix[n - j - 1][i]
