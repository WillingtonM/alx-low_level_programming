#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * 
 * @h: double pointer to the beginning of the linked list
 * @idx: index at which to insert new node
 * @n: the data to enter into new node
 *
 * Return: returns the pointer to the new node, or returns NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node;
    dlistint_t *next_node;
    dlistint_t *current_node;
    unsigned int i;

    if (h == NULL)
        return (NULL);
    if (idx != 0)
    {
        current_node = *h;
        for (i = 0; i < idx - 1 && current_node != NULL; i++)
            current_node = current_node->next;
        if (current_node == NULL)
            return (NULL);
    }
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = n;
    if (idx == 0)
    {
        next_node = *h;
        *h = new_node;
        new_node->prev = NULL;
    }
    else
    {
        new_node->prev = current_node;
        next_node = current_node->next;
        current_node->next = new_node;
    }
    new_node->next = next_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    return (new_node);
}
