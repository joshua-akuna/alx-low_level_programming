#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: size of the array property of the sorted hash table.
 * Return: the new sorted hash table created if successful else NULL;
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = NULL;

	if (size == 0)
		return (NULL);

	table = (shash_table_t *) malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	table->array = (shash_node_t **)calloc(sizeof(shash_node_t *), table->size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - adds a new node with key @key and value @value to
 *	to the hash array and sorted doubly linked list of the hash table.
 * @ht: a pointer to the hash table of type shash_table_t.
 * @key: the key (string) of the node to add or value to update.
 * @value: value mapped to the key.
 * Return: 1 if successful else 0.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *temp = NULL, *new_node = NULL;
	char *new_value = NULL;
	int index = 0;

	if (ht == NULL || ht->size == 0 || key == NULL
		|| *key == '\0' || value == NULL)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(temp->value);
			temp->value = new_value;
			return (1);
		}
		temp = temp->next;
	}

	new_node = create_snode(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	add_to_list_sorted(ht, new_node);
	return (1);
}

/**
 * shash_table_print - prints the sorted doubly linked list
 *	of the hash table argument.
 * @ht: a pointer to a hash table of type shash_table_t.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node; node = node->snext)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
	}
	printf("}");
	printf("\n");
}

/**
 * shash_table_print_rev - prints the sorted linked list of the sorted
 *	hash table in a reverse order.
 * @ht: pointer to the hash table of type shash_table_t.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (node = ht->stail; node; node = node->sprev)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
	}
	printf("}");
	printf("\n");
}

/**
 * shash_table_delete - deletes a hash table.
 * @ht: a hash table to delete of type shash_table_t
 * Return: Nothing.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node = ht->shead, *temp = NULL;

	while (node)
	{
		temp = node;
		node = node->snext;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	free(ht->array);
	free(ht);
}

/**
 * shash_table_get - returns the value mapped to the key argument
 *	in the hash table.
 * @ht: a pointer to the hash table of type shash_table_t
 * @key: the key whose value is to be returned
 * Return: the value mapped to the key in the hast table if it
 *	exists else NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	int idx;
	shash_node_t *node;

	if (ht == NULL || ht->size == 0 || ht->array == NULL
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
