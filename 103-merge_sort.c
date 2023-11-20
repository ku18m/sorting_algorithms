#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one line to another.
 *
 * @src: source line
 * @dst: destination line
 * @size: size of lines
 */
void copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: first set of data
 * @line: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minR: lower range of second set of data
 * @maxR: upper range of second set of data
 */
void merge(int *array, int *line, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)

		if (i <= maxL && j <= maxR)
			if (line[i] <= line[j])
				array[k] = line[i], k++, i++;
			else
				array[k] = line[j], k++, j++;

		else if (i > maxL && j <= maxR)
			array[k] = line[j], k++, j++;
		else
			array[k] = line[i], k++, i++;
}
/**
 * sub_print - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 */
void sub_print(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @line: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 */
void split(int *array, int *line, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, line, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, line, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	sub_print(array, minL, maxL);

	printf("[right]: ");

	sub_print(array, minR, maxR);
	merge(array, line, minL, maxL, minR, maxR);
	copy(array, line, size);

	printf("[Done]: ");
	sub_print(array, minL, maxR);
}
/**
 * merge_sort - Sorts an array using merge algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *line;

	if (size < 2)
		return;

	line = malloc(sizeof(int) * size);
	if (line == NULL)
		return;

	copy(array, line, size);

	split(array, line, 0, size - 1, size);

	free(line);
}
