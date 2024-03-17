#include "lists.h"

/**
 * add_dnodeint - Adds a new node to the head of a doubly linked list
 *
 * @head: The head of the doubly linked list to be altered
 * @n: The data for the new node
 *
 * Return: The address of the new node (or NULL on failure to execute)
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode = NULL;

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
	{
		return (NULL);
	}

	newNode->n = n;

	newNode->prev = NULL;
	newNode->next = NULL;

	if (*head != NULL)
	{
		newNode->next = *head;
		(*head)->prev = newNode;
	}
	*head = newNode;
	return (newNode);
}
