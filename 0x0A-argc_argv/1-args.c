#include <stdio.h>
/**
 * main - prints the number of arguments passed to this program.
 * @argc: int argument for the size of the array "argv".
 * @argv: a string array.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
