#include "main.h"

/**
 * read_textfile - Reads a text file and prints letters.
 * @filename: A pointer to the filename.
 * @letters: The number of letters printed.
 *
 * Return: Returns 0, if it fails otherwise Returns number of printed letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd_o, fr, fw;

	if (filename == NULL)
		return (0);

	fd_o = open(filename, O_RDONLY);

	if (fd_o == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	fr = read(fd_o, buff, letters);
	fw = write(STDOUT_FILENO, buff, fr);

	if (fr == -1 || fw == -1 || fw != fr)
	{
		free(buff);
		return (0);
	}

	close(fd_o);
	free(buff);

	return (fw);
}
