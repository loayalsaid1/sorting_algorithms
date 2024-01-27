#include "sort.h"


/**
 * insertion_sort_list - implement insertion sort in a DLL
 * @list: Pointer to the head of the list
 * Return: none
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *pre, *temp, *curr, *temp_2;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		if (curr->prev->n > curr->n)
		{
			temp = curr;
			pre = temp->prev;
			curr = curr->next;
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = pre;
			temp_2 = pre;
			while (temp_2->prev && temp_2->n <= temp->n)
				temp_2 = temp_2->prev;

			if (temp_2->prev == NULL)
			{
				temp_2->prev = temp;
				temp->next = temp_2;
				temp->prev = NULL;
				*list = temp;
				print_list(*list);
				continue;
			}
			temp->next = temp_2->next;
			temp->prev = temp_2;
			if (temp_2->next)
				temp_2->next->prev = temp;
			temp_2->next = temp;
			print_list(*list);
			continue;
		}
		curr = curr->next;
	}
}
