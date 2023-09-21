#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * @list: Double pointer to the head of the linked list
 *
 * return: Avoid
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			prev->next = temp->next;

			if (temp->next != NULL)
			temp->next->prev = prev;

			temp->next = prev;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;
			prev = temp->prev;
			print_list((const listint_t *)*list);
		}
		current = current->next;
	}
}
