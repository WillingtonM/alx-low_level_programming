#include "hash_tables.h"

hash_node_t *add_n_hash(hash_node_t **head, const char *key, const char *value);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/**
 * hash_table_set - adds a hash (key, value) to a given hash table
 *
 * @ht: pointer to the hash table
 * @key: key of the hash
 * @value: value to store
 * Return: 1 if successes, 0 if fails
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_index;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	k_index = key_index((unsigned char *)key, ht->size);

	if (add_n_hash(&(ht->array[k_index]), key, value) == NULL)
		return (0);

	return (1);
}

/**
 * add_n_hash - adds node at beginning of  hash at a given index
 *
 * @head: Head of hash linked list
 * @key: key of hash
 * @value: value to store
 * Return: head of hash
 */
hash_node_t *add_n_hash(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *n_tmp;

	n_tmp = *head;

	while (n_tmp != NULL)
	{
		if (strcmp(key, n_tmp->key) == 0)
		{
			free(n_tmp->value);
			n_tmp->value = strdup(value);
			return (*head);
		}
		n_tmp = n_tmp->next;
	}

	n_tmp = malloc(sizeof(hash_node_t));

	if (n_tmp == NULL)
		return (NULL);

	n_tmp->key = strdup(key);
	n_tmp->value = strdup(value);
	n_tmp->next = *head;
	*head = n_tmp;

	return (*head);
}
