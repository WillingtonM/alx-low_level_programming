#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing djb2 algorithm.
 * @str: String to hash.
 *
 * Return: Calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int t_hash;
	int chr;

	t_hash = 5381;
	while ((chr = *str++))
		t_hash = ((t_hash << 5) + t_hash) + chr;

	return (t_hash);
}
