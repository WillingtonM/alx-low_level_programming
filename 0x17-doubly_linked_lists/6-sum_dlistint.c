#include "lists.h"

/**
 * sum_dlistint - sums all of the data of a dlistint_t linked list
 * @head: pointer to the beginning of the linked list
 *
 * Return: returns the sum of all data, or returns 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int total;

	total = 0;

	while (head != NULL)
	{
		total += head->n;
		head = head->next;
	}
	return (total);
}
