#include "main.h"
/**
 * print_binary - prints the binary representation of a number.
 * @n: an unsigned int to convert to binary.
 * Return: nothing.
 */
void print_binary(unsigned long int n)
{
	unsigned long int num = n;
	if (num >= 2)
		print_binary(num >> 1);
	putchar((num & 1) + '0');
}
