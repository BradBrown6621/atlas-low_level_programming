#include "hash_tables.h"

/**
 * node_prepend - Prepends nodes in a collision chain
 *
 * @node: The node to be added
 * @ht: The hash table to be altered
 * @index: The index of the hash table array to be altered
 *
 * Return: Nothing
 */

void node_prepend(hash_node_t *node, hash_table_t *ht, unsigned long int index)
{
	node->next = ht->array[index];
	ht->array[index] = node;
}

/**
 * is_collision - Checks whether the index of hash table array has collisions
 *
 * @beginning: The first node in the chain at a hash table array index
 * @key: The key to be checked for
 * @value: The value that nodes can be updated with
 *
 * Return: 0 if no collisions reported, 1 if collisions
 */

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

/**
 * hash_table_set - Sets new data into a hash table
 *
 * @ht: The hash table to be altered
 * @key: The key to set new data at
 * @value: The value associated with key
 *
 * Description: This function will do one of 3 things:
 *
 * 1) If a node does not exist at the hashed index of the hash table array,
 * the program mallocs a new node, initializes it's key/value pair, and
 * inserts the new node into that index.
 *
 * 2) If there is a node that exists at that index, then:
 *
 * - If any of the nodes' keys match the new key, that node's value is updated
 *   to the new value.
 *
 * - If there are no nodes with matching keys to our new key, then we prepend
 *   a new node with data to the beginning of that chain at that index of the
 *   hash table array.
 *
 * Return: 0 on failure to create/update nodes, 1 on successful creation/update
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *newNode = NULL;
	char *value_cpy = NULL;
	char *key_cpy = NULL;

	if (!ht)
		return (0);

	value_cpy = malloc(strlen(value) + 1);
	if (!value_cpy)
	{
		return (0);
	}
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
