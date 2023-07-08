#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int ix;
	hash_node_t *ht_tmp_1, *ht_tmp_2;

	if (ht == NULL)
		return;

	for (x = 0; x < ht->size; x++)
	{
		ht_tmp_1 = ht->array[x];
		while ((ht_tmp_2 = ht_tmp_1) != NULL)
		{
			ht_tmp_1 = ht_tmp_1->next;
			free(ht_tmp_2->key);
			free(ht_tmp_2->value);
			free(ht_tmp_2);
		}
	}
	free(ht->array);
	free(ht);
}
