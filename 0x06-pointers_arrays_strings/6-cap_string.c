#include <string.h>
/**
 * cap_string- capitalizes all words of a string;
 * @str: a string parameter;
 * Return: Always str.
 */

char *cap_string(char *str)
{
	char *sep = " \t\n,;.!?\"()}{";
	int i;
	int len = strlen(str);

	for (i = 0; i < len - 1; i++)
	{
		if (!strchr(sep, str[i]))
			continue;
		if (str[i + 1] < 'a' || str[i + 1] > 'z')
			continue;
		str[i + 1] -= 32;
	}
	return (str);
}
