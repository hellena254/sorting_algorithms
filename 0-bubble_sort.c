#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using
 *               the Bubble sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap = 1;
				print_array(array, size);
			}
		}

		/* If no two elements were swapped by inner loop, the array is sorted */
		if (swap == 0)
			break;
	}
}
