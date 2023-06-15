#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int j, b;
	size_t length, addition;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char pass[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	length = strlen(argv[1]);
	pass[0] = l[(length ^ 59) & 63];
	for (j = 0, addition = 0; j < length; j++)
		addition += argv[1][j];
	pass[1] = l[(addition ^ 79) & 63];
	for (j = 0, b = 1; j < length; j++)
		b *= argv[1][j];
	pass[2] = l[(b ^ 85) & 63];
	for (b = argv[1][0], j = 0; j < length; j++)
		if ((char)b <= argv[1][j])
			b = argv[1][j];
	srand(b ^ 14);
	pass[3] = l[rand() & 63];
	for (b = 0, j = 0; j < length; j++)
		b += argv[1][j] * argv[1][j];
	pass[4] = l[(b ^ 239) & 63];
	for (b = 0, j = 0; (char)j < argv[1][0]; j++)
		b = rand();
	pass[5] = l[(b ^ 229) & 63];
	printf("%s\n", pass);
	return (0);
}
