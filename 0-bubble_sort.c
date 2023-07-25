#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order, using the
 * Bubble sort algorithm
 *
 * @array: The array that will be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapper;
	size_t x, n, new_n;

	if ((size < 2) || (array == NULL))
		return;

	n = size;

	for (; n > 0; n = new_n)
	{
		new_n = 0;
		for (x = 0; x < n - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swapper = array[x];
				array[x] = array[x + 1];
				array[x + 1] = swapper;
				new_n = x + 1;
				print_array(array, size);
			}
		}

		if (new_n == 0)
			break;
	}
}

