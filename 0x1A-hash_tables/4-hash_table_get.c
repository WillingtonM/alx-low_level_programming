#include "hash_tables.h"

/**
 * hash_table_get - retrieves value associated with a key
 *
 * @ht: pointer to hash table
 * @key: key of hash
 * Return: value of hash.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	hash_node_t *n_tmp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, ht->size);

	n_tmp = ht->array[k_index];

	while (n_tmp != NULL)
	{
		if (strcmp(n_tmp->key, key) == 0)
			return (n_tmp->value);
		n_tmp = n_tmp->next;
	}

	return (NULL);
}
