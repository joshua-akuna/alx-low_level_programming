/**
 * wildcmp - compares two strings accounting for the
 * wildcard character.
 * @s1: a char pointer to a string being compared to.
 * @s2: a char pointer to a string being compared with.
 * Return: 1 if strings are identical else 0.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2))
			return (1);
	}
	return (0);
}
