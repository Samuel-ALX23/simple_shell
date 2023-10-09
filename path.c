#include "shell.h"

char *fetch_path(char *sh) 
{
  
  #define MAX_PATH_SIZE 1024
  char *path = NULL;
  int sh_len;
  int cmd_len;
  int i = 0;
char *list[] = {"/bin/", "/usr/bin/", NULL};


  
  path = malloc(MAX_PATH_SIZE);

    if (path == NULL) 
    {
        perror("Path: allocation error");
        exit(2);
    }
     i = 0;
    while (list[i])
    {
      char *cmd = list[i];
        cmd_len = strlen(list[i]);
        sh_len = strlen(sh);

        
        strcpy(path, list[i]);
       strcpy(path + cmd_len, sh);

          path[cmd_len + sh_len] = '\0';

        
        if (access(path, X_OK) == 0) 
        {
            return path;
        }
        i++;
    }
          perror("Error: File not executable");
    
    free(path);
   return (NULL);
}

