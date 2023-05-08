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
	int src, dest, fclose;
	ssize_t nread = 1024, nwrite;
	char buffer[1024];

	/* validate the number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	/* opens the source and destination files */
	src = open(argv[1], O_RDONLY);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	/* validates the file descriptors */
	validate_fd(src, dest, argv);
	/* transfer bytes from the src to the destination files */
	while (nread == 1024)
	{
		/* read and validate bytes from the src file into the buffer */
		nread = read(src, buffer, 1024);
		if (nread == -1)
			validate_fd(-1, 0, argv);
		/* write and validate bytes from the buffer to the destination file */
		nwrite = write(dest, buffer, nread);
		if (nwrite == -1)
			validate_fd(0, -1, argv);
	}
	/* closes the file descriptors */
	fclose = close(src);
	if (fclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	fclose = close(dest);
	if (fclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	/* returns 0 if successful */
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
