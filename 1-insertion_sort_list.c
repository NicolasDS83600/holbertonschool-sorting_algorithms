#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list using Insertion sort
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			insert->next = current->next;

			if (current->next)
				current->next->prev = insert;

			current->prev = insert->prev;
			current->next = insert;

			if (insert->prev)
				insert->prev->next = current;

			else
				*list = current;

			insert->prev = current;

			print_list(*list);

			insert = current->prev;
		}

		current = current->next;
	}
}
