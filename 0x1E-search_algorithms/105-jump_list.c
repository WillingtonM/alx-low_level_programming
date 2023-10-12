#include "search_algos.h"

/**
 * jump_list - Search for algorithm in sorted singly linked list of integers
 *             using jump search.
 * @list: Pointer to  head of linked list to search.
 * @size: Number of nodes in list.
 * @value: Value to search for.
 *
 * Return: If value is not present or head of list is NULL, NULL.
 *         Otherwise, a pointer to first node where value is located.
 * Description: Prints value every time it is compared in list.
 *              Uses square root of list size as jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t stp, stp_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	stp = 0;
	stp_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (stp += stp_size; jump->index < stp; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
