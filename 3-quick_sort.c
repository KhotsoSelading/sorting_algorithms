#include "sort.h"

/**
 * swap_nums - Swaps two elements in an array and print the array.
 *
 * @array: The array to swap elements in.
 * @i: The index of the first element in the array to swap.
 * @j: The index of the second element in the array to swap.
 *
 * Return: Nothing
 */
void swap_nums(int *array, size_t i, size_t j)
{
	int swapper = 0;

	if (i != j)
	{
		swapper = array[i];
		array[i] = array[j];
		array[j] = swapper;
	}
}

/**
 * lomuto_partition - Perform the Lomuto partition scheme.
 *
 * @array: The array to partition.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_nums(array, i, j);
			print_array(array, high + 1);
			i++;
		}
	}

	swap_nums(array, i, high);
	print_array(array, high + 1);
	return (i);
}

/**
 * recursive_quick_sort - Recursive implementation of quicksort.
 * @array: The array to sort.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 *
 * Return: Nothing
 */
void recursive_quick_sort(int *array, int low, int high)
{
	int partition_index = 0;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high);
		recursive_quick_sort(array, low, partition_index - 1);
		recursive_quick_sort(array, partition_index + 1, high);
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

	recursive_quick_sort(array, 0, size - 1);
}
