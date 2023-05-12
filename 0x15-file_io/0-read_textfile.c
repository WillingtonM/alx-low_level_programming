#include "main.h"

/**
 * read_textfile - reads a text file and prints letters.
 * @filename: A pointer to the filename.
 * @letters: The number of letters printed.
 *
 * Return: Returns 0, if it fails. Returns number of printed letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd_o, fd_r, fd_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd_o = open(filename, O_RDONLY);
	fd_r = read(fd_o, buffer, letters);
	fd_w = write(STDOUT_FILENO, buffer, fd_r);

	if (fd_o == -1 || fd_r == -1 || fd_w == -1 || fd_w != fd_r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd_o);

	return (fd_w);
}
