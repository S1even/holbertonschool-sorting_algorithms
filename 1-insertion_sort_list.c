#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (!list || !*list)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev;

			if (temp->prev)
				temp->prev->next = current;

			if (current->next)
				current->next->prev = temp;

			current->prev = temp->prev;
			temp->next = current->next;
			current->next = temp;
			temp->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = next;
	}
}
