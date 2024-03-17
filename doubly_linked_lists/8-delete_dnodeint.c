#include "lists.h"

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
