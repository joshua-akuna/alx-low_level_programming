/**
 * rot13 - rotates each character of a string by 13 steps alpahbetically forward.
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
