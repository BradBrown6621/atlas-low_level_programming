#include "hash_tables.h"

/**
 * key_index - Retrieves the index of a hash table for a given key
 *
 * @key: The key to be hashed
 * @size: The size of the array in the hash table
 *
 * Return: The index at which the key/value pair should be stored in the array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key) % size;

	return (index);
}
