#include "sort.h"

/**
 * radix_sort - function to perform radix sort
 * @array: array to sort
 *
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long my_long_e = 1;
	int *temp, min_int = INT_MIN;

	if (size < 2 || !array)
		return;

	temp = malloc(sizeof(int *) * size);
	if (!temp)
		return;

	for (i = 0; i < size; i++)
		min_int = array[i] > min_int ? array[i] : min_int;

	while (min_int / my_long_e > 0)
	{
		cod_sort(array, size, temp, my_long_e);
		print_array(array, size);
		my_long_e *= 10;
	}
	free(temp);
}

/**
 * cod_sort - sort
 * @array: array to sort
 * @size: size of the array
 * @temp: temporal array
 * @my_long_e: exp number
 *
 * Return: sorted array
 */
int cod_sort(int *array, ssize_t size, int *temp, long my_long_e)
{
	ssize_t i;
	int aux[10] = {0};

	for (i = 0; i < size; i++)
		aux[(array[i] / my_long_e) % 10]++, temp[i] = 0;

	for (i = 1; i < 10; i++)
		aux[i] += aux[i - 1];

	for (i = size - 1; i >= 0; i--)
		temp[--aux[(array[i] / my_long_e) % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	return (0);
}
