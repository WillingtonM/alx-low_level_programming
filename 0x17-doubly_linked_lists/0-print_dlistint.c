#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 *
 * @h: pointer to the head of the list
 * Return: the number of nodes of dlistint_t list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int node_counter;

	node_counter = 0;

	if (h == NULL)
		return (node_counter);
	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		node_counter++;
		h = h->next;
	}

	return (node_counter);
}
