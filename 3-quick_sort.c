#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low;
int j, temp;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
i++;
}
}

if (array[i] != array[high])
{
temp = array[i];
array[i] = array[high];
array[high] = temp;
print_array(array, size);
}

return (i);
}

/**
 * quick_sort_recursive - sorts recursively using quick sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot_index;

if (low < high)
{
pivot_index = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - sorts array using quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
