#include "lists.h"

/**
 * get_dnodeint_at_index - Gets the node at a specified index in a list
 *
 * @head: The head node of the doubly linked list to be checked
 * @index: The index of the node desired
 *
 * Return: The node at that index (or NULL if OOB or if head is NULL);
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current = head;

	if (!head)
	{
		return (NULL);
	}
	for (i = 0; (i < index) && current; i++)
	{
		current = current->next;
	}
	return (current);
}
