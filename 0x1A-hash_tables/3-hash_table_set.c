#include "hash_tables.h"

/**
 * hash_table_set - adds a new_node of type hash_node_t if a node with
 *	the key argument does not exist else update the value of the
 *	node whose key equals the key argument.
 * @ht: the hash table containing an array of buckets.
 * @key: a string argument.
 * @value: a string argument.
 * Return: 1 if operation was successful else 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node = NULL, *new_node = NULL;
	int idx;
	char *new_value;

	/* checks if the arguments are valid */
	if (ht == NULL || ht->array == NULL || ht->size == 0
		|| key == NULL || value == NULL || *key == '\0')
		return (0);
	/* gets the head of the linked list at the specified index */
	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];
	/* searches the list at the index if a node with the key exists */
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			break;
		node = node->next;
	}
	/* if there's a node with the key, updates its value */
	if (node)
	{
		new_value = strdup(value);
		if (new_value == NULL)
			return (0);
		free(node->value);
		node->value = new_value;
	}
	else
	{
		/* else, create a new node and attach it to the bucket */
		new_node = create_new_node(key, value);
		if (new_node == NULL)
			return (0);
		new_node->next = ht->array[idx];
		ht->array[idx] = new_node;
	}

	return (1);
}

/**
 * create_new_node - creates a new node of type hash_node_t.
 * @key: the key for the new_node.
 * @value: the value mapped to the key of the new_node.
 * Return: a new_node if successful else NULL.
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	char *new_key = NULL, *new_value = NULL;

	new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_key = strdup(key);
	if (new_key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->key = new_key;

	new_value = strdup(value);
	if (new_value == NULL)
	{
		free(new_key);
		free(new_node);
		return (NULL);
	}
	new_node->value = new_value;

	return (new_node);
}
