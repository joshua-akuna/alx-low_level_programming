#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output.
 * @filename: a string describing the path to the file to read.
 * @letters: the number of characters to read.
 * Return: the actual number of letters read and printed.
 * 0 if the file cannot be opened or read.
 * 0 if the filename is NULL.
 * 0 if the write faile or does not return the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc = -1;
	int buffer[1024];
	size_t bytes_read = 0, bytes_out = 0;

	if (filename == NULL || letters == 0)
		return (0);

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);
	bytes_read = read(file_desc, buffer, letters);
	if (bytes_read == 0)
	{
		close(file_desc);
		return (0);
	}
	close(file_desc);
	bytes_out = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_read != bytes_out)
		return (0);
	return (bytes_out);
}
