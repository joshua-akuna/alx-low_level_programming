#include "hash_tables.h"
/**
 * main - test for 0-hash_table_create.c
 * Return: 0 always.
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	printf("%p\n", (void *)ht);
	return (EXIT_SUCCESS);
}
