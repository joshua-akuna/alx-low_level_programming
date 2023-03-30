#include "lists.h"
/**
 * before_main - prints "You're beat! and yet, you must allow,
 * \nI bore my house upon my back!\n" before the main function
 * executes.
 * Return: nothing.
 */
void before_main(void)
{
	char *str = "You're beat! and yet, you must allow\n";

	printf("%sI bore my house upon my back!\n", str);
}
