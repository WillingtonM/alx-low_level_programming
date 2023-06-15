#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds node to the end of linked list
 *
 * @head: double pointer to the beginning of the linked list
 * @n: value to add to new_n node
 * Return: returns the pointer to the new_n node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp_n;
	dlistint_t *new_n;

	if (head == NULL)
		return (NULL);
	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);
	new_n->n = n;
	new_n->next = NULL;
	if (*head == NULL)
	{
		new_n->prev = NULL;
		*head = new_n;
		return (new_n);
	}
	tmp_n = *head;
	while (tmp_n->next != NULL)
		tmp_n = tmp_n->next;
	tmp_n->next = new_n;
	new_n->prev = tmp_n;
	return (new_n);
}
