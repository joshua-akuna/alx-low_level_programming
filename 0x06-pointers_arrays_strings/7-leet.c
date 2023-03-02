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
	char *ptr = str;
	int i;
	char encrypt[][10] = { { 'a', 'A', 't', 'T', 'o', 'O', 'e', 'E', 'l', 'L'}
				  , { '4', '4', '7', '7', '0', '0', '3', '3', '1', '1'} };

	while (*ptr)
	{
		if (*ptr == 'a' || *ptr == 'A' || *ptr == 'e' || *ptr == 'E'
		    || *ptr == 'o' || *ptr == 'O' || *ptr == 't' || *ptr == 'T'
		    || *ptr == 'l' || *ptr == 'L')
		{
			i = 0;
			while (encrypt[0][i] != *ptr)
				i++;
			*ptr = encrypt[1][i];
		}
		ptr++;
	}
	return (str);
}
