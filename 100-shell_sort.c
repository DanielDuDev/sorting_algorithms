#include "sort.h"

/**
 * shell_sort - shell sort algortihnm
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t i = 0, value = 0;
	size_t j = 0;
	size_t gap = 0;

	if (size < 2)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1; /*Knuth sequence*/
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			value = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= (int)value)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
