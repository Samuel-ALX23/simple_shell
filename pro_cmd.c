#include "shell.h"
/**
 * procmd - Executes a command with the given arguments
 * @argv: The array of command arguments
 * Description: The function fetches the absolute path of the command
 *
 * Return: void always(sucess)
 */
void procmd(char **argv);
void procmd(char **argv)
{
	pid_t pid;
	int status = 0;
	char *cmd = NULL;
	char *process_cmd = NULL;

	if(argv)
	{
		cmd = argv[0];
		process_cmd = fetch_path(cmd);

		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		if (strcmp(cmd, "env") == 0)
		{
			env();
			return;
		}
		argv[0] = process_cmd;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("ERROR: Child_fork failed");
				free(argv[0]);
				exit(2);
			}
		}
		else if  (pid < 0)
		{
			perror("ERROR: fork error");
			free(argv[0]);
			exit(2);
		}
		else
		{
			wait(&status);
			free(argv);
		}
	}
}
