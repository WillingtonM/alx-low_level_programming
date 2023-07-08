#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: is the hash table we want to look into
 * @key: the key we are looking for
 * Return: value associated with the element, or NULL
**/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *n_tmp;
	unsigned long int k_index;

	if (key == NULL || ht == NULL)
		return (NULL);

	k_index = key_index((const unsigned char *)key, ht->size);
	n_tmp = ht->array[k_index];

	for (; n_tmp != NULL; n_tmp = n_tmp->next)
	{
		if (strcmp(n_tmp->key, key) == 0)
			return (n_tmp->value);
	}

	return (NULL);
}
