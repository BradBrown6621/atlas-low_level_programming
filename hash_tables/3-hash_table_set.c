#include "hash_tables.h"

void node_prepend(hash_node_t *node, hash_table_t *ht, unsigned long int index)
{
	node->next = ht->array[index];
	ht->array[index] = node;
}

int is_collision(hash_node_t *beginning, const char *key, char *value)
{
	hash_node_t *current = beginning;

	while (current)
	{
		if (!strcmp(current->key, key))
		{
			current->value = value;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *newNode = NULL;
	char *value_cpy = malloc(strlen(value) + 1);
	char *key_cpy = NULL;

	if (!value_cpy)
		return (0);

	strcpy(value_cpy, value);

	if (is_collision(ht->array[index], key, value_cpy))
	{
		return (1);
	}

	key_cpy = malloc(strlen(key) + 1);
	if (!key_cpy)
	{
		free(value_cpy);
		return (0);
	}
	strcpy(key_cpy, key);
	newNode = malloc(sizeof(hash_node_t));
	if (!newNode)
	{
		free(key_cpy);
		free(value_cpy);
		return (0);
	}
	newNode->key = key_cpy;
	newNode->value = value_cpy;
	newNode->next = NULL;
	node_prepend(newNode, ht, index);
	return (1);
}
