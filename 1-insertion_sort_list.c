#include "sort.h"

/**
 * insertion_sort_list - navigate list, find, swap at lower numbers
 * @list: list of numbers to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;
	listint_t *swap = NULL;
	listint_t *current = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	
	while (current != NULL)
	{
		tmp = current;
		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			swap = tmp->prev;
			tmp->prev = swap->prev;
			swap->next = tmp->next;
			if (swap->prev != NULL)
				swap->prev->next = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = swap;
			tmp->next = swap;
			swap->prev = tmp;
			if (current == tmp)
				current = swap;
			while ((*list)->prev != NULL)
				*list = (*list)->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
