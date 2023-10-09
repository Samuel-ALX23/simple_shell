#include "shell.h"

int main(void)
{
  char **tokens = NULL;
  char **args = NULL;
    char *command;
  size_t size = 0;
  int interactive = 1;
  size_t get_byte = 0;
  int j = 0;
  int i = 0;
  
   while (1) 
    {
       interactive = isatty(STDIN_FILENO);
      i = 0;
      if (interactive)
        write(1, "$ ", 2);
      get_byte = getline(&command, &size, stdin);
        if (get_byte == -1)
        break;
    tokens[0] = tokenizer(command);

        if (check_variable(tokens) == 0) 
        {
            exe_cmd(tokens);
        }
     
  j = 0;
  for (; tokens[j]; j++) 
      {
            free(tokens[j]);
      }
      free(tokens);
      
    {
        free(command); 
    }
  }
    return 0;
}

