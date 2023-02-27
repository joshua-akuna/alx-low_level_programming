#include "main.h"
#include <string.h>

/**
 * rev_string- reverses a string.
 * @s: a char pointer to a string.
 */

void rev_string(char *s)
{
	int len, i, temp;

	len = strlen(s);

	for (i = 0; i < len / 2; i++)
	{
		temp = s[len - 1 - i];
		s[len - 1 - i] = s[i];
		s[i] = temp;
	}
}
