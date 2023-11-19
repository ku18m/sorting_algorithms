#include "sort.h"

/**
 * insertion_sort_list - Sorts a linked list.
 *
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cursor;

	if (!list || !(*list)->next)
		return;

	cursor = *list;

	while (cursor)
	{
		while (cursor->next && cursor->n > cursor->next->n)
		{
			temp = cursor->next;
			cursor->next = temp->next;
			temp->prev = cursor->prev;
			if (cursor->prev)
				cursor->prev->next = temp;
			if (temp->next)
				temp->next->prev = cursor;
			cursor->prev = temp;
			temp->next = cursor;
			if (temp->prev)
				cursor = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		cursor = cursor->next;
	}
}
