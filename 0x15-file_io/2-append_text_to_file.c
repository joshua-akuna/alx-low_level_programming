#include "main.h"
/**
 * append_text_to_file - appends a text argument
 * to the end of a file.
 * @filename: path to the file.
 * @text_content: text to append to the end of the file.
 * Return: 1 if operation was successful, else -1;
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_desc;
	int len = 0, bytes_out = 0;

	if (filename == NULL)
		return (-1);

	file_desc = open(filename, O_WRONLY | O_APPEND);
	if (file_desc == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		bytes_out = write(file_desc, text_content, len);
	}

	if (bytes_out != len || close(file_desc))
		return (-1);
	return (1);
}
