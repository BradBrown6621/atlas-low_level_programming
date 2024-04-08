#include "hash_tables.h"

/**
 * free_chain - Recursively free's a collision chain in a hash table array
 *
 * @current: The current node to be free'd
 *
 * Return: Nothing
 */

void free_chain(hash_node_t *current)
{
	if (!current)
	{
		return;
	}
	free_chain(current->next);
	free(current->key);
	free(current->value);
	free(current);
}

/**
 * hash_table_delete - Free's all the memory for a hash table
 *
 * @ht: The hash table to be free'd
 *
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
			free_chain(ht->array[i]);
	}

	free(ht->array);

	free(ht);
}
