#include "lists.h"

/**
 * dlistint_len - Finds the length of a doubly linked list
 *
 * @h: The doubly linked list to be evaluated.
 *
 * Return: The length of the doubly linked list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t listlength = 0;

	while (current)
	{
		listlength++;
		current = current->next;
	}
	return (listlength);
}
