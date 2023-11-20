#include "sort.h"

/**
 * counting_sort - Sorts an array using counting algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 **/
void counting_sort(int *array, size_t size)
{
	int n, j, *count_array, *tmp;
	size_t i;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	}
	count_array = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, n + 1);
	tmp = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		tmp[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	free(tmp);
	free(count_array);
}
