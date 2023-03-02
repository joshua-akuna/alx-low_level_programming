#include <stdio.h>

/**
 * print_buffer- prints a buffer;
 * @b: char pointer to the buffer.
 * @size: integer for size of buffer to print.
 */

void print_buffer(char *b, int size)
{
	int bytes_printed, _size = size, count = 0;
	char *_b = b;

	if (size == 0)
		printf("\n");
	while (size > 0)
	{
		printf("%08x:", count);
		bytes_printed = 0;
		while (bytes_printed < 10 && size > 0)
		{
			if (bytes_printed % 2 == 0)
				printf(" ");
			printf("%02x", *b);
			b++;
			size--;
			bytes_printed++;
			count++;
		}
		while (count % 10 != 0)
		{
			if (count % 2 == 0)
				printf(" ");
			printf("  ");
			count++;
		}
		printf(" ");
		bytes_printed = 0;
		while (bytes_printed < 10 && _size > 0)
		{
			if (*_b > 31 && *_b != 127)
				printf("%c", *_b);
			else
				printf(".");
			_b++;
			_size--;
			bytes_printed++;
		}
		printf("\n");
	}
}
