#include "shell.h"

/**
 * exe_process - Execute a command in a child process.
 * @tokens: An array of command arguments.
 * Description: This function creates a child process and executes
 * the specified command with the given arguments
 * It waits for the child process to complete before returning
 * The environment variables are inherited from the parent process
 *
 * Return: void as (sucess);
 */

void exe_process(char **tokens)
{
	pid_t pid = getpid();
	int status = 0;
	extern char **environ;
	/* char *com_path = NULL;*/

	/* com_path = fetch_path(tokens[0]);*/


	pid = fork();
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, environ))
			perror("ERROR: Child_fork failed");
		exit(2);
	}
	else if  (pid < 0)
	{
		perror("ERROR: fork error");
	}
	else
	{
		wait(&status);
	}
}
