#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: double pointer to the head of the list
 * @n: value n of the new node to be added to the list
 * Return:  returns the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_n;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = n;
	new_n->next = *head;
	new_n->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_n;
	*head = new_n;
	return (new_n);
}
