#include <string.h>
#include <stdio.h>
/**
 * cap_string- capitalizes all words of a string;
 * @str: a string parameter;
 * Return: Always str.
 */

char *cap_string(char *str)
{
	char *ptr = str;
	int flag = 1;

	while (*ptr != 0)
	{
		if (flag)
		{
			flag = 0;
			if (*ptr >= 'a' && *ptr <= 'z')
				*ptr -= 32;
		}

		if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == ','
		    || *ptr == ';' || *ptr == '.' || *ptr == '!' || *ptr == '"'
		    || *ptr == '(' || *ptr == ')' || *ptr == '{' || *ptr == '}')
			flag = 1;
		ptr++;
	}
	return (str);
}
