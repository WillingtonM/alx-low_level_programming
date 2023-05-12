#include "main.h"

/**
 * create_file - Creates a file
 * @filename: A pointer to a filename to create.
 * @text_content: Pointer to string/content to be writen to file.
 *
 * Return: Return 1 if it success. Return -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd_o, n_letters, fw;

	if (filename == NULL)
		return (-1);

	fd_o = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd_o == -1)
		return (-1);

	if (text_content != NULL)
		for (n_letters = 0; text_content[n_letters];)
			n_letters++;

	fw = write(fd_o, text_content, n_letters);

	if (fw == -1)
		return (-1);

	close(fd_o);

	return (1);
}
