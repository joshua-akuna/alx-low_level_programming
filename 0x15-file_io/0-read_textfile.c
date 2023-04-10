#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output.
 * @filename: a string describing the path to the file to read.
 * @letters: the number of characters to read.
 * Return: the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc;
	int buffer[2048];
	size_t bytes_read = 0;

	(void) letters;

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (-1);
	bytes_read = read(file_desc, buffer, letters);

	close(file_desc);
	buffer[bytes_read] = '\0';

	return (write(1, buffer, bytes_read));
}
