#include "hash_tables.h"

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *htkill_node, *ht_current;
	unsigned long int i;

	x = 0;
	while (x < ht->size)
	{
		ht_current = ht->array[x];
		while (ht_current != NULL)
		{
			htkill_node = ht_current;
			ht_current = ht_current->next;
			free(htkill_node->key);
			free(htkill_node->value);
			free(htkill_node);
		}
		x++;
	}
	free(ht->array);
	free(ht);
}
