#include "main.h"
/**
 * create_file - creates a file.
 * @filename: name of the file to create.
 * @text_content: content to be written to the newly created file.
 * Return: 1 if operation was successful else -1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc;
	int len = 0;

	if (filename == NULL)
		return (-1);

	while (text_content[len])
		len++;

	file_desc = open(filename, O_WRONLY | O_TRUNC | O_CREAT,
			0640);
	if (file_desc == -1)
		return (-1);

	if (text_content != NULL)
		write(file_desc, text_content, len);

	close(file_desc);

	return (1);
}
