#include "sort.h"

/**
 * selection_sort - finds the min number, swaps at beginning
 * @array: list of numbers to sort
 * @size: number of entries in array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, min_index;
	bool swap_made;

	for (i = 0; i < (size - 1); i++)
	{
		swap_made = false;
		min_index = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				swap_made = true;
				min_index = j;
			}
		}
		tmp = array[i];
		array[i] = array[min_index];
		array[min_index] = tmp;
		if (swap_made == true)
			print_array(array, size);
	}
}
