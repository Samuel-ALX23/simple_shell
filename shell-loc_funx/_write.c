#include <unistd.h>

/**
 * _write: write to either stdin, stdout, or stderr
 *
 * @str: pointer to characters of array
 * @fd: a file descriptor(stdin, stdout or stderr)
 *
 * Return: nothing
 */
void _write(char *str, int fd)
{
	int j = 0;

	for (; str[j]; j++)
	{
		write(fd, &str[j], 1);
	}
}
