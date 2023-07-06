#ifndef _HASH_TABLES_H_
#define _HASH_TABLES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct hash_node_s - node of a hash table
 *
 * @key: The key, string
 * The key is unique in the hash table
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the list
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data struct.
 *
 * @size: The size of the hash table.
 * @array: An array of size at size.
 * Each cell of this array is a pointer to the first node
 * of a linked list,
 * because we want a HashTable to use a chaining collision
 * handling.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
#endif /*_HASH_TABLES_H_*/