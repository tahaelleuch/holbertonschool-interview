#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void radix_sort(int *array, size_t size);
int cod_sort(int *array, ssize_t size, int *temp, long my_long_e);
void print_array(const int *array, size_t size);

#endif
