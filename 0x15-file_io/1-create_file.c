#include "main.h"
/**
 * create_file - creates a file.
 * @filename: name of the file to create.
 * @text_content: content to be written to the newly created file.
 * Return: 1 if operation was successful.
 * -1 if filename is NULL or on operation failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc;
	int len = 0, bytes_out = 0;

	if (filename == NULL)
		return (-1);


	file_desc = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0640);
	if (file_desc == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		bytes_out = write(file_desc, text_content, len);
	}

	if (bytes_out != len)
		return (-1);
	close(file_desc);

	return (1);
}
