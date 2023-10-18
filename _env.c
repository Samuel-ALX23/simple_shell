#include "shell.h"

/**
 * _env - Prints the environment variables
 *
 * Description: This function prints all the environment variables
 * to the standard output, with each variable on a new line
 *
 * REturn: void as (sucess)
 */

void _env(void)
{
	int i = 0;

	i = 0;
	while (environ[i])
	{
		my_write(1, environ[i], my_strlen(environ[i]));
		my_write(1, "\n", 1);
		i++;
	}
}
