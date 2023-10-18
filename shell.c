#include "shell.h"

/**
 * main - reads commands from the user, parses them into tokens and executes
 *
 * Return: 0 always(sucess)
 */
int main(void);
int main(void)
{
	char *command = NULL;
	char *argv[1024] = {NULL};
	char *index = NULL;
	char cwd[1024];
	int interactive = 1;
	size_t size = 0;
	ssize_t get_byte = 0;
	int i = 0;

	while (1)
	{
		interactive = isatty(STDIN_FILENO);
		if (interactive != 0)

			/*write(1, "$ ", 2);*/
		get_byte = getline(&command, &size, stdin);
		if (get_byte == -1)
		{
			perror("ERROR: Reading line fail");
			free(command);
			exit(0);
		}
		index = my_strtok(command, " \n\t\r");
		for (i = 0; index; i++)
		{
			argv[i] = index;
			index = my_strtok(NULL, " \n\t\r");

		}
		argv[i] = NULL;
		i = 0;
		if (argv[0] == NULL)
			continue;
		if (my_strcmp(argv[0], "exit") == 0)
		{
			free(command);
			exit(0);
		}
		if (my_strcmp(argv[0], "env") == 0)
		{
			env();
			continue;
		}

		if (my_strcmp(argv[0], "cd") == 0)
		{
			if (argv[1] == NULL)
			{
				chdir(getenv("HOME"));
			}
			else if (my_strcmp(argv[1], "-") == 0)
			{
				chdir(getenv("HOME"));
			}
			else
			{
				if (chdir(argv[1]) < 0)
				{
					perror("ERROR: changing failed");
				}
			}

			continue;
		}
		if (my_strcmp(argv[0], "pwd") == 0)
		{

			getcwd(cwd, sizeof(cwd));
			my_write(1, cwd, my_strlen(cwd));
			my_write(1, "\n", 1);


			continue;
		}
		procmd(argv, command);
		if (interactive == 0)
			break;
		continue;
	}

	return (0);
}
