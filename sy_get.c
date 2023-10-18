#include <stdio.h>

/**
 * my_getline - Read a line from a stream and store it in a buffer
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the capacity of the buffer
 * @stream: The input stream to read from
 *
 * Return: num_chars always(success)
 */
ssize_t my_getline(char *lineptr, size_t size, FILE *stream)
{
	if (lineptr == NULL || stream == NULL || size == 0)
	{
		return (-1);
	}

	ssize_t num_chars = 0;
	int c;

	while ((c = fgetc(stream)) != EOF)
	{
		if (num_chars >= size - 1)
		{
			break;
		}

		lineptr[num_chars] = c;
		num_chars++;

		if (c == '\n')
		{
			break;
		}
	}

	if (num_chars == 0)
	{
		return (-1);
	}

	lineptr[num_chars] = '\0';

	if (c != '\n' && c != EOF)
	{
		int discard;
		while ((discard = fgetc(stream)) != '\n' && discard != EOF)
		{

		}
	}

	return (num_chars);
}
