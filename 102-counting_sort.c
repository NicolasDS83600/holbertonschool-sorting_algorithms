#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
size_t i, max = 0;
int *count, *output;

if (array == NULL || size < 2)
return;

for (i = 0; i < size; i++)
{
if ((size_t)array[i] > max)
max = array[i];
}

count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
return;

output = malloc(sizeof(int) * size);
if (output == NULL)
{
free(count);
return;
}
