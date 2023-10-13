#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 *
 */
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

	while(1)
	{
		interactive = isatty(STDIN_FILENO);
		if (interactive != 0)

		write(1, "$ ", 2);
		get_byte = getline(&command, &size, stdin);
		if (get_byte == -1)
		{
			perror("ERROR: Reading line fail");
			return(-1);
		}
		tokens = malloc(get_byte * sizeof(char));
		if(!tokens)
		{
			perror("ERROR: Allocation failed");
			return (-1);
		}
		strcpy(tokens, command);
		index = strtok(command, "\n\t\r");
		while(index)
		{
			num_tok++;
			index = strtok(NULL, "\n\t\r");

		}
		num_tok++;

		argv = malloc(num_tok * sizeof(char *));
		index = strtok(tokens, "\n\t\r");
		
		i = 0;
		for(; index; i++)
		{
			argv[i] = malloc(sizeof(char) *strlen(index));
			strcpy(argv[i], index);
			index = strtok(NULL, "\n\t\r");
		}
		argv[i] = NULL;
		if (interactive == 1)
                        continue;

		procmd(argv);
	}
	free(tokens);
	free(command);
	return (0);
}
