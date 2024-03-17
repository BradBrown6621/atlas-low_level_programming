#include "lists.h"

dlistint_t *traverse_dlistint(dlistint_t **h, unsigned int idx)
{
	unsigned int i;
	dlistint_t *current = *h;

	for (i = 0; (i < idx - 1) && (idx != 0); i++)
	{
		if (current == NULL)
		{
			return (NULL);
		}
		current = current->next;
	}
	return (current);
}
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
	dlistint_t *new = NULL;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*h == NULL)
	{
		if (idx != 0)
		{
			free(new);
			return (NULL);
		}
		*h = new;
		return (new);
	}
	current = traverse_dlistint(h, idx);
	if (current == NULL)
	{
		free(new);
		return (NULL);
	}
	if (idx != 0)
	{
		new->prev = current;
		new->next = current->next;
		if (current->next)
			current->next->prev = new;
		current->next = new;
		return (new);
	}
	new->next = current;
	current->prev = new;
	*h = new;
	return (new);
}
