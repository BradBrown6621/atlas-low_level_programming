#include "hash_tables.h"

/**
 * hash_djb2 - Hashes a string to an unsigned long integer
 *
 * @str: The string to be hashed
 *
 * Return: The number used for finding a hash index
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}
