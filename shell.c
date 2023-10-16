#include "shell.h"
/**
 * main - Entry point of the shell program
 * @ac: The number of command-line arguments (unused)
 * @argv: An array of command-line arguments
 * Description: It reads commands from the user, parses
 * them into tokens, and executes them using procmd function
 *
 * Return: 0 always(sucess)
 */

int main(__attribute__((unused))int ac, char **argv);
int main(__attribute__((unused))int ac, char **argv)
{
	char *command = NULL;
	char *tokens = NULL;
	char *index = NULL;
	int interactive = 1;
	size_t size = 0;
	ssize_t get_byte = 0;
	int i = 0;
	int num_tok = 0;
	char *input = NULL;
	char *token = NULL;

	while (1)
	{
		interactive = isatty(STDIN_FILENO);
		if (interactive != 0)

			write(1, "$ ", 2);
		get_byte = getline(&command, &size, stdin);
		if (get_byte == -1)
		{
			perror("ERROR: Reading line fail");
			free(command);
			return (-1);
		}
		input = strdup(command);
		token = strtok(input, " ");
		if (strcmp(token, "\n") == 0)
		{
			free(input);
			free(command);
			continue;
		}

		tokens = malloc(get_byte * sizeof(char));
		if (!tokens)
		{
			perror("ERROR: Allocation failed");
			free(command);
			free(tokens);
			free(input);
			return (-1);
		}
		strcpy(tokens, command);
		index = strtok(command, " \n\t\r");
		while (index)
		{
			num_tok++;
			index = strtok(NULL, " \n\t\r");
		}
		num_tok++;

		argv = malloc(num_tok * sizeof(char *));
		if (!argv)
		{
			perror("ERROR: Allocation failed");
			free(command);
			free(input);
			free(argv);
			free(tokens);
			return (-1);
		}
		index = strtok(tokens, " \n\t\r");

		i = 0;
		argv[i] = index;
		i++;
		index = strtok(NULL, " \n\t\r");
		for (; index; i++)
		{
			argv[i] = index;
			index = strtok(NULL, " \n\t\r");
		}
		argv[i] = NULL;

		procmd(argv);
		if (interactive == 0)
			break;
	}
	free(input);
	free(tokens);
	free(command);

	return (0);
}
