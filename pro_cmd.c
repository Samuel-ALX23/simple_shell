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
	pid_t pid;
        int status = 0;
        char *cmd = NULL;
        char *process_cmd = NULL;
/*	extern char **environ;*/


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
		/*if (strcmp(cmd, "ls") == 0)*/
	argv[0] = process_cmd;
	
			pid = fork();
        if (pid == 0)
        {
                if (execve(argv[0], argv, NULL) == -1)
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
}
