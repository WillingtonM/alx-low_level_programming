#ifndef HASH_H
#define HASH_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Nodes for the lists in the array
 * @key: Key, string
 * The key is unique in HashTable
 * @value: Value corresponding to a key
 * @next: Pointer to next node of list
 **/
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table struct
 * @size: Size of array
 * @array: Array of size
 **/
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;


unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
hash_table_t *hash_table_create(unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
void hash_table_print(const hash_table_t *ht);
char *hash_table_get(const hash_table_t *ht, const char *key);
int check_list(char *key, hash_table_t *ht, unsigned long int, char *value);
#endif
