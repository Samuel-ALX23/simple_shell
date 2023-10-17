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
	 char *temp = NULL;

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
<<<<<<< HEAD:shell.c
		input = my_strdup(command);
		token = my_strtok(input, " ");
		if (my_strcmp(token, "\n") == 0)
=======
		input = strdup(command);
		token = strtok(input, " \n");
		if (strcmp(token, "\n") == 0)
>>>>>>> cec26668c2b4b10d1dd47ff98a6f81ec2e002e29:shell-loc_funx/shell2.c
		{
			free(input);
			free(command);
			continue;
		}

		tokens = malloc((get_byte + 1) * sizeof(char));
		if (!tokens)
		{
			perror("ERROR: Allocation failed");
			free(command);
			free(tokens);
			free(input);
			return (-1);
		}
<<<<<<< HEAD:shell.c
		my_strcpy(tokens, command);
		index = my_strtok(command, " \n\t\r");
=======
		strcpy(tokens, command);
		temp  = command;
		index = strtok(command, " \n\t\r");
>>>>>>> cec26668c2b4b10d1dd47ff98a6f81ec2e002e29:shell-loc_funx/shell2.c
		while (index)
		{
			num_tok++;
			index = my_strtok(NULL, " \n\t\r");
		}
		num_tok++;
		free(temp);

		argv = malloc(num_tok * sizeof(char *));
		if (!argv)
		{
			perror("ERROR: Allocation failed");
			free(input);
			free(argv);
			free(tokens);
			return (-1);
		}
		index = my_strtok(tokens, " \n\t\r");

		i = 0;
		argv[i] = index;
		i++;
		index = my_strtok(NULL, " \n\t\r");
		for (; index; i++)
		{
			argv[i] = index;
			index = my_strtok(NULL, " \n\t\r");
		}
		argv[i] = NULL;

		procmd(argv);
		if (interactive == 0)
		break;
	}
	/*free(input);*/
	free(tokens);
	/*free(command);*/

	return (0);
}
