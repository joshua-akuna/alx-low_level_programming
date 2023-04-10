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
	int buffer[1024];
	size_t bytes_read = 0;

	if (filename == NULL || letters == 0)
		return (0);

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);
	bytes_read = read(file_desc, buffer, letters);
	if (bytes_read == 0)
		return (0);

	close(file_desc);

	return (write(1, buffer, bytes_read));
}
