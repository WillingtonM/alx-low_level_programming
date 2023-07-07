/*
 * File: 100-sorted_hash_table.c
 * Auth: Brennan D Baraban
 */

#include "hash_tables.h"

int shash_table_set(shash_table_t *ht, const char *key, const char *value);
shash_table_t *shash_table_create(unsigned long int size);
void shash_table_delete(shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_print(const shash_table_t *ht);
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *n_tmp, *n_new;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	n_tmp = ht->shead;
	while (n_tmp)
	{
		if (strcmp(n_tmp->key, key) == 0)
		{
			free(n_tmp->value);
			n_tmp->value = value_copy;
			return (1);
		}
		n_tmp = n_tmp->snext;
	}

	n_new = malloc(sizeof(shash_node_t));
	if (n_new == NULL)
	{
		free(value_copy);
		return (0);
	}
	n_new->key = strdup(key);
	if (n_new->key == NULL)
	{
		free(value_copy);
		free(n_new);
		return (0);
	}
	n_new->value = value_copy;
	n_new->next = ht->array[index];
	ht->array[index] = n_new;

	if (ht->shead == NULL)
	{
		n_new->sprev = NULL;
		n_new->snext = NULL;
		ht->shead = n_new;
		ht->stail = n_new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		n_new->sprev = NULL;
		n_new->snext = ht->shead;
		ht->shead->sprev = n_new;
		ht->shead = n_new;
	}
	else
	{
		n_tmp = ht->shead;
		while (n_tmp->snext != NULL && strcmp(n_tmp->snext->key, key) < 0)
			n_tmp = n_tmp->snext;
		n_new->sprev = n_tmp;
		n_new->snext = n_tmp->snext;
		if (n_tmp->snext == NULL)
			ht->stail = n_new;
		else
			n_tmp->snext->sprev = n_new;
		n_tmp->snext = n_new;
	}

	return (1);
}

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_tb;
	unsigned long int i;

	hash_tb = malloc(sizeof(shash_table_t));
	if (hash_tb == NULL)
		return (NULL);

	hash_tb->size = size;
	hash_tb->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_tb->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash_tb->array[i] = NULL;
	hash_tb->shead = NULL;
	hash_tb->stail = NULL;

	return (hash_tb);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *h_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	h_node = ht->shead;
	while (h_node != NULL && strcmp(h_node->key, key) != 0)
		h_node = h_node->snext;

	return ((h_node == NULL) ? NULL : h_node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *h_node;

	if (ht == NULL)
		return;

	h_node = ht->shead;
	printf("{");
	while (h_node != NULL)
	{
		printf("'%s': '%s'", h_node->key, h_node->value);
		h_node = h_node->snext;
		if (h_node != NULL)
			printf(", ");
	}
	printf("}\n");
}


/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *n_tmp , *h_node;

	if (ht == NULL)
		return;

	h_node = ht->shead;
	while (h_node)
	{
		n_tmp = h_node->snext;
		free(h_node->key);
		free(h_node->value);
		free(h_node);
		h_node = n_tmp;
	}

	free(head->array);
	free(head);
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *h_node;

	if (ht == NULL)
		return;

	h_node = ht->stail;
	printf("{");
	while (h_node != NULL)
	{
		printf("'%s': '%s'", h_node->key, h_node->value);
		h_node = h_node->sprev;
		if (h_node != NULL)
			printf(", ");
	}
	printf("}\n");
}