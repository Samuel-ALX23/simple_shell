#include <stdio.h>

/**
 * my_getline - Read a line from a stream and store it in a buffer
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the capacity of the buffer
 * @stream: The input stream to read from
 *
 * Return: num_chars always(success)
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	size_t capacity = *n;
	ssize_t num_chars = 0;
	int c;

	if (*lineptr == NULL)
	{
		capacity = 128;
		*lineptr = malloc(capacity);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (num_chars >= capacity - 1)
		{
			capacity *= 2;
			char *temp = realloc(*lineptr, capacity);
			if (temp == NULL)
			{
				return (-1);
			}
			*lineptr = temp;
			*n = capacity;
		}

		(*lineptr)[num_chars] = c;
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

	(*lineptr)[num_chars] = '\0';

	return (num_chars);
}
