/**
 * _strncpy - copies a string
 * @dest: char pointer to a string to copy to.
 * @src: char pointer to a string to copy from.
 * Return: always dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	unsigned int i;

	for (i = 0; i < (unsigned)n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < (unsigned)n; i++)
		dest[i] = '\0';

	return (dest);
}
