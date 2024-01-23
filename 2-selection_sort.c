#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending
 *		order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int temp;

	/* iterate through the array and select the min element*/
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		/* comparecurrent element to the end of the array to find the min element*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}

		if (index != i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
