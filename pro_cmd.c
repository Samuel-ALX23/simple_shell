#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 */
void procmd(char **argv)
{
	char *process_cmd = NULL;

	char *cmd = NULL;
	extern char **environ;


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
			free(cmd);
			return;


		}
		if (strcmp(cmd, "ls") == 0)
		{

			if (execve(process_cmd, argv, environ) == -1)
			{
				perror("ERROR: Process failed");

			}




		}
	}
}
