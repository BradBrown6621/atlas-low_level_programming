#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node from a doubly linked list
 *
 * @head: The pointer to the head node in the list
 * @index: The index of the list to be deleted
 *
 * Return: 1 on successful deletion, -1 if unsuccessful
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		if ((*head)->next)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
		} else
		{
			*head = NULL;
		}
		current->next = NULL;
		current->prev = NULL;
		free(current);
		return (1);
	}
	while (current->next)
	{
		current = current->next;
		index--;
		if (index == 0)
			break;
	}
	if (index)
	{
		/** index is OOB */
		return (-1);
	}
	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	current->next = NULL;
	current->prev = NULL;
	free(current);
	return (1);
}
