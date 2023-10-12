#include "search_algos.h"
/**
 * linear_search - searches for value in array of integers
 * using Linear search algorithm
 * @array: input array
 * @size: size of array
 * @value: value to search in
 * Return: EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int z;

	if (array == NULL)
		return (-1);

	for (z = 0; z < (int)size; z++)
	{
		printf("Value checked array[%u] = [%d]\n", z, array[z]);
		if (value == array[z])
			return (z);
	}
	return (-1);
}
