#include "sort.h"

/**
 * swap - swap 2 elements of a doubly linked list
 * @list: the list
 * @left: the left element
 * @right: the right element
 * Return: void
*/
void swap(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev == NULL)
		*list = right;

	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;

	left->next = right->next;
	right->next = left;
	left->prev = right;
}


/**
 * insertion_sort_list - implement insertion sort in a DLL
 * @list: Pointer to the head of the list
 * Return: none
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *curr;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		temp = curr;
		curr = curr->next;

		if (temp->prev->n > temp->n)
		{
			while (temp->prev && temp->prev->n > temp->n)
			{
				swap(list, temp->prev, temp);
				print_list(*list);
			}
		}
	}
}
