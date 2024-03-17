#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at desired index
 *
 * @h: The pointer to the head of the list
 * @idx: The index to be inserted into
 * @n: The data for the new node
 *
 * Description: This function initializes and inserts a new node into a
 * doubly-linked list. Note that this insertion pushes the nodes at and
 * after that index by 1 index (i.e., if you inserted at index 11, the node
 * at index 11 is now index 12, index 12 is now 13, etc.)
 *
 * Return: The node that was created (or NULL on function failure)
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h;
	dlistint_t *newNode = NULL;
	unsigned int i;

	for (i = 0; (i < idx) && current; i++)
		current = current->next;

	if (i > idx && !current)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (current && current->prev)
	{
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;
	} else
	{
		*h = newNode;
	}

	return (newNode);
}
