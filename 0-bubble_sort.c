#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Flag to check if any swaps were made in this pass */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If the current element is greater than the next element, swap them */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Set the swapped flag to 1 */
				print_array(array, size); /* Print the array after swapping */
			}
		}
		/* If no swaps were made in this pass, the array is already sorted */
		if (swapped == 0)
		break;
	}
}
