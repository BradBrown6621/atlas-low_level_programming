#include "hash_tables.h"

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;

	printf("===Checking if ht == NULL===\n");

	if (!ht)
	{
		printf("===Array is null===\n");
		return;
	}

	printf("{");

	for (i = 0; i < ((ht->size) - 1); i++)
	{
		printf("'%s': '%s', ", ht->array[i]->key, ht->array[i]->value);
	}
	i++;
	printf("'%s': '%s'}", ht->array[i]->key, ht->array[i]->value);
}
