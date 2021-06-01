#include "sort.h"

/**
 * change - Change the two element
 * @first: the first element
 * @second: the second element
 */
void change(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * make_heap - find the lement
 * @array: array
 * @n: size
 * @idx: index
 * @size: the original size
*/
void make_heap(int *array, size_t n, int idx, size_t size)
{
	int largest = idx;
	int first = 2 * idx + 1;
	int second = 2 * idx + 2;

	if (first < (int) n && array[first] > array[largest])
		largest = first;

	if (second < (int) n && array[second] > array[largest])
		largest = second;

	if (largest != idx)
	{
		change(&array[idx], &array[largest]);
		print_array(array, size);
		make_heap(array, n, largest, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size == 0)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		make_heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		change(&array[0], &array[i]);
		print_array(array, size);
		make_heap(array, i, 0, size);
	}
}
