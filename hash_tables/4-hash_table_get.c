#include "hash_tables.h"

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current = NULL;
	long unsigned int i;

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
