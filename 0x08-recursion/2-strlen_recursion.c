/**
 * _strlen_recursion - determines the lenght of a string.
 * @s: a char pointer to a string.
 * Return: Always length of the string.
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}
