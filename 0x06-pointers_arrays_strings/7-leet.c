#include <string.h>

/**
 * leet- replaces in a with, all 'a', 'A' with 4,
 * 'e', 'E' with 3, 'o', 'O'  with 0,
 * 't', 'T' wth 7 and 'l', 'L' with 1.
 * @str: a pointer to a string.
 * Return: Always str.
 */

char *leet(char *str)
{
	int i, len;

	len = strlen(str);

	for (i = 0; i < len && str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'A')
			str[i] = '4';
		else if (str[i] == 'e' || str[i] == 'E')
			str[i] = '3';
		else if (str[i] == 'o' || str[i] == 'O')
			str[i] = '0';
		else if (str[i] == 't' || str[i] == 'T')
			str[i] = '7';
		else if (str[i] == 'l' || str[i] == 'L')
			str[i] = '1';
	}
	return (str);
}
