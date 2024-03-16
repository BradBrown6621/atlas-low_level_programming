#include "lists.h"

/**
 * print_dlistint - Prints the data elements of a doubly linked list.
 *
 * @h: The doubly linked list to be printed
 *
 * Return: The number of data elements in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t listlength = 0;
	const dlistint_t *head = h;

	if (head)
	{
		while (head != NULL)
		{
			printf("%i\n", head->n);
			head = head->next;
			listlength++;
		}
	}
	return (listlength);
}
