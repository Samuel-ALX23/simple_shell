#include "shell.h"


char *tokenizer(char *command)
{
	size_t size = 0;
	int i = 0;
  char *index = NULL;
	char **tokens = NULL;

  tokens = malloc(20 * sizeof(char *))
  if(!tokens)
  {
    perror(ERROR: Memory allocation failed);
    exist (2);
  }

   index = strtok(command, " \t");
	 i = 0;
	while(index)
	{
	  tokens[i] = malloc(sizeof(char) * (strlen(index) + 1));
    if (!tokens[i]) 
    {
        perror("ERROR: Memory allocation failed");
            exit(2);
    }
    strcpy(tokens[i], index);
	       i++;
	       index = strtok(NULL, " \t");
  }
  free(tokens[i])
   tokens[i] = NULL;
  return (tokens);
}

