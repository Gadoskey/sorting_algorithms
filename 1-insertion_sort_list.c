#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *key;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (i = (*list)->next; i != NULL; i = i->next)
	{
		key = i;
		j = i->prev;
		while (j != NULL && j->n > key->n)
		{
			key->prev->next = key->next;
			if (key->next != NULL)
			{
				key->next->prev = key->prev;
			}
			key->prev = j->prev;
			key->next = j;
			if (j->prev != NULL)
			{
				j->prev->next = key;
			}
			else
			{
				*list = key;
			}
			j->prev = key;
			j = j->prev;
		}
		print_list(*list);
	}
}
