#include "sort.h"

/**
* swap_int - Swap two integers
* @a: first int
* @b: second int
*/
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme
* @array: array to sort
* @low: start index
* @high: end index (pivot)
* @size: array size (for printing)
* Return: pivot index after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);

	return (i + 1);
}

/**
* quicksort_recursive - Recursive helper
* @array: array to sort
* @low: start index
* @high: end index
* @size: array size
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array using Quick sort (Lomuto)
* @array: array to sort
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
