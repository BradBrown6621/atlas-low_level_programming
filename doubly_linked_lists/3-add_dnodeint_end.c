#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node to the tail of a doubly linked list
 *
 * @head: The head of the doubly linked list to be altered
 * @n: The data for the new node
 *
 * Return: The address of the new node (or NULL on failure to execute)
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current = *head;
	dlistint_t *newNode = NULL;

	while (current && (current)->next)
	{
		current = current->next;
	}

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
	{
		return (NULL);
	}

	newNode->n = n;

	newNode->prev = NULL;
	newNode->next = NULL;

	if (current != NULL)
	{
		newNode->prev = current;
		current->next = newNode;
	} else
	{
		*head = newNode;
	}
	return (newNode);
}
