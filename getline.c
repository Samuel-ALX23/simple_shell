#include "shell.h"

int main(int ac __attribute__((unused)),char*av[] __attribute__((unused)),
	       	char**envp __attribute__((unused))) 
{

  char *command = NULL;
  char **command_tok = NULL;
  size_t size = 0;
  ssize_t get_byte = 0;
  int i = 0;

  while(1)
  {
    write(1, "|_>$ ", 5);
  get_byte = getline(&command, &size, stdin);
  if (get_byte == -1)
  {
    perror ("ERROR");
    free(command);
    break;
  }
  else
  write (1, command, get_byte);
  i = 0;
  while(command[i])
  {
    if (command[i] == '\n')
      command[i] = '\0';
    i++;
    
  }
  command_tok = tokenize(command, " \t");
  command = NULL;
  free(command);
}
	free(command_tok);
	return (0);
}
