#include "hash_tables.h"

/**
 * hash_table_get - Gets a value from a key/value pair in a hash table
 *
 * @ht: The hash table to be checked for key/value pair
 * @key: The key used to find key/value pair
 *
 * Return: Value (or NULL on failure)
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current = NULL;
	unsigned long int i;

	if (!ht || !key)
	{
		return (NULL);
	}

	i = key_index((const unsigned char *)key, ht->size);

	current = ht->array[i];

	while (current)
	{
		if (!(strcmp(current->key, key)))
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}
