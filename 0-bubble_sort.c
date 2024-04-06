#include "sort.h"

/**
 * bubble_sort - navigate list, swapping at higher numbers
 * @array: list of numbers to sort
 * @size: number of entries in array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i;
	bool is_sorted = false;

	while (is_sorted == false)
	{
		for (i = 0; i < (size - 1); i++)
		{
			is_sorted = true;
			if (array[i] > array[i + 1])
			{
				is_sorted = false;
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
