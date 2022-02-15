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
 * heapify - recursion function
 *
 * @arr: array
 * @n: position
 * @i: index
 * @size: size of array
 *
 * Return: Nothing
 */
void heapify(int arr[], int n, int i, int size)
{
	/*Find largest among root, left child and right child*/
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	/*Swap and continue heapifying if root is not largest*/
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, largest, size);
	}
}

/**
 * heap_sort - sort an array
 *
 * @array: array to sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i = 0;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, (int)size, i, size);

	/*Heap sort*/
	for (i = (int)size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);

		/*Heapify root element to get highest element at root again*/
		heapify(array, i, 0, size);
	}
}
