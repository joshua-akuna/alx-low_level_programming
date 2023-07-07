#include "hash_tables.h"

/**
 * main - test code.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	shash_table_t *ht;
	char *val = NULL;

	ht = shash_table_create(1024);

	printf("%lu\n", ht->size);

	shash_table_set(ht, "y", "0");
	shash_table_print(ht);
	shash_table_set(ht, "j", "1");
	shash_table_print(ht);
	shash_table_set(ht, "c", "2");
	shash_table_print(ht);
	shash_table_set(ht, "b", "3");
	shash_table_print(ht);
	shash_table_set(ht, "z", "4");
	shash_table_print(ht);
	shash_table_set(ht, "n", "5");
	shash_table_print(ht);
	shash_table_set(ht, "a", "6");
	shash_table_print(ht);
	shash_table_set(ht, "m", "7");
	shash_table_print(ht);
	shash_table_print_rev(ht);

	val = shash_table_get(ht, "z");
	printf("%s\n", val);

	val = shash_table_get(ht, "a");
	printf("%s\n", val);

	shash_table_delete(ht);
	return (EXIT_SUCCESS);
}
