#include "sort.h"

/**
 * swap_list - Swaps nodes in doubly linked list.
 *
 * @node: node base to change.
 * @list: Head of the list to swap.
 */
void swap_list(listint_t **node, listint_t **list)
{
	listint_t *tmp1, *tmp2, *tmp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp1 = *node, tmp1 = tmp3 = *node, tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp3 = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp1->next)
		tmp1->next->prev = tmp1;

	*node = tmp2;

}

/**
 * cocktail_sort_list - Sorts a list using cocktail shaker algorithm.
 *
 * @list: head of list to be sortered.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c, n, m;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	c = 0, n = -1, m = -1;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
				   swap_list(&aux, list);
				   print_list(*list);
				   head = aux;
			}

			c++;
			head = head->next;
		}
		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				swap_list(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
