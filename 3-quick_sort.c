#include "sort.h"

/**
 * swap - Function that swap two integers
 * @a: The first integer variable to swap
 * @b: The second integer variable to swap
 *
 * Retrun: Avoid
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Function that partition scheme
 * @array: The array of integers that you want to partition
 * @size: The size of the array
 * @high: Indice that define the range high of element within the array
 * @low: Indice that define the range low of element within the array
 *
 * Return: the index of the pivot element final sorted position in array
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i, j, pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort - Function that sorts an array of integers in ascending order
 * @array: to print after each time swaping two elements
 * @size: size of array
 *
 * Return: Avoid
 */
void quick_sort(int *array, size_t size)
{
	int top, low, high, *stack;
	int pivot_index;

	low = 0;
	high = size - 1;

	if (size <= 1)
		return;

	stack = malloc(size * sizeof(int));
	top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];

		pivot_index = lomuto_partition(array, size, low, high);

		if (pivot_index - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot_index - 1;
		}
		if (pivot_index + 1 < high)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = high;
		}
	}
	print_array(array, size);
	free(stack);
}
