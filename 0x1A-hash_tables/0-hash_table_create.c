#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: a pointer to the newly created hash table
**/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_tb;

	if (!size)
		return (NULL);

	hash_tb = calloc(1, sizeof(hash_table_t));
	if (!hash_tb)
		return (NULL);
	hash_tb->size = size;
	hash_tb->array = calloc(size, sizeof(hash_node_t *));
	if (!hash_tb->array)
	{
		free(hash_tb);
		return (NULL);
	}

	return (hash_tb);
}
