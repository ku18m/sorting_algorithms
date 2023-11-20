#include "sort.h"
#include <stdio.h>
/**
 * _swap - change two values in ascending or descending order
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void _swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			_swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * helper - bitonic sort algorithm helper
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void helper(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		helper(arr, low, mid, 1, size);
		helper(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort - Sorts an array using bitonic algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	helper(array, 0, size, order, size);
}
