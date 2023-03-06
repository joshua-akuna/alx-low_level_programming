/**
 * _memset - fills the first 'n' bytes of the memory area pointed
 * to by s with the constant byte 'b'.
 * @s: a pointer to a memory area.
 * @b: character to assign to fill 'n' block in the memory area.
 * @n: bytes of memory area to fill by 'n'.
 * Return: Always pointer to the memory area 's'
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
