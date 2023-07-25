#include "sort.h"

/**
 * shell_sort - Sort an array using shell_sort algorithm
 *
 * @array: The array
 * @size: The size of the array
 *
 * Return: Nothing
 **/
void shell_sort(int *array, size_t size)
{
	int Swapper, gap, i, j;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			Swapper = array[i];
			j = i;
			while (j >= gap && array[j - gap] > Swapper)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = Swapper;

			i++;
		}

		print_array(array, size);

		gap /= 3;
	}
}
