#include "sort.h"

/**
 *  insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: pointer to a pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current;
	listint_t *prev_node;
	listint_t *next_node;

	current = (*list)->next;

	while (current != NULL)
	{
		prev_node = current->prev;
		next_node = current->next;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			/* swap the nodes */
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;

			if (next_node != NULL)
				next_node->prev = prev_node;

			current->prev = prev_node->prev;
			prev_node->next = next_node;

			current->next = prev_node;
			prev_node->prev = current;

			/* print the list */
			print_list(*list);

			prev_node = current->prev;
		}
		current = next_node;
	}
}
