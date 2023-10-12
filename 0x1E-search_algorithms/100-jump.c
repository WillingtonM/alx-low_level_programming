#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for value in array of integers
 * using the Jump search algorithm
 * @array: input array
 * @size: size of array
 * @value: value to search in
 * Return: index of number
 */
int jump_search(int *array, size_t size, int value)
{
	int indx, p, q, prv;

	if (array == NULL || size == 0)
		return (-1);

	p = (int)sqrt((double)size);
	q = 0;
	prv = indx = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", indx, array[indx]);

		if (array[indx] == value)
			return (indx);
		q++;
		prv = indx;
		indx = q * p;
	} while (indx < (int)size && array[indx] < value);

	printf("Value found between indexes [%d] and [%d]\n", prv, indx);

	for (; prv <= indx && prv < (int)size; prv++)
	{
		printf("Value checked array[%d] = [%d]\n", prv, array[prv]);
		if (array[prv] == value)
			return (prv);
	}

	return (-1);
}
