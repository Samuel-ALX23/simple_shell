#include "shell.h"


char *tokenizer()
{

	int i = 0;
	char *index = NULL;
	char **tokens = malloc(20 * sizeof(char *));
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
		index = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;
	return (tokens[i]);
}

