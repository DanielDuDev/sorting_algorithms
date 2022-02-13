#include "sort.h"

/**
 * size_list - count the size of the linked list
 *
 * @list - double linked list
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
 * @list: souble linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
    /*int size = 0;*/

    listint_t *h = *list, *current = NULL, *head = NULL, *phead = NULL;
    if (h && h->next)
    {
        while (h != NULL)
        {
            current = h;
            h = h->next;
            if (head == NULL || current->n < head->n)
            {
                /*insert inte the head of ther sorted list*/
                current->next = head;
                head = current;
            }
            else
            {
                phead = head;
                while (phead != NULL)
                {
                    if (phead->next == NULL || current->n < phead->next->n)
                    {
                        current->next = phead->next;
                        phead->next = current;
                        break;
                    }
                    phead = phead->next;
                }
            }
        }
    }
    *list = head;
}
