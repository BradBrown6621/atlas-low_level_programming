#include "lists.h"

/**
 * sum_dlistint - Sums the data elements of a doubly linked list.
 *
 * @head: The doubly linked list to be summed together
 *
 * Return: The sum of data elements in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int listSum = 0;

	if (head)
	{
		while (head != NULL)
		{
			listSum += head->n;
			head = head->next;
		}
	}
	return (listSum);
}
