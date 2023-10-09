#include "shell.h"


int check_variable(char **args)
{ 
  char *path = "usr/bin/ls";
  extern char **environ;
  int i = 0; 
  
  if (strcmp(args[0], "ls") == 0) 
  {
  if (execve("/usr/bin/ls", args, environ) == -1) 
        {
            perror("ERROR: Execution failed");
        }
  }
 else if (strcmp(args[0], "exit") == 0) 
    {
        exit(0);
    } 
  else if(strcmp(args[0], "env") == 0)
    {    i = 0;
        while(environ[i])
        {
            write(1, environ[i], strlen(environ[i]));
            write(1, "\n", 1);
          i++;
        }
        return 1;
   
    }
    return 0;
}

