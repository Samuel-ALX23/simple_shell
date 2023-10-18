#include <unistd.h>

/**
 * my_write - a function that write to either stdin, stdout, or stderr
 * @buf: pointer to characters of array
 * @fd: a file descriptor(stdin, stdout or stderr)
 * @n: unsigned integer
 *
 * Return: bytes always (sucess)
 */

ssize_t my_write(int fd, const void *buf, size_t n)
{
	const char *buffer = buf;
	size_t bytes = 0;

	while (bytes < n)
	{
		ssize_t result = write(fd, buffer + bytes, n - bytes);

		if (result == -1)
		{
			return (-1);
		}

		bytes += result;
	}

	return (bytes);
}
