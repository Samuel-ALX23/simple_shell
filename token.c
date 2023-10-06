#include "shell.h"
/**
 *
 *
 *
 *
 */
char **tokenize(char *command, char *delim)
{
	char *index = NULL;
	int i = 0;
	char **command_tok = NULL;
	int index_count = 0;
	char *temp = NULL;

	temp = strdup(command);
	index = strtok(temp, delim);

	while(index)
	{
		index_count++;
		index = strtok(NULL, " \t");

		write(1, command, index_count);

		command_tok = malloc(sizeof(char*) * (index_count) + 1);
		if (command_tok == NULL)
		{
			return (NULL);
		}

		index = strtok(command, delim);
		i = 0;
		while(index)
		{
			command_tok[i] = index;
			index = strtok(NULL, delim);
			i++;
		}
		command_tok[i] =NULL;
		free(temp);
	}

		return(command_tok);
}
