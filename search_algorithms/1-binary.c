#include "search_algos.h"

int binary_search(int *array, size_t size, int value)
{
	size_t i;
	int middle;

	if (!array || size == 0)
		return (-1);

	printf("Searching in array: %i", array[0]);

	for (i = 1; i < size; i++)
	{
		printf(", %i", array[i]);
	}
	printf("\n");

	if (array[0] != value && size == 1)
	{
		return (-1);
	}

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
