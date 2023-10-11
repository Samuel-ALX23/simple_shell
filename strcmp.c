#include "shell.h"
/**
 *
 *
 *
 *
 *
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

	if(strcmp(tokens[0], "env") == 0)
	{
		env();
		freeus(tokens);

	}
	return (0);
}
