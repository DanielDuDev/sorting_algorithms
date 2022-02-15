#include "sort.h"

/**
 * merge - recursion method
 *
 * @array: array to sorted
 * @size: size of the array
 * @start: initial value
 * @div: middle value
 *
 * Return: Nothing
 */
void merge(int *array, int start, int div, int size)
{
	int i = 0, j = 0, k = 0, d = 0, n1 = div - start + 1, n2 = size - div;
	int *arrLeft = NULL, *arrRight = NULL, *done = NULL;

	printf("Merging...\n");
	arrLeft = malloc(n1 * sizeof(int));
	arrRight = malloc(n2 * sizeof(int));
	done = malloc((n2 + n1) * sizeof(int));
	if (!arrLeft || !arrRight || !done)
	{
		free(arrLeft), free(arrRight), free(done);
		return;
	}
	for (i = 0, j = 0; i < n1 || j < n2; i++, j++)
	{
		arrLeft[i] = array[start + i];
		arrRight[j] = array[div + j + 1];
	}
	printf("[left]: "), print_array(arrLeft, n1);
	printf("[right]: "), print_array(arrRight, n2);
	i = 0, j = 0, k = start;
	while (i < n1 && j < n2)
	{
		if (arrLeft[i] < arrRight[j])
			array[k] = arrLeft[i], i++;
		else
			array[k] = arrRight[j], j++;
		done[d] = array[k], k++, d++;
	}
	while (i < n1)
	{
		array[k] = arrLeft[i], done[d] = array[k], i++, k++, d++;
	}
	while (j < n2)
	{
		array[k] = arrRight[j], done[d] = array[k];
		j++, k++, d++;
	}
	printf("[Done]: "), print_array(done, n1 + n2);
	free(arrLeft), free(arrRight), free(done);
}
/**
 * recursion_sort - recursion method
 *
 * @array: array to sorted
 * @size: size of the array
 * @start: initial value
 *
 * Return: Nothing
 */
void recursion_sort(int *array, int start, int size)
{
	int div = 0;

	if (start >= size)
		return;
	if ((size + start) % 2 != 0)
		div = (size + start) / 2;
	else
		div = (size + start - 1) / 2;
	recursion_sort(array, start, div);
	recursion_sort(array, div + 1, size);
	merge(array, start, div, size);
}

/**
 * merge_sort - mergesort algorihtnm
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	recursion_sort(array, 0, size - 1);
}
