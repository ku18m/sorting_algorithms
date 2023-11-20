#include "sort.h"

/**
 * lomuto - Sorts an array using quick lomuto partitioning scheme.
 *
 * @array: The array to be sorted.
 * @low: The lowest idx of the array.
 * @high: The last idx of the array.
 * @size: The size of the array.
 */
void lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t i, o, tmp;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	o = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (o != i)
			{
				tmp = array[o], array[o] = array[i], array[i] = tmp;
				print_array(array, size);
			}
			o++;
		}
	}
	if (o != high)
	{
		tmp = array[o], array[o] = array[high], array[high] = tmp;
		print_array(array, size);
	}
	if (o - low > 1)
		lomuto(array, low, o - 1, size);
	if (high - o > 1)
		lomuto(array, o + 1, high, size);
}


/**
 * quick_sort - Sorts an array using quick lomuto partitioning scheme.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 0)
		lomuto(array, 0, size - 1, size);
}
