#include "main.h"

int close_fd(int file_desc);
void print_error(char *arg, int action, int code);
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
	int file_from_desc = -1, file_to_desc = -1;
	char buffer[1024];
	int bytes_read = -1;

	if (argc != 3)
	{
		dprintf(2, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from_desc = open(argv[1], O_RDONLY);
	file_to_desc = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_from_desc == -1)
		print_error(argv[1], 0, 98);
	if (file_to_desc == -1)
		print_error(argv[2], 1, 99);

	do {
		bytes_read = read(file_from_desc, buffer, 1024);
		if (bytes_read == -1)
			print_error(argv[1], 1, 98);
		if (write(file_to_desc, buffer, bytes_read) == -1)
			print_error(argv[2], 2, 99);
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
 * print_error - prints an error message and exit the progrma.
 * @name: a string.
 * @action: an integer representing the action to take.
 * @exit_code: code to exit with.
 * Return: nothing.
 */
void print_error(char *arg, int action, int code)
{
	if (action == 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", arg);
		exit(code);
	}
	else if (action == 1)
	{
		dprintf(2, "Error: Can't write to %s\n", arg);
		exit(code);
	}
}
