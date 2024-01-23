#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	qsort_recursive(array, 0, size - 1, size);
}

/**
 * qsort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 * @size: The size of the array
 */
void qsort_recursive(int *array, int start, int end, size_t size)
{
	int p;

	if (start < end)
	{
		p = lomuto_partition(array, start, end, size);
		qsort_recursive(array, start, p - 1, size);
		qsort_recursive(array, p + 1, end, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int p = array[end];
	int i = start - 1;
	int j, temp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= p)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != end)
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
