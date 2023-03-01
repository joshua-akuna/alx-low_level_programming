/**
 * _strcmp- compares two strings.
 * @s1: first string parameter
 * @s2: second string parameter
 * Return: 0 if s1 equals s2, 1 if s1 is greater than s2, else -1.
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int  i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		return (s1[i] - s2[i]);
	}

	return (0);
}
