#include "main.h"

void validate_fd(int fd_src, int fd_dest, char *file_names[]);

/**
 * main - copies the content of one file to another.
 * @argc: number of arguments passed to the main function.
 * @argv: an array of strings passed to the main function.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int src, dest, chk_close;
	ssize_t bytes_read = 1024, bytes_out;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	validate_fd(src, dest, argv);
	while (bytes_read == 1024)
	{
		bytes_read = read(src, buffer, 1024);
		if (bytes_read == -1)
			validate_fd(-1, 0, argv);
		bytes_out = write(dest, buffer, bytes_read);
		if (bytes_out == -1)
			validate_fd(0, -1, argv);
	}
	chk_close = close(src);
	if (chk_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	chk_close = close(dest);
	if (chk_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	return (0);
}

/**
 * validate_fd - checks if files can be opened.
 * @fd_src: the file descriptor to copy from.
 * @fd_dest: file descriptor to copy to
 * @file_names: array of string arguments
 */
void validate_fd(int fd_src, int fd_dest, char *file_names[])
{
	if (fd_src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_names[1]);
		exit(98);
	}
	if (fd_dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_names[2]);
		exit(99);
	}
}
