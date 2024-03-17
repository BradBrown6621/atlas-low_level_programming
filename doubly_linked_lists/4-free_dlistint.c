#include "lists.h"

/**
 * free_dlistint - Frees the memory for a doubly-linked list
 *
 * @head: The pointer to the head node of the list to be free'd
 *
 * Return: NOTHING
 */

void free_dlistint(dlistint_t *head)
{
	if (head)
	{
		if (head->next)
		{
			free_dlistint(head->next);
		}
		free(head);
	}
}
