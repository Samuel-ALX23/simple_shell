#include "shell.h"

/**
 * freeus - Free memory allocated for an array of strings
 * @tokens: An array of strings
 * Description: This function frees the memory allocated for the
 * array of strings passed as @tokens
 *
 * Return: void always (sucess)
 */

void freeus(char **tokens)
{
	int j = 0;

	if (tokens == NULL)
	{
		return;
	}

	j = 0;
	for (j = 0; tokens[j]; j++)
	{
		if (tokens[j] != NULL)
		{
			free(tokens[j]);
		}

	}

	if (tokens != NULL)
	free(tokens);
}
