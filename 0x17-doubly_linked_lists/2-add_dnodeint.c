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
    dlistint_t *new = malloc(sizeof(dlistint_t));

    if (!new)
        return (NULL);

    new->n = n;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;

    *head = new;

    return (new);
}
