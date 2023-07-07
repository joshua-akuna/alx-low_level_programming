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

/**
 * create_new_node - creates a new node of type hash_node_t.
 * @key: the key for the new_node.
 * @value: the value mapped to the key of the new_node.
 * Return: a new_node of type hash_node_t if successful else NULL.
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

/**
 * create_snode - creates a new node for the sorted hash_node_t.
 * @key: the key for the new_node.
 * @value: the value mapped to the key of the new_node.
 * Return: a new_node of type shash_node_t if successful else NULL.
 */
shash_node_t *create_snode(const char *key, const char *value)
{
	shash_node_t *new_node = NULL;
	char *new_key = NULL, *new_value = NULL;

	new_node = (shash_node_t *)malloc(sizeof(shash_node_t));
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
	new_node->snext = NULL;
	new_node->sprev = NULL;

	return (new_node);
}

/**
 * add_to_list_sorted - adds the new_node to the sorted doubly linked
 *	list of the hash table.
 * @ht: the hash table.
 * @new_node: the new node to add to the doubly linked list sorted.
 * Return: Always 1.
 */
int add_to_list_sorted(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *temp = NULL;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, new_node->key) > 0)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext && strcmp(temp->snext->key, new_node->key) < 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new_node;
		else
			temp->snext->sprev = new_node;
		temp->snext = new_node;
	}
	return (1);
}
