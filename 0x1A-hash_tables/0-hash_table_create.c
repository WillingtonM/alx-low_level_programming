#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
  * hash_table_create - Creates hash table
  * @size: Size of array
  *
  * Return: Pointer to the newly created hash table
  */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int j;
	hash_node_t **ht_arr = NULL;
	hash_table_t *hash_t = NULL;

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);

	ht_arr = malloc(sizeof(hash_node_t *) * size);
	if (ht_arr == NULL)
		return (NULL);

	for (j = 0; j < size; ++j)
		ht_arr[i] = NULL;

	hash_t->size = size;
	hash_t->array = ht_arr;

	return (hash_t);
}
