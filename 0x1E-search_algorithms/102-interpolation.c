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
	size_t pstn, lw, hg;
	double f_src;

	if (array == NULL)
		return (-1);

	lw = 0;
	hg = size - 1;

	while (size)
	{
		f_src = (double)(hg - lw) / (array[hg] - array[lw]) * (value - array[lw]);
		pstn = (size_t)(lw + f_src);
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
			lw = pstn + 1;
		else
			hg = pstn - 1;

		if (lw == hg)
			break;
	}

	return (-1);
}
