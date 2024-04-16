#include "search_algos.h"

/**
 * linear_search - Loops through an array for a value
 *
 * @array: The array to search
 * @size: The size of the array to search
 * @value: The value to be searched for in the array
 *
 * Return: The first index where value is found at (or -1 if not found)
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%i]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
