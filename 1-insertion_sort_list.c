#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		temp = current->next;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
			{
				prev->prev->next = current;
			}
			if (current->next != NULL)
			{
				current->next->prev = prev;
			}
			current->prev = prev->prev;
			prev->next = current->next;
			current->next = prev;
			prev->prev = current;
			if (current->prev == NULL)
			{
				*list = current;
			}
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
