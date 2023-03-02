/**
 * rot13 - rotates each character in a string by 13 alphabetically.
 * @str: a pointer to a string.
 * Return: Alwasys str.
 */

char *rot13(char *str)
{
	char *ptr = str;

	while (*ptr != 0)
	{
		while ((*ptr <= 'z' && *ptr >= 'a') || (*ptr <= 'Z' && *ptr >= 'A'))
		{
			if ((*ptr > 'm' && *ptr <= 'z') || (*ptr > 'M' && *ptr <= 'Z'))
			{
				*ptr -= 13;
				break;
			}

			*ptr += 13;
			break;
		}
		ptr++;
	}

	return (str);
}
