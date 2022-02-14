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
 * partition - part in two the array
 *
 * @array: array
 * @left: point to start
 * @p: pivot
 * @size: size of the array
 * Return: Nothing
 */
int partition(int *array, int left, int p, int size)
{
	int i = left;
	int j = p - 1;
	int pivot = array[p];

	while (i < j)
	{
		while (i < pivot && array[i] < pivot)
			i++;
		while (j > i && array[j] >= pivot)
			j--;
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[p]);
		print_array(array, size);
	}

	return (i);
}
/**
 * QuickSort - sort an array
 *
 * @array: array to sorted
 * @left: point to initialize
 * @p: pivot
 * @size: size of the array
 *
 * Return: Nothing
 */
void QuickSort(int *array, int left, int p, int size)
{
	int pos = 0;

	if (left < p)
	{
		pos = partition(array, left, p, size);
		QuickSort(array, left, pos - 1, size);
		QuickSort(array, pos + 1, p, size);
	}
}
/**
 * quick_sort - sort an array
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	QuickSort(array, 0, (unsigned int)size - 1, (unsigned int)size);
}
