#include "shell.h"

/**
 * tokenize - Tokenizes a string based on delimiters
 * @command: The string to be tokenized
 * @delim: The string containing delimiters
 *
 * Return: A pointer to an array of tokenized strings, or NULL on failure
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

	while (index)
	{
		index_count++;
		index = strtok(NULL, " \t");

		write(1, command, index_count);

		command_tok = malloc(sizeof(char *) * (index_count) + 1);
		if (command_tok == NULL)
		{
			return (NULL);
		}

		index = strtok(command, delim);
		i = 0;
		while (index)
		{
			command_tok[i] = index;
			index = strtok(NULL, delim);
			i++;
		}
		command_tok[i] = NULL;
		
			free(command_tok[i]);

	}
		free(temp); 
	return (command_tok);
}
