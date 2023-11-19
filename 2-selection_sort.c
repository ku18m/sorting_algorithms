#include "sort.h"

/**
 * selection_sort - Sorts an array using selection algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, o;
	int mem, mem_idx;

	if (!array || size <= 0)
		return;

	i = 0;
	while (i < size - 1)
	{
		mem = array[i];
		o = i + 1;
		while (o < size)
		{
			if (array[o] < mem)
			{
				mem = array[o];
				mem_idx = o;
			}
			o++;
		}
		if (mem != array[i])
		{
			array[mem_idx] = array[i];
			array[i] = mem;
			print_array(array, size);
		}
		i++;
	}
}
