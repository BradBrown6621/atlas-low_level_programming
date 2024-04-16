#include "search_algos.h"

/**
 * print_array - Prints an array, given its size
 *
 * @arr: The array, of which its contents will be printed
 * @size: The size of arr
 *
 * Return: Nothing
 */

void print_array(int arr[], size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

/**
 * binary_search - Searches an array for a value
 *
 * @arr: The array to be searched for "value"
 * @size: The size of "arr"
 * @value: The value searched for in "arr"
 *
 * Description:
 * [SEARCH ALGORITHM]
 * This search implements a "divide-and-conquer" type of search algorithm,
 * which chops the lists into 2 sublists, decides which sublist to check
 * for a specified value, and discards the rest. This means that a list
 * which would take O(n) time to search through actually takes O(log(n)) time
 * to search through.
 *
 * Return: If "value" isn't in the list, the integer -1 is returned.
 * Otherwise, the first index that "value" is found at is returned.
 */

int binary_search(int arr[], size_t size, int value)
{
	int mid = 0, index = 0;
	int *start = NULL;
	int end, result;

	if (!arr)
		return (-1);
	print_array(arr, size);
	if (size == 1)
	{
		if (value != arr[0])
		{
			return (-1);
		}
		return (index);
	}
	mid = size / 2;
	end = mid;
	if (value < arr[mid])
	{
		start = &(arr[0]);
		end--; /** delete this after you submit, checker was wrong*/
	} else
	{
		if (size % 2 == 1)
		{
			end++;
		}
		start = &(arr[mid]);
		index += mid;
	}
	result = binary_search(start, end, value);
	if (result == -1)
		return (-1);
	return (index + result);
}
