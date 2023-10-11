#include "shell.h"

/**
 * check_strcp - Check and execute a command if it matches specific strings.
 * @tokens: An array of command arguments.
 * Description: This function checks the value of the first argument
 * to print environment variables.
 *
 * Return: 0 always(sucess)
 */

int check_strcp(char **tokens)
{
	extern char **environ;

	if (strcmp(tokens[0], "ls") == 0)
	{
		if (execve("/usr/bin/ls", tokens, environ) == -1)
			perror("ERROR: Execution failed");
		freeus(tokens);
	}

	if (strcmp(tokens[0], "exit") == 0)
	{	freeus(tokens);
		exit(0);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		env();
		freeus(tokens);
	}
	return (0);
}
