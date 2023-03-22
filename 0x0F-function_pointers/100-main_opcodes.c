#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the opcodes of its own main function.
 * @argc: the number of arguments passed to the main function.
 * @argv: an array containing the arguments passed to the main function.
 *
 * Return: 0 if executed successfully.
 */
int main(int argc, char *argv[])
{
	int tot_bytes, i;
	unsigned char *f;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	tot_bytes = atoi(argv[1]);
	if (tot_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	f =  (unsigned char *)(long int) main;

	for (i = 0; i < tot_bytes; i++)
	{
		if ( i && i < tot_bytes)
			putchar(' ');
		printf("%02x", *(f + i));

		if (i == tot_bytes - 1)
			putchar('\n');
	}

	return (0);
}
