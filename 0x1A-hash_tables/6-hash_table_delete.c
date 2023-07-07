#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table.
 * @ht: a hash table to delete.
 * Return: Nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node = NULL, *temp = NULL;
	unsigned int i = 0;

	if (ht == NULL || ht->size == 0 || ht->array == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}
