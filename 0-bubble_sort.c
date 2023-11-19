#include "sort.h"

/**
 * bubble_sort - Prints a list of integers
 *
 * @array: The array to be sorted.
 * @size: Array size.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, o;

	if (!array || size <= 0)
		return;

	o = 0;
	while (o < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i], array[i] = array[i + 1], array[i + 1] = tmp;
				print_array(array, size);
			}
			i++;
		}
		o++;
	}
}
