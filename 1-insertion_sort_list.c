#include "sort.h"

/**
 * insertion_sort_list - sorts list in ascending order, using
 * Insertion sort algorithm.
 *
 * @list: a doubly linked list of integers that will be sorted
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *swapper;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		swapper = current;

		while (swapper->prev != NULL && swapper->n < swapper->prev->n)
		{
			swapper->prev->next = swapper->next;
			if (swapper->next != NULL)
				swapper->next->prev = swapper->prev;

			swapper->next = swapper->prev;
			swapper->prev = swapper->prev->prev;

			if (swapper->prev != NULL)
				swapper->prev->next = swapper;

			if (swapper->next != NULL)
				swapper->next->prev = swapper;

			if (swapper->prev == NULL)
				*list = swapper;

			print_list(*list);
		}
	}
}
