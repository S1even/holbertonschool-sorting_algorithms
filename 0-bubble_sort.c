#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		n--;
	} while (swapped);
}
