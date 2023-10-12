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
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t stp, stp_size;
	listint_t *nd, *jmp;

	if (list == NULL || size == 0)
		return (NULL);

	stp = 0;
	stp_size = sqrt(size);
	for (nd = jmp = list; jmp->index + 1 < size && jmp->n < value;) {
		nd = jmp;
		for (stp += stp_size; jmp->index < stp; jmp = jmp->next) {
			if (jmp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jmp->index, jmp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			nd->index, jmp->index);

	for (; nd->index < jmp->index && nd->n < value; nd = nd->next)
		printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);
	printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);

	return (nd->n == value ? nd : NULL);
}
