#include "shell.h"



void exe_cmd(char **args) 
{
    pid_t pid;
    int status;
  extern char **environ;
    char *com_path = NULL;

  com_path = fetch_path(args[0]);
    if (com_path == NULL) 
    {
       perror ("Path: command not found");
        return;
    }

    pid = fork();
      if(pid == 0)
    {
      if (execve(args[0], args, environ) == -1)
        {
            perror("ERROR: Child_fork failed");
        }
        exit(2);
    } 
    else if (pid < 0) 
    {
        perror("ERROR: fork error");
    } 
    else 
    {
        wait(&status);
    }
    free(com_path);
}

