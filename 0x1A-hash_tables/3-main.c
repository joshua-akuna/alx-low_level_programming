#include "hash_tables.h"

/**
 * main - test code for the hash_table_set implementation.
 *
 * Return: Always 0
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "cool");
	return (EXIT_SUCCESS);
}
