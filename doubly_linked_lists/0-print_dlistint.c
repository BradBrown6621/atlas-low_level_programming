#include "lists.h"

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
