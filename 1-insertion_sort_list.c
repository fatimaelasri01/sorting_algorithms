#include "sort.h"

/**
 * insertion_sort_list -  function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @list: A double pointer to the first node of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = NULL, *next_node = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		tmp = current_node;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		current_node = next_node;
	}
}
