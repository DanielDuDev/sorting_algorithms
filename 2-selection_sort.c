#include "sort.h"

/**
 * swap - swap the values in the array
 *
 * @x: value array[i]
 * @y: value array[i+1]
 * Return: Nothing
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sort an array
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, MinValue = 0;
	size_t j = 0;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		MinValue = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[MinValue])
			{
				MinValue = j;
			}
		}
		if (MinValue != i)
		{
			swap(&array[i], &array[MinValue]);
			print_array(array, size);
		}
	}
}
