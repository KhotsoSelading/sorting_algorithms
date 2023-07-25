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
	int Swapper, interval, i, j;

	if (array == NULL || size < 2)
		return;

	interval = 1;
	while (interval < (int)size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			Swapper = array[i];
			j = i;
			while (j >= interval && array[j - interval] > Swapper)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = Swapper;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
