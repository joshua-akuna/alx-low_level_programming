#include "hash_tables.h"

/**
 * hash_table_print - prints the contents of the hash table.
 * @ht: the hash table.
 * Return: Nothing.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned int i, flag = 0;
	hash_node_t *node = NULL;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node; node = node->next)
		{
			if (flag)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			flag = 1;
		}
	}
	printf("}");
	printf("\n");
}
