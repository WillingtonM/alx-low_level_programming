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
	size_t pstn, lower, higher;
	double f_src;

	if (array == NULL)
		return (-1);

	lower = 0;
	higher = size - 1;

	while (size)
	{
		f_src = (double)(higher - lower) / (array[higher] - array[lower]) * (value - array[lower]);
		pstn = (size_t)(lower + f_src);
		printf("Value checked array[%d]", (int)pstn);

		if (pstn >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[pstn]);
		}

		if (array[pstn] == value)
			return ((int)pstn);

		if (array[pstn] < value)
			lower = pstn + 1;
		else
			higher = pstn - 1;

		if (lower == higher)
			break;
	}

	return (-1);
}
