/**
 * _memcpy - copies 'n' bytes from the memory area "src"
 * to the memory area "dest".
 * @dest: memory area to copy to.
 * @src: memory area to copy from.
 * @n: size of bytes to copy.
 * Return: Always poiner to dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
