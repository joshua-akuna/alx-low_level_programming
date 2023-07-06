#include "hash_tables.h"
/**
 * key_index - calculate an index based on the key and array size.
 * @key: key to store a value in the array.
 * @size: size of the array.
 * Return: the index of the array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
