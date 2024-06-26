#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table
 *
 * @size: The size of the array of hash nodes
 *
 * Return: A new hash_table (or NULL on failure)
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	unsigned long int i;

	table = malloc(sizeof(hash_table_t));

	if (!table)
	{
		return (NULL);
	}

	table->array = malloc(sizeof(hash_node_t *) * size);

	if (!(table->array))
	{
		free(table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		table->array[i] = NULL;
	}

	table->size = size;

	return (table);
}
