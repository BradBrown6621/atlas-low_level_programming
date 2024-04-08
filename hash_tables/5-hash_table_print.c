#include "hash_tables.h"

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int start = 1;

	if (!ht)
	{
		return;
	}

	printf("{");

	for (i = 0; i < ((ht->size) - 1); i++)
	{
		if (ht->array[i])
		{
			if (start)
			{
				start = 0;
			} else
			{
				printf(", ");
			}
			printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
		}
	}
	i++;
	if (ht->array[i])
	{
		printf(", '%s': '%s'", ht->array[i]->key, ht->array[i]->value);
	}
	printf("}\n");
}
