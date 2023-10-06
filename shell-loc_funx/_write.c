#include "shell.h"

/**
 * _write: write to either stdin, stdout, or stderr
 *
 * @str: pointer to characters of array
 * @stm: where to print to (stdin, stdout or stderr)
 *
 * Return: nothing
 */
void _write(char *str, int stm)
{
	int index = 0;

	for (; str[index]; index++)
	{
		write(stm, &str[index], 1);
	}
}
