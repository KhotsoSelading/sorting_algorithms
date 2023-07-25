#include "sort.h"

/**
 * swap_nums - Swaps two elements in an array and print the array.
 *
 * @array: The array to swap elements in.
 * @i: The index of the first element in the array to swap.
 * @j: The index of the second element in the array to swap.
 * @size: The size of the array
 *
 * Return: Nothing
 */
void swap_nums(int *array, int i, int j, int size)
{
	int swapper;

	if (array[i] == array[j])
		return;

	swapper = array[i];
	array[i] = array[j];
	array[j] = swapper;
	print_array(array, size);
}

/**
 * lomuto_partition - Perform the Lomuto partition scheme.
 *
 * @array: The array to partition.
 * @start: The lower bound of the partition.
 * @end: The upper bound of the partition.
 * @size: size of the array
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int pivot = array[end], split_idx = start, j;

	for (j = start; j < end; j++)
		if (array[j] < pivot)
			swap_nums(array, split_idx++, j, size);
	swap_nums(array, split_idx, end, size);
	return (split_idx);
}

/**
 * recursive_quick_sort - Recursive implementation of quicksort.
 * @array: The array to sort.
 * @start: The lower bound of the partition.
 * @end: The upper bound of the partition.
 * @size: size of the array
 * Return: Nothing
 */
void recursive_quick_sort(int *array, int start, int end, int size)
{
	int pivot_pos = 0;

	if (start < end)
	{
		pivot_pos = lomuto_partition(array, start, end, size);
		recursive_quick_sort(array, start, pivot_pos - 1, size);
		recursive_quick_sort(array, pivot_pos + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quicksort
 *
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if ((size < 2) || (array == NULL))
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}
