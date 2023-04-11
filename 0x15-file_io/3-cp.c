#include "main.h"

/**
 * checks_file_desc - checks if files can be opened.
 * @file_from_desc: the file descriptor to copy from.
 * @file_to_desc: file descriptor to copy to
 * @argv: array of string arguments
 */
void check_file_desc(int file_from_desc, int file_to_desc, char *argv[])
{
	if (file_from_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copies the content of one file to another.
 * @argc: number of arguments passed to the main function.
 * @argv: an array of strings passed to the main function.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from_desc, file_to_desc, chk_close;
	ssize_t bytes_read = 1024, bytes_out;
	char buffer[1024];
	
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	
	file_from_desc = open(argv[1], O_RDONLY);
	file_to_desc = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_file_desc(file_from_desc, file_to_desc, argv);
	
	while (bytes_read == 1024)
	{
		bytes_read = read(file_from_desc, buffer, 1024);
		if (bytes_read == -1)
			check_file_desc(-1, 0, argv);
		bytes_out = write(file_to_desc, buffer, bytes_read);
		
		if (bytes_out == -1)
			check_file_desc(0, -1, argv);
	}
	chk_close = close(file_from_desc);
	if (chk_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from_desc);
		exit(100);
	}
	
	chk_close = close(file_to_desc);
	if (chk_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from_desc);
		exit(100);
	}
return (0);
}
