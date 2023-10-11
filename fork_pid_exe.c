#include "shell.h"



void exe_process(char **tokens) 
{
    pid_t pid = getpid();
    int status = 0;
  extern char **environ;
   /* char *com_path = NULL;*/

 /* com_path = fetch_path(tokens[0]);*/


    pid = fork();
      if(pid == 0)
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
