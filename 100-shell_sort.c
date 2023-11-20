#include "sort.h"

/**
 * shell_sort - Sorts an array using knuth sequence algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t h, i, j;
	int tmp;

	if (size < 2)
		return;

	h = 0;
	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				tmp = array[j], array[j] = array[j - h], array[j - h] = tmp;
		h /= 3;
		print_array(array, size);
	}
}
