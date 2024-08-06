#include "sort.h"

/**
 * swap_integer - Swaps two integers in an array and prints the array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */

void swap_integer(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an integer array for quick Sort
 * @array: the array to partition
 * @start: starting index of the range to be partitioned
 * @end: ending index of the range to be partitioned
 * @size: size of the array
 * Return: the final index of the pivot
 */

int partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_integer(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_integer(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * sort_recursion - recursively sorts an integer array using quick Sort
 * @array: pointer to the integer array to be sorted
 * @start: starting index of the array or partition to be sorted
 * @end: ending index of the array or partition to be sorted
 * @size: size of the array
 */

void sort_recursion(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = partition(array, size, start, end);
		sort_recursion(array, size, start, part - 1);
		sort_recursion(array, size, part + 1, end);
	}

}

/**
 * quick_sort - sorts an array of integers using the suick Sort algorithm
 * @array: the array of integers to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_recursion(array, size, 0, size - 1);
}
