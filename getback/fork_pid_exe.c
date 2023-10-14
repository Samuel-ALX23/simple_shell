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

void exe_process(char **argv)
{
	pid_t pid;
	int status = 0;
	extern char **environ;
	char *cmd = argv[0];
	char *process_cmd = NULL;

	process_cmd = fetch_path(cmd);


	pid = fork();
	if (pid == 0)
	{
		if (execve(process_cmd, argv, environ) == -1)
			perror("ERROR: Child_fork failed");
		exit(2);
	}
	else if  (pid < 0)
	{
		perror("ERROR: fork error");
		exit(2);
	}
	else
	{
		wait(&status);
	}
}
