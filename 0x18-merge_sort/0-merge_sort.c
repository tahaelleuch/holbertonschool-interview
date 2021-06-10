#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * printing - print left and right elements
 * @array: an array
 * @size: size of second array
 * @one: first position
 * @second: second position
 */
void printing(int *array, int size, int one, int second)
{
	int tmp;

	printf("Merging...\n");
	printf("[left]: ");
	tmp = one;
	while (tmp < second)
	{
		if (tmp != second - 1)
			printf("%d, ", array[tmp]);
		else
			printf("%d\n", array[tmp]);
		tmp++;
	}

	printf("[right]: ");
	tmp = second;
	while (tmp < size)
	{
		if (tmp < size - 1)
			printf("%d, ", array[tmp]);
		else
			printf("%d\n", array[tmp]);
		tmp++;
	}
}

/**
 * merge - merge the value
 * @array: the array
 * @size: size of second array
 * @the_copy: the copy of array
 * @first: first position
 * @scnd: second position
 */
void merge(int *array, int size, int first, int scnd, int *the_copy)
{
	int i, tmp, two;

	printing(array, size, first, scnd);

	i = first;
	tmp = scnd;

	printf("[Done]: ");
	two = first;
	while (two < size)
	{
		if (i < scnd && (tmp >= size || array[i] <= array[tmp]))
		{
			the_copy[two] = array[i];
			i++;
		}
		else
		{
			the_copy[two] = array[tmp];
			tmp++;
		}
		if (two < size - 1)
			printf("%d, ", the_copy[two]);
		else
			printf("%d\n", the_copy[two]);
		two++;
	}
}
/**
 * merging - array separator
 * @the_copy: copy of array
 * @first: initial position
 * @size: size of the original  array
 * @array: the original array
 */
void merging(int *the_copy, int first, int size, int *array)
{
	int scnd;

	if (size - first < 2)
		return;

	scnd = (size + first) / 2;

	merging(array, first, scnd, the_copy);
	merging(array, scnd, size, the_copy);

	merge(the_copy, size, first, scnd, array);
}
/**
 * make_copy - copy array of int
 * @arr: array src
 * @the_copy: array dest
 * @size : array size
 */
void make_copy(int *arr, int *the_copy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		the_copy[i] = arr[i];
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array
 * @size : array size
 */
void merge_sort(int *array, size_t size)
{
	int *the_copy;

	the_copy = malloc(sizeof(int) * size - 1);

	if (the_copy == NULL)
		return;

	make_copy(array, the_copy, size);

	merging(the_copy, 0, size, array);
	free(the_copy);
}
