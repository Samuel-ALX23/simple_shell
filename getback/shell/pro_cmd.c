#include "shell.h"
/**
 * procmd - Executes a command with the given arguments
 * @argv: The array of command arguments
 * Description: The function fetches the absolute path of the command
 *
 * Return: void always(sucess)
 */
void procmd(char **argv, char *cmd);
void procmd(char **argv, char *cmd)
{
	pid_t pid;
	int status = 0;
	extern char **environ;

	pid = fork();
	if (pid == 0)
	{
<<<<<<< HEAD:pro_cmd.c
		if(strcmp(argv[0], "ls") == 0)
		{
			if (execve("/bin/ls", argv, environ) == -1)
=======
		cmd = argv[0];
		process_cmd = fetch_path(cmd);

		if (my_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		if (my_strcmp(cmd, "env") == 0)
		{
			env();
			return;
		}
		argv[0] = process_cmd;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
>>>>>>> 42e538268198e44c8550bf289bc7b8b08dd47f03:shell/pro_cmd.c
			{
				perror("ERROR: Child_fork failed");
				free(cmd);
				exit(2);
			}
		}
		else
		{

			if (execve(argv[0], argv, environ) == -1)
			{	
				write(2, "./hsh: 1: ", 10); 
				write(2, argv[0], strlen(argv[0]));
				write(2,": not found\n", 12);
				free(cmd);
				exit(2);
			}
		}
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
