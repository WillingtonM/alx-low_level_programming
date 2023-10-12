#include "search_algos.h"

/**
 * bin_search - Searches for value in sorted array of integers using
 *                 binary search.
 * @array: Pointer to first element of array to search.
 * @left: Starting index of [sub]array to search.
 * @right: Ending index of [sub]array to search.
 * @value: Value to search for.
 * Return: If value is not present or array is NULL, -1. Otherwise,
 *        index where value is located.
 * Description: Prints [sub]array being searched after each change.
 */
int bin_search(int *array, size_t left, size_t right, int value)
{
	size_t z;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (z = left; z < right; z++)
			printf("%d, ", array[z]);
		printf("%d\n", array[z]);

		z = left + (right - left) / 2;
		if (array[z] == value)
			return (z);
		if (array[z] > value)
			right = z - 1;
		else
			left = z + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for value in sorted array of integers
 *                      using exponential search.
 * @array: Pointer to first element of array to search.
 * @size: Number of elements in array.
 * @value: Value to search for.
 * Return: If value is not present or array is NULL, -1. Otherwise,
 *         index where value is located.
 * Description: Prints value every time it is compared in array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t rght;
	size_t z = 0;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (z = 1; z < size && array[z] <= value; z = z * 2)
			printf("Value checked array[%ld] = [%d]\n", z, array[z]);
	}

	rght = z < size ? z : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", z / 2, rght);
	return (bin_search(array, z / 2, rght, value));
}
