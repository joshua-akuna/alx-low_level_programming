#include "main.h"

int close_fd(int file_desc);
void check_file_desc(int file_from_desc, int file_to_desc, char **arg);
/**
 * main - copies the content of a file to another.
 * @argc: number of arguments passed to main.
 * @argv: array of string of arguments passed to main.
 * Return: Always 0.
 * exit with code 98 if file_from does not exist or can't be read.
 * exit with code 99 if file_to cannot be created or if write
 * to file fails.
 * exit with code 100 if a file descriptor cannot close.
 */
int main(int argc, char **argv)
{
	int file_from_desc, file_to_desc;
	char buffer[1024];
	ssize_t bytes_read, bytes_out;

	if (argc != 3)
	{
		dprintf(2, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from_desc = open(argv[1], O_RDONLY);
	file_to_desc = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	check_file_desc(file_from_desc, file_to_desc, argv);

	do {
		bytes_read = read(file_from_desc, buffer, 1024);
		if (bytes_read == -1)
			check_file_desc(-1, 1, argv);
		bytes_out = write(file_to_desc, buffer, bytes_read);
		if (bytes_out == -1)
			check_file_desc(1, -1, argv);
	} while (bytes_read == 1024);


	if (close_fd(file_to_desc) || close_fd(file_from_desc))
		exit(100);

	return (0);
}

/**
 * close_fd - closes a file descriptor.
 * @file_desc: file descriptor to close.
 * Return: 0 if file descriptors closed successfully, else 1.
 */
int close_fd(int file_desc)
{
	if (close(file_desc))
	{
		dprintf(2, "Error: Can't close fd %d\n", file_desc);
		return (1);
	}
	return (0);
}

/**
 * check_file_desc - checks if the file descriptors are valid.
 * @arg: an array of strings
 * @file_from_desc: file descriptor of the file to read from.
 * @file_to_desc: file descriptor of the file to write to.
 * Return: nothing.
 */
void check_file_desc(int file_from_desc, int file_to_desc, char **arg)
{
	if (file_from_desc == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", arg[1]);
		exit(98);
	}
	else if (file_to_desc == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", arg[2]);
		exit(99);
	}
}
