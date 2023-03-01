/**
 * string_toupper- changes all lowercase letters in a string to uppercase.
 * @str: pointer to a string.
 * Return: Always strr.
 */

char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}

	return (str);
}
