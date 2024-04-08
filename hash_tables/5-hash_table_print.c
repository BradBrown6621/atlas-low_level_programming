#include "hash_tables.h"

/**
 * hash_table_print - Prints the contents of a hash table's array
 *
 * @ht: The hash table to be printed
 *
 * Return: Nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int start = 1;
	hash_node_t *current = NULL;

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
			current = ht->array[i];
			while (current)
			{
				printf("'%s': '%s'",
					ht->array[i]->key,
					ht->array[i]->value
					);
				current = current->next;
			}
		}
	}
	i++;
	if (ht->array[i])
	{
		printf(", '%s': '%s'", ht->array[i]->key, ht->array[i]->value);
	}
	printf("}\n");
}
