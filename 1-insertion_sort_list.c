#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes in a
 *	listint_t doubly-linked list
 * @h: ptr to the head of the doubly-linked list.
 * @n1: ptr to the first node to swap.
 * @n2: second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->nxt = n2->nxt;
	if (n2->nxt != NULL)
		n2->nxt->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->nxt = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->nxt = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *	using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->nxt == NULL)
		return;

	for (iter = (*list)->nxt; iter != NULL; iter = tmp)
	{
		tmp = iter->nxt;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
