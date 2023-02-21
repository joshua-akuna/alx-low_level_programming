#include "main.h"

/**
 * print_last_digit - prints the last digit of parameter num.
 * @num: and intger parameter.
 * Return: return (int). returns the last digit of parameter num.
 */

int print_last_digit(int num)
{
	int res;

	res = num % 10;
	res *= ((res > 0) - (res < 0));
	_putchar(res + '0');

	return (res);
}
