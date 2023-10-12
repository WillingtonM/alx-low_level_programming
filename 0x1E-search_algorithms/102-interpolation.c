#include "search_algos.h"

/**
 *interpolation_search - function that searches for a value in sorted
 *array of integers
 *@array: pointer to first element of array to search in
 *@size: number of elements in array
 *@value: value to search for
 *Return: first index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t x, y, z;

	if (array == NULL)
		return (-1);

	for (y = 0, (z = size - 1); z >= y;)
	{
		x = y + (((double)(z - y) / (array[z] - array[y])) * (value - array[y]));
		if (x < size)
		{
			printf("Value checked array [%ld] = [%d]\n", x, array[x]);
		}
		else
		{
			printf("Value checked array [%ld] is out of range\n", x);
			break;
		}

		if (array[x] == value)
			return (x);
		if (array[x] > value)
			z = x - 1;
		else
			y = x + 1;
	}
	return (-1);

}
