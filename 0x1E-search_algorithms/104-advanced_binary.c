#include "search_algos.h"

/**
 * rec_search - searches for value in array of integers
 * using Binary search algorithm
 * @array: Input array
 * @size: Size of array
 * @value: Value to search in
 * Return: Index of number
 */
int rec_search(int *array, size_t size, int value)
{
	size_t z;
	size_t hlf = size / 2;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (z = 0; z < size; z++)
		printf("%s %d", (z == 0) ? ":" : ",", array[z]);

	printf("\n");

	if (hlf && size % 2 == 0)
		hlf--;

	if (value == array[hlf]) {
		if (hlf > 0)
			return (rec_search(array, hlf + 1, value));
		return ((int)hlf);
	}

	if (value < array[hlf])
		return (rec_search(array, hlf + 1, value));

	hlf++;
	return (rec_search(array + hlf, size - hlf, value) + hlf);
}

/**
 * advanced_binary - calls to rec_search to return index of number
 * @array: Input array
 * @size: Size of array
 * @value: Value to search in
 * Return: Index of number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int indx;

	indx = rec_search(array, size, value);

	if (indx >= 0 && array[indx] != value)
		return (-1);

	return (indx);
}
