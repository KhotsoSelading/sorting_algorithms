#include "sort.h"

/**
 * swap_nums - Swaps two elements in an array and print the array.
 *
 * @array: The array to swap elements in.
 * @i: The index of the first element in the array to swap.
 * @j: The index of the second element in the array to swap.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void swap_nums(int *array, size_t i, size_t j, size_t size)
{
	int swapper;

	if (i != j)
	{
		swapper = array[i];
		array[i] = array[j];
		array[j] = swapper;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Perform the Lomuto partition scheme.
 *
 * @array: The array to partition.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 * @size: The size of the array.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_nums(array, i, j, size);
			i++;
		}
	}

	swap_nums(array, i, high, size);
	return (i);
}

/**
 * recursive_quick_sort - Recursive implementation of quicksort.
 * @array: The array to sort.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 * @size: The size of the array.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		if (partition_index != 0)
			recursive_quick_sort(array, low, partition_index - 1, size);

		recursive_quick_sort(array, partition_index + 1, high, size);
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
