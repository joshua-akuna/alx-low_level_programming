/**
 * print_name - pass a string argument to be printed
 * to the function pointer argument.
 * @name: a string argument to be printed.
 * @f: a function pointer takes a string argument.
 *
 * Return: returns nothing.
 */

void print_name(char *name, void (*f)(char *))
{
	if (!f)
		return;

	f(name);
}
