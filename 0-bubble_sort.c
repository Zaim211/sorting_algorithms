#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers
 * @array: the array print after each time swaping two elements
 * @size: size of array
 *
 * Return: Avoid
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
			int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
		{
			break;
		}
	}
}
