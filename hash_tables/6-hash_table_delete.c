#include "hash_tables.h"

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
