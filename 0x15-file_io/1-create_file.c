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
	int fd, nletters, fw;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
		for (nletters = 0; text_content[nletters];)
			nletters++;

	fw = write(fd, text_content, nletters);

	if (fw == -1)
		return (-1);

	close(fd);

	return (1);
}