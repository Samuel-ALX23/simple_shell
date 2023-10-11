#include "shell.h"
/**
 *
 *
 *
 *
 */
void freeus(char **tokens)
{
int j = 0;

if (tokens == NULL){
	return;
}
	j = 0;
	for(j = 0; tokens[j]; j++)
	{
		if(tokens[j] != NULL)
		{
		free(tokens[j]);
		}
	
	}
	if (tokens != NULL)
	
		free(tokens);
}

