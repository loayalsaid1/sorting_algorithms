#include "sort.h"

/**
 * locate_smallest - find the mallest element in a unsorted protionof an array
 * @arr: the array
 * @current_index: the index to start counting from
 * @size: the size of the array
 * Return: the index
*/
int locate_smallest(int arr[], size_t current_index, size_t size)
{
	size_t temp_index = current_index;
	size_t j;

	for (j = temp_index; j < size; j++)
	{
		if (arr[j] < arr[temp_index])
		{
			temp_index = j;
		}
	}

	return (temp_index);
}

/**
 * swap - swap 2 elemnts in an array or ints
 * @arr: the array target
 * @index_x: the index of the first elemnet
 * @index_y: hte index of the second elemnt
 * Return: void
*/
void swap(int arr[], size_t index_x, size_t index_y)
{
	int temp = arr[index_x];

	arr[index_x] = arr[index_y];
	arr[index_y] = temp;
}

/**
 * selection_sort - implement the selectoin sort algorithm
 * @array: the target array
 * @size: the size of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t temp_index;

	if (array == NULL)
		return;
	while (i < size - 1)
	{
		temp_index = locate_smallest(array, i, size);
		if (temp_index != i)
		{
			swap(array, i, temp_index);
			print_array(array, size);
		}
		i++;
	}
}
