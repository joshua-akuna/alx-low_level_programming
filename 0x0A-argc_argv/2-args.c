#include <stdio.h>
/**
 * main - prints all the arguments passed to this program.
 * @argc: int argument for the size of the array "argv".
 * @argv: a string array.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
