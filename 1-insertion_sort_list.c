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
	listint_t *sorted_list, *temp, *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	sorted_list = NULL;

	while (*list != NULL)
	{
		current = *list;
		*list = (*list)->next;

		if (sorted_list == NULL || current->n < sorted_list->n)
		{
			current->next = sorted_list;
			current->prev = NULL;
			if (sorted_list)
				sorted_list->prev = current;
			sorted_list = current;
		}
		else
		{
			temp = sorted_list;

			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->prev = temp;
			current->next = temp->next;
			if (temp->next)
				temp->next->prev = current;
			temp->next = current;
		}
	}
	*list = sorted_list;
}
