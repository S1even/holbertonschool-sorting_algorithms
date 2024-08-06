#include "sort.h"

/**
 * swap_integer - Swaps two integers in an array and prints the array
 * @array: pointer to the integer array
 * @i: pointer to the first integer
 * @j: pointer to the second integer
 * @size: the size of the array
 */

void swap_integer(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
		print_array(array, size);
	}
}

/**
 * partition - partitions an integer array for quick Sort
 * @array: the array to partition
 * @start: starting index of the range to be partitioned
 * @end: ending index of the range to be partitioned
 * @size: size of the array
 * Return: the final index of the pivot
 */

int partition(int *array, int start, int end, size_t size)
{
	int i, pivot = array[end];

	for (i = start; i <= end; i++)
	{
		if (array[i] < pivot)
		{
			swap_integer(array, start, i, size);
			start++;
		}
	}
	swap_integer(array, start, end, size);
	return (start);
}

/**
 * sort_recursion - recursively sorts an integer array using quick Sort
 * @array: pointer to the integer array to be sorted
 * @start: starting index of the array or partition to be sorted
 * @end: ending index of the array or partition to be sorted
 * @size: size of the array
 */

void sort_recursion(int *array, int start, int end, size_t size)
{
	int part;

	if (start >= end)
		return;


	part = partition(array, start, end, size);
	sort_recursion(array, start, part - 1, size);
	sort_recursion(array, part + 1, end, size);

}

/**
 * quick_sort - sorts an array of integers using the suick Sort algorithm
 * @array: the array of integers to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sort_recursion(array, 0, size - 1, size);
}
