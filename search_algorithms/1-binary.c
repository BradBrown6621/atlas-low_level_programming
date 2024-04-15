#include "search_algos.h"

int binary_search(int *array, size_t size, int value)
{
	size_t i;
	int middle;

	if (!array || size == 0)
		return (-1);

	if (size == 1 && array[0] != value)
		return (-1);

	printf("Searching in array:");

	for (i = 0; i < size; i++)
	{
		printf(" %i", array[i]);
	}
	printf("\n");

	middle = size / 2;

	if (value == array[0])
	{
		return (middle);
	} else if (value < array[middle])
	{
		return (binary_search(
					array,
					middle,
					value)
				+ 1);
	} else
	{
		return (binary_search(
			array + middle,
			size - middle,
			value));
	}
	return (-1);
}
