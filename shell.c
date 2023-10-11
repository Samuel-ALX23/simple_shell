#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function serves as the entry point of the program that
 * implements a simple command-line interpreter.
 *
 * Return: 0 always(sucess)
 */

int main(void);
int main(void)
{
	char **tokens = NULL;
	char *command = NULL;
	size_t size = 0;
	int i = 0;
	char *index = NULL;
	int terminal = 1;
	ssize_t get_byte = 0;

	while (1)
	{
		terminal = isatty(STDIN_FILENO);
		tokens =  malloc(10 * sizeof(char *));
		if (terminal != 0)

			write(1, "$ ", 2);
		i = 0;
		get_byte = getline(&command, &size, stdin);
		index = strtok(command, "\n\t\r");
		while (index)
		{
			tokens[i] = malloc(sizeof(char) * (strlen(index) + 1));
			if (!tokens[i])
			{
				perror("ERROR: Memory allocation failed");
				exit(2);
			}
			strcpy(tokens[i], index);
			i++;
			index = strtok(NULL, "\n\t\r");
		}
		if (i == 0)
		{
			free(tokens);
			continue;
		}
		tokens[i] = NULL;

		check_strcp(tokens);

		if (terminal == 1)
			break;


		exe_process(tokens);

		if (get_byte > 1)
		{
			if (tokens[0] != NULL)
			{
				freeus(tokens);
			}
		}

	}
	if (command != NULL)
		free(command);
	return (0);
}
