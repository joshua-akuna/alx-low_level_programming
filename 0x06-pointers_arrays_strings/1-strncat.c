/**
 * _strncat - concatenates two strings.
 * @dest: char pointer to a string.
 * @src: char pointer to a string.
 * @n: number of bytes in integer.
 * Return: dest always.
 */

char *_strncat(char *dest, char *src, int n)
{
	unsigned int len, i;

	len = 0;

	for (i = 0; dest[i] != '\0'; i++)
		len++;

	for (i = 0; i < (unsigned int)n && src[i] != '\0'; i++)
		dest[len + i] = src[i];

	return (dest);
}
