#include "hash_tables.h"

/**
 * hash_table_set - adds an element to hash table
 * @ht: hash table
 * @key: key
 * @value: value associated with key
 * Return: return 1 if successful return 0 otherwise
**/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long k_index, ht_size;
	hash_node_t *new_ht_node;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	ht_size = ht->size;
	k_index = key_k_index((const unsigned char *)key, ht_size);

	if (ht->array[k_index] != NULL && strcmp(ht->array[k_index]->key, key) == 0)
	{
		ht->array[k_index]->value = strdup(value);
		return (1);
	}

	new_ht_node = malloc(sizeof(hash_node_t));

	if (new_ht_node == NULL)
		return (0);

	new_ht_node->key = strdup(key);
	new_ht_node->value = strdup(value);
	new_ht_node->next = ht->array[k_index];
	ht->array[k_index] = new_ht_node;

	return (1);
}
