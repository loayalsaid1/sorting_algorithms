#include "sort.h"

/**
 * swap - swap 2 elemnts in an array or ints
 * @arr: the array target
 * @index_x: the index of the first elemnet
 * @index_y: hte index of the second elemnt
 * Return: void
*/
void swap(int arr[], int index_x, int index_y)
{
	int temp = arr[index_x];

	arr[index_x] = arr[index_y];
	arr[index_y] = temp;
}

/**
 * bubble_sort - Implement the bubble sort algorithm on an arra
 * @array: an array of integers
 * @size: The size of the arra
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swaps;

	for (i = 0; i < size - 1; i++)
	{
		swaps = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				swaps++;
				print_array(array, size);
			}
		}
		if (swaps == 0)
			break;
	}
}
