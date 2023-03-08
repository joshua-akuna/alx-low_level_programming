int _is_palindrome(char *s, int start, int end);
int _strlen(char *s);

/**
 * is_palindrome - determines if a string is a palidrome.
 * @s: char pointer to a string.
 * Return: 1 if 's' is a palidrome else 0.
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (0);
	if (*(s + 1) == '\0')
		return (1);
	len = _strlen(s);

	return (_is_palindrome(s, 0, len - 1));
}

/**
 * _strlen- determines the lenght of a string.
 * @s: a char pointer to a string.
 * Return: Always the length of the strirng.
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

/**
 * _is_palindrome - determines if a string is a palidrome.
 * @s: char pointer to a string.
 * @start: index of string from o moving forward.
 * @end: last index of string moving backward;
 * Return: 1 if 's' is a palidrome else 0.
 */
int _is_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (*(s + start) != *(s + end))
		return (0);

	return (_is_palindrome(s, start + 1, end - 1));
}
