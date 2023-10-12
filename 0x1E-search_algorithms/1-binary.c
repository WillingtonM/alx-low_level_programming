#include "search_algos.h"

/**
 * binary_search - Searches for value in sorted array of
 *                 integers using binary search.
 * @array: Pointer to first element of array to search.
 * @size: Number of elements in array.
 * @value: Value to search for.
 * Return: If value is not present or array is NULL, -1.
 *         Otherwise, index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t z, lft, rgt;

	if (array == NULL)
		return (-1);

	for (lft = 0, rgt = size - 1; rgt >= lft;)
	{
		printf("Searching in array: ");
		for (z = lft; z < rgt; z++)
			printf("%d, ", array[z]);
		printf("%d\n", array[z]);

		z = lft + (rgt - lft) / 2;
		if (array[z] == value)
			return (z);
		if (array[z] > value)
			rgt = z - 1;
		else
			lft = z + 1;
	}

	return (-1);
}
