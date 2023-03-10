#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the product of the index 1 and 2 elements in "argv".
 * @argc: int argument for the size of the array "argv".
 * @argv: a string array.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int num1, num2;

	if (argc != 3)
	{
		printf("%s\n", "Error");
		return (1);
	}

	num1 = atoi(*(argv + 1));
	num2 = atoi(*(argv + 2));

	printf("%d\n", num1 * num2);

	return (0);
}
