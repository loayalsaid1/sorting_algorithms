#include "sort.h"


/**
 * insertion_sort_list - implement insertion sort in a DLL
 * @list: Pointer to the head of the list
 * Return: none
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *pre, *temp, *curr = *list;

    if (list == NULL || *list == NULL)
        return;
    if ((*list)->next == NULL)
        return;
    
    while (curr)
    {
        pre = curr->prev;
        while (pre && pre->n > pre->next->n)
        {
            temp = pre->next;
            pre->next = temp->next;
            pre->next->prev = pre;

            temp->next = pre;
            temp->prev = pre->prev;

            pre->prev->next = temp;
            pre->prev = temp;

            pre = pre->prev;
        }
        curr = curr->next;
    }
}
