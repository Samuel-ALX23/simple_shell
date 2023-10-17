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
int main(void)
{
	char *command = NULL;
	char *argv[1024] = {NULL};
	char *index = NULL;
	int interactive = 1;
	size_t size = 0;
	ssize_t get_byte = 0;
	int i = 0;

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
			exit(0);
		}
		index = strtok(command, " \n\t\r");
		for (i = 0; index; i++)
		{
			argv[i] = index;
			index = strtok(NULL, " \n\t\r");

		}
		argv[i] = NULL;
		i = 0;
		if (argv[0] == NULL)
			continue;
		if (strcmp(argv[0], "exit") == 0)
		{
			free(command);
			exit(0);
		}
		if (strcmp(argv[0], "env") == 0)
		{
			env();
			continue;
		}



		procmd(argv, command);
		if (interactive == 0)
			break;
		continue;
	}

	return (0);
}
