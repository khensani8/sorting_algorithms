#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 * the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	 listint_t  *current, *sorted, *temp;

	 sorted = NULL;
	 current = *list;

	while (*list)
	{
		current= *list;
		*list = (*list)->next;

        /* Check if the new element should be inserted at the beginning */
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted)

				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next && current->n > temp->next->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;
			if (temp->next)
				temp->next->prev = current;
			temp->next = current;
		}
	}
	*list = sorted; /* Update the original list pointer*/ 
}
