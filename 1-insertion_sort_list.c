#include "sort.h"

/**
 * size_list - count the size of the linked list
 *
 * @list: double linked list
 * Return: size
 */
int size_list(listint_t *list)
{
	int i = 0;

	if (list)
	{
		while (list)
		{
			list = list->next;
			i++;
		}
	}
	return (i);
}

/**
 * insertion_sort_list - sort with insertion method
 *
 * @list: double linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *phead = NULL;

	if (*list != NULL && (*list)->next != NULL && list != NULL)
	{
		current = (*list)->next;
		while (current != NULL)
		{
			phead = current->next;
			while (current->prev != NULL && current->n < current->prev->n)
			{
				if (current->next != NULL)
				{
					current->next->prev = current->prev;
				}
				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->next->prev;
				current->next->prev = current;
				if (current->prev != NULL)
				{
					current->prev->next = current;
				}
				else
				{
					*list = current;
				}
				print_list(*list);
			}
			current = phead;
		}
	}
}
