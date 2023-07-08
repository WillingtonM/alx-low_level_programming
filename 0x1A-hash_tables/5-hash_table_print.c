#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
**/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp_node;
	unsigned long int contng = 0, x = 0;

	if (ht != NULL)
	{
		printf("{");

		for (contng = 0; contng < ht->size; contng++)
		{
			tmp_node = ht->array[contng];

			while (tmp_node != NULL)
			{
				if (x != 0)
					printf(", ");
				x = 1;
				printf("'%s': '%s'", tmp_node->key, tmp_node->value);
				tmp_node = tmp_node->next;
			}
		}

		printf("}\n");
	}
}
