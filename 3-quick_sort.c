#include "sort.h"

void swap(int *a, int *b);
void quick_sort_calc(int *array, int low, int high, size_t size);
int split(int *array, int low, int high, size_t size);

/**
 * quick_sort - sort array using pivot
 * @array: array of numbers to sort
 * @size: number of entries in array
 */
void quick_sort(int *array, size_t size)
{
	/* array too small to sort */
	if (size < 2)
		return;
	quick_sort_calc(array, 0, size - 1, size);
}

/**
 * swap - swaps values for two integers
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort_calc - revursive function to do actual sorting
 * @array: array to sort
 * @low: start index of array (can change with recursive step)
 * @high: end index of array (can change with recursive step)
 * @size: number of entries in array
 */
void quick_sort_calc(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = split(array, low, high, size);
		quick_sort_calc(array, low, pivot_index - 1, size);
		quick_sort_calc(array, pivot_index + 1, high, size);
	}
}

/**
 * split - separates provided values into greater/less than pivot
 * @array: array to separate
 * @low: start index of array (can change with recursive step)
 * @high: end index of array (can change with recursive step)
 * @size: number of entries in array
 *
 * Return: next position of pivot
 */
int split(int *array, int low, int high, size_t size)
{
	int pivot_val = array[high];
	int i, j;

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_val)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
