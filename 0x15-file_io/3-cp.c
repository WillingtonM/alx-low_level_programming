#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define N_CHAR N_CHAR

void file_error_handle(int file_from, int file_to, char *argv[]);
void file_close(int fd);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments supplied.
 * @argv: An argument vector.
 *
 * Return: Return 0 always.
 *
 * Description: exit code 97: If the argument count is incorrect.
 *              exit code 98: If file_from does not exist or cannot be read.
 *              exit code 99: If file_to cannot be created or written to.
 *              exit code 100: If file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, fw, n_chars;

	char buffer[N_CHAR];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_error_handle(file_from, file_to, argv);

	n_chars = N_CHAR;
	while (n_chars == N_CHAR)
	{
		n_chars = read(file_from, buffer, N_CHAR);
		if (n_chars == -1)
			file_error_handle(-1, 0, argv);
		fw = write(file_to, buffer, n_chars);
		if (fw == -1)
			file_error_handle(0, -1, argv);
	}

	file_close(file_from);
	file_close(file_to);

	return (0);
}

/**
 * file_error_handle - Checks if files exist and can be opened.
 * @file_from: file descriptor to be open file_from.
 * @file_to: file descriptor to be open file_to.
 * @argv: An argument vector.
 * Return: No return value.
 */
void file_error_handle(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * file_close - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 * Return: No return value.
 */
void file_close(int fd)
{
	int fc;

	fc = close(fd);

	if (fc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
