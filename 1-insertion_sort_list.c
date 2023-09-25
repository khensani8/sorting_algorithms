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

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *prev = current->prev;
		listint_t *next = current->next;
		
		while (prev && prev->n > current->n)
		{
			/* Swap the nodes */
			if (next)
				next->prev = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->next = next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			print_list(*list); /* Print the list after each swap */

			prev = current->prev;
		}
		current = next;
	}
}
