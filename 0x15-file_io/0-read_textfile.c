
#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - reads a text file and prints letters.
 * @filename: A pointer to the filename.
 * @letters: The number of letters printed.
 *
 * Return: Returns 0, if it fails. Returns number of printed letters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t fr, fw;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fr = read(fd, buffer, letters);
	fw = write(STDOUT_FILENO, buffer, fr);

	if (fr == -1 || fw == -1 || fw != fr)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);

	return (fw);
}
