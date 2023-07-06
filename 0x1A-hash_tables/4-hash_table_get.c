#include "hash_tables.h"

/**
 * hash_table_get - returns the value mapped to the key argument
 *	in the hash table.
 * @ht: a pointer to the hash table.
 * @key: the key whose value is to be returned
 * Return: the value mapped to the key in the hast table if it
 *	exists else NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	int idx;
	hash_node_t *node;

	if (ht == NULL || ht->size == 0 || t->array == NULL
		|| key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
