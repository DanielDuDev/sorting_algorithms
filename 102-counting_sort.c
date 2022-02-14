#include "sort.h"

/**
 * counting_sort - sort an array
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *count = NULL;
	int *output = NULL;
	int i = 0, max = 0;

	if (size < 2 || array == NULL)
		return;
	/*find the largest element of the array*/
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/*create the list with lentgh max + 1*/
	count = malloc((max + 1) * sizeof(int));
	output = malloc((int)size * sizeof(int));
	if (!output)
	{
		free(output);
		free(count);
		return;
	}
	for (i = 0; i <= max; i++) /*initialize output with zeros*/
		count[i] = 0;
	for (i = 0; i < (int)size; i++) /*store the times of the each value*/
		count[array[i]] = 1;
	for (i = 1; i <= max; i++) /*store the commulative value*/
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/*Find the index of each element of the original array in count array*/
	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/*copy the sorted elements into original array*/
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}
