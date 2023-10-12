#include "search_algos.h"

/**
 * linear_skip - Searches for an algorithm in sorted singly linked list
 *               of integers using linear skip.
 * @list: Pointer to head oflinked list to search.
 * @value: Value to search for.
 * Return: If value is not present or head of list is NULL, NULL.
 *         Otherwise, pointer to first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *nd;
	skiplist_t *jmp;

	if (list == NULL)
		return (NULL);

	for (nd = jmp = list; jmp->next != NULL && jmp->n < value;) {
		nd = jmp;
		if (jmp->express != NULL) {
			jmp = jmp->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jmp->index, jmp->n);
		} else {
			while (jmp->next != NULL)
				jmp = jmp->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			nd->index, jmp->index);

	for (; nd->index < jmp->index && nd->n < value; nd = nd->next)
		printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);
	printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);

	return (nd->n == value ? nd : NULL);
}
