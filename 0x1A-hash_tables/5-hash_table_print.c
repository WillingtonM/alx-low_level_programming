#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
  * hash_table_print - Prints a hash table
  * @ht: Hash table to prints
  *
  * Return: void
  */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *ht_node = NULL;
	unsigned long int i = 0;
	short pr_commas = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (; i < ht->size; ++i)
	{
		ht_node = ht->array[i];

		while (ht_node)
		{
			if (pr_commas == 1)
				printf(", ");

			pr_commas = 1;
			printf("'%s': '%s'", (char *) ht_node->key,
								(char *) ht_node->value);

			ht_node = ht_node->next;
		}
	}

	printf("}\n");
}
